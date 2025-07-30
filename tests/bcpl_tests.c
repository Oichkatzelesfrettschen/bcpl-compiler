#include <stdio.h>

int run_test_runtime(void);
int run_test_platform_abstraction(void);
int run_test_memory_safety(void);
int run_test_architecture(void);
int run_test_performance(void);
int run_test_assembly_elimination(void);

int main(void) {
    int result = 0;
    result |= run_test_runtime();
    result |= run_test_platform_abstraction();
    result |= run_test_memory_safety();
    result |= run_test_architecture();
    result |= run_test_performance();
    result |= run_test_assembly_elimination();
    if (result == 0) {
        printf("\nAll BCPL tests passed.\n");
    } else {
        printf("\nSome BCPL tests failed.\n");
    }
    return result;
}
