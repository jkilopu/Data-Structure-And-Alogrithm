# 最低CMake版本要求
cmake_minimum_required(VERSION 3.12.0)

# 项目名称
project(Test)

# 设置C/C++标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加子目录，使子目录中的CMakelists.txt被执行
add_subdirectory(Algorithm)
add_subdirectory(AVL_Tree)
add_subdirectory(Expression_Tree)
add_subdirectory(Huffman_Tree)
add_subdirectory(List)
add_subdirectory(Stack)
add_subdirectory(Queue)
add_subdirectory(Graph)
