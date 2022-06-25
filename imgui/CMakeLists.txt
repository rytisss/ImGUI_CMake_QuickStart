cmake_minimum_required(VERSION 3.17.0)

project(imgui)
set(CMAKE_BUILD_PARALLEL_LEVEL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)

include_directories(
	imgui/
	imgui/examples/
	third_party/glfw/include
	third_party/gl3w/
	third_party/glm-0.9.9.6/
	${Vulkan_INCLUDE_DIRS}
 )

add_library(imgui 
	imgui/imconfig.h
	imgui/imgui.cpp
	imgui/imgui.h
	imgui/imgui_tables.cpp
	imgui/imgui_demo.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_internal.h
	imgui/imgui_widgets.cpp
	imgui/imstb_rectpack.h
	imgui/imstb_textedit.h
	imgui/imstb_truetype.h
	imgui/backends/imgui_impl_vulkan.cpp
	imgui/backends/imgui_impl_vulkan.h
	imgui/backends/imgui_impl_glfw.cpp
	imgui/backends/imgui_impl_glfw.h

	#compile gl3w into executable
	third_party/gl3w/GL/gl3w.c
	third_party/gl3w/GL/gl3w.h
	third_party/gl3w/GL/glcorearb.h

	)

target_link_libraries(imgui PRIVATE
	glfw
	${Vulkan_LIBRARIES})


