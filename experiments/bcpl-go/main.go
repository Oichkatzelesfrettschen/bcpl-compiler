package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"os/exec"
	"path/filepath"
)

func runtimeDir() string {
	if p := os.Getenv("PREFIX"); p != "" {
		return filepath.Join(p, "lib", "bcplc")
	}
	exe, err := os.Executable()
	if err == nil {
		d := filepath.Dir(exe)
		if _, err := os.Stat(filepath.Join(d, "st")); err == nil {
			return d
		}
		parent := filepath.Join(d, "..", "lib", "bcplc")
		if _, err := os.Stat(filepath.Join(parent, "st")); err == nil {
			return parent
		}
	}
	return filepath.Join("/usr/local", "lib", "bcplc")
}

func usage() {
	fmt.Fprintf(os.Stderr, "usage: bcplc [-COSc] [-o output] file ...\n")
	os.Exit(2)
}

func main() {
	var (
		optC bool
		optO bool
		optS bool
		optc bool
		out  string
	)
	flag.BoolVar(&optC, "C", false, "stop after bcpl->Ocode")
	flag.BoolVar(&optO, "O", false, "optimise")
	flag.BoolVar(&optS, "S", false, "stop after Ocode->asm")
	flag.BoolVar(&optc, "c", false, "stop after assemble")
	flag.StringVar(&out, "o", "", "output file")
	flag.Usage = usage
	flag.Parse()

	cflag := 4
	if optC {
		cflag = 1
	} else if optS {
		cflag = 2
	} else if optc {
		cflag = 3
	}

	files := flag.Args()
	if len(files) == 0 {
		usage()
	}

	d := runtimeDir()
	stcmd := filepath.Join(d, "st")
	cg := filepath.Join(d, "cg")
	op := filepath.Join(d, "op")
	asCmd := os.Getenv("CROSS_PREFIX") + "as"
	ldCmd := os.Getenv("CROSS_PREFIX") + "ld"
	bits := os.Getenv("BITS")
	if bits == "" {
		bits = "64"
	}

	for _, arg := range files {
		ext := filepath.Ext(arg)
		var i int
		switch ext {
		case ".b":
			i = 1
		case ".O":
			i = 2
		case ".s":
			i = 3
		case ".o":
			i = 4
		default:
			log.Fatalf("%s: unknown file type", arg)
		}
		infile := arg
		base := arg[:len(arg)-len(ext)]
		if out == "" {
			out = base
		}
		if i > cflag {
			log.Fatalf("%s: can't process further", arg)
		}
		for i <= 3 && i <= cflag {
			var outfile string
			switch i {
			case 1:
				outfile = base + ".O"
				cmd := exec.Command(stcmd)
				in, err := os.Open(infile)
				if err != nil {
					log.Fatal(err)
				}
				defer in.Close()
				outF, err := os.Create(outfile)
				if err != nil {
					log.Fatal(err)
				}
				cmd.Stdin = in
				cmd.Stdout = outF
				if err := cmd.Run(); err != nil {
					log.Fatal(err)
				}
			case 2:
				outfile = base + ".s"
				if !optO {
					cmd := exec.Command(cg)
					in, err := os.Open(infile)
					if err != nil {
						log.Fatal(err)
					}
					defer in.Close()
					outF, err := os.Create(outfile)
					if err != nil {
						log.Fatal(err)
					}
					cmd.Stdin = in
					cmd.Stdout = outF
					if err := cmd.Run(); err != nil {
						log.Fatal(err)
					}
				} else {
					cmd1 := exec.Command(cg)
					cmd2 := exec.Command(op)
					in, err := os.Open(infile)
					if err != nil {
						log.Fatal(err)
					}
					defer in.Close()
					outF, err := os.Create(outfile)
					if err != nil {
						log.Fatal(err)
					}
					r, w := os.Pipe()
					cmd1.Stdin = in
					cmd1.Stdout = w
					cmd2.Stdin = r
					cmd2.Stdout = outF
					if err := cmd1.Start(); err != nil {
						log.Fatal(err)
					}
					if err := cmd2.Start(); err != nil {
						log.Fatal(err)
					}
					cmd1.Wait()
					w.Close()
					cmd2.Wait()
				}
			case 3:
				outfile = base + ".o"
				args := []string{"--" + bits, "--defsym", "BITS=" + bits, "-o", outfile, infile}
				cmd := exec.Command(asCmd, args...)
				cmd.Stdout = os.Stdout
				cmd.Stderr = os.Stderr
				if err := cmd.Run(); err != nil {
					log.Fatal(err)
				}
			}
			infile = outfile
			i++
		}
	}

	if cflag == 4 {
		em := "elf_x86_64"
		if bits != "64" {
			em = "elf_i386"
		}
		args := []string{"-m", em, "-o", out}
		args = append(args, filepath.Join(d, "su.o"))
		for _, arg := range files {
			base := arg[:len(arg)-len(filepath.Ext(arg))]
			args = append(args, base+".o")
		}
		args = append(args, filepath.Join(d, "blib.o"), filepath.Join(d, "global.o"), filepath.Join(d, "rt.o"), filepath.Join(d, "sys.o"))
		cmd := exec.Command(ldCmd, args...)
		cmd.Stdout = os.Stdout
		cmd.Stderr = os.Stderr
		if err := cmd.Run(); err != nil {
			log.Fatal(err)
		}
	}
}
