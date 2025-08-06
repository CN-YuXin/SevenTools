# SymbolVisibility.h

用于提供动态库符号可见性相关的宏，展开后为扩展属性或为空

## 宏

| 标识符 | 介绍 |
| :-    | :-  |
| `ExportSymbol` | 导出符号 |
| `HideSymbol` | 隐藏符号 |
| `ImportSymbol` | 导入符号，仅在 Windows 平台适用，其他平台下展开为空 |

## 概要

```cpp
#define ExportSymbol /* 见介绍 */
#define HideSymbol   /* 见介绍 */
#define ImportSymbol /* 见介绍 */
```