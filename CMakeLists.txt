cmake_minimum_required(VERSION 3.5)
project(MyProject)

# 查找 Protocol Buffers 库
find_package(Protobuf REQUIRED)

# 添加生成 protobuf 文件的目录
set(PROTO_FILE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/message.proto)

# 指定生成的 .proto 文件的输出路径
set(PROTOBUF_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

# 生成对应的 C++ 代码
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTOBUF_OUTPUT_PATH} ${PROTO_FILE_PATH})

# 将生成的头文件添加到包含目录中
include_directories(${PROTOBUF_OUTPUT_PATH})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

# 添加可执行文件
add_executable(main main.cpp ${PROTO_SRCS} ${PROTO_HDRS})

# 链接 Protocol Buffers 库
target_link_libraries(main ${PROTOBUF_LIBRARIES})