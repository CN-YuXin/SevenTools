# CompilerNames.h

提供与使用的编译器相关的宏定义，支持的编译器有:
1. Clang
2. GCC
3. MSVC

## 宏

| 标识符 | 介绍 |
| :-    | :-  |
| `CompilerName` | 使用的编译器的名字，如果使用了受支持的编译器则它展开后为 clang、gcc、MSVC 之一，否则为 `Unknown` |
| `UsingClang`<br>`UsingGCC`<br>`UsingMSVC` | 如果使用的是其对应的编译器则展开为 `true` 否则为 `false`，分别对应编译器 Clang、GCC、MSVC |

## 概要

```cpp
#define CompilerName /* 使用的编译器名 */
#define UsingClang   /* 见介绍 */
#define UsingGCC     /* 见介绍 */
#define UsingMSVC    /* 见介绍 */
```