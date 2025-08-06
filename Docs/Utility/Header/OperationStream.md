# OperationStream.h

提供操作序列(就像流水线一般)

## 类

| 标识符 | 介绍 |
| :-    | :-  |
| [`OperationStream`](../OperationStream.md) | 提供操作流类 |

## 概要

```cpp
namespace SevenTools {
    template <class T>
    class OperationStream {
        using SizeType = /* 见介绍 */;
        using DataType = T;

        OperationStream() noexcept;
        OperationStream(const OperationStream& other);
        OperationStream(OperationStream&& other) noexcept;

        OperationStream& operator=(const OperationStream& v);
        OperationStream& operator=(OperationStream&& v);

        SizeType maxSize() const noexcept;

        template <class F>
        void addOperation(F&& op);

        void clear();

        SizeType size() const;
        SizeType length() const;
        bool empty() const;

        template <class... Args>
        T inputData(Args&&... args) const;
        template <class... Args>
        T operator()(Args&&... args) const;

        void swap(OperationStream& other);

        template <class F>
        friend OperationStream operator|(const OperationStream& os, F&& op);
        template <class F>
        friend OperationStream operator|(OperationStream&& os, F&& op);
        friend T operator|(const T& v, const OperationStream& os);
        friend OperationStream operator|(const OperationStream& lhs, const OperationStream& rhs);

        static auto add(const T& v);// (C++14 起)
        static auto sub(const T& v);// (C++14 起)
        static auto mul(const T& v);// (C++14 起)
        static auto div(const T& v);// (C++14 起)
    };
    template <class T>
    void swap(OperationStream<T>& lhs, OperationStream<T>& rhs);
}
```