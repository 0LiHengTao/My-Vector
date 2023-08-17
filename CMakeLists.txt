cmake_minimum_required (VERSION 3.12)

project (CMake_MyVector)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#头文件指定目录
include_directories(${PROJECT_SOURCE_DIR}/include)
#源文件目录
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
#静态库路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(calc STATIC ${PROJECT_SOURCE_DIR}/src/CMake_MyVector.cpp)
#链接静态库
link_libraries(calc)
link_directories(${PROJECT_SOURCE_DIR}/lib)
# 将源代码添加到此项目的可执行文件。
add_executable (CMake_MyVector ${SRC})


