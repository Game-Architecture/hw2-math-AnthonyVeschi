cmake_minimum_required (VERSION 3.6)
project (ga2)

# GA engine:
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}")
file(GLOB_RECURSE GA_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
if (MSVC)
	set(CMAKE_CXX_FLAGS "$(CMAKE_CXX_FLAGS) /EHsc")
endif()
if (MINGW)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_POSIX_C_SOURCE")
endif()
add_executable(ga ${GA_SOURCE_FILES})
