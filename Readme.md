#### <center> Protobuf
`protobuf`也叫`protocol buffer`是google 的一种数据交换的格式，它独立于语言，独立于平台。google 提供了多种语言的实现：java、c#、c++、go 和 python 等，每一种实现都包含了相应语言的编译器以及库文件。由于它是一种二进制的格式，比使用 xml 、json进行数据交换快许多。可以把它用于分布式应用之间的数据通信或者异构环境下的数据交换。作为一种效率和兼容性都很优秀的二进制数据传输格式，可以用于诸如`网络传输、配置文件、数据存储`等诸多领域。
- 网络传输速度快；
- 配置文件扩展性强；

1. 新建并进入到`build`目录下
```
mkdir build; cd build
```
2. 在`build`目录下，进行编译
```linux
cmake ..; make 
```
3. 运行可执行文件
```linux
./protobuf
```
-- -- 
如何在ROS2 C++中使用
1. 编译生成对应的C++文件
```linux
protoc --cpp_out=. message.proto # .表示当前路径，在当前路径下编译message.proto文件生成message.pb.h 和 message.pb.cc文件
```
2. 更改对应功能包的CMakeList文件，以下加入到对应位置中
```
# 查找 Protocol Buffers 库
find_package(Protobuf REQUIRED)

# 包含生成的头文件  proto生成的文件在proto路径下
include_directories(
  proto
)

# 查找添加proto文件夹中生成的所有文件
File(GLOB MAIN_PROTO ${CMAKE_CURRENT_SOURCE_DIR}/proto/*)

# 生成可执行文件
add_executable(${PROJECT_NAME}
  src/main.cpp
  ${MAIN_PROTO})

# 链接到protobuf的动态库
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${PROTOBUF_LIBRARIES})
```