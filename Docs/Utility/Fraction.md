# SevenTools::Fraction

###### *定义在 [Fraction.h](Header/Fraction.md)*
```cpp
template <class T = int>
class Fraction;
```

旨提供运行时可用的分数类，此类会自动进行约分，因此总是为最简形式

## 模板参数

- `T` \- 不为 `bool` 的整数类型，否则非良构

## 成员类型

| 标识符 | 定义 |
| :-    | :-  |
| `ValueType` | `T` |

## 成员函数

| 标识符 | 介绍 |
| :-    | :-  |
| [`(构造函数)`](Fraction/Fraction.md) | 构造分数 |
| [`operator=`](Fraction/operator=.md) | 赋值分数 |
| [`getDenominator`](Fraction/getDenominator.md) | 获取分母 |
| [`setDenominator`](Fraction/setDenominator.md) | 设置分母 |
| [`getNumerator`](Fraction/getDenominator.md) | 获取分子 |
| [`setNumerator`](Fraction/setDenominator.md) | 设置分子 |
| [`getValue`](Fraction/getValue.md) | 获取值 |
| [`operator T`](Fraction/operator_T.md) | 获取值 |
| [`reciprocal`](Fraction/reciprocal.md) | 获取其倒数 |
| [`operator+`<br>`operator-`](Fraction/operator_arith.md) | 实现一元 + 和 - |
| [`operator+`<br>`operator-`<br>`operator*`<br>`operator/`](Fraction/operator_arith2.md) | 进行算术运算 |
| [`operator+=`<br>`operator-=`<br>`operator*=`<br>`operator/=`](Fraction/operator_arith3.md) | 进行复合赋值 |
| [`swap`](Fraction/swap.md) | 与另一个分数进行交换 |

## 非成员函数

| 标识符 | 介绍 |
| :-    |:-   |
| [`operator==`<br>`operator<`<br>`operator<=`<br>`operator>`<br>`operator>=`](Fraction/operator_cmp.md) | 比较两个分数 |
| [`swap`](Fraction/swap2.md) | 与另一个分数进行交换 |