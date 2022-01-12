cmake_minimum_required(VERSION 3.13)

project(oop)
add_subdirectory(matplotplusplus)
include_directories(include) 

add_executable(program 
		src/main.cpp
		src/Knn.cpp
		src/Node.cpp
		src/Visualize.cpp
		include/Knn.h
		include/Node.h
		include/Visualize.h
		)
		
target_link_libraries(program PUBLIC matplot)

