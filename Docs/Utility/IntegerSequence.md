# SevenTools::IntegerSequence

###### *定义在 [IntegerSequence.h](./Header/IntegerSequence.md)*
```cpp
template <class T, T... i>
struct IntegerSequence;
```

## 模板参数

- `T` \- 用于序列元素的类型
- `...i` \- 表示序列的非类型形参包

## 成员类型

| 标识符 | 定义 |
| :-  | :-  |
| `ValueType` | `T` |

## 成员函数

| 标识符 | 介绍 |
| :-    | :-  |
| [`size`](./IntegerSequence/size.md) | 获取序列长度 |

## 辅助模板

`SevenToools::IndexSequence` 辅助类型别名模板提供 `std::size_t` 类型的序列
```cpp
template <std::size_t... i>
using IndexSequence = IntegerSequence<std::size_t, i...>
```
`SevenTools::MakeIntegerSequence` 和 `SevenTools::MakeIndexSequence` 辅助类型别名模板用于简化 `SevenTools::IntegerSequence` 和 `SevenTools::IndexSequence` 的创建
```cpp
template <class T, T N>
using MakeIntegerSequence = IntegerSequence<std::size_t, /* 0 到 N-1 的序列 */>;// 若 N 为 0 则为 IntegerSequence<std::size_t>，若 N 为负则非良构

template <std::size_t N>
using MakeIndexSequence = MakeIntegerSequence<std::size_t, N>;
```