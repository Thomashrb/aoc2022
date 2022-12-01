# advent of code 2022


## build

```
$ mkdir build && cd build
$ cmake ..
$ make
```

## tests

```
$ # mkdir build && cd build
$ # cmake ..
$ # cp ../input/* test/
$ ctest
```

## dependencies

- cmake
- make
- g++
- (CPM - Catch2)
- (Bear - needed to resolve lsp missing header files complaints wrt Catch2)

## debug

```
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug
$ make
```

