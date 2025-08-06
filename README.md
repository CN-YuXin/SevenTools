![logo](logo.png)

这是一个 C++ 工具库，有各种杂七杂八的小玩意，要想使用请看参考文档(安装在 Docs)

对于编译，需要使用 CMake，此库能忍受的最低 C++ 版本是 11，过低的版本会减少库的功能

选项:
1. `BUILD_SHARED`: 是否构建动态库(默认否)
2. `INSTALL_DOC`: 是否安装文档(默认是)

例如:
```
cd <SRC>
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```
---
#### 没啥用的部分，可以说是花絮(?)

..........事实上，因为全是模板没法分文件，所以这个 `BUILD_SHARED` 暂时还没啥用(原本是有的，但是发现那个东西太没用就删了，后来就这样了)
