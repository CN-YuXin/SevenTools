# SevenTools::BasicStringView

###### *定义在 [StringView.h](Header/StringView.md)*
```cpp
template <class C, class CTraits = std::char_traits<C>>
class BasicStringView;
```

旨提供在 C++17 前可用的 `std::basic_string_view`，此类是*可平凡拷贝*的

提供了对于 `char` 和 `wchar_t` 的类型别名:
###### *定义在 [StringView.h](Header/StringView.md)*
```cpp
using StringView  = BasicStringView<char>;
using WStringView = BasicStringView<wchar_t>;
```

## 模板参数

- `C` \- 满足*可平凡拷贝*的字符类型，它必须与 `typename CTraits::char_type` 为同一类型且不是数组类型，否则非良构
- `CTraits` \- 满足 *CharTraits* 要求的类型，用于提供对字符的操作，注: 它还需要满足与 `std::char_traits` 相同的 `constexpr` 性

## 成员类型

| 标识符 | 定义 |
| :-    | :-  |
| `ValueType` | `const C` |
| `TraitsType` | `CTraits` |
| `ConstIterator` | `const C*` |
| `Iterator` | `ConstIterator` |
| `SizeType` | `std::size_t` |
| `ConstReference` | `const C&` |
| `Reference` | `ConstReference` |
| `ConstPointer` | `const C*` |
| `Pointer` | `ConstPointer` |

## 成员对象

| 定义 | 介绍 |
| :-  | :-  |
| `constexpr static SizeType npos` | `-1` |

## 成员函数

| 标识符 | 介绍 |
| :-    | :-  |
| [(构造函数)](BasicStringView/BasicStringView.md) | 构造视图 |
| [`operator=`](BasicStringView/operator=.md) | 赋值视图 |
| [`size`<br>`length`](BasicStringView/length.md) | 返回视图大小 |
| [`maxSize`](BasicStringView/maxSize.md) | 返回视图可能拥有的最大大小 |
| [`empty`](BasicStringView/empty.md) | 返回视图是否为空 |
| [`begin`](BasicStringView/begin.md) | 返回视图的起始迭代器 |
| [`end`](BasicStringView/end.md) | 返回视图的尾后迭代器 |
| [`operator[]`](BasicStringView/operator[].md) | 访问指定位置的字符 |
| [`at`](BasicStringView/at.md) | 带边界检查的访问指定位置的字符 |
| [`front`<br>`operator*`](BasicStringView/front.md) | 访问第一个字符 |
| [`back`](BasicStringView/back.md) | 访问最后一个字符 |
| [`data`](BasicStringView/data.md) | 返回指向视图首字符的指针 |
| [`swap`](BasicStringView/swap.md) | 交换两个视图的内容 |
| [`subStr`](BasicStringView/subStr.md) | 返回子视图 |
| [`compare`](BasicStringView/compare.md) | 比较两个视图 |
| [`startsWith`](BasicStringView/startsWith.md) | 检查视图是否以指定内容开始 |
| [`endsWith`](BasicStringView/endsWith.md) | 检查视图是否以指定内容结束 |
| [`contains`](BasicStringView/contains.md) | 检查视图是否包含指定内容 |
| [`find`](BasicStringView/find.md) | 在视图中查找内容的第一次出现位置 |
| [`rfind`](BasicStringView/rfind.md) | 在视图中查找内容的最后一次出现位置 |
| [`findFirstOf`](BasicStringView/findFirstOf.md) | 查找多个字符首次出现的位置 |
| [`findLastOf`](BasicStringView/findLastOf.md) | 查找多个字符最后一次出现的位置 |
| [`findFirstNotOf`](BasicStringView/findFirstNotOf.md) | 查找字符首次缺失的位置 |
| [`findLastNotOf`](BasicStringView/findLastNotOf.md) | 查找字符最后缺失的位置 |

## 非成员函数

| 标识符 | 介绍 |
| :-    | :-  |
| [`operator==`<br>`operator!=`](BasicStringView/operator_cmp.md) | 比较两个视图 |

## 注解

应当确保 `SevenTools::BasicStringView` 预览的字符数组在生存期之内:
```cpp
// 这是正确的
SevenTools::StringView sv = "Hello World";
// 这是错误的，你可能需要 std::string 或者使用 new 表达式来创建字符数组
SevenTools::StringView hw() {
    char text = "Hello World";
    return text;
}
``` 

不推荐直接使用 `const C*` 与 `SevenTools::BasicStringView` 交互，因为其 `Iterator` 成员类型可能在后续版本改变