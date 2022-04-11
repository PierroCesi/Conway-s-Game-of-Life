cmake_minimum_required(VERSION 3.21)
project(jeudlavie)

set(CMAKE_CXX_STANDARD 14)

add_executable(jeudlavie main.cpp Controller/Map.cpp Controller/Map.h Model/MMap.cpp Model/MMap.h View/VMap.cpp View/VMap.h)


find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(jeudlavie sfml-system sfml-window sfml-graphics sfml-audio sfml-network)