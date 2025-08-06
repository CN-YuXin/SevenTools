# SevenTools::OperationStream::addOperation

```cpp
template <class F>
void addOperation(F&& op);
```

添加操作到序列末尾，如果 `F` 删除引用和 CV 限定后与 `OperationStream<T>` 为同一类型或 `std::decay<F>` 类型的左值对于参数类型 `T&` 和返回值类型 `bool` 不可调用则非良构，并且 `F` 还需满足*可拷贝构造*、*可移动插入*、*可就位构造*要求，否则行为未定义

操作 `op` 应当返回一个 `bool` 值，此返回值的含义是是否进行进一步处理，即将数据继续给到下一个可能的操作进行后续处理(这意味着对于最后一个操作，返回 `true` 还是 `false` 是无关紧要的)，并且操作应当有一个参数以修改数据

## 参数

- `op` \- 要添加的操作

## 注解

此函数是强异常安全的: 如果有任何异常抛出则此函数无效果(除非是由 `F` 的移动构造抛出的，或者内部出现 `std::bad_alloc`)

## 示例

```cpp
#include <OperationStream.h>
#include <cassert>

int main() {
    SevenTools::OperationStream<int> os;
    os.addOperation([](int& v) {
        ++v;
        return true;// 若返回 false 则最终结果为 28
    });
    os.addOperation([](int& v) {
        v *= 2;
        return true;
    });
    assert(os(27) == 56);// 永远通过
}
```