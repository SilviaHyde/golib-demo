Here we demonstrate how to compile a Go library under **Linux**, but to be used by C source with `gcc` on **Windows**.

# Under Linux

## Setup the build environment

Pull the official golang docker: (it's a **Debian buster**)
```
docker pull golang:1.14
```
In that container, install [**mingw w64 gcc**](https://packages.debian.org/source/buster/gcc-mingw-w64):
```
apt install gcc-mingw-w64
```

## Cross-compile with mingw

### Archived version, for static link:
This will produce two files: `libaw.a`, `libaw.h` .
```
GOOS=windows CC=x86_64-w64-mingw32-gcc CGO_ENABLED=1 go build -v -o libaw.a -buildmode=c-archive aw.go
```

### Shared version, for dynamic link:

This will produce two files: `aw.dll`, `aw.h` .
```
GOOS=windows CC=x86_64-w64-mingw32-gcc CGO_ENABLED=1 go build -v -o aw.dll -buildmode=c-shared aw.go
```

# Under Windows

The compiler used is (from `gcc --version`)
```
gcc (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
```

### Archived version, for static link:

This will produce a standalone portable `c.exe` .
```
gcc -pthread -o c.exe client.c -L. -law
```

### Shared version, for dynamic link:

This will produce a `c.exe`, which is portable along with `aw.dll` .
```
gcc -pthread -o c.exe client.c -L. -law
```
