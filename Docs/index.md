# 首页

此库是一个小型的工具库，为 C++ 语言提供，工具种类比较杂，库名为 `Seven Tools`，在源码可以看到它的 logo

整个库分为了多个部分，以下是介绍及索引:
1. `Macros`: 提供与宏有关的头文件
	- [`CompilerNames.h`](Macros/Header/CompilerNames.md): 提供与使用的编译器相关宏
	- [`CppVersions.h`](Macros/Header/CppVersions.md): 提供与 C++ 版本相关的宏
	- [`SymbolVisibility.h`](Macros/Header/SymbolVisibility.md): 提供动态库符号可见性相关的宏
	- [`SystemNames.h`](Macros/Header/SystemNames.md): 提供与系统名相关的宏
2. `Threads`: 提供与线程有关的头文件
	- [`ThreadPool.h`](Threads/Header/ThreadPool.md): 提供一个固定线程数的线程池，可获取 `std::future` 以获得结果
3. `Utility`: 提供杂乱的一些工具
	- [`Fraction.h`](Utility/Header/Fraction.md): 提供一个分数类
	- [`IntegerSequence.h`](Utility/Header/IntegerSequence.md): 提供一个 C++14 前可用的 `std::integer_sequence`
	- [`OperatorStream.h`](Utility/Header/OperationStream.md): 提供操作流类，每个操作可以返回一个 bool 值以决定是否进行下一个操作
	- [`StringView.h`](Utility/Header/StringView.md): 提供 C++17 前可用的 `std::string_view`

每个部分在包含头文件时，可以选择性的加上它的前缀，例如 `#include <Macros/CppVersion.h>` 或 `#include <CppVersion>`，它们是等价的

所有库的内容都将放在名为 SevenTools 的命名空间内，所有以 SevenTools 开头的标识符除非另有说明否则总是为内部使用


除了 Macros 部分外，所有头文件都有用于防重复包含头文件的宏，其格式为:
```text
<文件名>ByYX
```
其中 `<文件名>` 是文件不包含扩展名的名字

注: 此库内部使用的互斥量可能抛出 `system_error` 异常，但并不会对此进行处理