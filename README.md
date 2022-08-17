# cppReadGeoDat

Reads the mesh file used in Alya, converted from Gmsh 2.2.

## Description

Basic code that reads the mesh file and returns the nodes and elements, grouped in a mesh object. This will later be implemented into libFEM, taking its class structure into account.

## Dependencies

Only a C++ compiler is required.

## Build

A CMake build system is under construction. From the build folder, simply run:

```bash
cmake ..
make
```

For now, each file has to be compiled separately, as shown below:

```bash
[CXX] -c Point.cpp
[CXX] -c Element.cpp
[CXX] -c Mesh.cpp
[CXX] -c main.cpp
[CXX] -o cppReadGeoDat *.o
```

## Usage

Simply run the executable with the mesh name as an argument:

```bash
cppReadGeoDat [MESH NAME]
```

The code will append the *.geo.dat termination by itself.
