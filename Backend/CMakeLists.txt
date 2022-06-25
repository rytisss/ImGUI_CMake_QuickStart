cmake_minimum_required(VERSION 3.22.0)

project(Backend)
set(CMAKE_BUILD_PARALLEL_LEVEL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions( -DBACKEND_EXPORT )
find_package(Vulkan REQUIRED)

include_directories(
	${Vulkan_INCLUDE_DIRS}
	..//imgui//
	..//imgui//imgui//
	..//imgui//imgui//examples//
	..//imgui//imgui//backends//
	..//imgui//third_party/glfw/include
 )

add_library(Backend SHARED 
	GraphicalBackend.h
	GraphicalBackend.cpp
	GraphicalBackendImpl.h
	GraphicalBackendImpl.cpp
	ContextWindow.h
	ContextWindow.cpp
	)

target_link_libraries(Backend PRIVATE
	${Vulkan_LIBRARIES}
	imgui)

add_dependencies(Backend
	imgui
	)
