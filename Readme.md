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
./main
```
