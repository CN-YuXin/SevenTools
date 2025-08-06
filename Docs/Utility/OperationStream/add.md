# SevenTools::OperationStream::add, SevenTools::OperationStream::sub, SevenTools::OperationStream::mul, SevenTools::OperationStream::div

```cpp
static auto add(const T& v);// 1 (C++14 起)
static auto sub(const T& v);// 2 (C++14 起)
static auto mul(const T& v);// 3 (C++14 起)
static auto div(const T& v);// 4 (C++14 起)
```

提供预定义的操作(加、减、乘、除)

1. 等价于:
    ```cpp
    [v](T& d) {
        d += v;
        return true;
    }
    ```
2. 等价于:
    ```cpp
    [v](T& d) {
        d -= v;
        return true;
    }
    ```
3. 等价于:
    ```cpp
    [v](T& d) {
        d *= v;
        return true;
    }
    ```
4. 等价于:
    ```cpp
    [v](T& d) {
        d /= v;
        return true;
    }
    ```

# 参数

- `v` \- 操作的右操作数

## 返回值

预定义的操作