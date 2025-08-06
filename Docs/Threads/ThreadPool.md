# SevenTools::ThreadPool

###### *定义在 [`ThreadPool.h`](Header/ThreadPool.md)*
```cpp
template <std::size_t N>
class ThreadPool;
```

## 模板参数

- `N` \- 线程总个数

## 成员对象

| 定义 | 介绍 |
| :-  | :-  |
| `constexpr static std::size_t size` | `N` |

## 成员函数

| 标识符 | 介绍 |
| :-    | :-  |
| [(构造函数)](ThreadPool/ThreadPool.md) | 构造线程池 |
| [(析构函数)](ThreadPool/~ThreadPool.md) | 析构线程池并阻塞至所有任务执行完毕 |
| `operator=` | 拷贝赋值被显式弃置 |
| [`addTask`](ThreadPool/addTask.md) | 添加任务，可能被推迟执行 |