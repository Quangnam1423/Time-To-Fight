# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(TimeToFight VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(dependencies/SFML/include)

# Add library directories
link_directories(dependencies/SFML/lib)

# Find all source files in the src directory
file(GLOB_RECURSE SOURCES src/*.cpp)

# Add the executable target
add_executable(TimeToFight ${SOURCES})

# Link with SFML libraries
target_link_libraries(TimeToFight 
    sfml-graphics
    sfml-window
    sfml-audio
    sfml-system
)
