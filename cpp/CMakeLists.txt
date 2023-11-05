# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(ManonTracer)

# Définir la version C++ pour CMake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Utiliser MinGW comme compilateur
set(CMAKE_C_COMPILER "C:/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")

# Liste des fichiers source
set(SOURCES
    main.cpp
    src/mn_vector.cpp
    src/mn_point.cpp
    src/mn_objects.cpp
    src/mn_materials.cpp
    src/mn_color.cpp
    src/mn_ray.cpp
    src/mn_scene.cpp
    src/mn_light.cpp
    src/mn_engine.cpp
    src/mn_image.cpp
)
# file(GLOB SOURCES "src/*.cpp")


# Ajouter le chemin du sous-dossier "include" pour les fichiers d'en-tête
include_directories(include)

# Créer l'exécutable
add_executable(ManonTracer ${SOURCES})
