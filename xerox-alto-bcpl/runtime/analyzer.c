/**
 * Xerox Alto BCPL Source Analyzer
 * Analyzes the structure and dependencies of the Alto BCPL compiler sources
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#define PATH_SEPARATOR '\\'
#else
#include <dirent.h>
#include <unistd.h>
#define PATH_SEPARATOR '/'
#endif

#define MAX_LINE_LENGTH 1024
#define MAX_FILENAME 256
#define MAX_FILES 100
#define MAX_DEPENDENCIES 50

typedef struct {
    char name[MAX_FILENAME];
    char type[32];  // "main", "cae", "lex", "sae", "trn", "ncg", "platform", "header"
    char dependencies[MAX_DEPENDENCIES][MAX_FILENAME];
    int dep_count;
    size_t size;
    int lines;
    bool analyzed;
    char description[512];
} bcpl_file_info_t;

typedef struct {
    bcpl_file_info_t files[MAX_FILES];
    int file_count;
    char source_dir[MAX_FILENAME];
} bcpl_project_t;

static bcpl_project_t project = {0};

/**
 * Determine file type based on name
 */
static const char* get_file_type(const char* filename) {
    if (strstr(filename, "BCPL0") || strstr(filename, "BCPL1")) {
        return "main";
    } else if (strncmp(filename, "BCAE", 4) == 0) {
        return "cae";
    } else if (strncmp(filename, "BLEX", 4) == 0) {
        return "lex";
    } else if (strncmp(filename, "BSAE", 4) == 0) {
        return "sae";
    } else if (strncmp(filename, "BTRN", 4) == 0) {
        return "trn";
    } else if (strncmp(filename, "BNCG", 4) == 0) {
        return "ncg";
    } else if (strstr(filename, "ALTO") || strstr(filename, "DOS")) {
        return "platform";
    } else if (strchr(filename, '.') == NULL && filename[strlen(filename)-1] == 'X') {
        return "header";
    } else {
        return "utility";
    }
}

/**
 * Extract dependencies from a BCPL file
 */
static void analyze_dependencies(bcpl_file_info_t* file_info, const char* filepath) {
    FILE* fp = fopen(filepath, "r");
    if (!fp) {
        fprintf(stderr, "Warning: Cannot open file %s\n", filepath);
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    file_info->dep_count = 0;
    file_info->lines = 0;
    
    bool in_comment = false;
    
    while (fgets(line, sizeof(line), fp) && file_info->dep_count < MAX_DEPENDENCIES) {
        file_info->lines++;
        
        // Remove trailing whitespace
        int len = strlen(line);
        while (len > 0 && isspace(line[len-1])) {
            line[--len] = '\0';
        }
        
        // Skip empty lines
        if (len == 0) continue;
        
        // Handle single-line comments
        if (strstr(line, "//")) {
            char* comment_start = strstr(line, "//");
            *comment_start = '\0';
        }
        
        // Look for GET directives
        if (strstr(line, "GET")) {
            char* get_pos = strstr(line, "GET");
            char* quote_start = strchr(get_pos, '"');
            if (quote_start) {
                quote_start++;
                char* quote_end = strchr(quote_start, '"');
                if (quote_end) {
                    *quote_end = '\0';
                    // Add dependency if not already present
                    bool already_exists = false;
                    for (int i = 0; i < file_info->dep_count; i++) {
                        if (strcmp(file_info->dependencies[i], quote_start) == 0) {
                            already_exists = true;
                            break;
                        }
                    }
                    if (!already_exists) {
                        strncpy(file_info->dependencies[file_info->dep_count], 
                               quote_start, MAX_FILENAME - 1);
                        file_info->dependencies[file_info->dep_count][MAX_FILENAME - 1] = '\0';
                        file_info->dep_count++;
                    }
                }
            }
        }
        
        // Extract description from comments near the top
        if (file_info->description[0] == '\0' && file_info->lines < 20) {
            if (strstr(line, "//") && (strstr(line, "BCPL") || strstr(line, "Compiler"))) {
                char* comment = strstr(line, "//");
                if (comment) {
                    comment += 2;
                    while (*comment == ' ') comment++;
                    if (strlen(comment) > 10) {  // Ignore very short comments
                        strncpy(file_info->description, comment, sizeof(file_info->description) - 1);
                        file_info->description[sizeof(file_info->description) - 1] = '\0';
                    }
                }
            }
        }
    }
    
    fclose(fp);
}

/**
 * Get file size
 */
static size_t get_file_size(const char* filepath) {
    struct stat st;
    if (stat(filepath, &st) == 0) {
        return st.st_size;
    }
    return 0;
}

/**
 * Scan directory for BCPL files
 */
static void scan_directory(const char* directory) {
    printf("🔍 Scanning directory: %s\n", directory);
    
    strncpy(project.source_dir, directory, sizeof(project.source_dir) - 1);
    project.source_dir[sizeof(project.source_dir) - 1] = '\0';
    
#ifdef _WIN32
    WIN32_FIND_DATA find_data;
    char search_path[MAX_FILENAME];
    snprintf(search_path, sizeof(search_path), "%s\\*", directory);
    
    HANDLE hFind = FindFirstFile(search_path, &find_data);
    if (hFind == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error: Cannot open directory %s\n", directory);
        return;
    }
    
    do {
        if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            continue;  // Skip directories
        }
        
        const char* filename = find_data.cFileName;
#else
    DIR* dir = opendir(directory);
    if (!dir) {
        fprintf(stderr, "Error: Cannot open directory %s\n", directory);
        return;
    }
    
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            continue;  // Skip directories
        }
        
        const char* filename = entry->d_name;
#endif
        
        // Check if it's a BCPL source file or header
        bool is_bcpl_file = false;
        if (strstr(filename, ".bcpl") || 
            (strchr(filename, '.') == NULL && 
             (filename[0] == 'B' && (strlen(filename) > 3)))) {
            is_bcpl_file = true;
        }
        
        if (is_bcpl_file && project.file_count < MAX_FILES) {
            bcpl_file_info_t* file_info = &project.files[project.file_count];
            
            strncpy(file_info->name, filename, sizeof(file_info->name) - 1);
            file_info->name[sizeof(file_info->name) - 1] = '\0';
            
            strncpy(file_info->type, get_file_type(filename), sizeof(file_info->type) - 1);
            file_info->type[sizeof(file_info->type) - 1] = '\0';
            
            // Build full file path
            char filepath[MAX_FILENAME];
            snprintf(filepath, sizeof(filepath), "%s%c%s", directory, PATH_SEPARATOR, filename);
            
            file_info->size = get_file_size(filepath);
            analyze_dependencies(file_info, filepath);
            file_info->analyzed = true;
            
            project.file_count++;
            
            printf("  📄 Found: %-20s Type: %-8s Size: %6zu bytes Lines: %4d Deps: %d\n",
                   filename, file_info->type, file_info->size, file_info->lines, file_info->dep_count);
        }
        
#ifdef _WIN32
    } while (FindNextFile(hFind, &find_data));
    FindClose(hFind);
#else
    }
    closedir(dir);
#endif
    
    printf("📊 Total files found: %d\n\n", project.file_count);
}

/**
 * Print project analysis
 */
static void print_analysis(void) {
    printf("🎯 Xerox Alto BCPL Compiler Analysis\n");
    printf("═══════════════════════════════════════════════════════════════\n\n");
    
    // Count by type
    int counts[10] = {0};
    const char* types[] = {"main", "cae", "lex", "sae", "trn", "ncg", "platform", "header", "utility", NULL};
    
    for (int i = 0; i < project.file_count; i++) {
        for (int j = 0; types[j]; j++) {
            if (strcmp(project.files[i].type, types[j]) == 0) {
                counts[j]++;
                break;
            }
        }
    }
    
    printf("📊 File Distribution by Component:\n");
    printf("─────────────────────────────────────\n");
    for (int i = 0; types[i]; i++) {
        if (counts[i] > 0) {
            printf("  %-12s: %2d files\n", types[i], counts[i]);
        }
    }
    printf("\n");
    
    // Show components and their purpose
    printf("🧩 Component Architecture:\n");
    printf("─────────────────────────────────────\n");
    printf("  MAIN     : Main program and I/O routines\n");
    printf("  CAE      : Compiler Analysis Engine (parser)\n");
    printf("  LEX      : Lexical Analyzer (tokenizer)\n");
    printf("  SAE      : Syntax Analysis Engine (semantic analysis)\n");
    printf("  TRN      : Translator (intermediate code generation)\n");
    printf("  NCG      : Nova Code Generator (target code generation)\n");
    printf("  PLATFORM : Platform-specific functions (Alto, DOS, RDOS)\n");
    printf("  HEADER   : Declaration files (constants, externals)\n");
    printf("\n");
    
    // Dependency analysis
    printf("🔗 Dependency Analysis:\n");
    printf("─────────────────────────────────────\n");
    for (int i = 0; i < project.file_count; i++) {
        if (project.files[i].dep_count > 0) {
            printf("  %-20s → ", project.files[i].name);
            for (int j = 0; j < project.files[i].dep_count; j++) {
                printf("%s", project.files[i].dependencies[j]);
                if (j < project.files[i].dep_count - 1) printf(", ");
            }
            printf("\n");
        }
    }
    printf("\n");
    
    // Size analysis
    printf("📏 Size Analysis:\n");
    printf("─────────────────────────────────────\n");
    size_t total_size = 0;
    int total_lines = 0;
    
    for (int i = 0; i < project.file_count; i++) {
        total_size += project.files[i].size;
        total_lines += project.files[i].lines;
    }
    
    printf("  Total size     : %zu bytes (%.1f KB)\n", total_size, total_size / 1024.0);
    printf("  Total lines    : %d\n", total_lines);
    printf("  Average size   : %.1f bytes per file\n", (double)total_size / project.file_count);
    printf("  Average lines  : %.1f lines per file\n", (double)total_lines / project.file_count);
    printf("\n");
    
    // Detailed file listing
    printf("📋 Detailed File Information:\n");
    printf("─────────────────────────────────────\n");
    printf("%-20s %-8s %8s %6s %4s %s\n", "File", "Type", "Size", "Lines", "Deps", "Description");
    printf("%-20s %-8s %8s %6s %4s %s\n", "────", "────", "────", "─────", "────", "───────────");
    
    for (int i = 0; i < project.file_count; i++) {
        printf("%-20s %-8s %8zu %6d %4d %s\n",
               project.files[i].name,
               project.files[i].type,
               project.files[i].size,
               project.files[i].lines,
               project.files[i].dep_count,
               project.files[i].description[0] ? project.files[i].description : "");
    }
    
    printf("\n🎉 Analysis complete! Ready for modernization and compilation.\n");
}

/**
 * Generate build recommendations
 */
static void generate_build_recommendations(void) {
    printf("\n🔧 Build Recommendations:\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    
    printf("1. 📦 Required Headers:\n");
    printf("   - LIBHDR (modern BCPL standard library)\n");
    printf("   - BCPLX (main compiler declarations)\n");
    printf("   - Component-specific headers (BCAEX, BLEXX, etc.)\n\n");
    
    printf("2. 🏗️  Build Order:\n");
    printf("   a) Headers and declarations\n");
    printf("   b) Platform-specific modules\n");
    printf("   c) Lexical analyzer (LEX)\n");
    printf("   d) Parser (CAE)\n");
    printf("   e) Semantic analyzer (SAE)\n");
    printf("   f) Translator (TRN)\n");
    printf("   g) Code generator (NCG)\n");
    printf("   h) Main program\n\n");
    
    printf("3. 🎯 Modernization Priorities:\n");
    printf("   - Replace Alto-specific I/O with portable equivalents\n");
    printf("   - Update memory management for modern systems\n");
    printf("   - Adapt 16-bit word assumptions to 32/64-bit\n");
    printf("   - Add proper error handling and diagnostics\n\n");
    
    printf("4. 🔨 Compilation Strategy:\n");
    printf("   - Use existing BCPL compiler for bootstrapping\n");
    printf("   - Create C runtime stubs for Alto functions\n");
    printf("   - Implement cross-compilation to x86_64\n");
    printf("   - Add debugging and profiling support\n\n");
}

/**
 * Main analyzer function
 */
int main(int argc, char* argv[]) {
    printf("🚀 Xerox Alto BCPL Source Analyzer\n");
    printf("═══════════════════════════════════════════════════════════════\n\n");
    
    const char* source_dir = "modernized";
    bool validate_mode = false;
    
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--validate") == 0) {
            validate_mode = true;
        } else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            printf("Usage: %s [--validate] [--help]\n", argv[0]);
            printf("  --validate  : Run in validation mode for testing\n");
            printf("  --help      : Show this help message\n");
            return 0;
        } else {
            source_dir = argv[i];
        }
    }
    
    // Scan the source directory
    scan_directory(source_dir);
    
    if (project.file_count == 0) {
        fprintf(stderr, "❌ No BCPL files found in directory: %s\n", source_dir);
        return 1;
    }
    
    // Perform analysis
    print_analysis();
    generate_build_recommendations();
    
    if (validate_mode) {
        printf("\n✅ Validation mode: Analysis completed successfully\n");
        return 0;
    }
    
    printf("\n🎯 Next Steps:\n");
    printf("   1. Review the analysis above\n");
    printf("   2. Build with: cmake . && make\n");
    printf("   3. Test compilation: make xerox_bcpl_build\n");
    printf("   4. Generate docs: make xerox_bcpl_docs\n");
    
    return 0;
}
