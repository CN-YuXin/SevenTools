# CppVersions.h

提供与 C++ 版本相关的宏定义

## 宏

| 标识符 | 介绍 |
| :-    | :-  |
| `HasCpp11`<br>`HasCpp14`<br>`HasCpp17`<br>`HasCpp20`<br>`HasCpp23` | 如果对应的 C++ 版本被支持则展开为 `true` 否则为 `false`，对应的 C++ 版本依次是 11、14、17、20、23 |

## 概要

```cpp
#define HasCpp11 /* 见介绍 */
#define HasCpp14 /* 见介绍 */
#define HasCpp17 /* 见介绍 */
#define HasCpp20 /* 见介绍 */
#define HasCpp23 /* 见介绍 */
```