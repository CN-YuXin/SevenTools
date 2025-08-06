# SevenTools::OperationStream

###### *定义在  [OperationStream.h](Header/OperationStream.md)*
```cpp
template <class T>
class OperationStream;
```

提供操作序列(就像流水线一般)，每个操作在序列中都有固定的先后顺序，数据经过一个操作处理后会继续传递给下一个操作进行处理

## 模板参数

- `T` \- 将要操作的数据类型，它必须不是引用类型

## 成员类型

| 标识符 | 定义 |
| :-    | :-  |
| `SizeType` | 无符号整数类型(通常是 `std::size_t`) |
| `DataType` | `T` |

## 成员函数

| 标识符 | 介绍 |
| :-    | :-  |
| [`(构造函数)`](OperationStream/OperationStream.md) | 构造操作序列 |
| [`operator=`](OperationStream/operator=.md) | 赋值操作序列 |
| [`maxSize`](OperationStream/maxSize.md) | 获取序列可能拥有的最大长度 |
| [`addOperation`](OperationStream/addOperation.md) | 添加操作 |
| [`clear`](OperationStream/clear.md) | 清空操作序列 |
| [`size`<br>`length`](OperationStream/length.md) | 返回序列长度 |
| [`empty`](OperationStream/empty.md) | 返回序列是否为空 |
| [`inputData`<br>`operator()`](OperationStream/inputData.md) | 将数据输入到序列中，返回处理后的数据 |
| [`swap`](OperationStream/swap.md) | 交换两个数据序列的所有操作 |
| [`add`<br>`sub`<br>`mul`<br>`div`](OperationStream/add.md) | 提供预制的加法、减法、乘法、除法操作 |

## 非成员函数

| 标识符 | 介绍 |
| :-    | :-  |
| [`operator\|`](OperationStream/operator\|.md) | 输入数据或拼接序列 |