# SystemNames.h

提供与使用的系统名相关的宏

## 宏

| 标识符 | 介绍 |
| :-    | :-   |
| `SystemName` | 使用的操作系统的名字，展开后是 `"Windows"`、`"Android"`、`"Linux"`、`"iOS"`、`"MacOS"`、`"Unix"`(类 Unix 系统也可能展开为这个值)、`"Unknown"` 之一(排在前面的优先级更高)，`"Unknown"`为未知系统 |
| `WindowsOS`<br>`AndroidOS`<br>`LinuxOS`<br>`iOS`<br>`MacOS`<br>`UnixOS` | 分别仅当 `SystemName` 宏展开后为 `"Windows"`、`"Android"`、`"Linux"`、`"iOS"`、`"MacOS"`、`"Unix"` 时会被定义，展开后为 `true` |

## 概要

```cpp
#define SystemName /* 系统名 */

#define WindowsOS true // 可能不被定义
#define AndroidOS true // 可能不被定义
#define LinuxOS true   // 可能不被定义
#define iOS true       // 可能不被定义
#define MacOS true     // 可能不被定义
#define UnixOS true    // 可能不被定义
```