# CMakeList.txt: proyecto de CMake para started_with_GTests, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

#reconocer libreria Gtest
find_package(GTest CONFIG REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#reconocer libreria pthreads
find_package(pthreads REQUIRED)


# Agregue un origen al ejecutable de este proyecto.
add_executable (started_with_GTests "started_with_GTests.cpp")

# TODO: Agregue pruebas y destinos de instalación si es necesario.
target_link_libraries(started_with_GTests PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main ${CMAKE_THREAD_LIBS_INIT})