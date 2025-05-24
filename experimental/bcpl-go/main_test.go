package main

import (
	"os"
	"path/filepath"
	"testing"
)

func TestRuntimeDirPrefix(t *testing.T) {
	tmp := t.TempDir()
	os.Setenv("PREFIX", tmp)
	defer os.Unsetenv("PREFIX")
	got := runtimeDir()
	want := filepath.Join(tmp, "lib", "bcplc")
	if got != want {
		t.Fatalf("runtimeDir()=%q want %q", got, want)
	}
}
