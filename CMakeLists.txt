cmake_minimum_required(VERSION 3.8)

project(XRF)

include(CMake/Config.cmake)
include(CMake/Compiler.cmake)
include(CMake/Scripts/Deploy.cmake)

set(XRF_SRC
	"Source/Main.cpp"
	"Source/Prerequisites.h"
	"Source/XRF.h"
	"Source/XRF.cpp"
	"Source/Flash/XBFS.h"
	"Source/Flash/XBFS.cpp"
)
 
add_executable(XRF ${XRF_SRC})
target_include_directories(XRF PUBLIC "Source")
target_link_libraries(XRF onecore.lib ucrt.lib libvcruntime.lib libcmt.lib)

deploy(XRF $<TARGET_FILE:XRF> "//XBOXONE/DevelopmentFiles/")