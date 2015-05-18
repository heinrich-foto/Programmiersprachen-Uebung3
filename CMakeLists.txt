cmake_minimum_required (VERSION 2.8) 
project(Aufgabenblatt3) 

set(CMAKE_CXX_FLAGS "-std=c++0x")


add_executable(aufgabe1 aufgabe1.cpp)

add_executable(aufgabe2bis4 aufgabe2bis4.cpp)

add_executable(aufgabe5 
				aufgabe5.cpp
				catch.hpp
)

add_executable(aufgabe6 
				aufgabe6.cpp
)

add_executable(aufgabe8 
				aufgabe8.cpp
				catch.hpp
				circle.hpp
				circle.cpp
				point2D.hpp
				point2D.cpp
				color.hpp
)

#add_custom_command(
# 	OUTPUT test.txt
# 	COMMAND tests
# 	VERBATIM
# )

# add_custom_target(
#   run_test ALL
#   DEPENDS test.txt
# )