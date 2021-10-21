# Pruebas Unitarias GTest

## Visual Studio + CMake + GTest

### Pre-requisitos

- IDE: Visual Studio 2019

- vcpkg

Paquetes de vcpkg 

- Fmt  

- range-v3 

- cxxopts 

- CMake 

- GTest 

- Pthreats 

Usar vcpkg library en Visual Studio: 
```
vcpkg integrate install 
```

### Construcción
La primer vez para compilar el proyecto es necesario definir el TOOLCHAIN FILE
```
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="{ruta de vcpkg}\vcpkg\scripts\buildsystems\vcpkg.cmake" 
```
