cmake_minimum_required(VERSION 3.20.0)

project(VulkanImgui)
set(CMAKE_BUILD_PARALLEL_LEVEL)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
	../Backend/
 )

add_executable(${PROJECT_NAME} 
	main.cpp
	)

add_dependencies(${PROJECT_NAME}
	Backend)

target_link_libraries(${PROJECT_NAME} PRIVATE
	Backend)


#add_custom_command(TARGET VulkanImgui POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy_if_different 
#	${opencv_path}//x64//vc17//bin//$<$<CONFIG:debug>:opencv_core455d.dll>$<$<CONFIG:release>:opencv_core455.dll>
#	$<TARGET_FILE_DIR:VulkanImgui>)
