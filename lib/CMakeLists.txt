project(myc)
cmake_minimum_required(VERSION 3.12.0)

# 输出路径(与可执行文件在同一文件夹中)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 查找当前目录下的所有源文件，并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(src/ DIR_LIB_SRCS)

# 生成链接库
add_library (${PROJECT_NAME} SHARED)
target_sources(${PROJECT_NAME} PRIVATE ${DIR_LIB_SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)

# 生成ALIAS（具有global scope）
add_library(DSA::myc ALIAS ${PROJECT_NAME})