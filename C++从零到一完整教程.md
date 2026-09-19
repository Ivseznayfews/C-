# C++ 从零到一 · 完整教程

> 面向 **完全没有编程基础** 的读者。
> 从"什么是编译器"讲到能独立写出几百行的程序。
> 每一段代码都可以直接复制运行，每一行都有解释。

> **📌 用 Visual Studio Community 的读者**：请配合 `Visual Studio 使用指南.md` 一起看。
> 本教程的代码在 MSVC（Visual Studio）和 GCC（MinGW）上都能跑，差异只在"怎么建工程、怎么运行、怎么调试"。
> 最需要先看的是 **[第 1 章 1.2 节](#12-使用-visual-studio-2022-community推荐)**（建项目流程）和 **[1.6 节](#16-visual-studio-专属注意事项重要)**（会踩的坑：C++17 标准、`/utf-8` 中文编码、`main` 只能有一个等）。

---

## 目录

- [第 0 章 · 开始之前：先搞懂几件事](#第-0-章--开始之前先搞懂几件事)
- [第 1 章 · 搭建环境：让你的电脑能写 C++](#第-1-章--搭建环境让你的电脑能写-c)
  - [1.2 使用 Visual Studio 2022 Community（推荐）](#12-使用-visual-studio-2022-community推荐)
  - [1.6 Visual Studio 专属注意事项（重要）](#16-visual-studio-专属注意事项重要)
- [第 2 章 · 第一个程序：Hello, World!](#第-2-章--第一个程序hello-world)
- [第 3 章 · 变量与数据类型](#第-3-章--变量与数据类型)
- [第 4 章 · 运算符与表达式](#第-4-章--运算符与表达式)
- [第 5 章 · 输入与输出](#第-5-章--输入与输出)
- [第 6 章 · 条件判断（if / switch）](#第-6-章--条件判断if--switch)
- [第 7 章 · 循环（for / while / do-while）](#第-7-章--循环for--while--do-while)
- [第 8 章 · 函数](#第-8-章--函数)
- [第 9 章 · 作用域与生命周期](#第-9-章--作用域与生命周期)
- [第 10 章 · 数组与 C 风格字符串](#第-10-章--数组与-c-风格字符串)
- [第 11 章 · `std::string` 字符串](#第-11-章--stdstring-字符串)
- [第 12 章 · `std::vector` 动态数组](#第-12-章--stdvector-动态数组)
- [第 13 章 · 引用与指针（C++ 的分水岭）](#第-13-章--引用与指针c-的分水岭)
- [第 14 章 · 结构体、枚举与联合体](#第-14-章--结构体枚举与联合体)
- [第 15 章 · 类与对象（OOP 上）](#第-15-章--类与对象oop-上)
- [第 16 章 · 构造函数、析构函数与运算符重载（OOP 中）](#第-16-章--构造函数析构函数与运算符重载oop-中)
- [第 17 章 · 继承、虚函数与多态（OOP 下）](#第-17-章--继承虚函数与多态oop-下)
- [第 18 章 · 模板与泛型编程](#第-18-章--模板与泛型编程)
- [第 19 章 · STL 容器](#第-19-章--stl-容器)
- [第 20 章 · STL 算法与 Lambda 表达式](#第-20-章--stl-算法与-lambda-表达式)
- [第 21 章 · 迭代器与范围 for](#第-21-章--迭代器与范围-for)
- [第 22 章 · 动态内存与智能指针](#第-22-章--动态内存与智能指针)
- [第 23 章 · 移动语义与右值引用](#第-23-章--移动语义与右值引用)
- [第 24 章 · 异常处理](#第-24-章--异常处理)
- [第 25 章 · 文件读写](#第-25-章--文件读写)
- [第 26 章 · 头文件与多文件项目](#第-26-章--头文件与多文件项目)
- [第 27 章 · 命名空间与 const 完全指南](#第-27-章--命名空间与-const-完全指南)
- [第 28 章 · 编译、链接与调试](#第-28-章--编译链接与调试)
- [第 29 章 · 实战项目一：命令行待办清单](#第-29-章--实战项目一命令行待办清单)
- [第 30 章 · 实战项目二：矩阵运算库](#第-30-章--实战项目二矩阵运算库)
- [附录 A · 常见错误与报错解读](#附录-a--常见错误与报错解读)
- [附录 B · 常用标准库速查表](#附录-b--常用标准库速查表)
- [附录 C · 术语中英对照表](#附录-c--术语中英对照表)
- [附录 D · 学习路线与练习建议](#附录-d--学习路线与练习建议)

---

# 第 0 章 · 开始之前：先搞懂几件事

## 0.1 什么是编程？

编程就是**用一门语言给电脑下指令**。

电脑本身很笨，它只会做加减乘除、比较大小、跳来跳去这几件事。但它极快，一秒能做几十亿次。所以我们要做的，是**把复杂任务拆成这几件小事，然后用电脑能懂的语言写下来**。

```
你想要的结果
     ↓  （你来拆解）
一步一步的小操作
     ↓  （写成代码）
C++ 源代码文件（.cpp）
     ↓  （编译器翻译）
机器能执行的程序（.exe）
```

## 0.2 什么是 C++？

C++ 是一门诞生于 1983 年的编程语言（作者 Bjarne Stroustrup），它是 C 语言的超集，加入了"面向对象"和大量现代特性。

**它为什么值得学？**

| 优点 | 说明 |
|---|---|
| 快 | 直接编译成机器码，性能接近硬件极限 |
| 可控 | 内存怎么用、数据怎么放，你说了算 |
| 通用 | 游戏引擎、操作系统、浏览器、数据库、AI 框架底层都是它 |
| 打基础 | 学完 C++ 再学 Java/Python/Go/Rust 都会很轻松 |

**它的代价：**

- 概念多，规则细，容易写出崩溃的程序（尤其是内存问题）
- 出错时的报错信息可能很长很难看懂
- 需要一点耐心

> **给零基础读者的心理准备**：前 10 章是"语法体力活"，会觉得平平无奇；第 13 章（指针）和第 15 章（类）是两道坎，很多人卡在这里。卡住时不要怀疑自己，**所有学 C++ 的人都卡过**，多看两遍、多敲几遍就通了。

## 0.3 C++ 的"版本"

C++ 不是一成不变的，它每隔三年左右发布一个新标准：

| 标准 | 俗称 | 年份 | 重要新特性 |
|---|---|---|---|
| C++98 | C++98 | 1998 | 第一版标准 |
| C++11 | **现代 C++ 起点** | 2011 | `auto`、lambda、智能指针、右值引用、范围 for |
| C++14 | — | 2014 | 小修补 |
| C++17 | — | 2017 | 结构化绑定、`std::optional`、`if constexpr` |
| C++20 | — | 2020 | 概念（concepts）、协程、模块、`std::format` |
| C++23 | — | 2023 | 继续完善 |

**本教程以 C++17 为基准**。原因：它够新（有现代特性），兼容性又够好（几乎所有编译器都完整支持）。

代码里凡是需要更新的标准，我都会标注 `// C++20`。

## 0.4 本教程怎么用？

1. **不要只读，必须敲。** 看懂的代码和能写出来的代码是两回事。
2. **每章末尾的练习要做。** 实在不会再看答案（答案在代码后）。
3. **报错是常态。** 遇到报错先看[附录 A](#附录-a--常见错误与报错解读)。
4. **按顺序学。** 后面章节会用到前面的知识，跳着看会处处碰壁。
5. **准备一个文件夹**专门放练习代码，比如 `C:\cpp-learning\`。

---

# 第 1 章 · 搭建环境：让你的电脑能写 C++

写 C++ 需要两样东西：

1. **编译器**（compiler）：把 `.cpp` 源代码翻译成 `.exe` 可执行文件
2. **编辑器**（editor）：写代码的地方

这两样可以合在一起（IDE），也可以分开。

## 1.1 方案对比（Windows 用户）

| 方案 | 编译器 | 优点 | 缺点 | 适合 |
|---|---|---|---|---|
| **Visual Studio 2022 Community** | MSVC (`cl.exe`) | 一键安装、调试器最强、零配置 | 体积大（几 GB）、只 Windows | **推荐，最省心** |
| VS Code + MinGW-w64 | GCC (`g++`) | 轻量、可迁移到 Linux/Mac | 要手动配 PATH | 想跨平台 |
| Dev-C++ | 老旧 GCC | 小、简单 | 2015 年停更、编译器太老 | 不推荐 |
| CLion | 可配 MSVC/MinGW | 智能提示最强 | 收费 | 有学生邮箱可免费用 |
| 在线编译器 | — | 零安装 | 不能做大项目、不能调试 | 只想试试语法 |

**本教程的代码在两种编译器上都能跑。** 区别只在"怎么编译运行"和少量语法细节上。

> **⚠️ 用 Visual Studio 的读者请先看 [1.2 节](#12-使用-visual-studio-2022-community推荐) 和 [1.6 节](#16-visual-studio-专属注意事项重要)，那里列出了会让你代码编不过的几个坑（尤其是 `M_PI` 和中文乱码）。**

## 1.2 使用 Visual Studio 2022 Community（推荐）

### 1.2.1 安装

1. 下载 <https://visualstudio.microsoft.com/zh-hans/vs/community/> 的 **Community 免费版**
2. 运行安装程序，在**工作负载**页面勾选：

   ```
   ☑ 使用 C++ 的桌面开发
   ```

3. 右侧"安装详细信息"里确认这两项被勾上（默认通常已勾选）：

   ```
   ☑ MSVC v143 - VS 2022 C++ x64/x86 生成工具
   ☑ Windows 11 SDK（或 Windows 10 SDK）
   ```

4. 点"安装"。**需要几 GB 空间，装 20-40 分钟**，期间可以去干别的。
5. 装完首次启动会让你选"开发设置"，选 **Visual C++** 就行，颜色主题随便。

### 1.2.2 创建第一个项目（关键步骤）

Visual Studio **不是**"打开一个 `.cpp` 文件就能编译"的，它要求你先建一个**项目（Project）**。

**每次开始一个新的练习，都走一遍这个流程：**

1. 启动 Visual Studio → 选 **创建新项目**（或菜单 `文件 → 新建 → 项目`）
2. 在搜索框输入 `空项目`，选择 **空项目 (Empty Project)** —— 注意是 **C++** 的那个，不要选成 C# 的

   > ⚠️ **不要选"控制台应用 (Console App)"**。那个会自带一堆模板代码和预编译头，对新手是干扰。**选"空项目"。**

3. 配置：
   - **项目名称**：用英文，**不要有空格和中文**，例如 `HelloWorld`、`Ch02_FirstProgram`
   - **位置**：建议专门建一个文件夹，例如 `D:\cpp-learning`
   - 其他保持默认，点**创建**

4. 创建完成后，你会看到"解决方案资源管理器"（右侧或左侧的竖条面板）。里面长这样：

   ```
   解决方案 'HelloWorld' (1 个项目)
   └── HelloWorld
       ├── 头文件
       ├── 源文件          ← 代码放这里
       └── 资源文件
   ```

5. **添加源文件**：右键 **源文件** → `添加` → `新建项`（快捷键 `Ctrl + Shift + A`）
   - 选 **C++ 文件(.cpp)**
   - 名称填 `main.cpp`（或 `hello.cpp`，英文名）
   - 点**添加**

6. 现在可以写代码了。在打开的 `main.cpp` 里输入：

   ```cpp
   #include <iostream>

   int main() {
       std::cout << "Hello, Visual Studio!" << std::endl;
       return 0;
   }
   ```

7. **运行**：按 `Ctrl + F5`（见下面的说明）

   ```
   Hello, Visual Studio!
   ```

   **如果看到的是一闪而过的黑窗口**，说明你按的是 `F5` —— 换成 `Ctrl + F5` 就行。

### 1.2.3 `F5` 和 `Ctrl + F5` 的区别（新手最容易踩的坑）

| 快捷键 | 名称 | 行为 |
|---|---|---|
| **`Ctrl + F5`** | 开始执行（不调试） | 程序跑完后**停住**，显示"按任意键继续…" | 
| `F5` | 开始调试 | 程序跑完后**立即关闭窗口**，你看不到输出 |

**⭐ 学习阶段一律用 `Ctrl + F5`。** 只有需要设断点调试时才用 `F5`。

**其他常用快捷键：**

| 快捷键 | 作用 |
|---|---|
| `Ctrl + F5` | 编译并运行（不调试） |
| `F5` | 编译并调试运行 |
| `Ctrl + Shift + B` | 只编译，不运行 |
| `F7` | 同上（只生成解决方案） |
| `Ctrl + K, Ctrl + D` | 格式化当前文档（自动缩进） |
| `Ctrl + K, Ctrl + C` | 注释选中行 |
| `Ctrl + K, Ctrl + U` | 取消注释 |
| `Ctrl + M, Ctrl + M` | 折叠/展开当前代码块 |
| `F9` | 在当前行设置/取消断点 |
| `F10` | 单步执行（不进入函数） |
| `F11` | 单步执行（进入函数） |
| `Shift + F5` | 停止调试 |
| `Ctrl + Alt + L` | 打开解决方案资源管理器 |

### 1.2.4 `main` 函数只能有一个（重要）

**一个项目里只能有一个 `main` 函数。** 如果你把第 2 章和第 3 章的代码都放进同一个项目，就会报链接错误：

```
error LNK2005: main 已经在 main.obj 中定义
fatal error LNK1169: 找到一个或多个多重定义的符号
```

**解决方案（选一个）：**

| 方法 | 做法 | 适合 |
|---|---|---|
| **方法 1（推荐）** | **一个练习一个项目**，每章新建项目 | 最清晰，不出错 |
| 方法 2 | 把旧代码用 `/* */` 注释掉，或改函数名 | 快速试验 |
| 方法 3 | 把旧文件从项目中"移除"（右键 → 移除，不是删除） | 保留文件 |

> **方法 1 的具体做法**：`文件 → 新建 → 项目`，一个解决方案里可以放多个项目。运行时右键想要的那个项目 → `设为启动项目`，再按 `Ctrl + F5`。

### 1.2.5 配置 C++ 标准为 C++17（重要）

Visual Studio 2022 默认可能是 C++14，用到 C++17 特性（如结构化绑定 `auto [a, b] = ...`）会报错。**第一次用的时候配置一次即可：**

1. 右键**项目名**（不是解决方案）→ `属性`（快捷键 `Alt + Enter`）
2. 左侧选 `配置属性` → `C/C++` → `语言`
3. 右侧 **C++ 语言标准** 改成 **ISO C++17 标准 (/std:c++17)**

   > 如果找不到"语言"这一项，说明你的源文件还没被识别为 C++，先添加一个 `.cpp` 文件再打开属性页。

4. 点**确定**

**同时建议设置编码**（解决中文乱码，见 1.6 节）：

1. 同一个属性页里，`C/C++` → `命令行`
2. 在 **其他选项** 里填入：`/utf-8`
3. 确定

**⭐ 这两个设置建议每次都做**（或者每章开始时做一次）。忘记设置 C++17 是新手最常见的"代码明明没错却编译失败"的原因。

## 1.3 使用 VS Code + MinGW-w64（备选方案）

如果你更喜欢轻量的编辑器，或者以后想转到 Linux/Mac，可以用这套。

### 1.3.1 安装编译器（MinGW-w64）

MinGW-w64 是 Windows 上的 GCC 编译器移植版，提供 `g++` 命令。

### 方法 A：用 MSYS2 安装（推荐，最省心）

1. 打开 <https://www.msys2.org/>，下载 `msys2-x86_64-xxxx.exe`
2. 双击安装，安装路径**不要有空格和中文**，建议直接用默认的 `C:\msys64`
3. 安装完成后会弹出 MSYS2 终端，输入下面这条命令并回车（更新包管理器）：

   ```bash
   pacman -Syu
   ```

   中途可能提示关闭终端，照做后重新打开 MSYS2 终端，再执行一次 `pacman -Syu`。

4. 安装 64 位 C++ 工具链：

   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```

   出现提示时全部按回车（默认选全部安装）。

5. **把编译器加入系统 PATH**（关键一步）：
   - 按 `Win + S`，搜索"环境变量"，打开**编辑系统环境变量**
   - 点**环境变量**按钮
   - 在"系统变量"里找到 `Path`，双击
   - 点**新建**，填入：`C:\msys64\mingw64\bin`
   - 一路**确定**保存

6. **验证**：关掉所有终端，重新按 `Win + R` 输入 `cmd` 打开新终端，输入：

   ```bash
   g++ --version
   ```

   如果看到类似这样的输出就成功了：

   ```
   g++ (Rev3, Built by MSYS2 project) 13.2.0
   Copyright (C) 2023 Free Software Foundation, Inc.
   ```

   > 如果提示 `'g++' 不是内部或外部命令`，说明 PATH 没配好，或者终端没重启。仔细检查第 5 步。

### 方法 B：用 WinLibs 免安装包

1. 打开 <https://winlibs.com/>
2. 下载 `UCRT runtime` + `GCC` 那一栏的 **Zip archive**（64 位）
3. 解压到一个固定位置，例如 `C:\mingw64`
4. 把 `C:\mingw64\bin` 加入系统 PATH（同方法 A 第 5 步）
5. 新开终端验证 `g++ --version`

> **说明**：这套方案用的是 `g++` 命令，本教程中所有 `g++ -std=c++17 ...` 形式的编译命令都适用于它。用 Visual Studio 的读者可以跳过 1.3 节，直接看 [1.6 节](#16-visual-studio-专属注意事项重要) 的选项对照表。

### 1.3.2 安装编辑器（VS Code）

1. 下载安装 <https://code.visualstudio.com/>
2. 打开 VS Code，点左侧的**扩展**图标（四个方块），搜索并安装：
   - **C/C++**（微软官方，提供语法高亮和智能提示）
   - **Code Runner**（可选，一键运行代码）
3. 中文界面：搜索扩展 **Chinese (Simplified)** 安装后重启

### 1.3.3 配置 VS Code 编译任务（可选但推荐）

在项目文件夹里新建 `.vscode\tasks.json`，内容如下。这样以后按 `Ctrl + Shift + B` 就能直接编译：

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "编译当前 C++ 文件",
            "type": "shell",
            "command": "g++",
            "args": [
                "-std=c++17",
                "-Wall",
                "-Wextra",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"]
        }
    ]
}
```

同时在 `.vscode\settings.json` 里加一句，关掉 VS Code 自己那套不太准的错误检查：

```json
{
    "C_Cpp.errorSquiggles": "disabled"
}
```

**为什么关掉？** VS Code 的 C/C++ 扩展有时会误报"找不到头文件"，实际编译却没问题。它的提示仅供参考，**以 `g++` 的输出为准**。

## 1.4 运行代码的三种方式

### 方式 1：命令行（最推荐，最能学到东西）

打开 VS Code 的终端（菜单"终端 → 新建终端"，或按 `` Ctrl + ` ``），输入：

```bash
g++ -std=c++17 -Wall -g hello.cpp -o hello
./hello.exe
```

**这条命令逐段解释：**

| 片段 | 含义 |
|---|---|
| `g++` | 调用 C++ 编译器 |
| `-std=c++17` | 使用 C++17 标准 |
| `-Wall` | 打开**所有**常见警告（Warning all） |
| `-Wextra` | 打开额外警告（可选，更严格） |
| `-g` | 生成调试信息，允许用调试器逐行执行 |
| `hello.cpp` | 要编译的源文件 |
| `-o hello` | 输出的可执行文件名叫 `hello`（Windows 上会生成 `hello.exe`） |
| `./hello.exe` | 运行它 |

> **关于 `./`**：在 Windows PowerShell 里 `./hello.exe` 表示"当前目录下的 hello.exe"。直接敲 `hello` 通常也能运行（如果当前目录在 PATH 里），但 `./` 更保险。

### 方式 2：VS Code 一键运行

装好 **Code Runner** 后，打开 `.cpp` 文件，按 `Ctrl + Alt + N`，它会在下方"输出"窗口显示结果。

> 注意：Code Runner 默认**不开启** `-std=c++17`，用到新特性会报错。可以在设置里搜索 `code-runner.executorMap`，把 `cpp` 那一项改成：
> `"cd $dir && g++ -std=c++17 -Wall $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"`

### 方式 3：Visual Studio 按 `Ctrl + F5`

最简单的方式，不需要看编译命令细节：

1. 确保代码在"源文件"里，且当前项目是**启动项目**（粗体显示）
2. 按 `Ctrl + F5`
3. 在下方"输出"窗口可以看到编译结果，然后弹出控制台窗口显示程序输出

**如果编译失败**，错误会出现在下方 **"错误列表"** 窗口，双击错误可以跳转到对应代码行。

**注意**：Visual Studio 把可执行文件放在 `项目目录\x64\Debug\` 下（Debug 配置）或 `x64\Release\` 下（Release 配置），**不在源码旁边**。所以教程里其他地方的 `./app.exe` 这类命令，在 VS 里对应的是去这些目录找 `.exe`，或者直接用 `Ctrl + F5`。

> **关于 Release / Debug 配置**：工具栏上方有个下拉框可以在 `Debug` 和 `Release` 之间切换。
> - **Debug**：不优化，带调试信息，`assert` 生效。**学习阶段用这个。**
> - **Release**：优化过，快，`assert` 被禁用（定义了 `NDEBUG`）。**发布时用这个。**
>
> 有些内存 bug 只在 Release 下暴露（因为优化会利用"未定义行为"）。如果你遇到"Debug 能跑 Release 崩溃"，看[附录 A.4](#a4-未定义行为ub--最危险的一类)。

## 1.5 第一个验证

新建文件 `test.cpp`，写入：

```cpp
#include <iostream>

int main() {
    std::cout << "环境配置成功！" << std::endl;
    return 0;
}
```

编译运行：

```bash
g++ -std=c++17 -Wall test.cpp -o test
./test.exe
```

输出：

```
环境配置成功！
```

**看到这行字，你的环境就搭好了。** 后面所有代码都可以这样编译运行。

---

## 1.6 Visual Studio 专属注意事项（重要）

这一节只有用 Visual Studio 的读者需要看。**建议先通读一遍，能帮你避开后面 90% 的"明明代码没错却编不过"的情况。**

### 1.6.1 ℹ️ 关于 `M_PI`（本教程已处理，供参考）

`M_PI`（圆周率）是 **GCC 的扩展**，标准 C++ 里没有它。**在 MSVC（Visual Studio）上直接写 `M_PI` 会报错：**

```
error C2065: "M_PI": 未声明的标识符
```

**本教程的代码已经全部改用自定义常量 `kPi`，两种编译器都能跑：**

```cpp
constexpr double kPi = 3.14159265358979323846;
double area = kPi * r * r;
```

**如果你从别处（网上、书里）抄来用了 `M_PI` 的代码，有三种解决办法：**

**方案 1（推荐）：自己定义常量**

```cpp
#include <cmath>

#ifndef M_PI
constexpr double M_PI = 3.14159265358979323846;
#endif

double area = M_PI * r * r;
```

**方案 2：在文件最顶部、所有 `#include` 之前加一个宏**

```cpp
#define _USE_MATH_DEFINES      // ⚠️ 必须在 #include <cmath> 之前
#include <cmath>

// 现在 M_PI 可用了（但在 MSVC 上需要定义 _USE_MATH_DEFINES）
double area = M_PI * r * r;
```

**方案 3：用 C++20 的 `std::numbers::pi`（需要项目标准设为 C++20）**

```cpp
#include <numbers>
double area = std::numbers::pi * r * r;
```

> **⭐ 结论：写字面量或 `constexpr` 常量最省事，不要依赖 `M_PI`。**

### 1.6.2 ⚠️ 中文乱码问题

MSVC 默认用**本地编码**（GBK）读取源文件。如果源文件是 UTF-8（VS Code 默认，Visual Studio 新版也常默认），中文字符串输出到控制台就会变成乱码：

```
鎴戝彨灏忔槑     ← 本来是"我叫小明"
```

**解决方案（二选一，推荐第一个）：**

**方案 1：给项目加 `/utf-8` 编译选项（推荐，一劳永逸）**

1. 右键项目 → `属性` → `C/C++` → `命令行`
2. 在"其他选项"里加上：`/utf-8`
3. 确定

或者在解决方案资源管理器的项目上右键，选择属性，C/C++，命令行，其他选项：`/utf-8`

> **注意**：如果源文件**带 BOM**，加 `/utf-8` 反而可能出问题。此时用 `/utf-8` 的同时，把文件另存为"UTF-8 无 BOM"。Visual Studio 的"另存为"对话框右下角有"编码"按钮，选"UTF-8 无签名"。

**方案 2：在代码里设置控制台输出编码**

```cpp
#include <iostream>
#include <windows.h>       // 仅 Windows

int main() {
    SetConsoleOutputCP(65001);      // 控制台输出用 UTF-8
    SetConsoleCP(65001);            // 控制台输入用 UTF-8

    std::cout << "我叫小明\n";
    return 0;
}
```

**方案 3：干脆不用中文字符串**

练习题里的输出全部改英文。最省事，但练习体验差一点。

> **⭐ 最简单可靠的组合：项目属性加 `/utf-8` + 源文件存为"UTF-8 无 BOM"。**

### 1.6.3 `.cpp` 文件必须"添加到项目"里

这是新手最常犯的错：**在项目文件夹里手动新建了一个 `.cpp`，但没通过 Visual Studio 添加进项目**，结果编译时它被完全忽略。

**症状**：改了代码但输出没变；或者报"找不到 `main`"。

**正确做法**：右键 **源文件** → `添加` → `新建项`（或 `现有项`）。

**验证**：在"解决方案资源管理器"里能看到这个文件，就对了。

### 1.6.4 多文件项目（第 26 章）

第 26 章讲头文件和多文件。在 Visual Studio 里，**不需要改任何配置**，只要：

1. `右键"头文件" → 添加 → 新建项 → 头文件(.h)` 创建 `math_utils.h`
2. `右键"源文件" → 添加 → 新建项 → C++ 文件(.cpp)` 创建 `math_utils.cpp`
3. 在 `math_utils.cpp` 和 `main.cpp` 里 `#include "math_utils.h"` —— **Visual Studio 自动把项目目录加入了搜索路径**，不用配置 `-I`

**第 26 章的 `#include "mylib/calculator.h"` 这种带子目录的写法**，在 VS 里需要把 `include` 目录加入搜索路径：

- 项目属性 → `C/C++` → `常规` → **附加包含目录** → 填 `$(ProjectDir)include`

但**新手建议先用平铺的文件结构**（所有 `.h` 和 `.cpp` 放一起，用 `#include "math_utils.h"`），等熟悉了再搞目录结构。

### 1.6.5 ⚠️ 预编译头（`pch.h`）问题

如果你不小心选了"控制台应用"而不是"空项目"，Visual Studio 会生成一个 `pch.h`（预编译头），并且默认要求**每个 `.cpp` 的第一行**都是：

```cpp
#include "pch.h"
```

**症状**：

```
error C1010: 在查找预编译头时遇到意外的文件结尾。是否忘记了向源中添加 "#include "pch.h""?
```

**解决方案：**

- **最好**：重新建一个"空项目"（就没有这个麻烦了）
- 或者在每个 `.cpp` 最顶部加 `#include "pch.h"`
- 或者在项目属性 → `C/C++` → `预编译头` → 把 **预编译头** 改成 **不使用预编译头**

### 1.6.6 编译器选项对照表（g++ ↔ MSVC）

教程后面（尤其第 28 章）会出现 `g++` 的命令行选项。**用 Visual Studio 的话你不需要敲这些命令**，但如果想知道对应的设置在哪里：

| g++ 选项 | MSVC 等价 | 在 Visual Studio 哪里设置 |
|---|---|---|
| `-std=c++17` | `/std:c++17` | 项目属性 → C/C++ → 语言 → C++ 语言标准 |
| `-Wall -Wextra` | `/W4` | 项目属性 → C/C++ → 常规 → 警告等级 |
| `-Werror` | `/WX` | 项目属性 → C/C++ → 常规 → 将警告视为错误 |
| `-O0` | `/Od` | 项目属性 → C/C++ → 优化 → 优化 = 禁用（Debug 默认） |
| `-O2` | `/O2` | 项目属性 → C/C++ → 优化 → 优化 = 最大优化（Release 默认） |
| `-g` | `/Zi` | 项目属性 → C/C++ → 常规 → 调试信息格式（Debug 默认） |
| `-I<dir>` | `/I<dir>` | 项目属性 → C/C++ → 常规 → 附加包含目录 |
| `-D<MACRO>` | `/D<MACRO>` | 项目属性 → C/C++ → 预处理器 → 预处理器定义 |
| `-DNDEBUG` | `/DNDEBUG` | Release 配置默认就有 |
| `-fsanitize=address` | `/fsanitize=address` | 项目属性 → C/C++ → 常规 → 启用地址擦除器 |
| `-pthread` | 不需要 | MSVC 的 `<thread>` 开箱即用 |
| `-lm` | 不需要 | MSVC 自动链接数学库 |

> **好消息**：用 Visual Studio 时，`-g`、`-O0`（Debug）和 `-O2`（Release）都由 Debug/Release 配置自动搞定，你基本不用管。

### 1.6.7 用 Visual Studio 调试（代替第 28 章的 gdb）

第 28 章讲的是 gdb 命令行调试。**Visual Studio 的图形调试器比 gdb 好用得多**，对照关系如下：

| gdb 命令 | Visual Studio 操作 |
|---|---|
| `break file.cpp:12` | 光标移到第 12 行，按 **`F9`**（行号左边出现红点） |
| `run` | **`F5`** |
| `continue` | **`F5`**（在断点处暂停后再按） |
| `next` | **`F10`** |
| `step` | **`F11`** |
| `finish` | **`Shift + F11`** |
| `print x` | 鼠标悬停在变量上；或"监视"窗口添加 `x` |
| `info locals` | **`调试 → 窗口 → 局部变量`** |
| `backtrace` | **`调试 → 窗口 → 调用堆栈`** |
| `quit` | **`Shift + F5`** |

**调试实操：**

1. 在第 28 章示例的 `int maxVal = v[0];` 那一行按 `F9` 设断点（左边出现红点）
2. 按 `F5` 开始调试，程序会停在断点处，当前行高亮为黄色
3. 把鼠标移到 `v` 上，会弹出小窗显示 `v` 的内容（`size`、`capacity`、元素）
4. 按 `F10` 逐行执行，同时观察下方 **"局部变量"** 窗口里 `maxVal`、`i` 的变化
5. 按 `Shift + F5` 停止

**⭐ 这是 Visual Studio 相比命令行的最大优势 —— 一定要用起来。**

**查看崩溃位置**：程序崩溃时，Visual Studio 会弹窗并自动停在出错的那一行。如果没停，看 **"调用堆栈"** 窗口 —— 双击其中的行可以跳过去。

### 1.6.8 用 AddressSanitizer（代替第 28.5 节）

第 28.5 节的 `-fsanitize=address,undefined` 在 MSVC 上只支持前半部分：

**开启方法：**

1. 项目属性 → `C/C++` → `常规`
2. **启用地址擦除器（Enable Address Sanitizer）** 改成 **是 (/fsanitize=address)**
3. 确定，然后按 `Ctrl + F5` 运行

**越界时输出（在"输出"窗口）：**

```
==12345==ERROR: AddressSanitizer: stack-buffer-overflow on address ...
READ of size 4 at ...
    #0 ... in main D:\cpp-learning\Ch10\main.cpp:6
```

**注意**：

- MSVC **没有** UndefinedBehaviorSanitizer（`-fsanitize=undefined` 那部分），所以整数溢出这类问题它抓不到
- Debug 配置下 Visual Studio 默认已经开启了 **`/RTC1`**（运行时检查），能抓到一部分未初始化变量和栈帧损坏问题
- 发布前记得把这个选项**关掉**（它会拖慢程序）

### 1.6.9 第 28.9 / 28.10 节（Makefile / CMake）要不要看？

| 情况 | 建议 |
|---|---|
| 你只用 Visual Studio 写代码 | **可以跳过**，VS 自带构建系统（`.sln` + `.vcxproj`） |
| 你想把代码分享给别人（尤其 Linux 用户） | **需要看**，CMake 是跨平台项目的标准 |
| 你想以后用 VS Code / 命令行 | **需要看** |

**用 Visual Studio 打开 CMake 项目**：VS 2017 起直接支持"打开文件夹"，能识别 `CMakeLists.txt` 并自动配置。所以第 28.10 节的 CMake 内容对 VS 用户也有价值。

### 1.6.10 其他容易踩的小坑

| 现象 | 原因 / 解决 |
|---|---|
| 提示 `scanf` 不安全，报 `C4996` | MSVC 特有。加 `#define _CRT_SECURE_NO_WARNINGS` 在文件最顶部，或改用 `std::cin` |
| `error C4996: 'strcpy': This function or variable may be unsafe` | 同上，或改用 `strcpy_s`，**但本教程建议直接用 `std::string`** |
| 编译特别慢 | 第一次编译正常；增量编译会快。`/MP` 可以开启多核编译 |
| 智能提示红线但能编译 | 关掉"错误列表"里的 IntelliSense 错误，只看"生成"错误（点错误列表左上角的筛选） |
| 找不到 `x64` 还是 `x86` | 默认 `x64` 就好，除非有特殊需求 |
| 想用命令行 `cl.exe` | 开始菜单搜 **"x64 Native Tools Command Prompt for VS 2022"**，在里面才能用 `cl` |
| 中文路径导致奇怪错误 | **项目路径不要有中文和空格**，用 `D:\cpp-learning\` 这种 |
| 项目名带空格 | 不要，用 `MyProject` 而不是 `My Project` |

### 1.6.11 本章自检清单

用 Visual Studio 的话，请确认以下几点：

- [ ] 安装了"使用 C++ 的桌面开发"工作负载
- [ ] 会新建**空项目**（不是控制台应用）
- [ ] 会通过"源文件 → 添加 → 新建项"创建 `.cpp`
- [ ] 知道用 `Ctrl + F5` 运行（不是 `F5`）
- [ ] 项目属性里 **C++ 语言标准 = ISO C++17**
- [ ] 项目属性命令行里加了 **`/utf-8`**
- [ ] 知道一个项目只能有一个 `main`
- [ ] 知道怎么用 `F9` + `F5` + `F10` 调试

**全部打勾，就可以放心进入第 2 章了。**

---

# 第 2 章 · 第一个程序：Hello, World!

## 2.1 完整代码

```cpp
// 第 2 章：第一个程序
// 以 // 开头的这一行是"注释"，编译器会忽略它，只写给人看

#include <iostream>   // 引入"输入输出流"库，让我们能用 std::cout

int main() {          // 程序从这里开始执行。main 是主函数，必须有且只有一个
    std::cout << "Hello, World!" << std::endl;   // 在屏幕上打印文字
    return 0;         // 返回 0 表示程序正常结束
}
```

**运行结果：**

```
Hello, World!
```

## 2.2 逐行拆解

### `// 注释`

- `//` 是**单行注释**，从 `//` 到行尾都被编译器忽略
- `/* ... */` 是**块注释**，可以跨多行：

```cpp
/*
   这是块注释
   可以写很多行
   编译器全部忽略
*/
```

> **为什么注释很重要？** 三个月后的你看自己写的代码，就像看陌生人写的。注释是给未来的自己留的字条。

### `#include <iostream>`

`include` 是"包含"的意思。`<iostream>` 是标准库的一个**头文件**，里面声明了输入输出相关的功能。

- 尖括号 `< >` 表示"去系统标准库目录找"
- 双引号 `" "` 表示"先去当前目录找，再找系统目录"（第 26 章会讲）

`iostream` = **i**nput **o**utput **stream**（输入输出流）。

### `int main() { ... }`

这是**主函数**。

- `int` 表示这个函数返回一个整数
- `main` 是函数名，**必须**叫 `main`
- `()` 里放参数，这里是空的
- `{ }` 里面是函数体，也就是要做的事

程序运行时，**操作系统会找到 `main` 并从它的第一行开始执行**。

### `std::cout << "Hello, World!" << std::endl;`

这是整个程序的核心，拆开看：

| 部分 | 含义 |
|---|---|
| `std` | **命名空间**（namespace），标准库的东西都在 `std` 里 |
| `::` | 作用域运算符，"`std` 里的" |
| `cout` | **c**haracter **out**put，字符输出，即"屏幕" |
| `<<` | 插入运算符，把右边的东西"塞进"左边的流 |
| `"Hello, World!"` | 字符串字面量，双引号包起来的文字 |
| `std::endl` | **end line**，换行并刷新缓冲区 |
| `;` | 分号，**每条语句必须以分号结尾** |

可以这样理解：

```
std::cout  <<  "Hello"  <<  " World"  <<  std::endl;
   ↑            ↑            ↑             ↑
 一个管子    塞进管子     再塞一段      塞一个换行
```

**可以连续塞多个东西**，比如：

```cpp
std::cout << "我的年龄是 " << 18 << " 岁" << std::endl;
```

输出：

```
我的年龄是 18 岁
```

### `return 0;`

把 0 返回给操作系统。**0 表示"成功"，非 0 表示"出错了"**。这是行业惯例。

## 2.3 分号的坑

**每个语句后必须有分号**，但注意：

```cpp
#include <iostream>   // 没有分号！这是预处理指令
int main() {          // 没有分号！函数定义后面直接跟 { }
    std::cout << "hi" << std::endl;   // 有分号
    return 0;         // 有分号
}                     // 没有分号！} 后面不加
```

漏分号是新手第一大错误，报错通常是 `expected ';' before ...`。

## 2.4 关于 `std::` 前缀：`using namespace std;`

每次都写 `std::` 很烦。可以在文件顶部加一行：

```cpp
#include <iostream>
using namespace std;   // 从此 std 里的东西不用写前缀

int main() {
    cout << "Hello" << endl;   // 不用写 std:: 了
    return 0;
}
```

**但本教程不建议这么做**，原因有三：

1. `std` 里有几千个名字，全部引入可能和你自己的变量/函数**重名冲突**（比如你自己写了个 `count`，就会和 `std::count` 打架）
2. 代码里看到 `cout` 不知道是标准库的还是自定义的，**可读性变差**
3. 大项目里是**明令禁止**的

**更好的折中做法**——只引入你确实需要的：

```cpp
#include <iostream>
using std::cout;
using std::endl;
using std::string;   // 需要时再单独引入

int main() {
    cout << "Hello" << endl;
    return 0;
}
```

> 你在网上会看到大量教程用 `using namespace std;`。看懂它就行，**自己写的时候尽量别用**。本教程之后为了代码简洁，代码里会用 `using std::cout;` 这类写法，并在示例中明确注明。

## 2.5 C++ 代码的书写规范

```cpp
// ❌ 不推荐：全挤在一起
#include <iostream>
int main(){int a=1;int b=2;std::cout<<a+b<<std::endl;return 0;}

// ✅ 推荐：清晰易读
#include <iostream>

int main() {
    int a = 1;
    int b = 2;
    std::cout << a + b << std::endl;
    return 0;
}
```

**基本规范：**

| 规则 | 说明 |
|---|---|
| 缩进 | 用 **4 个空格**或一个 Tab，保持一致 |
| 一行一条语句 | 不要用 `;` 把多条语句挤在一行 |
| 花括号位置 | 推荐 `{` 跟在行尾（K&R 风格），全文统一 |
| 命名 | 变量用小写+下划线 `student_age` 或驼峰 `studentAge`，全项目统一 |
| 空行 | 用空行分隔逻辑块，提高可读性 |
| 空格 | 运算符两边加空格：`a = b + c;` 而不是 `a=b+c;` |

代码是**写给人看的**，顺便能让机器执行。

## 2.6 练习

1. 打印你的名字和年龄，分两行输出。
2. 打印下面这个图形：

   ```
   *
   ***
   *****
   ```

3. 故意删掉一个分号，看看 `g++` 报什么错，理解报错信息的样子。

**参考答案：**

```cpp
#include <iostream>
using std::cout;
using std::endl;

int main() {
    // 练习 1
    cout << "我叫小明" << endl;
    cout << "今年 18 岁" << endl;

    // 练习 2
    cout << "*" << endl;
    cout << "***" << endl;
    cout << "*****" << endl;

    return 0;
}
```

---

# 第 3 章 · 变量与数据类型

## 3.1 什么是变量？

**变量就是一个带名字的盒子，里面装数据。**

```cpp
int age = 18;
```

读作："创建一个叫 `age` 的整数盒子，把 18 放进去。"

```
  age
 ┌──────┐
 │  18  │     ← 盒子（内存空间）
 └──────┘
    ↑
  名字（标识符）
```

之后你可以：

- **读取**它：`cout << age;`
- **修改**它：`age = 19;`
- **使用**它参与计算：`int next = age + 1;`

**变量三要素：**

1. **类型**（type）：`int` —— 决定盒子能装什么、占多大空间
2. **名字**（name）：`age` —— 你怎么称呼它
3. **值**（value）：`18` —— 里面装的内容

## 3.2 基本数据类型总览

| 类型 | 含义 | 典型大小 | 取值范围 | 示例 |
|---|---|---|---|---|
| `int` | 整数 | 4 字节 | -21亿 ~ 21亿 | `int n = 42;` |
| `short` | 短整数 | 2 字节 | -32768 ~ 32767 | `short s = 100;` |
| `long long` | 长整数 | 8 字节 | ±9.2×10^18 | `long long big = 9000000000LL;` |
| `float` | 单精度小数 | 4 字节 | ±3.4×10^38（约 7 位有效数字） | `float f = 3.14f;` |
| `double` | 双精度小数 | 8 字节 | ±1.7×10^308（约 15 位有效数字） | `double d = 3.14159;` |
| `char` | 单个字符 | 1 字节 | -128 ~ 127（ASCII 码） | `char c = 'A';` |
| `bool` | 真假 | 1 字节 | `true` / `false` | `bool ok = true;` |
| `void` | 无类型 | — | 不能定义变量 | 只用于函数返回值 |

> **"典型大小"**：C++ 标准不强制规定 `int` 一定是 4 字节，只保证 `sizeof(short) <= sizeof(int) <= sizeof(long)`。在 Windows/Linux 的 64 位上，上表是实际情况。

### 怎么验证大小？

```cpp
#include <iostream>

int main() {
    std::cout << "char:      " << sizeof(char) << " 字节\n";
    std::cout << "short:     " << sizeof(short) << " 字节\n";
    std::cout << "int:       " << sizeof(int) << " 字节\n";
    std::cout << "long long: " << sizeof(long long) << " 字节\n";
    std::cout << "float:     " << sizeof(float) << " 字节\n";
    std::cout << "double:    " << sizeof(double) << " 字节\n";
    std::cout << "bool:      " << sizeof(bool) << " 字节\n";
    return 0;
}
```

`sizeof` 是一个运算符，返回某个类型或变量占用的字节数。

> 注意上面我用了 `"\n"` 而不是 `std::endl`。`"\n"` 就是换行符，**更快**（不刷新缓冲区）。后面会详细讲区别。

**典型的 64 位 Windows 输出：**

```
char:      1 字节
short:     2 字节
int:       4 字节
long long: 8 字节
float:     4 字节
double:    8 字节
bool:      1 字节
```

## 3.3 整数类型详解

### 有符号与无符号

- **有符号**（signed）：能表示负数，默认就是有符号
- **无符号**（unsigned）：只能表示非负数，但正数范围翻倍

```cpp
int a = -100;              // 有符号，可以负数
unsigned int b = 100;      // 无符号，不能负数

unsigned int c = 4000000000u;   // 可以，因为无符号 int 上限约 42 亿
// int d = 4000000000;          // ❌ 超出 int 范围，行为未定义！
```

**⚠️ 无符号数的经典陷阱：**

```cpp
#include <iostream>

int main() {
    unsigned int x = 0;
    x = x - 1;                    // 0 减 1，不是 -1！
    std::cout << x << std::endl;  // 输出 4294967295（2^32 - 1）
    return 0;
}
```

因为无符号数"不能是负数"，减到 0 以下就会**回绕**到最大值。这不是 C++ 的 bug，是设计如此。

**另一个经典陷阱：**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3};
    // v.size() 返回无符号数
    // 下面这个循环永远不会结束（或者行为诡异）！
    // for (int i = 0; i < v.size() - 1; i++) { ... }

    // ✅ 正确写法：用有符号的 int 接收，或者用 ptrdiff_t
    int n = static_cast<int>(v.size());
    for (int i = 0; i < n - 1; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

**为什么？** 当 `v` 为空时 `v.size()` 是 0，`v.size() - 1` 在无符号算术下变成 4294967295，`i < 4294967295` 恒真。

**结论：日常写代码优先用有符号 `int`，只在明确需要位运算/超大正数时用 `unsigned`。**

### 整数字面量的写法

```cpp
int a = 42;          // 十进制
int b = 0b101010;    // 二进制（C++14）：等于 42
int c = 052;         // 八进制（以 0 开头）：等于 42
int d = 0x2A;        // 十六进制：等于 42

long long e = 1000000LL;    // LL 后缀表示 long long
unsigned f = 100u;          // u 后缀表示 unsigned

// 数字分隔符（C++14），方便读大数：
int g = 1'000'000;          // 等于 1000000
int h = 0xFF'FF'FF;         // 十六进制也能分组
```

> **⚠️ 八进制是个坑**：`int x = 010;` 不是 10，是 8！所以**不要给数字加前导 0**。

### 整数溢出

每个类型都有范围。超出范围叫**溢出**（overflow），后果是**未定义行为**（undefined behavior）——程序可能输出任何东西，甚至崩溃。

```cpp
#include <iostream>
#include <climits>   // 提供 INT_MAX 等常量

int main() {
    std::cout << "int 最大值: " << INT_MAX << std::endl;   // 2147483647

    int big = INT_MAX;
    big = big + 1;   // ❌ 溢出！未定义行为
    std::cout << big << std::endl;   // 通常输出 -2147483648，但不保证

    return 0;
}
```

**防范方法：**

1. 预估范围，选够大的类型（`long long` 很便宜）
2. 运算前检查：

```cpp
#include <iostream>
#include <climits>

bool willOverflow(int a, int b) {
    if (b > 0 && a > INT_MAX - b) return true;
    if (b < 0 && a < INT_MIN - b) return true;
    return false;
}

int main() {
    int a = 2000000000;
    int b = 2000000000;
    if (willOverflow(a, b)) {
        std::cout << "会溢出，改用 long long" << std::endl;
        long long r = static_cast<long long>(a) + b;
        std::cout << r << std::endl;
    }
    return 0;
}
```

## 3.4 浮点类型详解

```cpp
float  f = 3.14f;      // 注意 f 后缀，否则 3.14 是 double
double d = 3.14159265358979;
long double ld = 3.14159265358979323846L;
```

**float 和 double 怎么选？**

- 默认用 **`double`**。它是 C++ 中浮点的"自然类型"，字面量 `3.14` 默认就是 `double`。
- 只有在**明确为了省内存**（比如几百万个浮点的数组、GPU 计算）时才用 `float`。
- `float` 只有约 7 位有效数字，`1.0f / 3.0f` 的精度损失很明显。

### ⚠️ 浮点数最大的坑：不能精确比较

```cpp
#include <iostream>

int main() {
    double a = 0.1 + 0.2;
    double b = 0.3;

    if (a == b) {
        std::cout << "相等" << std::endl;
    } else {
        std::cout << "不相等！" << std::endl;
        std::cout.precision(17);
        std::cout << "a = " << a << std::endl;   // 0.30000000000000004
        std::cout << "b = " << b << std::endl;   // 0.29999999999999999
    }
    return 0;
}
```

**输出：**

```
不相等！
a = 0.30000000000000004
b = 0.29999999999999999
```

**为什么？** 因为计算机用二进制存小数，而 0.1、0.2、0.3 在二进制里都是**无限循环小数**，只能存近似值。

**正确做法：判断差值是否足够小**

```cpp
#include <iostream>
#include <cmath>     // std::fabs

bool nearlyEqual(double a, double b, double epsilon = 1e-9) {
    return std::fabs(a - b) < epsilon;
}

int main() {
    double a = 0.1 + 0.2;
    double b = 0.3;
    if (nearlyEqual(a, b)) {
        std::cout << "在这个精度下相等" << std::endl;
    }
    return 0;
}
```

> **`epsilon`（伊普西龙）怎么选？** 一般用 `1e-9`。如果数据本身很大（比如 1e12），要按比例放大；标准库提供 `std::numeric_limits<double>::epsilon()` 给出机器精度。

### 浮点数的特殊值

```cpp
#include <iostream>
#include <cmath>
#include <limits>

int main() {
    double inf = 1.0 / 0.0;   // 无穷大
    double nan = 0.0 / 0.0;   // 非数字 Not-a-Number

    std::cout << "inf  = " << inf << std::endl;     // inf
    std::cout << "nan  = " << nan << std::endl;     // nan
    std::cout << "1/0 > 1000 ? " << (inf > 1000) << std::endl;   // 1
    std::cout << "nan == nan ? " << (nan == nan) << std::endl;   // 0 ！NaN 不等于自己

    // 正确检查 NaN
    if (std::isnan(nan)) {
        std::cout << "nan 确实是 NaN" << std::endl;
    }
    // 检查无穷
    if (std::isinf(inf)) {
        std::cout << "inf 确实是无穷" << std::endl;
    }
    // 检查是否有限
    if (std::isfinite(3.14)) {
        std::cout << "3.14 是有限数" << std::endl;
    }
    return 0;
}
```

> `1.0 / 0.0` 在浮点下得到 `inf`（不报错），但在**整数**下 `1 / 0` 是**未定义行为**（通常直接崩溃）。

### 浮点数的输出精度控制

```cpp
#include <iostream>
#include <iomanip>   // 提供 setprecision

int main() {
    double pi = 3.141592653589793;

    std::cout << pi << std::endl;                        // 3.14159（默认 6 位有效数字）

    std::cout << std::fixed << std::setprecision(2);
    std::cout << pi << std::endl;                        // 3.14

    std::cout << std::setprecision(5) << pi << std::endl; // 3.14159

    std::cout << std::scientific << pi << std::endl;      // 3.14159e+00

    // 用 printf 风格（也能用，需要 <cstdio>）
    std::printf("%.3f\n", pi);                            // 3.142
    return 0;
}
```

> **`std::fixed` 之后会一直生效**，除非再用 `std::defaultfloat` 改回来。

## 3.5 `char` 类型与 ASCII

`char` 存的是**一个字节的整数**，但被解释为字符。

```cpp
#include <iostream>

int main() {
    char c1 = 'A';        // 单引号！这是字符字面量
    // char c2 = "A";     // ❌ 双引号是字符串，类型是 const char*，不能赋给 char

    std::cout << c1 << std::endl;              // A（当字符输出）
    std::cout << (int)c1 << std::endl;         // 65（当整数输出，A 的 ASCII 码）

    char c3 = c1 + 1;                          // 65 + 1 = 66
    std::cout << c3 << std::endl;              // B

    // 常用 ASCII 码
    std::cout << "'0' = " << (int)'0' << std::endl;   // 48
    std::cout << "'a' = " << (int)'a' << std::endl;   // 97
    std::cout << "'z' = " << (int)'z' << std::endl;   // 122
    std::cout << "' ' = " << (int)' ' << std::endl;   // 32

    return 0;
}
```

**关键 ASCII 码表（记这几个就够）：**

| 字符 | 码 | 字符 | 码 |
|---|---|---|---|
| `'0'` ~ `'9'` | 48 ~ 57 | `'A'` ~ `'Z'` | 65 ~ 90 |
| `'a'` ~ `'z'` | 97 ~ 122 | `' '`（空格） | 32 |
| `'\n'`（换行） | 10 | `'\0'`（结束符） | 0 |

**这就是为什么大小写转换可以这样做：**

```cpp
char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';   // 小写转大写：减去小写基准，加上大写基准
    }
    return c;
}
```

### 转义字符

有些字符打不出来，用反斜杠 + 字母表示：

| 写法 | 含义 | ASCII |
|---|---|---|
| `'\n'` | 换行 | 10 |
| `'\t'` | 制表符（Tab） | 9 |
| `'\r'` | 回车 | 13 |
| `'\\'` | 反斜杠 `\` | 92 |
| `'\''` | 单引号 | 39 |
| `'\"'` | 双引号 | 34 |
| `'\0'` | 空字符（字符串结束标记） | 0 |
| `'\a'` | 响铃 | 7 |

```cpp
#include <iostream>

int main() {
    std::cout << "第一行\n第二行\n";
    std::cout << "姓名\t年龄\t城市\n";
    std::cout << "小明\t18\t北京\n";
    std::cout << "文件路径: C:\\Users\\test\n";   // 要写两个反斜杠
    std::cout << "他说：\"你好\"\n";
    return 0;
}
```

**输出：**

```
第一行
第二行
姓名	年龄	城市
小明	18	北京
文件路径: C:\Users\test
他说："你好"
```

## 3.6 `bool` 类型

只有两个值：`true`（真）和 `false`（假）。

```cpp
#include <iostream>

int main() {
    bool ok = true;
    bool no = false;

    std::cout << ok << std::endl;    // 1
    std::cout << no << std::endl;    // 0

    // 需要输出 true/false 文字时：
    std::cout << std::boolalpha << ok << std::endl;   // true
    std::cout << no << std::endl;                     // false

    // bool 和整数可以互相转换
    bool b1 = 5;      // 非 0 → true
    bool b2 = 0;      // 0 → false
    int i1 = true;    // → 1
    int i2 = false;   // → 0

    std::cout << std::noboolalpha << b1 << " " << b2 << " " << i1 << " " << i2 << "\n";
    // 输出：1 0 1 0

    return 0;
}
```

## 3.7 变量的声明、定义与初始化

### 三种初始化写法

```cpp
int a = 10;        // 拷贝初始化（传统 C 风格）
int b(10);         // 直接初始化
int c{10};         // 列表初始化（C++11 起，推荐！）
int d{};           // 列表初始化为 0
```

**为什么推荐 `{}`？** 因为它**不允许窄化转换**（会丢失数据的转换）：

```cpp
int x = 3.9;       // ⚠️ 编译通过但会丢数据，x = 3
int y(3.9);        // ⚠️ 同样丢数据，y = 3
// int z{3.9};     // ✅ 编译错误！编译器救了你一命
```

**所以，新代码统一用 `{}`。**

### 未初始化的变量是灾难

```cpp
#include <iostream>

int main() {
    int x;                       // ❌ 未初始化，里面是"垃圾值"
    std::cout << x << std::endl; // 输出什么完全随机！

    int y{};                     // ✅ 初始化为 0
    std::cout << y << std::endl; // 一定输出 0
    return 0;
}
```

**规则：定义变量时永远给它一个初始值。** 这是能省下你无数小时的铁律。

> 局部变量（函数内的变量）不初始化就是"未定义行为"。全局变量会被自动置 0，但别依赖这个。

### 一次定义多个变量

```cpp
int a = 1, b = 2, c = 3;   // ✅ 可以，但每个都要单独初始化

int x, y, z;               // ⚠️ 三个都是垃圾值
int p = 1, q;              // ⚠️ 只有 p 初始化了
```

**推荐一行一个变量**，清晰且不易出错。

## 3.8 `auto`：让编译器推断类型（C++11）

```cpp
auto a = 10;              // a 是 int
auto b = 3.14;            // b 是 double
auto c = 'x';             // c 是 char
auto d = true;            // d 是 bool
auto e = 10LL;            // e 是 long long
auto f = 3.14f;           // f 是 float
```

**什么时候用 `auto`？**

```cpp
// ✅ 类型名很长或很明显时
std::vector<std::string> names = getNames();
for (auto it = names.begin(); it != names.end(); ++it) { ... }   // 省得写一长串迭代器类型

// ✅ 类型很明显时
auto count = 0;                       // 一眼能看出是 int

// ❌ 不要滥用
auto x = compute();                   // 看代码完全不知道 x 是什么类型
```

**`auto` 的规则：**

- 必须有初始值：`auto x;` ❌ 编译错误
- `auto` 会**丢掉引用和 const**：

```cpp
const int ci = 10;
auto a = ci;          // a 是 int（const 丢了）
const auto b = ci;    // b 是 const int（显式加回）

int n = 5;
int& r = n;
auto c = r;           // c 是 int（拷贝了一份！不是引用）
auto& d = r;          // d 是 int&（引用要显式写 &）
```

## 3.9 类型转换

### 隐式转换（编译器自动做）

```cpp
int i = 3.9;              // double → int，截断小数，i = 3
double d = 5;             // int → double，d = 5.0
char c = 65;              // int → char，c = 'A'
bool b = 100;             // int → bool，b = true
```

**⚠️ 隐式转换是很多 bug 的来源**，尤其是 `double → int` 的截断（不是四舍五入！）。

你可能见过这个经典错误：

```cpp
int a = 5;
int b = 2;
double avg = a / b;       // ❌ 3，不是 2.5！
// 因为 a / b 先做整数除法得 2，再转成 double 得 2.0

double avg2 = a / 2.0;    // ✅ 2.5
double avg3 = static_cast<double>(a) / b;   // ✅ 2.5
```

### 显式转换（你主动要求）

**C++ 风格（推荐）：**

```cpp
double d = 3.9;
int i = static_cast<int>(d);      // ✅ 清晰表明"我知道在转换"

long long big = 1000000;
int small = static_cast<int>(big);  // 可能溢出，但你明确表示知道
```

**四种转换运算符：**

| 运算符 | 用途 |
|---|---|
| `static_cast<T>(x)` | 常规转换（数值之间、有继承关系的指针之间）。**最常用，优先用它** |
| `dynamic_cast<T>(x)` | 多态类型的安全向下转换（运行时检查），第 17 章讲 |
| `const_cast<T>(x)` | 去掉 `const`，**极度危险，尽量别用** |
| `reinterpret_cast<T>(x)` | 按位重新解释，最危险，用于底层位操作 |

**C 风格（不推荐）：**

```cpp
int i = (int)d;    // 能工作，但看不出是哪种转换，容易误用
```

**为什么用 `static_cast` 而不是 `(int)`？**

1. 一眼能看出这是转换，方便搜索
2. `(int)` 太强大，可能不小心做了危险的转换
3. 编译器能更好地帮你检查

## 3.10 常量：`const` 与 `constexpr`

### `const`：运行期常量，不能被修改

```cpp
#include <iostream>

int main() {
    const double PI = 3.14159;
    // PI = 3.14;              // ❌ 编译错误：不能给 const 赋值

    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];         // 可以用 const 定义数组大小（C++ 中）

    std::cout << PI << std::endl;
    return 0;
}
```

**好处：**

1. 防手滑改错
2. 名字比"魔数"（magic number）可读：`if (age > MAX_AGE)` 比 `if (age > 150)` 清楚
3. 便于统一修改

### `constexpr`：编译期常量（C++11）

```cpp
constexpr int SQUARE(int x) {
    return x * x;
}

constexpr int N = 10;
constexpr int AREA = SQUARE(N);   // 编译时就算好了

int arr[SQUARE(5)];               // 数组大小在编译期确定：25
```

**`const` 和 `constexpr` 的区别：**

| | `const` | `constexpr` |
|---|---|---|
| 何时确定值 | 编译期或运行期 | **必须**编译期 |
| 能否做数组大小 | 常量表达式可以 | 一定可以 |
| 能否修饰函数 | 成员函数可以 | 可以，表示编译期可求值 |

**实践建议：**

- 能用 `constexpr` 就用 `constexpr`（更强，编译期优化）
- 运行期才知道的值（如用户输入算出来的）用 `const`
- 函数参数尽量用 `const`（下一节讲）

### 常量命名规范

约定俗成用 `k` 开头或全大写：

```cpp
const int MAX_STUDENTS = 100;      // 全大写+下划线（C 风格，宏常用）
constexpr int kMaxStudents = 100;  // k 开头驼峰（Google 风格）
```

## 3.11 命名规范与关键字

### 命名规则（硬性）

- 只能包含：字母、数字、下划线
- **不能以数字开头**：`1var` ❌，`var1` ✅
- 不能是 C++ 关键字
- 区分大小写：`Age` 和 `age` 是两个不同的变量

### 常见 C++ 关键字（不能用作变量名）

```
int  double  float  char  bool  void  long  short  unsigned  signed
if  else  switch  case  default  for  while  do  break  continue  return
class  struct  enum  union  namespace  template  typename  using
public  private  protected  virtual  override  final  static
const  constexpr  mutable  volatile  static_cast  new  delete
try  catch  throw  this  nullptr  true  false  auto  inline  explicit
```

### 命名建议

| 对象 | 推荐风格 | 例子 |
|---|---|---|
| 变量 | 小写下划线 或 小驼峰 | `student_age` / `studentAge` |
| 函数 | 小驼峰 或 大驼峰 | `getAge()` / `GetAge()` |
| 类/结构体 | 大驼峰 | `StudentRecord` |
| 常量 | k 前缀 或 全大写 | `kMaxSize` / `MAX_SIZE` |
| 私有成员 | 末尾加下划线 | `age_` 或 `m_age` |

**关键：一个项目里保持一致。**

### 起名的艺术

```cpp
// ❌ 差
int a, b, c;
int data1, data2;
int flag;

// ✅ 好
int studentCount, teacherCount;
int maxScore, minScore;
bool isGameOver;
```

名字应该说明**它是什么**（名词）或**它是否满足某条件**（`is`/`has`/`can` 开头）。

## 3.12 练习

1. 定义变量存你的姓名（字符串先不用，用 char 数组跳过）、年龄、身高、是否学生，并打印出来。
2. 写一个程序，定义 `constexpr double PI = 3.14159;` 和 `double radius = 5.0;`，计算并输出圆的面积和周长。
3. 下面这段代码输出什么？先猜，再运行验证：

```cpp
#include <iostream>
int main() {
    int x = 7;
    int y = 2;
    std::cout << x / y << std::endl;
    std::cout << x % y << std::endl;
    std::cout << x / 2.0 << std::endl;
    std::cout << (double)(x / y) << std::endl;
    return 0;
}
```

**参考答案：**

```cpp
#include <iostream>

int main() {
    // 练习 1
    int age = 18;
    double height = 175.5;
    bool isStudent = true;

    std::cout << "年龄: " << age << " 岁\n";
    std::cout << "身高: " << height << " cm\n";
    std::cout << "是学生: " << std::boolalpha << isStudent << "\n\n";

    // 练习 2
    constexpr double PI = 3.14159;
    double radius = 5.0;
    double area = PI * radius * radius;
    double circumference = 2 * PI * radius;

    std::cout << "圆面积: " << area << "\n";
    std::cout << "圆周长: " << circumference << "\n\n";

    // 练习 3 验证
    int x = 7, y = 2;
    std::cout << x / y << "\n";            // 3   整数除法
    std::cout << x % y << "\n";            // 1   取余
    std::cout << x / 2.0 << "\n";          // 3.5 有浮点参与
    std::cout << (double)(x / y) << "\n";  // 3   先整除再转 double，为时已晚！

    return 0;
}
```

---

# 第 4 章 · 运算符与表达式

## 4.1 算术运算符

| 运算符 | 名称 | 例子 | 结果 |
|---|---|---|---|
| `+` | 加 | `7 + 3` | `10` |
| `-` | 减 | `7 - 3` | `4` |
| `*` | 乘 | `7 * 3` | `21` |
| `/` | 除 | `7 / 3` | `2`（整数除法！） |
| `%` | 取余（模） | `7 % 3` | `1` |

**整数除法的陷阱（重点）：**

```cpp
#include <iostream>

int main() {
    std::cout << 7 / 3 << std::endl;        // 2     不是 2.333
    std::cout << -7 / 3 << std::endl;       // -2    C++11 起向零取整
    std::cout << 7 % 3 << std::endl;        // 1
    std::cout << -7 % 3 << std::endl;       // -1    余数符号跟着被除数

    std::cout << 7.0 / 3 << std::endl;      // 2.33333
    std::cout << 7 / 3.0 << std::endl;      // 2.33333
    std::cout << 7 / 3 * 1.0 << std::endl;  // 2     ！为时已晚
    std::cout << 1.0 * 7 / 3 << std::endl;  // 2.33333  先转成浮点

    return 0;
}
```

**记住：只要有一个操作数是浮点，结果就是浮点。转换发生在运算之前。**

### 取余的实用技巧

```cpp
#include <iostream>

int main() {
    // 判断奇偶
    int n = 7;
    if (n % 2 == 0) std::cout << "偶数\n";
    else            std::cout << "奇数\n";

    // 判断能否被 3 整除
    if (n % 3 == 0) std::cout << "能被 3 整除\n";

    // 循环绕圈：0,1,2,3,0,1,2,3,...
    for (int i = 0; i < 8; i++) {
        std::cout << i % 4 << " ";
    }
    std::cout << "\n";

    // 取一个数的各位数字
    int num = 12345;
    while (num > 0) {
        std::cout << num % 10 << " ";   // 5 4 3 2 1
        num /= 10;
    }
    std::cout << "\n";

    return 0;
}
```

> ⚠️ `%` **不能用于浮点数**：`7.5 % 2` 编译错误。浮点取余要用 `std::fmod(7.5, 2.0)`。

## 4.2 赋值运算符

| 运算符 | 例子 | 等价于 |
|---|---|---|
| `=` | `a = 5` | 把 5 赋给 a |
| `+=` | `a += 3` | `a = a + 3` |
| `-=` | `a -= 3` | `a = a - 3` |
| `*=` | `a *= 3` | `a = a * 3` |
| `/=` | `a /= 3` | `a = a / 3` |
| `%=` | `a %= 3` | `a = a % 3` |
| `&=` | `a &= 3` | `a = a & 3`（位与） |
| `\|=` | `a \|= 3` | `a = a \| 3`（位或） |
| `^=` | `a ^= 3` | `a = a ^ 3`（位异或） |
| `<<=` | `a <<= 1` | `a = a << 1`（左移） |
| `>>=` | `a >>= 1` | `a = a >> 1`（右移） |

```cpp
#include <iostream>

int main() {
    int a = 10;
    a += 5;   std::cout << a << "\n";   // 15
    a -= 3;   std::cout << a << "\n";   // 12
    a *= 2;   std::cout << a << "\n";   // 24
    a /= 4;   std::cout << a << "\n";   // 6
    a %= 4;   std::cout << a << "\n";   // 2
    return 0;
}
```

**赋值表达式的值是赋完后的值**，所以可以链式赋值：

```cpp
int a, b, c;
a = b = c = 10;      // 从右往左：c=10, b=c, a=b
```

> ⚠️ 别把 `=` 和 `==` 搞混：

```cpp
int x = 5;
if (x = 3) { }      // ❌ 编译通过！把 3 赋给 x，然后判断 3（真），永远进这个分支
if (x == 3) { }     // ✅ 这才是比较
```

**防呆技巧**：把常量写在左边，写错会编译报错：

```cpp
if (3 == x) { }     // ✅ 写成 3 = x 会直接编译错误
```

## 4.3 自增自减

```cpp
int a = 5;
a++;      // 后置自增，a 变成 6
++a;      // 前置自增，a 变成 7
a--;      // 后置自减，a 变成 6
--a;      // 前置自减，a 变成 5
```

**单独使用时，`i++` 和 `++i` 没区别。但用在表达式里就不同了：**

```cpp
#include <iostream>

int main() {
    int i = 5;
    int a = i++;    // 先把 i 的旧值 5 给 a，再让 i 变 6
    std::cout << "a = " << a << ", i = " << i << "\n";   // a = 5, i = 6

    int j = 5;
    int b = ++j;    // 先让 j 变 6，再把 6 给 b
    std::cout << "b = " << b << ", j = " << j << "\n";   // b = 6, j = 6
    return 0;
}
```

**记忆法：**

- `i++` —— `++` 在后面，**先交货后加价**（先用旧值，再加）
- `++i` —— `++` 在前面，**先加价后交货**（先加，再用新值）

**⚠️ 未定义行为警告：**

```cpp
int i = 5;
int x = i++ + ++i;    // ❌ 未定义行为！
// 同一表达式里既读又写 i，编译器可以做任何事
```

**规则：不要在一个表达式里对同一个变量多次修改。**

**性能小贴士**：对自定义类型（比如迭代器），`++i` 比 `i++` 快（因为 `i++` 要先复制一份旧值）。养成用 `++i` 的习惯，对 `int` 无所谓。

## 4.4 比较运算符

| 运算符 | 含义 |
|---|---|
| `==` | 等于 |
| `!=` | 不等于 |
| `>` | 大于 |
| `<` | 小于 |
| `>=` | 大于等于 |
| `<=` | 小于等于 |

```cpp
#include <iostream>

int main() {
    int a = 5, b = 3;
    std::cout << std::boolalpha;
    std::cout << (a == b) << "\n";   // false
    std::cout << (a != b) << "\n";   // true
    std::cout << (a > b)  << "\n";   // true
    std::cout << (a <= b) << "\n";   // false

    // ⚠️ 比较的结果是 bool，可以当整数用
    std::cout << std::noboolalpha << (a > b) << "\n";   // 1

    // ⚠️ 浮点数不要用 == 直接比较（见第 3 章）
    // ⚠️ 也不要连写：a < b < c 是错的！
    int c = 10;
    // if (a < b < c)   // ❌ 等价于 (a < b) < c  →  0 < 10  →  true，永远为真
    if (a < b && b < c) { }   // ✅ 正确写法

    return 0;
}
```

## 4.5 逻辑运算符

| 运算符 | 名称 | 含义 | 例子 |
|---|---|---|---|
| `&&` | 逻辑与 | 两边都真才真 | `a > 0 && b > 0` |
| `\|\|` | 逻辑或 | 有一边真就真 | `a > 0 \|\| b > 0` |
| `!` | 逻辑非 | 取反 | `!flag` |

**真值表：**

| A | B | A && B | A \|\| B | !A |
|---|---|---|---|---|
| true | true | true | true | false |
| true | false | false | true | false |
| false | true | false | true | true |
| false | false | false | false | true |

### ⭐ 短路求值（非常重要）

- `A && B`：**如果 A 是 false，B 根本不会被执行**
- `A || B`：**如果 A 是 true，B 根本不会被执行**

这不是优化，是**语言规定**，可以用来写安全代码：

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    // ✅ 利用短路：先检查索引是否合法，再访问
    int index = 5;
    if (index >= 0 && index < static_cast<int>(v.size()) && v[index] > 0) {
        std::cout << "访问成功\n";
    } else {
        std::cout << "索引非法，安全跳过\n";   // 走这里，不会崩
    }

    // ❌ 反过来写就会崩（越界访问）
    // if (v[index] > 0 && index < (int)v.size()) { }

    // ✅ 指针检查也是经典用法
    int* p = nullptr;
    if (p != nullptr && *p > 0) {      // p 为空时，*p 不会被求值
        std::cout << *p << "\n";
    }

    return 0;
}
```

**这条规则能救你无数次。**

## 4.6 位运算符（进阶，先了解）

位运算直接操作二进制位，常用于底层开发、加密、性能优化、状态标志位。

| 运算符 | 名称 | 例子 | 结果 |
|---|---|---|---|
| `&` | 按位与 | `12 & 10` | `8` |
| `\|` | 按位或 | `12 \| 10` | `14` |
| `^` | 按位异或 | `12 ^ 10` | `6` |
| `~` | 按位取反 | `~12` | `-13` |
| `<<` | 左移 | `12 << 1` | `24` |
| `>>` | 右移 | `12 >> 1` | `6` |

**手动验算 `12 & 10`：**

```
12 = 1100 (二进制)
10 = 1010
&  = 1000 = 8
```

```cpp
#include <iostream>
#include <bitset>     // 用来看二进制表示

int main() {
    int a = 12, b = 10;
    std::cout << "12  = " << std::bitset<8>(a) << "\n";   // 00001100
    std::cout << "10  = " << std::bitset<8>(b) << "\n";   // 00001010
    std::cout << "&   = " << std::bitset<8>(a & b) << " = " << (a & b) << "\n";   // 00001000 = 8
    std::cout << "|   = " << std::bitset<8>(a | b) << " = " << (a | b) << "\n";   // 00001110 = 14
    std::cout << "^   = " << std::bitset<8>(a ^ b) << " = " << (a ^ b) << "\n";   // 00000110 = 6
    std::cout << "12<<1 = " << (12 << 1) << "\n";   // 24（相当于 ×2）
    std::cout << "12>>1 = " << (12 >> 1) << "\n";   // 6 （相当于 ÷2）
    return 0;
}
```

### 位运算的实用技巧

```cpp
#include <iostream>

int main() {
    // 1) 判断奇偶（比 % 快，但现代编译器会自动优化，主要是炫技）
    int n = 7;
    if (n & 1) std::cout << "奇数\n";

    // 2) 乘除 2 的幂
    std::cout << (5 << 3) << "\n";    // 5 * 8 = 40
    std::cout << (40 >> 3) << "\n";   // 40 / 8 = 5

    // 3) 交换两个数（不用临时变量）
    int x = 3, y = 5;
    x ^= y;
    y ^= x;
    x ^= y;
    std::cout << "x = " << x << ", y = " << y << "\n";   // x=5, y=3

    // 4) 用位标志表示多个开关（最实用的用法）
    constexpr unsigned READ    = 1u << 0;   // 0001
    constexpr unsigned WRITE   = 1u << 1;   // 0010
    constexpr unsigned EXECUTE = 1u << 2;   // 0100

    unsigned perms = 0;
    perms |= READ;                 // 加上读权限
    perms |= WRITE;                // 加上写权限

    if (perms & READ)    std::cout << "有读权限\n";
    if (perms & EXECUTE) std::cout << "有执行权限\n";   // 不输出

    perms &= ~WRITE;               // 去掉写权限
    if (!(perms & WRITE)) std::cout << "写权限已移除\n";

    return 0;
}
```

> **`~WRITE`** 是把 `0010` 按位取反得到 `...11111101`，再和 `perms` 做 `&`，就能把 WRITE 那一位清零。这个"清位"套路要记住。

## 4.7 三元运算符 `? :`

```cpp
条件 ? 值1 : 值2
```

条件为真取值1，否则取值2。**它是唯一需要三个操作数的运算符**。

```cpp
#include <iostream>

int main() {
    int a = 5, b = 3;

    // 传统写法
    int max1;
    if (a > b) max1 = a;
    else       max1 = b;

    // 三元写法
    int max2 = (a > b) ? a : b;

    std::cout << max1 << " " << max2 << "\n";   // 5 5

    // 常用于赋值和输出
    int score = 75;
    std::cout << "结果: " << (score >= 60 ? "及格" : "不及格") << "\n";
    std::cout << "评价: " << (score >= 90 ? "优秀" :
                              score >= 80 ? "良好" :
                              score >= 60 ? "及格" : "不及格") << "\n";

    // ⚠️ 注意：三元表达式的两个分支类型要兼容
    // auto x = cond ? 1 : 2.5;   // x 是 double（int 被提升）

    return 0;
}
```

**什么时候用？**

- ✅ 简单的二选一赋值：`int max = a > b ? a : b;`
- ❌ 复杂的嵌套（像上面"评价"那个，虽然能写但难读，用 if-else 更好）

## 4.8 优先级与结合性

**优先级**：谁先算。**结合性**：同优先级从左还是从右算。

**从高到低（常用部分）：**

| 优先级 | 运算符 | 结合性 |
|---|---|---|
| 1 | `::` | 左 |
| 2 | `()` `[]` `.` `->` `x++` `x--` | 左 |
| 3 | `!` `~` `++x` `--x` `+x` `-x` `(type)` `*p` `&x` `sizeof` | 右 |
| 4 | `.*` `->*` | 左 |
| 5 | `*` `/` `%` | 左 |
| 6 | `+` `-` | 左 |
| 7 | `<<` `>>` | 左 |
| 8 | `<` `<=` `>` `>=` | 左 |
| 9 | `==` `!=` | 左 |
| 10 | `&` | 左 |
| 11 | `^` | 左 |
| 12 | `\|` | 左 |
| 13 | `&&` | 左 |
| 14 | `\|\|` | 左 |
| 15 | `?:` `=` `+=` `-=` 等 | 右 |
| 16 | `,` | 左 |

**别背这张表，记住两条：**

1. **拿不准就加括号。** 括号不花钱，bug 很贵。
2. **注意这几个反直觉的：**

```cpp
// 陷阱 1：位运算优先级低于比较运算符！
// if (a & 1 == 0)      // ❌ 等价于 a & (1 == 0)  →  a & 0  →  0
if ((a & 1) == 0) { }   // ✅

// 陷阱 2：<< 优先级高于比较
// if (x << 1 > 10)     // ❌ 等价于 (x << 1) > 10 ... 其实这个是对的
//                       // 但 std::cout << x > 5 是灾难：等价于 (cout << x) > 5
std::cout << (x > 5) << "\n";   // ✅

// 陷阱 3：赋值优先级极低
// int y = a > b ? a : b;   // 其实没问题，?: 优先级高于 =
int y = (a > b) ? a : b;     // 但加括号更清楚

// 陷阱 4：负数取模
std::cout << -7 % 3 << "\n";     // -1，不是 2

// 陷阱 5：/ 和 % 的符号组合
std::cout << -7 / 2 << "\n";     // -3（C++11 起向零截断）
std::cout << -7 % 2 << "\n";     // -1
```

## 4.9 复合表达式与副作用

**副作用**：表达式除了产生值，还改变了什么（比如改变变量）。

```cpp
int a = 1;
int b = a++ + a++;   // ❌ 未定义行为：a 被修改两次
```

**规则：一个变量在一个表达式里最多修改一次，且修改后不要再读它。**

```cpp
// ✅ 拆开写，永远安全
int a = 1;
int t1 = a++;   // t1=1, a=2
int t2 = a++;   // t2=2, a=3
int b = t1 + t2;  // 3
```

## 4.10 练习

1. 输入一个三位数，输出它的百位、十位、个位数字。
2. 判断一个年份是否是闰年（能被 4 整除但不能被 100 整除，或能被 400 整除）。
3. 用三元运算符求三个数中的最大值。
4. 不使用临时变量交换两个整数（用加减法或异或）。
5. 下面代码输出什么？先猜再运行：

```cpp
#include <iostream>
int main() {
    int a = 5;
    std::cout << a++ << "\n";
    std::cout << ++a << "\n";
    std::cout << (a > 5 ? "big" : "small") << "\n";
    return 0;
}
```

**参考答案：**

```cpp
#include <iostream>

int main() {
    // 练习 1
    int num = 375;
    int hundreds = num / 100;
    int tens = num / 10 % 10;
    int ones = num % 10;
    std::cout << hundreds << " " << tens << " " << ones << "\n";   // 3 7 5

    // 练习 2
    int year = 2024;
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    std::cout << year << (isLeap ? " 是闰年" : " 不是闰年") << "\n";

    // 练习 3
    int x = 3, y = 9, z = 5;
    int maxVal = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
    std::cout << "最大值: " << maxVal << "\n";   // 9

    // 练习 4
    int p = 3, q = 8;
    p = p + q;    // p = 11
    q = p - q;    // q = 3
    p = p - q;    // p = 8
    std::cout << "p = " << p << ", q = " << q << "\n";   // p=8, q=3

    // 练习 5
    int a = 5;
    std::cout << a++ << "\n";   // 5   输出旧值，a 变 6
    std::cout << ++a << "\n";   // 7   先加，a 变 7，输出 7
    std::cout << (a > 5 ? "big" : "small") << "\n";   // big

    return 0;
}
```

---

# 第 5 章 · 输入与输出

到现在为止，我们的程序只会"说"，不会"听"。这一章让它能接收用户输入，就能写交互式程序了。

## 5.1 `std::cout` 输出

```cpp
#include <iostream>

int main() {
    int age = 18;
    double score = 95.5;
    char grade = 'A';
    bool pass = true;
    const char* name = "小明";

    // 连续输出
    std::cout << "姓名: " << name << "\n";
    std::cout << "年龄: " << age << "\n";
    std::cout << "分数: " << score << "\n";
    std::cout << "等级: " << grade << "\n";
    std::cout << "通过: " << std::boolalpha << pass << "\n";
    return 0;
}
```

**`<<` 可以连着用任意多次**，它会把每个东西依次送到屏幕。`<<` 会**自动处理类型**——不管你给 int、double 还是 char，它都知道怎么打印。

### `std::endl` vs `"\n"`

| | `std::endl` | `"\n"` |
|---|---|---|
| 作用 | 换行 + **刷新缓冲区** | 只换行 |
| 速度 | 慢（每次都要和屏幕同步） | 快 |
| 何时用 | 需要立即看到输出时（如调试、交互提示） | 大多数情况 |

**缓冲区**是什么？`cout` 不是每写一个字就立刻显示，而是先攒在内存里（缓冲区），攒够了一批再一起刷到屏幕。这样效率高。

```cpp
#include <iostream>

int main() {
    // 大量输出时，用 "\n" 快很多
    for (int i = 0; i < 100000; i++) {
        std::cout << i << "\n";       // ✅ 快
        // std::cout << i << std::endl;  // ❌ 慢几十倍
    }
    return 0;
}
```

**建议：日常用 `"\n"`，交互提示或调试时用 `std::endl`。**

### 格式化输出：`<iomanip>`

```cpp
#include <iostream>
#include <iomanip>   // 格式化输出

int main() {
    double pi = 3.14159265358979;

    // 精度
    std::cout << std::setprecision(4) << pi << "\n";          // 3.142（4 位有效数字）

    // 定点 + 精度（小数位数）
    std::cout << std::fixed << std::setprecision(2) << pi << "\n";   // 3.14

    // 科学计数法
    std::cout << std::scientific << std::setprecision(3) << pi << "\n";  // 3.142e+00

    // 恢复默认
    std::cout << std::defaultfloat << std::setprecision(6) << pi << "\n";  // 3.14159

    // 宽度与对齐
    std::cout << std::setw(10) << "姓名" << std::setw(10) << "分数" << "\n";
    std::cout << std::setw(10) << "小明" << std::setw(10) << 95 << "\n";
    std::cout << std::setw(10) << "小红" << std::setw(10) << 88 << "\n";

    // 左对齐
    std::cout << std::left;
    std::cout << std::setw(10) << "小明" << std::setw(10) << 95 << "\n";

    // 填充字符
    std::cout << std::right << std::setfill('*');
    std::cout << std::setw(10) << 42 << "\n";     // *******42

    // 进制
    std::cout << std::setfill(' ') << std::dec << 255 << "\n";   // 255
    std::cout << std::hex << 255 << "\n";                        // ff
    std::cout << std::oct << 255 << "\n";                        // 377
    std::cout << std::showbase << std::hex << 255 << "\n";       // 0xff

    return 0;
}
```

> ⚠️ `std::setw` **只对下一次输出生效**，其他操纵符（`fixed`、`hex`、`left`）会一直生效直到改回来。

### `printf` 风格（可选）

C 风格的 `printf` 也能用，很多老代码和竞赛代码还在用：

```cpp
#include <cstdio>    // 或 <stdio.h>

int main() {
    int a = 42;
    double d = 3.14159;
    const char* s = "你好";

    std::printf("整数: %d\n", a);
    std::printf("小数: %.2f\n", d);
    std::printf("字符串: %s\n", s);
    std::printf("字符: %c\n", 'X');
    std::printf("宽度: [%5d]\n", a);       // [   42]
    std::printf("左对齐: [%-5d]\n", a);    // [42   ]
    std::printf("补零: [%05d]\n", a);      // [00042]
    return 0;
}
```

**常用格式符：**

| 格式 | 类型 |
|---|---|
| `%d` / `%i` | int |
| `%u` | unsigned int |
| `%lld` | long long |
| `%f` / `%lf` | double |
| `%c` | char |
| `%s` | C 字符串 |
| `%x` | 十六进制 |
| `%%` | 百分号本身 |

> ⚠️ `printf` **不做类型检查**，格式符和参数类型不匹配会输出垃圾或崩溃。这是它不如 `cout` 的地方。

## 5.2 `std::cin` 输入

```cpp
#include <iostream>

int main() {
    int age;
    std::cout << "请输入你的年龄: ";
    std::cin >> age;
    std::cout << "你的年龄是 " << age << " 岁\n";
    return 0;
}
```

**运行示例：**

```
请输入你的年龄: 25
你的年龄是 25 岁
```

**注意 `>>` 的方向**：数据从 `cin` **流进**变量。

```
std::cin  >>  age;
  ↑           ↑
 数据源      接收者
```

### 连续输入多个值

```cpp
#include <iostream>

int main() {
    int a, b;
    std::cout << "请输入两个整数（用空格分隔）: ";
    std::cin >> a >> b;
    std::cout << "和为: " << a + b << "\n";
    return 0;
}
```

**输入 `3 5` 会得到 8**。也可以分两行输入：

```
3
5
```

`cin` 会**自动跳过空格、Tab、换行**，所以怎么分隔都行。

也可以输入一串：

```cpp
int x, y, z;
std::cin >> x >> y >> z;      // 输入 "1 2 3" 或 "1\n2\n3" 都行
```

### 读取字符串

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "请输入你的名字: ";
    std::cin >> name;
    std::cout << "你好, " << name << "!\n";
    return 0;
}
```

**⚠️ `cin >>` 读字符串时遇到空白就停：**

输入 `Zhang San` → `name` 只会得到 `Zhang`，`San` 留在输入缓冲区里。

**要读一整行（含空格），用 `std::getline`：**

```cpp
#include <iostream>
#include <string>

int main() {
    std::string fullName;
    std::cout << "请输入你的全名: ";
    std::getline(std::cin, fullName);
    std::cout << "你好, " << fullName << "!\n";
    return 0;
}
```

输入 `Zhang San` → 得到完整的 `Zhang San`。

### ⚠️ `cin >>` 和 `getline` 混用的经典陷阱

```cpp
#include <iostream>
#include <string>

int main() {
    int age;
    std::string name;

    std::cout << "年龄: ";
    std::cin >> age;              // 你输入 "18" 然后按回车
                                  // cin 只取走 "18"，回车符 '\n' 还在缓冲区！

    std::cout << "姓名: ";
    std::getline(std::cin, name); // getline 立刻读到那个残留的 '\n'，返回空字符串！
                                  // name 是空的，你根本没机会输入

    std::cout << "姓名是: [" << name << "]\n";   // 输出 []
    return 0;
}
```

**三种修复方法：**

```cpp
#include <iostream>
#include <string>
#include <limits>     // 方法 3 需要

int main() {
    int age;
    std::string name;

    std::cout << "年龄: ";
    std::cin >> age;

    // 方法 1：用 getline 吃掉剩下的整行
    std::string dummy;
    std::getline(std::cin, dummy);

    // 方法 2：忽略一个字符（如果只剩 '\n' 就够了）
    // std::cin.ignore();

    // 方法 3：忽略直到换行符（最稳健）
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "姓名: ";
    std::getline(std::cin, name);
    std::cout << "你好, " << name << "!\n";
    return 0;
}
```

**记住这个套路：`cin >>` 后面接 `getline` 时，中间必须清理缓冲区。**

## 5.3 输入失败的处理

如果用户输入了字母但你期望整数，`cin` 会进入**失败状态**：

```cpp
#include <iostream>
#include <limits>

int main() {
    int num;

    while (true) {
        std::cout << "请输入一个整数: ";
        if (std::cin >> num) {
            break;   // 成功
        } else {
            std::cout << "输入无效，请重新输入！\n";
            std::cin.clear();   // 1. 清除错误标志
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 2. 清空缓冲区
        }
    }

    std::cout << "你输入了: " << num << "\n";
    return 0;
}
```

**三步走（必须按顺序）：**

1. `std::cin.clear()` —— 把流恢复到正常状态
2. `std::cin.ignore(...)` —— 把缓冲区里那个坏输入扔掉
3. 重新尝试读取

**`std::numeric_limits<std::streamsize>::max()`** 是一个极大的数，意思是"忽略尽可能多的字符，直到遇到换行符"。

## 5.4 一个完整的交互程序

```cpp
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::string name;
    int age;
    double height;

    std::cout << "===== 信息录入 =====\n";

    std::cout << "请输入姓名: ";
    std::getline(std::cin, name);

    std::cout << "请输入年龄: ";
    std::cin >> age;

    std::cout << "请输入身高(cm): ";
    std::cin >> height;

    std::cout << "\n===== 录入结果 =====\n";
    std::cout << std::left << std::setw(10) << "姓名" << ": " << name << "\n";
    std::cout << std::left << std::setw(10) << "年龄" << ": " << age << " 岁\n";
    std::cout << std::left << std::setw(10) << "身高" << ": "
              << std::fixed << std::setprecision(1) << height << " cm\n";

    return 0;
}
```

**运行示例：**

```
===== 信息录入 =====
请输入姓名: 张三
请输入年龄: 25
请输入身高(cm): 178.5

===== 录入结果 =====
姓名      : 张三
年龄      : 25 岁
身高      : 178.5 cm
```

## 5.5 练习

1. 让用户输入两个数，输出它们的和、差、积、商（保留 2 位小数）。
2. 让用户输入圆的半径，输出面积和周长。
3. 让用户依次输入姓名（可能含空格）和年龄，都正确输出。
4. 让用户输入一个摄氏温度，转换成华氏温度（公式：`F = C × 9/5 + 32`）。

**参考答案：**

```cpp
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    // 练习 1
    double a, b;
    std::cout << "请输入两个数: ";
    std::cin >> a >> b;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "和: " << a + b << "\n";
    std::cout << "差: " << a - b << "\n";
    std::cout << "积: " << a * b << "\n";
    if (b != 0) {
        std::cout << "商: " << a / b << "\n";
    } else {
        std::cout << "商: 除数不能为 0\n";
    }

    // 练习 2
    constexpr double PI = 3.14159265358979;
    double r;
    std::cout << "\n请输入圆半径: ";
    std::cin >> r;
    std::cout << "面积: " << PI * r * r << "\n";
    std::cout << "周长: " << 2 * PI * r << "\n";

    // 练习 3
    std::cin.ignore(10000, '\n');   // 清理缓冲区
    std::string name;
    int age;
    std::cout << "\n请输入姓名: ";
    std::getline(std::cin, name);
    std::cout << "请输入年龄: ";
    std::cin >> age;
    std::cout << "你好 " << name << "，你 " << age << " 岁了。\n";

    // 练习 4
    double c;
    std::cout << "\n请输入摄氏温度: ";
    std::cin >> c;
    double f = c * 9.0 / 5.0 + 32.0;
    std::cout << c << "°C = " << f << "°F\n";

    return 0;
}
```

---

# 第 6 章 · 条件判断（if / switch）

程序需要根据情况做不同的事，这就是**分支**。

## 6.1 `if` 语句

```cpp
if (条件) {
    // 条件为真时执行
}
```

```cpp
#include <iostream>

int main() {
    int score = 85;

    if (score >= 60) {
        std::cout << "及格了！\n";
    }

    std::cout << "程序结束\n";   // 无论如何都执行
    return 0;
}
```

**关键点：**

- 条件要写在**圆括号**里
- 条件的结果必须是能当"真假"用的东西（`bool` 最好）
- 花括号里的代码叫**代码块**

### 单条语句可以省略花括号（但不建议）

```cpp
if (score >= 60)
    std::cout << "及格\n";      // 只有这一句属于 if

// ⚠️ 危险示例：
if (score >= 60)
    std::cout << "及格\n";
    std::cout << "恭喜\n";      // ❌ 这句不属于 if！缩进骗了你，它总是执行
```

**结论：永远写花括号。** 这是无数血案换来的经验（Apple 的 goto fail 漏洞就是这么来的）。

## 6.2 `if - else`

```cpp
#include <iostream>

int main() {
    int num;
    std::cout << "请输入一个整数: ";
    std::cin >> num;

    if (num % 2 == 0) {
        std::cout << num << " 是偶数\n";
    } else {
        std::cout << num << " 是奇数\n";
    }
    return 0;
}
```

## 6.3 `if - else if - else`

```cpp
#include <iostream>

int main() {
    int score;
    std::cout << "请输入分数: ";
    std::cin >> score;

    if (score < 0 || score > 100) {
        std::cout << "分数不合法\n";
    } else if (score >= 90) {
        std::cout << "优秀\n";
    } else if (score >= 80) {
        std::cout << "良好\n";
    } else if (score >= 70) {
        std::cout << "中等\n";
    } else if (score >= 60) {
        std::cout << "及格\n";
    } else {
        std::cout << "不及格\n";
    }
    return 0;
}
```

**⭐ 执行顺序很重要**：从上往下依次检查，**一旦某个条件为真，执行完就跳出整个 if-else 链**。

所以上面的 `score >= 90` 必须先写。如果把 `score >= 60` 写在最前面，那么 95 分也会被判成"及格"。

## 6.4 嵌套 `if`

```cpp
#include <iostream>

int main() {
    int age = 20;
    bool hasTicket = true;

    if (age >= 18) {
        if (hasTicket) {
            std::cout << "可以入场\n";
        } else {
            std::cout << "请先买票\n";
        }
    } else {
        std::cout << "未成年，不能入场\n";
    }
    return 0;
}
```

**等价写法（用逻辑运算符合并）：**

```cpp
if (age >= 18 && hasTicket) {
    std::cout << "可以入场\n";
} else if (age >= 18) {
    std::cout << "请先买票\n";
} else {
    std::cout << "未成年，不能入场\n";
}
```

**嵌套太深（超过 3 层）就该重构了。** 常见手法是**提前返回**：

```cpp
// ❌ 深层嵌套
bool check(int age, bool hasTicket, bool isBanned) {
    if (age >= 18) {
        if (hasTicket) {
            if (!isBanned) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

// ✅ 卫语句（guard clause）：把异常情况提前踢出去
bool checkBetter(int age, bool hasTicket, bool isBanned) {
    if (age < 18)     return false;
    if (!hasTicket)   return false;
    if (isBanned)     return false;
    return true;
}
```

## 6.5 悬空 else 问题

```cpp
int x = 10;
if (x > 5)
    if (x > 8)
        std::cout << "A\n";
else                      // ❌ 这个 else 属于内层 if！
    std::cout << "B\n";
```

**`else` 总是和最近的、还没配对的 `if` 结合。** 缩进不影响语义。

**解决：永远用花括号。**

```cpp
if (x > 5) {
    if (x > 8) {
        std::cout << "A\n";
    }
} else {
    std::cout << "B\n";
}
```

## 6.6 `switch` 语句

当你要**根据一个整数值做多路分支**时，`switch` 比一长串 `if-else` 更清晰。

```cpp
#include <iostream>

int main() {
    int choice;
    std::cout << "1. 开始游戏\n";
    std::cout << "2. 读取存档\n";
    std::cout << "3. 设置\n";
    std::cout << "4. 退出\n";
    std::cout << "请选择: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "游戏开始！\n";
            break;
        case 2:
            std::cout << "读取存档中...\n";
            break;
        case 3:
            std::cout << "打开设置\n";
            break;
        case 4:
            std::cout << "再见！\n";
            break;
        default:
            std::cout << "无效选择\n";
            break;
    }
    return 0;
}
```

**结构：**

```
switch (表达式) {     ← 表达式必须是整数/字符/枚举类型
    case 值1:         ← 必须是编译期常量
        语句;
        break;        ← 跳出 switch
    case 值2:
        语句;
        break;
    default:          ← 都不匹配时执行（可选）
        语句;
        break;
}
```

### ⚠️ `break` 不能忘！（穿透 fallthrough）

```cpp
int x = 2;
switch (x) {
    case 1:
        std::cout << "一\n";
        // 忘了 break！
    case 2:
        std::cout << "二\n";
        // 忘了 break！
    case 3:
        std::cout << "三\n";
        break;
    default:
        std::cout << "其他\n";
}
```

**输出：**

```
二
三
```

因为从 `case 2` 开始执行，执行完没有 `break` 就**继续往下"穿透"**到 `case 3`。

### 穿透有时是故意的

```cpp
#include <iostream>

int main() {
    char grade = 'B';

    switch (grade) {
        case 'A':
        case 'B':
        case 'C':
            std::cout << "通过\n";
            break;
        case 'D':
        case 'E':
            std::cout << "未通过\n";
            break;
        default:
            std::cout << "无效成绩\n";
    }
    return 0;
}
```

这里多个 `case` 共享同一段代码，是**合法且常见**的用法。建议加注释说明是故意的：

```cpp
    case 'A':
    case 'B':
        // 故意穿透
    case 'C':
        std::cout << "通过\n";
        break;
```

> **C++17 有 `[[fallthrough]];` 属性**，明确表示"我是故意穿透的"：

```cpp
switch (x) {
    case 1:
        std::cout << "一\n";
        [[fallthrough]];        // C++17
    case 2:
        std::cout << "二\n";
        break;
}
```

### `case` 里定义变量要加花括号

```cpp
switch (x) {
    case 1: {
        int temp = 10;       // ✅ 用花括号包起来限定作用域
        std::cout << temp << "\n";
        break;
    }
    case 2:
        // int temp2 = 20;   // ❌ 可能报 "jump to case label crosses initialization"
        break;
}
```

### `switch` vs `if-else`

| 用 `switch` | 用 `if-else` |
|---|---|
| 判断一个整数/字符/枚举的**多个具体值** | 判断**范围**（`score >= 90`） |
| 分支很多（≥4 个）且值离散 | 条件复杂（含 `&&`、`\|\|`） |
| 例：菜单选择、状态机、字符分类 | 例：分数等级、数值区间 |

## 6.7 `switch` 的新写法（C++17）

```cpp
// C++17：初始化语句 + 条件
switch (int choice = getChoice(); choice) {
    case 1: /* ... */ break;
    default: break;
}
```

这个特性配合 `if` 的初始化语句一起看：

```cpp
// C++17 的 if 初始化语句：把变量的作用域限制在 if 里
if (auto it = map.find(key); it != map.end()) {
    std::cout << it->second << "\n";
}
// 这里 it 已经不存在了，不会污染外部作用域
```

## 6.8 条件运算符的坑

```cpp
// ⚠️ 在 if 里赋值
int x;
if (x = 5) { }        // 编译通过，永远为真！应该用 ==

// ✅ 开高警告级别，g++ 会警告你
// g++ -Wall -Wextra 会提示 "suggest parentheses around assignment used as truth value"

// ⚠️ 用浮点数做条件判断
double d = 0.1 + 0.2 - 0.3;
if (d == 0.0) { }     // ❌ 可能不成立
if (std::fabs(d) < 1e-9) { }   // ✅

// ⚠️ 用指针/整数当 bool
int* p = nullptr;
if (p) { }            // ✅ 合法：nullptr 转 false，非空转 true
// 但不推荐，写 if (p != nullptr) 更清楚
```

## 6.9 练习

1. 输入一个整数，判断它是正数、负数还是零。
2. 输入三个数，输出最大值和最小值（不用 `max` 函数）。
3. 输入一个字符，判断它是大写字母、小写字母、数字还是其他。
4. 用 switch 写一个简易计算器：输入两个数和运算符，输出结果。
5. 输入一个月份（1-12），输出该月天数（不考虑闰年）。

**参考答案：**

```cpp
#include <iostream>

int main() {
    // 练习 1
    int n;
    std::cout << "请输入一个整数: ";
    std::cin >> n;
    if (n > 0)      std::cout << "正数\n";
    else if (n < 0) std::cout << "负数\n";
    else            std::cout << "零\n";

    // 练习 2
    int a, b, c;
    std::cout << "\n请输入三个数: ";
    std::cin >> a >> b >> c;

    int maxV = a;
    if (b > maxV) maxV = b;
    if (c > maxV) maxV = c;

    int minV = a;
    if (b < minV) minV = b;
    if (c < minV) minV = c;

    std::cout << "最大值: " << maxV << ", 最小值: " << minV << "\n";

    // 练习 3
    char ch;
    std::cout << "\n请输入一个字符: ";
    std::cin >> ch;
    if (ch >= 'A' && ch <= 'Z')      std::cout << "大写字母\n";
    else if (ch >= 'a' && ch <= 'z') std::cout << "小写字母\n";
    else if (ch >= '0' && ch <= '9') std::cout << "数字\n";
    else                             std::cout << "其他字符\n";

    // 练习 4
    double x, y;
    char op;
    std::cout << "\n请输入表达式（如 3 + 5）: ";
    std::cin >> x >> op >> y;

    switch (op) {
        case '+': std::cout << x + y << "\n"; break;
        case '-': std::cout << x - y << "\n"; break;
        case '*': std::cout << x * y << "\n"; break;
        case '/':
            if (y != 0) std::cout << x / y << "\n";
            else        std::cout << "除数不能为 0\n";
            break;
        default: std::cout << "未知运算符\n";
    }

    // 练习 5
    int month;
    std::cout << "\n请输入月份 (1-12): ";
    std::cin >> month;

    switch (month) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            std::cout << month << " 月有 31 天\n";
            break;
        case 4: case 6: case 9: case 11:
            std::cout << month << " 月有 30 天\n";
            break;
        case 2:
            std::cout << month << " 月有 28 或 29 天\n";
            break;
        default:
            std::cout << "月份无效\n";
    }

    return 0;
}
```

---

# 第 7 章 · 循环（for / while / do-while）

循环让我们**重复做一件事**。这是编程威力的真正来源。

## 7.1 `while` 循环

```cpp
while (条件) {
    // 条件为真时反复执行
}
```

```cpp
#include <iostream>

int main() {
    int i = 1;
    while (i <= 5) {
        std::cout << "第 " << i << " 次\n";
        i++;                       // ⚠️ 千万别忘了这行！
    }
    std::cout << "循环结束\n";
    return 0;
}
```

**输出：**

```
第 1 次
第 2 次
第 3 次
第 4 次
第 5 次
循环结束
```

**执行流程：**

```
      ┌──────────────┐
      ↓              │
  检查条件 ──真──→ 执行循环体 ──┘
      │
     假
      ↓
   继续往下
```

### ⚠️ 死循环

```cpp
int i = 1;
while (i <= 5) {
    std::cout << i << "\n";
    // 忘了 i++ ！i 永远是 1，条件永远为真
}
// 程序卡死，疯狂输出 1
```

**如果真卡死了**：在终端按 `Ctrl + C` 强制终止。

### 故意写死循环

```cpp
while (true) {
    // 一直执行，直到内部 break
    if (某个条件) break;
}
```

这在"游戏主循环""服务器监听"里很常见。

## 7.2 `for` 循环

`for` 把"初始化、条件、更新"三件事写在一行，最紧凑：

```cpp
for (初始化; 条件; 每次循环后执行) {
    // 循环体
}
```

```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 5; i++) {
        std::cout << "第 " << i << " 次\n";
    }
    return 0;
}
```

**执行顺序（非常重要）：**

```
1. 初始化   int i = 1     ← 只执行一次
2. 检查条件 i <= 5
3. 真 → 执行循环体
4. 更新     i++           ← 循环体执行完才做
5. 回到第 2 步
6. 假 → 退出循环
```

**注意：`i++` 是在循环体**之后**执行的，不是之前。** 这解释了为什么循环体里 `i` 的值是 1,2,3,4,5。

### 各种循环写法

```cpp
#include <iostream>

int main() {
    // 0 到 4（程序员习惯从 0 开始）
    for (int i = 0; i < 5; i++) std::cout << i << " ";
    std::cout << "\n";                            // 0 1 2 3 4

    // 5 到 1（倒着数）
    for (int i = 5; i >= 1; i--) std::cout << i << " ";
    std::cout << "\n";                            // 5 4 3 2 1

    // 步长 2
    for (int i = 0; i <= 10; i += 2) std::cout << i << " ";
    std::cout << "\n";                            // 0 2 4 6 8 10

    // 多个变量
    for (int i = 0, j = 10; i < j; i++, j--) {
        std::cout << "i=" << i << " j=" << j << "\n";
    }

    // 空初始化（变量在外面定义）
    int k = 0;
    for (; k < 3; k++) std::cout << k << " ";
    std::cout << "\n";                            // 0 1 2
    // 注意：k 在这里还存在，值 = 3

    // 死循环
    // for (;;) { ... }   // 等价于 while (true)

    return 0;
}
```

### 变量作用域

```cpp
for (int i = 0; i < 3; i++) { }
// std::cout << i;    // ❌ 编译错误：i 只活在 for 里

int i;
for (i = 0; i < 3; i++) { }
std::cout << i;       // ✅ 输出 3
```

**推荐在 `for` 里定义循环变量**，作用域越小越安全。

## 7.3 `do-while` 循环

**先执行一次，再检查条件**：

```cpp
do {
    // 至少执行一次
} while (条件);      // ⚠️ 注意结尾分号！
```

```cpp
#include <iostream>

int main() {
    int choice;
    do {
        std::cout << "\n1. 继续  2. 退出\n";
        std::cout << "请选择: ";
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "继续中...\n";
        }
    } while (choice != 2);

    std::cout << "已退出\n";
    return 0;
}
```

**`do-while` 最适合"菜单"这种必须至少显示一次的场景。**

**对比：**

```cpp
int i = 10;
while (i < 5) { std::cout << "A"; }       // 一次都不输出
do { std::cout << "B"; } while (i < 5);   // 输出一次 "B"
```

## 7.4 `break` 和 `continue`

### `break`：立即跳出整个循环

```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            std::cout << "找到 5，提前结束\n";
            break;
        }
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}
```

**输出：**

```
1 2 3 4 找到 5，提前结束
```

### `continue`：跳过本次，进入下一次

```cpp
#include <iostream>

int main() {
    // 只输出奇数
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;      // 偶数跳过，后面的 cout 不执行
        }
        std::cout << i << " ";
    }
    std::cout << "\n";     // 1 3 5 7 9
    return 0;
}
```

**区别记牢：**

- `break` —— 我不玩了，整个循环结束
- `continue` —— 这一轮我不玩了，下一轮继续

### ⚠️ `continue` 在 while 里的陷阱

```cpp
int i = 0;
while (i < 10) {
    if (i % 2 == 0) {
        continue;      // ❌ 死循环！i++ 被跳过了，i 永远是 0
    }
    std::cout << i << " ";
    i++;
}

// ✅ 正确：把 i++ 放在 continue 之前
int j = 0;
while (j < 10) {
    j++;
    if (j % 2 == 0) continue;
    std::cout << j << " ";
}
```

**`for` 循环不会有这个问题**，因为 `i++` 是循环机制的一部分，`continue` 跳不过它。

### `break` 只跳出最内层循环

```cpp
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (i == 1 && j == 1) break;   // 只跳出内层 j 循环
        std::cout << "(" << i << "," << j << ") ";
    }
}
```

**要一次跳出多层，用标志位或 `goto`：**

```cpp
// 方法 1：标志位
bool found = false;
for (int i = 0; i < 3 && !found; i++) {
    for (int j = 0; j < 3; j++) {
        if (i == 1 && j == 1) {
            found = true;
            break;
        }
    }
}

// 方法 2：函数 + return（最推荐）
bool search() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) return true;   // 直接返回，两个循环一起结束
        }
    }
    return false;
}

// 方法 3：goto（能用但尽量避免）
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        if (i == 1 && j == 1) goto done;
    }
}
done:
std::cout << "跳出来了\n";
```

## 7.5 嵌套循环

```cpp
#include <iostream>

int main() {
    // 打印乘法表
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j << "x" << i << "=" << i * j << "\t";
        }
        std::cout << "\n";
    }
    return 0;
}
```

**输出：**

```
1x1=1	
1x2=2	2x2=4	
1x3=3	2x3=6	3x3=9	
...
```

**图形打印练习：**

```cpp
#include <iostream>

int main() {
    int n = 5;

    // 直角三角形
    std::cout << "直角三角形:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) std::cout << "*";
        std::cout << "\n";
    }

    // 倒直角三角形
    std::cout << "\n倒直角三角形:\n";
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) std::cout << "*";
        std::cout << "\n";
    }

    // 等腰三角形（前面补空格）
    std::cout << "\n等腰三角形:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) std::cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) std::cout << "*";
        std::cout << "\n";
    }

    // 正方形
    std::cout << "\n正方形:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) std::cout << "* ";
        std::cout << "\n";
    }

    return 0;
}
```

## 7.6 常见的循环模式

### 累加求和

```cpp
#include <iostream>

int main() {
    // 1 + 2 + ... + 100
    int sum = 0;                        // ⚠️ 初始值必须是 0
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    std::cout << "1+2+...+100 = " << sum << "\n";   // 5050
    return 0;
}
```

### 求最大值/最小值

```cpp
#include <iostream>
#include <vector>
#include <climits>

int main() {
    std::vector<int> nums = {34, 7, 89, 23, 56};

    int maxV = nums[0];       // ⚠️ 用第一个元素初始化，不要用 0！
    for (int n : nums) {
        if (n > maxV) maxV = n;
    }
    std::cout << "最大值: " << maxV << "\n";   // 89

    // 如果一定要用极小值初始化
    int minV = INT_MAX;
    for (int n : nums) {
        if (n < minV) minV = n;
    }
    std::cout << "最小值: " << minV << "\n";   // 7
    return 0;
}
```

> ⚠️ **不要用 `maxV = 0` 初始化**！如果所有数都是负数，答案就错了。

### 计数

```cpp
#include <iostream>

int main() {
    // 统计 1-100 中有多少个能被 3 或 5 整除的数
    int count = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            count++;
        }
    }
    std::cout << "共 " << count << " 个\n";
    return 0;
}
```

### 判断素数

```cpp
#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;      // 偶数（除 2）都不是素数

    // 只需检查到 sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    for (int i = 1; i <= 50; i++) {
        if (isPrime(i)) std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}
```

> **为什么只需检查到 √n？** 如果 n = a × b，那么 a 和 b 中必然有一个 ≤ √n。所以找到 ≤ √n 的因子就够了。
> **为什么写 `i * i <= n` 而不是 `i <= sqrt(n)`？** 避免每次循环都调用 `sqrt`（虽然编译器可能优化），而且避免了浮点误差。

### 数字反转

```cpp
#include <iostream>

int main() {
    int n = 12345;
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;   // 取出末位，拼到结果后面
        n /= 10;                             // 去掉末位
    }
    std::cout << reversed << "\n";           // 54321
    return 0;
}
```

### 辗转相除法求最大公约数

```cpp
#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    std::cout << gcd(48, 18) << "\n";    // 6
    std::cout << gcd(100, 75) << "\n";   // 25
    return 0;
}
```

## 7.7 循环的性能与陷阱

### 循环里不要做重复计算

```cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // ❌ 每次循环都调用 size()
    for (int i = 0; i < (int)v.size(); i++) { }

    // ✅ 提前算好（注意：只在循环体内不改变 v 大小时才对）
    int n = (int)v.size();
    for (int i = 0; i < n; i++) { }

    std::string s = "hello";
    for (std::size_t i = 0; i < s.length(); i++) { }   // 现代编译器会自动优化，但这样写更明确

    return 0;
}
```

> 好消息：现代编译器通常会自动做这个优化。但**在循环体可能改变容器大小时，缓存 size 会导致 bug**，这种时候反而不能缓存。

### 浮点循环变量

```cpp
// ❌ 危险：浮点累加有误差
for (double d = 0.0; d != 1.0; d += 0.1) { }
// 永远不会等于 1.0，可能死循环

// ✅ 用整数循环，内部转换
for (int i = 0; i <= 10; i++) {
    double d = i / 10.0;
}
```

### 循环变量用 `size_t` 的陷阱

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3};

    // ❌ 倒序循环，用无符号类型会崩
    // for (std::size_t i = v.size() - 1; i >= 0; i--)
    //     条件 i >= 0 永远为真（无符号），而且 v.size()-1 在空容器时巨大

    // ✅ 方法 1：用有符号 int
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    // ✅ 方法 2：用反向迭代器（第 21 章讲）
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## 7.8 练习

1. 输出 1 到 100 中所有能被 7 整除的数。
2. 求 1! + 2! + 3! + ... + 10!（阶乘之和）。
3. 输出斐波那契数列前 20 项（1, 1, 2, 3, 5, 8, ...）。
4. 输入一个整数 n，输出它的所有因数。
5. 猜数字游戏：程序随机想一个 1-100 的数，让用户猜，提示"大了/小了"，统计猜了几次。
6. 输出 1-1000 中所有的"水仙花数"（三位数，各位数字立方和等于它本身，如 153 = 1³+5³+3³）。
7. 打印九九乘法表（直角三角形形式）。

**参考答案：**

```cpp
#include <iostream>
#include <cstdlib>     // rand, srand
#include <ctime>       // time

int main() {
    // 练习 1
    std::cout << "能被 7 整除: ";
    for (int i = 1; i <= 100; i++) {
        if (i % 7 == 0) std::cout << i << " ";
    }
    std::cout << "\n\n";

    // 练习 2
    long long sum = 0;
    long long fact = 1;
    for (int i = 1; i <= 10; i++) {
        fact *= i;          // 累积阶乘
        sum += fact;
    }
    std::cout << "1!+2!+...+10! = " << sum << "\n\n";   // 4037913

    // 练习 3
    std::cout << "斐波那契: ";
    long long a = 1, b = 1;
    std::cout << a << " " << b << " ";
    for (int i = 3; i <= 20; i++) {
        long long c = a + b;
        std::cout << c << " ";
        a = b;
        b = c;
    }
    std::cout << "\n\n";

    // 练习 4
    int n;
    std::cout << "请输入一个整数: ";
    std::cin >> n;
    std::cout << n << " 的因数: ";
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) std::cout << i << " ";
    }
    std::cout << "\n\n";

    // 练习 5
    std::srand(static_cast<unsigned>(std::time(nullptr)));   // 用时间做随机种子
    int secret = std::rand() % 100 + 1;    // 1-100
    int guess = 0, tries = 0;

    std::cout << "我想了一个 1-100 的数，来猜吧！\n";
    while (guess != secret) {
        std::cout << "你的猜测: ";
        std::cin >> guess;
        tries++;
        if (guess > secret)      std::cout << "大了\n";
        else if (guess < secret) std::cout << "小了\n";
        else                     std::cout << "猜对了！用了 " << tries << " 次\n";
    }
    std::cout << "\n";

    // 练习 6
    std::cout << "水仙花数: ";
    for (int i = 100; i <= 999; i++) {
        int h = i / 100;
        int t = i / 10 % 10;
        int o = i % 10;
        if (h * h * h + t * t * t + o * o * o == i) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n\n";   // 153 370 371 407

    // 练习 7
    std::cout << "九九乘法表:\n";
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j << "x" << i << "=" << i * j << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
```

> **关于随机数**：`std::rand()` 是老式 C 随机数，质量一般。现代 C++ 推荐 `<random>`：

```cpp
#include <iostream>
#include <random>

int main() {
    std::random_device rd;                        // 真随机种子
    std::mt19937 gen(rd());                       // 梅森旋转引擎
    std::uniform_int_distribution<int> dist(1, 100);   // 1-100 均匀分布

    for (int i = 0; i < 5; i++) {
        std::cout << dist(gen) << " ";
    }
    std::cout << "\n";
    return 0;
}
```

---



# 第 8 章 · 函数

**函数是把一段代码打包起来，起个名字，以后随时调用。** 这是对抗复杂度的第一件武器。

## 8.1 为什么需要函数？

假设没有函数，你要三次计算圆面积：

```cpp
double r1 = 5, r2 = 8, r3 = 12;
double area1 = 3.14159 * r1 * r1;
double area2 = 3.14159 * r2 * r2;
double area3 = 3.14159 * r3 * r3;
```

问题：

- 重复代码（改公式要改三处）
- 主程序越来越长，看不懂
- 没法复用

用函数：

```cpp
#include <iostream>

constexpr double PI = 3.14159265358979;

double circleArea(double r) {          // 定义一次
    return PI * r * r;
}

int main() {
    std::cout << circleArea(5) << "\n";    // 到处用
    std::cout << circleArea(8) << "\n";
    std::cout << circleArea(12) << "\n";
    return 0;
}
```

## 8.2 函数的定义

```cpp
返回类型 函数名(参数列表) {
    函数体
    return 返回值;
}
```

```cpp
int add(int a, int b) {
    int sum = a + b;
    return sum;
}
```

| 部分 | 名称 | 说明 |
|---|---|---|
| `int` | 返回类型 | 函数算完之后交给调用者的东西是什么类型 |
| `add` | 函数名 | 调用时用的名字 |
| `(int a, int b)` | 参数列表 | 调用时要传进来的东西，可以有 0 个或多个 |
| `{ ... }` | 函数体 | 具体做什么 |
| `return sum;` | 返回语句 | 把结果交出去，同时结束函数 |

### 调用

```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(3, 5);          // 调用，把 3 和 5 传进去
    std::cout << result << "\n";     // 8

    std::cout << add(10, 20) << "\n";      // 直接当表达式用
    int x = add(add(1, 2), add(3, 4));     // 嵌套调用 → add(3,7) → 10
    std::cout << x << "\n";
    return 0;
}
```

**调用过程：**

```
main 里调用 add(3, 5)
    ↓
把 3 复制给 a，5 复制给 b
    ↓
执行函数体：return a + b  →  8
    ↓
把 8 交回给 main，函数结束，a 和 b 被销毁
```

## 8.3 参数与实参

- **形参**（parameter）：函数定义里写的 `a`、`b`
- **实参**（argument）：调用时传的具体值 `3`、`5`

```cpp
int add(int a, int b) {   // a、b 是形参
    return a + b;
}

add(3, 5);                // 3、5 是实参
```

**默认是"传值"（按值传递）**：实参被**复制**一份给形参，函数里改形参**不影响**实参。

```cpp
#include <iostream>

void tryModify(int x) {    // void 表示"不返回任何东西"
    x = 999;
    std::cout << "函数内 x = " << x << "\n";
}

int main() {
    int a = 10;
    tryModify(a);
    std::cout << "函数外 a = " << a << "\n";   // 还是 10！
    return 0;
}
```

**输出：**

```
函数内 x = 999
函数外 a = 10
```

**为什么？** 因为函数内的 `x` 是 `a` 的一份**复印件**，改复印件不影响原件。

（想改原件要用**引用**，第 13 章讲。）

## 8.4 `return` 语句

### 有返回值的函数

```cpp
int square(int x) {
    return x * x;      // 返回一个值，函数立即结束
}

int max3(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}
```

**`return` 一执行，函数就结束，后面的代码不会跑：**

```cpp
int check(int n) {
    if (n < 0) {
        return -1;         // 这里返回后，下面的代码全部跳过
    }
    std::cout << "这行只在 n >= 0 时执行\n";
    return n * 2;
}
```

### `void` 函数：不返回值

```cpp
void printLine() {
    std::cout << "----------------\n";
}

void greet(const std::string& name) {
    std::cout << "你好, " << name << "!\n";
    // 没有 return，或者写 return; 都可以
}
```

**`void` 函数里可以写 `return;`（不带值），表示提前结束：**

```cpp
void process(int n) {
    if (n < 0) {
        std::cout << "输入非法\n";
        return;            // 提前结束
    }
    std::cout << "处理中...\n";
}
```

### ⚠️ 有返回值的函数必须有 `return`

```cpp
int bad(int x) {
    if (x > 0) {
        return 1;
    }
    // ❌ x <= 0 时没有 return，返回值是垃圾（未定义行为）
}

int good(int x) {
    if (x > 0) {
        return 1;
    }
    return 0;      // ✅ 所有路径都有返回
}
```

**`-Wall` 会警告这种问题：`warning: control reaches end of non-void function`。看到就修。**

## 8.5 函数声明与定义分离

如果函数 A 调用函数 B，但 B 定义在 A 后面，编译会报错：

```cpp
// ❌ 编译错误：'foo' was not declared in this scope
int main() {
    foo();     // 编译器还不知道 foo 是什么
    return 0;
}

void foo() {
    std::cout << "foo\n";
}
```

**解决：先声明（原型），后定义。**

```cpp
#include <iostream>

// 函数声明（原型）：只写返回类型、名字、参数类型，后面加分号
void foo();

int main() {
    foo();     // ✅ 现在编译器认识 foo 了
    return 0;
}

// 函数定义
void foo() {
    std::cout << "foo\n";
}
```

**声明只写类型，参数名可省略：**

```cpp
double power(double base, int exp);   // 有参数名，便于阅读
double power(double, int);            // 也可以省略参数名
```

**实践建议：把声明放在文件顶部（或头文件里），定义放后面。**

## 8.6 默认参数

```cpp
#include <iostream>

// 默认参数：调用时不传就用默认值
void printMessage(const std::string& msg, int times = 1, bool newline = true) {
    for (int i = 0; i < times; i++) {
        std::cout << msg;
        if (newline) std::cout << "\n";
    }
}

int main() {
    printMessage("Hello");                    // 用默认 times=1, newline=true
    printMessage("Hi", 3);                    // times=3
    printMessage("Yo", 2, false);             // 全部指定
    return 0;
}
```

**规则：**

1. **默认参数必须从右往左连续**：

```cpp
void f(int a, int b = 2, int c = 3);   // ✅
// void g(int a = 1, int b, int c = 3);  // ❌ 中间的不能有默认值
```

2. **默认参数只能在声明里写一次**（通常在声明处，不在定义处）：

```cpp
void f(int a, int b = 2);    // 声明里有默认值

void f(int a, int b) {       // 定义里不要再写 = 2！
    std::cout << a + b;
}
```

## 8.7 函数重载（Overloading）

**同一个函数名，不同参数列表**，编译器根据实参自动选：

```cpp
#include <iostream>

int add(int a, int b) {
    std::cout << "int 版本\n";
    return a + b;
}

double add(double a, double b) {
    std::cout << "double 版本\n";
    return a + b;
}

int add(int a, int b, int c) {
    std::cout << "三个参数版本\n";
    return a + b + c;
}

int main() {
    std::cout << add(1, 2) << "\n";          // int 版本 → 3
    std::cout << add(1.5, 2.5) << "\n";      // double 版本 → 4
    std::cout << add(1, 2, 3) << "\n";       // 三个参数版本 → 6
    return 0;
}
```

**⚠️ 只有返回类型不同不算重载：**

```cpp
int f(int a);
// double f(int a);    // ❌ 编译错误：仅返回类型不同，不能重载
```

**⚠️ 重载要避免歧义：**

```cpp
void f(int a);
void f(double a);

f(5);        // 调用 int 版本（精确匹配优先）
f(5.0);      // 调用 double 版本
f('a');      // char → int（整型提升），调用 int 版本
// f(5.0f);  // float → double（提升）还是 float → int（转换）？double 版本，因为提升优于转换
```

**优先级：精确匹配 > 提升（char→int）> 标准转换（double→int）> 用户定义转换。**

## 8.8 内联函数与 `inline`

函数调用有开销（压栈、跳转、返回）。对于极小的函数，可以建议编译器"直接把代码展开"：

```cpp
inline int square(int x) {
    return x * x;
}
```

**现代实践：**

- `inline` 如今主要是**链接相关**的含义（允许在头文件里定义函数而不违反"一次定义规则"）
- 编译器**自己会决定**是否内联，`inline` 只是建议
- 类内定义的成员函数**自动**是内联的

**不要为性能焦虑**，先写清晰的代码。

## 8.9 递归

**函数调用自己。**

```cpp
#include <iostream>

long long factorial(int n) {
    if (n <= 1) return 1;          // 基准情况（base case）：停止条件
    return n * factorial(n - 1);   // 递归情况
}

int main() {
    std::cout << factorial(5) << "\n";    // 120
    return 0;
}
```

**执行过程展开：**

```
factorial(5)
= 5 * factorial(4)
= 5 * 4 * factorial(3)
= 5 * 4 * 3 * factorial(2)
= 5 * 4 * 3 * 2 * factorial(1)
= 5 * 4 * 3 * 2 * 1
= 120
```

**递归三要素（缺一不可）：**

1. **基准情况**：什么时候停（`if (n <= 1) return 1;`）
2. **递归调用**：自己调用自己
3. **向基准靠近**：每次调用参数要变小（`n - 1`）

**忘了基准情况 → 无限递归 → 栈溢出（stack overflow）→ 程序崩溃。**

### 经典递归：斐波那契

```cpp
#include <iostream>

// ❌ 天真递归：指数级复杂度，n=45 就要跑很久
long long fibSlow(int n) {
    if (n <= 1) return n;
    return fibSlow(n - 1) + fibSlow(n - 2);
}

// ✅ 迭代版：线性复杂度
long long fibFast(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// ✅ 递归 + 记忆化（memoization）
#include <vector>
std::vector<long long> memo(100, -1);

long long fibMemo(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];        // 算过了，直接返回
    memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return memo[n];
}

int main() {
    std::cout << fibFast(50) << "\n";
    std::cout << fibMemo(50) << "\n";
    return 0;
}
```

### 经典递归：汉诺塔

```cpp
#include <iostream>

void hanoi(int n, char from, char to, char via) {
    if (n == 1) {
        std::cout << "把盘 1 从 " << from << " 移到 " << to << "\n";
        return;
    }
    hanoi(n - 1, from, via, to);        // 先把上面 n-1 个挪到中转柱
    std::cout << "把盘 " << n << " 从 " << from << " 移到 " << to << "\n";
    hanoi(n - 1, via, to, from);        // 再把 n-1 个挪到目标柱
}

int main() {
    hanoi(3, 'A', 'C', 'B');
    return 0;
}
```

### 什么时候用递归？

| 适合递归 | 适合循环 |
|---|---|
| 问题天然是递归结构的（树、图、分治） | 简单的重复计算 |
| 代码明显更短更清晰 | 递归深度可能很大 |
| 深度可控 | 性能敏感 |

**经验法则：能用循环就用循环；当递归能大幅简化代码时才用递归。**

## 8.10 函数设计原则

### 1. 一个函数只做一件事

```cpp
// ❌ 什么都干
void processUser() {
    // 读输入
    // 验证
    // 存数据库
    // 发邮件
    // 打日志
}

// ✅ 拆分
std::string readInput();
bool validate(const std::string& s);
void saveToDb(const User& u);
void sendEmail(const User& u);
```

**判断标准：函数名里出现"和""以及"就说明该拆了。**

### 2. 函数要短

理想情况下**不超过 20-30 行**。超过一屏就要考虑拆。

### 3. 名字要说明它做什么

```cpp
// ❌
void handle();
int calc(int a, int b);
bool check(int x);

// ✅
void saveUserToFile();
int computeAverageScore();
bool isValidEmail(const std::string& email);
```

### 4. 参数不要太多

超过 4-5 个参数就考虑用结构体封装：

```cpp
// ❌
void drawRect(int x, int y, int w, int h, int color, int thickness, bool filled);

// ✅
struct RectStyle { int color; int thickness; bool filled; };
void drawRect(int x, int y, int w, int h, const RectStyle& style);
```

### 5. 尽量少用全局变量

全局变量让函数之间产生隐藏依赖，难以测试和调试。**能传参就传参。**

## 8.11 练习

1. 写函数 `int max3(int a, int b, int c)` 返回三个数的最大值。
2. 写函数 `bool isLeapYear(int year)` 判断闰年。
3. 写函数 `int reverseNumber(int n)` 返回反转后的数字。
4. 写函数 `bool isPalindrome(int n)` 判断回文数（如 121）。
5. 写函数 `double power(double base, int exp)` 计算幂（不用 `std::pow`），支持负指数。
6. 写递归函数计算斐波那契第 n 项。
7. 写函数把十进制数转成二进制字符串。

**参考答案：**

```cpp
#include <iostream>
#include <string>

// 练习 1
int max3(int a, int b, int c) {
    int m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
}

// 练习 2
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 练习 3
int reverseNumber(int n) {
    int result = 0;
    while (n > 0) {
        result = result * 10 + n % 10;
        n /= 10;
    }
    return result;
}

// 练习 4
bool isPalindrome(int n) {
    if (n < 0) return false;
    return n == reverseNumber(n);
}

// 练习 5
double power(double base, int exp) {
    if (exp == 0) return 1.0;

    bool negative = exp < 0;
    if (negative) exp = -exp;

    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return negative ? 1.0 / result : result;
}

// 练习 6
long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// 练习 7
std::string toBinary(int n) {
    if (n == 0) return "0";
    std::string result;
    while (n > 0) {
        result = char('0' + n % 2) + result;   // 注意：每次插到最前面
        n /= 2;
    }
    return result;
}

int main() {
    std::cout << "max3(3,9,5) = " << max3(3, 9, 5) << "\n";
    std::cout << "2024 是闰年? " << std::boolalpha << isLeapYear(2024) << "\n";
    std::cout << "reverse(12345) = " << reverseNumber(12345) << "\n";
    std::cout << "121 是回文? " << isPalindrome(121) << "\n";
    std::cout << "2^10 = " << power(2, 10) << "\n";
    std::cout << "2^-3 = " << power(2, -3) << "\n";
    std::cout << "fib(10) = " << fib(10) << "\n";
    std::cout << "10 的二进制 = " << toBinary(10) << "\n";
    return 0;
}
```

---

# 第 9 章 · 作用域与生命周期

理解"一个变量在哪些地方能用、什么时候消失"，能避免大量诡异 bug。

## 9.1 什么是作用域？

**作用域（scope）** = 一个名字能被使用的范围。

```cpp
#include <iostream>

int globalVar = 100;          // 全局作用域：整个文件都能用

void func() {
    int localVar = 10;        // 函数作用域：只有 func 里能用
    std::cout << globalVar << "\n";    // ✅ 能访问全局
    std::cout << localVar << "\n";     // ✅
}

int main() {
    std::cout << globalVar << "\n";    // ✅
    // std::cout << localVar;          // ❌ 编译错误：localVar 不在这里
    func();
    return 0;
}
```

## 9.2 块作用域

`{ }` 划出一个新的作用域：

```cpp
#include <iostream>

int main() {
    int x = 1;
    std::cout << x << "\n";      // 1

    {
        int x = 2;               // 新的 x，遮蔽（shadow）了外面的
        std::cout << x << "\n";  // 2

        int y = 10;
        std::cout << y << "\n";  // 10
    }

    std::cout << x << "\n";      // 1（外层 x 没变）
    // std::cout << y;           // ❌ y 已经不存在了

    // for 循环的 i 也是块作用域
    for (int i = 0; i < 3; i++) { }
    // std::cout << i;           // ❌ i 不存在

    // if 的块
    if (true) {
        int z = 5;
    }
    // std::cout << z;           // ❌ z 不存在

    return 0;
}
```

## 9.3 变量遮蔽（Shadowing）与 `-Wshadow`

```cpp
#include <iostream>

int value = 10;      // 全局

int main() {
    std::cout << value << "\n";    // 10

    int value = 20;                // ⚠️ 遮蔽了全局 value
    std::cout << value << "\n";    // 20

    {
        int value = 30;            // ⚠️ 又遮蔽
        std::cout << value << "\n"; // 30
    }

    std::cout << value << "\n";    // 20

    // 想访问全局的怎么办？用 ::
    std::cout << ::value << "\n";  // 10
    return 0;
}
```

**遮蔽是 bug 温床。** 加 `-Wshadow` 编译选项让编译器警告你：

```bash
g++ -std=c++17 -Wall -Wextra -Wshadow main.cpp -o main
```

**建议：不要用重复的变量名。** 换个名字，比如 `globalValue` / `localValue`。

## 9.4 生命周期 vs 作用域

这两个概念容易混：

| | 作用域 | 生命周期 |
|---|---|---|
| 回答的问题 | **名字**在哪里可见 | **对象**何时存在 |
| 关于 | 编译期的名字查找 | 运行期的内存 |

```cpp
#include <iostream>

int* dangerous() {
    int local = 42;
    return &local;         // ❌ 返回局部变量的地址
}                          // local 在这里被销毁！

int main() {
    int* p = dangerous();
    std::cout << *p << "\n";   // ❌ 未定义行为：访问已销毁的内存
    return 0;
}
```

**`local` 的作用域是函数体，生命周期也是函数体（从定义到函数返回）。函数一返回，它就没了。**

这类 bug 常常"看起来能跑"，但在你改代码、换编译器、开优化后会突然崩溃。**这是最阴险的一类 bug。**

## 9.5 存储期（Storage Duration）

C++ 有四种存储期：

### 1. 自动存储期（automatic）

**局部变量默认都是这个。** 进入作用域时创建（在栈上），离开时销毁。

```cpp
void f() {
    int x = 10;        // 进 f 时创建
}                      // 出 f 时销毁
```

### 2. 静态存储期（static）

**全局变量、`static` 变量。** 程序启动时创建，程序结束时销毁。**只初始化一次。**

```cpp
#include <iostream>

void counter() {
    static int count = 0;      // ⚠️ 只初始化一次！
    count++;
    std::cout << "第 " << count << " 次调用\n";
}

int main() {
    counter();    // 第 1 次调用
    counter();    // 第 2 次调用
    counter();    // 第 3 次调用
    return 0;
}
```

**`static` 局部变量 = "活在函数里，但记住上次的值"。**

**经典用途：单例、缓存、计数器。**

```cpp
// 实现一个只初始化一次的昂贵对象
const BigConfig& getConfig() {
    static BigConfig config = loadConfigFromFile();   // 只加载一次
    return config;
}
```

> **C++11 起，局部 static 的初始化是线程安全的**（编译器会加锁）。这是个很有用的保证。

### 3. 线程存储期（thread_local，C++11）

每个线程一份：

```cpp
#include <iostream>
#include <thread>

thread_local int counter = 0;      // 每个线程有独立的 counter

void work(const char* name) {
    for (int i = 0; i < 3; i++) {
        counter++;
        std::cout << name << ": " << counter << "\n";
    }
}

int main() {
    std::thread t1(work, "T1");
    std::thread t2(work, "T2");
    t1.join();
    t2.join();
    return 0;
}
```

### 4. 动态存储期（dynamic）

用 `new` 手动分配的内存。**你不 `delete`，它就一直在**（内存泄漏）。第 22 章讲。

## 9.6 全局变量的利与弊

```cpp
#include <iostream>

int gCounter = 0;              // 全局变量

void increment() { gCounter++; }
void reset()     { gCounter = 0; }

int main() {
    increment();
    increment();
    std::cout << gCounter << "\n";   // 2
    return 0;
}
```

**好处：** 方便，随处可用。

**坏处：**

1. **谁改的不知道** —— 调试时追踪不到
2. **难以测试** —— 函数依赖外部状态，测试要重置全局
3. **初始化顺序问题** —— 不同文件里的全局变量初始化顺序**不确定**
4. **线程不安全**

```cpp
// ❌ 经典全局变量 bug：初始化顺序
// a.cpp
extern int b;
int a = b + 1;      // 如果 b 还没初始化，a 就是错的

// b.cpp
int b = 10;
// 谁先初始化？标准没规定！
```

**建议：**

- 优先用**函数参数**传递数据
- 常量（`constexpr`）放全局没问题
- 必须用全局状态时，用 `static` 限制在文件内，或者封装成类（单例）

## 9.7 `static` 的三种含义（容易混）

### 1. 局部 `static`：变量持久化

```cpp
void f() {
    static int n = 0;    // 只初始化一次，跨调用保持
    n++;
}
```

### 2. 全局/文件级 `static`：内部链接（只在本文件可见）

```cpp
// a.cpp
static int helper = 5;          // 只有 a.cpp 能访问
static void internalFunc() { }  // 只有 a.cpp 能调用

// b.cpp
// static int helper = 5;       // ✅ 可以重名，互不冲突
```

> **C++ 更推荐用匿名命名空间代替文件级 static：**

```cpp
namespace {
    int helper = 5;
    void internalFunc() { }
}
```

### 3. 类成员 `static`：属于类而非对象

```cpp
#include <iostream>

class Counter {
public:
    static int total;            // 声明：所有对象共享一个

    Counter() { total++; }
};

int Counter::total = 0;          // 定义（必须在类外定义一次）

int main() {
    Counter a, b, c;
    std::cout << Counter::total << "\n";    // 3
    return 0;
}
```

## 9.8 练习

1. 写一个函数，用 `static` 局部变量统计它被调用了多少次。
2. 下面代码输出什么？为什么？

```cpp
#include <iostream>
int x = 1;
int main() {
    std::cout << x << " ";
    int x = 2;
    std::cout << x << " ";
    {
        int x = 3;
        std::cout << x << " ";
    }
    std::cout << x << " ";
    std::cout << ::x << "\n";
    return 0;
}
```

3. 找出下面代码的 bug：

```cpp
int* createArray() {
    int arr[5] = {1, 2, 3, 4, 5};
    return arr;
}
```

**参考答案：**

```cpp
#include <iostream>

// 练习 1
void callMe() {
    static int count = 0;
    count++;
    std::cout << "被调用了 " << count << " 次\n";
}

int x = 1;   // 练习 2 用

int main() {
    callMe();
    callMe();
    callMe();
    std::cout << "\n";

    // 练习 2
    std::cout << x << " ";        // 1  （全局）
    int x = 2;                    // 遮蔽全局
    std::cout << x << " ";        // 2
    {
        int x = 3;                // 再遮蔽
        std::cout << x << " ";    // 3
    }
    std::cout << x << " ";        // 2
    std::cout << ::x << "\n";     // 1  （:: 访问全局）
    // 输出：1 2 3 2 1

    return 0;
}
```

**练习 3 的 bug**：`arr` 是局部数组，函数返回时就被销毁了，返回的指针指向已释放的栈内存。这是**未定义行为**，可能看起来正常，也可能崩溃。

修复方法：

```cpp
// 方法 1：用 std::vector（推荐）
#include <vector>
std::vector<int> createArray() {
    return {1, 2, 3, 4, 5};      // 返回副本，安全
}

// 方法 2：调用者提供数组
void fillArray(int* arr, int size) {
    for (int i = 0; i < size; i++) arr[i] = i + 1;
}

// 方法 3：用 static（不推荐，因为所有调用共享同一个数组）
int* createArrayStatic() {
    static int arr[5] = {1, 2, 3, 4, 5};
    return arr;
}
```

---

# 第 10 章 · 数组与 C 风格字符串

## 10.1 什么是数组？

**数组 = 一组相同类型的元素的连续排列，用下标访问。**

```
int arr[5] = {10, 20, 30, 40, 50};

内存里的样子：
 下标:    [0]   [1]   [2]   [3]   [4]
       ┌─────┬─────┬─────┬─────┬─────┐
       │  10 │  20 │  30 │  40 │  50 │
       └─────┴─────┴─────┴─────┴─────┘
地址:   1000  1004  1008  1012  1016   （int 占 4 字节）
```

**关键特点：**

- **下标从 0 开始**（不是 1！）
- 长度固定，定义后不能改
- 元素在内存里**连续**存放
- 数组名可以当指针用（第 13 章讲）

## 10.2 定义与初始化

```cpp
#include <iostream>

int main() {
    // 1) 完整初始化
    int a[5] = {10, 20, 30, 40, 50};

    // 2) 部分初始化：剩下的自动补 0
    int b[5] = {1, 2};              // {1, 2, 0, 0, 0}

    // 3) 全部初始化为 0
    int c[5] = {};                  // {0, 0, 0, 0, 0}
    int d[5] = {0};                 // 同上

    // 4) 让编译器推断长度
    int e[] = {1, 2, 3};            // 长度 3

    // 5) 指定下标初始化（C++ 设计器初始化）
    int f[5] = {[0] = 1, [4] = 9};  // {1, 0, 0, 0, 9}

    // 6) 先定义后赋值（不能整体赋值！）
    int g[3];
    g[0] = 1;
    g[1] = 2;
    g[2] = 3;
    // g = {1,2,3};                 // ❌ 编译错误

    std::cout << a[0] << " " << a[4] << "\n";    // 10 50
    std::cout << c[2] << "\n";                   // 0
    std::cout << sizeof(e) / sizeof(e[0]) << "\n";   // 3（求长度）
    return 0;
}
```

**⚠️ 数组长度必须是编译期常量：**

```cpp
int n = 5;
// int arr[n];           // ⚠️ 在某些编译器上是"变长数组"，C++ 标准不支持！
constexpr int N = 5;
int arr2[N];             // ✅ 正确
```

> 实际中 GCC 支持变长数组作为扩展，但**不是标准 C++**，换编译器就报错。**需要动态大小请用 `std::vector`（第 12 章）。**

## 10.3 访问与遍历

```cpp
#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // 读取
    std::cout << arr[0] << "\n";      // 10
    std::cout << arr[2] << "\n";      // 30

    // 修改
    arr[1] = 99;
    std::cout << arr[1] << "\n";      // 99

    // 遍历：用下标
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // 遍历：范围 for（C++11，推荐）
    for (int x : arr) {               // 读
        std::cout << x << " ";
    }
    std::cout << "\n";

    // 引用遍历：可以修改
    for (int& x : arr) {              // 注意 &
        x *= 2;
    }
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
```

### 求数组长度

```cpp
// 对真正的数组有效
int arr[10];
int n = sizeof(arr) / sizeof(arr[0]);    // 10

// C++17 标准库版本
#include <iterator>
int n2 = std::size(arr);                 // 10
```

**⚠️ 这条只在"数组还在作用域里"时有效。** 一旦数组传给函数，它就退化成指针，`sizeof` 就不对了：

```cpp
void bad(int arr[]) {
    // sizeof(arr) 是指针大小（8），不是数组长度！
    int n = sizeof(arr) / sizeof(arr[0]);   // ❌ 错的（通常是 2 或 1）
}

void good(int arr[], int n) {              // ✅ 必须额外传长度
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
}
```

> **这是 C 风格数组最大的坑。** 所以现代 C++ 推荐用 `std::array` 或 `std::vector`。

## 10.4 ⚠️ 越界访问：C++ 最危险的地方

**C++ 不检查数组下标！** 越界不会报错，只会**默默读写别的内存**。

```cpp
#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    std::cout << arr[10] << "\n";    // ❌ 越界读：输出垃圾值，或崩溃
    arr[100] = 999;                  // ❌ 越界写：可能破坏别的变量，可能崩溃

    return 0;
}
```

**为什么这么危险？** 因为越界写可能：

- 悄悄改掉旁边变量的值（bug 极难查）
- 破坏函数返回地址 → 崩溃，或被黑客利用（**缓冲区溢出攻击**）

### 防范措施

1. **确保下标在 `[0, n-1]` 范围内**，特别是循环边界

```cpp
// ❌ 经典 off-by-one 错误
int arr[5];
for (int i = 0; i <= 5; i++) arr[i] = 0;   // i=5 时越界！

// ✅
for (int i = 0; i < 5; i++) arr[i] = 0;
```

2. **用 `std::array::at()` 或 `std::vector::at()`**（会做检查，越界抛异常）

```cpp
#include <iostream>
#include <array>
#include <stdexcept>

int main() {
    std::array<int, 3> a = {1, 2, 3};
    std::cout << a[1] << "\n";       // 不检查，快
    try {
        std::cout << a.at(10) << "\n";   // 检查，越界抛异常
    } catch (const std::out_of_range& e) {
        std::cout << "越界了: " << e.what() << "\n";
    }
    return 0;
}
```

3. **开发时用 `-fsanitize=address`（GCC/Clang）**

```bash
g++ -std=c++17 -g -fsanitize=address,undefined main.cpp -o main
./main
```

**AddressSanitizer 会在越界发生时立刻告诉你具体哪一行**，这是排查内存问题的神器：

```
=================================================================
==12345==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffd...
WRITE of size 4 at 0x7ffd... thread T0
    #0 0x... in main /home/user/main.cpp:8
...
```

**强烈建议：写 C++ 时默认带上 `-fsanitize=address,undefined`，只在发布时才去掉。**

## 10.5 多维数组

```cpp
#include <iostream>

int main() {
    // 3 行 4 列
    int grid[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    // 访问
    std::cout << grid[0][0] << "\n";    // 1
    std::cout << grid[2][3] << "\n";    // 12

    // 遍历
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << grid[i][j] << "\t";
        }
        std::cout << "\n";
    }

    // 部分初始化
    int zeroGrid[3][4] = {};            // 全 0
    int sparse[3][4] = {{1}, {2, 3}};   // 其余补 0

    // 三维数组
    int cube[2][3][4] = {};
    cube[1][2][3] = 99;
    std::cout << cube[1][2][3] << "\n";

    // 范围 for 遍历二维数组
    for (const auto& row : grid) {       // row 是 int[4]
        for (int x : row) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
```

**内存布局：多维数组在内存里也是连续的**，`grid[1][0]` 紧跟在 `grid[0][3]` 后面：

```
[1][2][3][4][5][6][7][8][9][10][11][12]
 ↑            ↑
grid[0][0]   grid[1][0]
```

**遍历顺序影响性能**：按行遍历（`i` 外层，`j` 内层）符合内存顺序，缓存命中率高，比按列遍历快很多倍（对超大数组）。

## 10.6 数组作为函数参数

```cpp
#include <iostream>

// 写法 1：数组语法（实参是指针）
void print1(int arr[], int n) {
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

// 写法 2：指针语法（完全等价）
void print2(int* arr, int n) {
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

// 写法 3：引用传数组（保留长度信息，推荐！）
template <std::size_t N>
void print3(const int (&arr)[N]) {
    for (int i = 0; i < (int)N; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
    std::cout << "长度: " << N << "\n";
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    print1(a, 5);
    print2(a, 5);
    print3(a);            // ✅ 不用传长度，模板自动推导
    return 0;
}
```

**⭐ 关键理解：数组传给函数时，传递的是"首元素的地址"，不是整个数组的副本。**

```cpp
void modify(int arr[], int n) {
    arr[0] = 999;         // 会改变调用者的数组！
}

int main() {
    int a[3] = {1, 2, 3};
    modify(a, 3);
    std::cout << a[0] << "\n";    // 999
    return 0;
}
```

**为什么？** 因为数组不能整体复制，传的是指针。**这是 C++ 里数组和 `std::vector` 最大的行为差异。**

**所以：想保护原数组，加 `const`：**

```cpp
void printArray(const int arr[], int n) {
    // arr[0] = 1;    // ❌ 编译错误，保护了原数组
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
}
```

## 10.7 C 风格字符串（`char` 数组）

**C 风格字符串 = 以 `'\0'`（空字符）结尾的 `char` 数组。**

```cpp
char s1[] = "Hello";        // 长度是 6！H e l l o \0
char s2[10] = "Hi";         // H i \0 后面是 7 个 0

// 内存布局：
//  s1: [H][e][l][l][o][\0]     ← 6 个字节
//  s2: [H][i][\0][0][0][0][0][0][0][0]
```

**⚠️ 别忘了 `'\0'`**：

```cpp
char a[] = "Hi";      // 3 字节（含 '\0'）
char b[] = {'H', 'i'};  // 2 字节，不是字符串！没有 '\0'
```

`b` 不是合法字符串，用 `cout << b` 会一直读到内存里某个 `'\0'` 才停（可能输出乱码或崩溃）。

### 常用 C 字符串函数（`<cstring>`）

```cpp
#include <iostream>
#include <cstring>     // strlen, strcpy, strcmp, strcat

int main() {
    char s1[50] = "Hello";
    char s2[] = "World";
    char s3[50];

    // 长度
    std::cout << std::strlen(s1) << "\n";      // 5（不含 '\0'）
    std::cout << sizeof(s1) << "\n";           // 50（数组容量）

    // 复制（⚠️ 没有边界检查！）
    std::strcpy(s3, s1);                       // s3 = "Hello"
    // strncpy(s3, s1, sizeof(s3) - 1);        // ✅ 更安全
    // s3[sizeof(s3)-1] = '\0';

    // 拼接
    char s4[50] = "Hello ";
    std::strcat(s4, s2);                       // s4 = "Hello World"

    // 比较（⚠️ 不能直接用 == ！）
    std::cout << (std::strcmp("abc", "abd") < 0) << "\n";   // 1（abc < abd）
    std::cout << (std::strcmp("abc", "abc") == 0) << "\n";  // 1
    // ❌ if (s1 == s2)  比较的是地址，不是内容！

    // 查找字符
    char* p = std::strchr(s1, 'l');
    if (p) std::cout << "在位置 " << (p - s1) << " 找到 'l'\n";   // 位置 2

    std::cout << s1 << " " << s2 << " " << s3 << " " << s4 << "\n";
    return 0;
}
```

**⚠️⚠️ C 字符串的致命陷阱：**

```cpp
char a[] = "Hello";
char b[5];                 // ❌ 只能装 4 个字符 + '\0'
// strcpy(b, a);           // 💥 缓冲区溢出！写 6 字节到 5 字节的空间

char* p = "Hello";         // ⚠️ 指向字符串字面量（只读）
// p[0] = 'J';             // 💥 未定义行为！字面量存在只读区，会崩溃
const char* q = "Hello";   // ✅ 正确写法
```

### 为什么现代 C++ 不用 C 字符串？

| 问题 | C 字符串 | `std::string` |
|---|---|---|
| 长度 | 要自己算/传 | `.size()` |
| 拼接 | `strcat`，可能溢出 | `s1 + s2`，自动扩容 |
| 比较 | `strcmp`，不能用 `==` | `==` 直接比较内容 |
| 复制 | `strcpy`，可能溢出 | `=` 自动深拷贝 |
| 内存 | 手动管理 | 自动管理 |

**结论：日常代码一律用 `std::string`。** C 字符串只在和 C 库交互、极高性能场景、嵌入式里用。

## 10.8 `std::array`（C++11，推荐）

**`std::array` = 固定长度的数组 + 标准库接口**，比 C 数组安全得多。

```cpp
#include <iostream>
#include <array>
#include <algorithm>    // std::sort

int main() {
    std::array<int, 5> a = {5, 2, 8, 1, 9};

    // 大小
    std::cout << a.size() << "\n";          // 5
    std::cout << a.empty() << "\n";         // 0（false）

    // 访问
    std::cout << a[0] << "\n";              // 5（不检查）
    std::cout << a.front() << "\n";         // 5
    std::cout << a.back() << "\n";          // 9
    std::cout << a.at(1) << "\n";           // 2（检查，越界抛 std::out_of_range）

    // 修改
    a[0] = 100;
    a.fill(7);                              // 全部填 7

    // 遍历
    for (int x : a) std::cout << x << " ";
    std::cout << "\n";

    // 排序
    std::array<int, 5> b = {5, 2, 8, 1, 9};
    std::sort(b.begin(), b.end());
    for (int x : b) std::cout << x << " ";
    std::cout << "\n";                      // 1 2 5 8 9

    // 传给函数时不会退化成指针！长度信息保留
    std::cout << sizeof(a) << "\n";         // 20（5 × 4），不是指针大小

    // 也可以当 C 数组用
    int* raw = a.data();
    std::cout << raw[0] << "\n";

    // 二维
    std::array<std::array<int, 3>, 2> matrix = {{{1,2,3}, {4,5,6}}};
    std::cout << matrix[1][2] << "\n";      // 6

    return 0;
}
```

**`std::array` vs C 数组：**

| | C 数组 | `std::array` |
|---|---|---|
| 求长度 | `sizeof` 技巧 | `.size()` |
| 传函数 | 退化成指针 | 保留类型和长度 |
| 越界检查 | 无 | `.at()` 有 |
| 赋值 | 不能整体赋值 | `a = b;` ✅ |
| 迭代器 | 没有 | `.begin()`/`.end()` |
| 性能 | 相同 | **相同**（零开销） |

**结论：需要固定长度数组时，优先用 `std::array`。**

## 10.9 练习

1. 定义数组 `{3, 7, 1, 9, 4, 8}`，求最大值、最小值、平均值。
2. 把数组逆序输出。
3. 输入 10 个数存到数组，统计其中正数、负数、零的个数。
4. 判断一个数组是否是回文（正读反读一样）。
5. 用二维数组打印杨辉三角前 6 行。
6. 冒泡排序：把数组从小到大排序。

**参考答案：**

```cpp
#include <iostream>
#include <array>

int main() {
    // 练习 1
    int arr[] = {3, 7, 1, 9, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxV = arr[0], minV = arr[0], sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxV) maxV = arr[i];
        if (arr[i] < minV) minV = arr[i];
        sum += arr[i];
    }
    std::cout << "最大: " << maxV << ", 最小: " << minV
              << ", 平均: " << (double)sum / n << "\n";

    // 练习 2
    std::cout << "逆序: ";
    for (int i = n - 1; i >= 0; i--) std::cout << arr[i] << " ";
    std::cout << "\n";

    // 练习 3
    int nums[10] = {-3, 0, 5, -1, 8, 0, 2, -7, 4, 0};
    int pos = 0, neg = 0, zero = 0;
    for (int i = 0; i < 10; i++) {
        if (nums[i] > 0) pos++;
        else if (nums[i] < 0) neg++;
        else zero++;
    }
    std::cout << "正数 " << pos << ", 负数 " << neg << ", 零 " << zero << "\n";

    // 练习 4
    int pal[] = {1, 2, 3, 2, 1};
    int pn = sizeof(pal) / sizeof(pal[0]);
    bool isPal = true;
    for (int i = 0; i < pn / 2; i++) {
        if (pal[i] != pal[pn - 1 - i]) {
            isPal = false;
            break;
        }
    }
    std::cout << "是回文? " << std::boolalpha << isPal << "\n";

    // 练习 5
    std::cout << "\n杨辉三角:\n";
    int tri[6][6] = {};
    for (int i = 0; i < 6; i++) {
        tri[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << tri[i][j] << " ";
        }
        std::cout << "\n";
    }

    // 练习 6
    int s[] = {5, 2, 9, 1, 5, 6};
    int sn = sizeof(s) / sizeof(s[0]);
    for (int i = 0; i < sn - 1; i++) {
        for (int j = 0; j < sn - 1 - i; j++) {
            if (s[j] > s[j + 1]) {
                int t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }
    std::cout << "\n排序后: ";
    for (int i = 0; i < sn; i++) std::cout << s[i] << " ";
    std::cout << "\n";

    return 0;
}
```

---

# 第 11 章 · `std::string` 字符串

## 11.1 基本用法

```cpp
#include <iostream>
#include <string>       // 必须包含！

int main() {
    // 创建
    std::string s1 = "Hello";
    std::string s2("World");
    std::string s3(5, 'x');        // "xxxxx"
    std::string s4;                // 空字符串
    std::string s5 = s1;           // 拷贝

    std::cout << s1 << " " << s2 << " " << s3 << "\n";

    // 长度
    std::cout << s1.size() << "\n";        // 5
    std::cout << s1.length() << "\n";      // 5（和 size 等价）
    std::cout << s1.empty() << "\n";       // 0（false）

    // 访问字符
    std::cout << s1[0] << "\n";            // 'H'
    std::cout << s1.at(1) << "\n";         // 'e'（带检查）
    std::cout << s1.front() << "\n";       // 'H'
    std::cout << s1.back() << "\n";        // 'o'

    // 修改字符
    s1[0] = 'J';
    std::cout << s1 << "\n";               // "Jello"

    return 0;
}
```

## 11.2 拼接与追加

```cpp
#include <iostream>
#include <string>

int main() {
    std::string a = "Hello";
    std::string b = "World";

    // 1) + 运算符（产生新字符串）
    std::string c = a + ", " + b + "!";
    std::cout << c << "\n";                // Hello, World!

    // 2) += 追加（原地修改，更高效）
    std::string d = "Hello";
    d += " there";
    d += '!';
    std::cout << d << "\n";                // Hello there!

    // 3) append / push_back
    std::string e = "abc";
    e.append("def");
    e.push_back('g');
    std::cout << e << "\n";                // abcdefg

    // 4) insert
    std::string f = "Helo";
    f.insert(2, "l");                      // 在下标 2 处插入
    std::cout << f << "\n";                // Hello

    // 5) 数字转字符串
    std::string num = std::to_string(42);
    std::string pi = std::to_string(3.14159);
    std::cout << num + " and " + pi << "\n";

    // ⚠️ 注意：不能直接 "abc" + "def"
    // std::string bad = "abc" + "def";     // ❌ 两个 const char* 相加，编译错误
    std::string ok = std::string("abc") + "def";   // ✅
    std::string ok2 = "abc" + std::string("def");  // ✅

    return 0;
}
```

> **`+` 与 `+=` 的性能差异**：`s = s + "x"` 会创建临时对象再拷贝，`s += "x"` 直接在原字符串后面追加。**循环里务必用 `+=`。**

```cpp
// ❌ 慢：每次循环都创建新字符串并复制
std::string result;
for (int i = 0; i < 10000; i++) {
    result = result + std::to_string(i) + ",";
}

// ✅ 快：原地追加
std::string result2;
for (int i = 0; i < 10000; i++) {
    result2 += std::to_string(i);
    result2 += ',';
}
```

## 11.3 比较

```cpp
#include <iostream>
#include <string>

int main() {
    std::string a = "apple";
    std::string b = "banana";
    std::string c = "apple";

    // 可以直接用 == != < > 等（比较的是内容！）
    std::cout << std::boolalpha;
    std::cout << (a == c) << "\n";     // true
    std::cout << (a == b) << "\n";     // false
    std::cout << (a < b) << "\n";      // true（字典序，按字符的 ASCII 比较）
    std::cout << (a != b) << "\n";     // true

    // 和 C 字符串比较也可以
    std::cout << (a == "apple") << "\n";    // true

    // 字典序细节：逐字符比 ASCII
    // "apple" vs "Apple"：'a'(97) > 'A'(65)，所以 "apple" > "Apple"
    std::cout << ("apple" < "banana") << "\n";     // true
    std::cout << (std::string("Zoo") < std::string("apple")) << "\n";   // true（'Z' < 'a'）

    return 0;
}
```

> **这就是 `std::string` 比 C 字符串好用的关键：`==` 比的是内容。** C 字符串的 `==` 比的是地址（永远不等于你期望的结果）。

## 11.4 子串、查找、替换

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello, World!";

    // substr(起始下标, 长度)
    std::cout << s.substr(0, 5) << "\n";      // "Hello"
    std::cout << s.substr(7) << "\n";         // "World!"（省略长度 = 到结尾）
    std::cout << s.substr(7, 5) << "\n";      // "World"

    // find：找子串，返回下标，找不到返回 std::string::npos
    std::size_t pos = s.find("World");
    if (pos != std::string::npos) {
        std::cout << "在 " << pos << " 找到\n";    // 在 7 找到
    }

    if (s.find("xyz") == std::string::npos) {
        std::cout << "没找到 xyz\n";
    }

    // 从指定位置开始找
    std::string s2 = "abcabcabc";
    std::cout << s2.find("abc") << "\n";        // 0
    std::cout << s2.find("abc", 1) << "\n";     // 3
    std::cout << s2.rfind("abc") << "\n";       // 6（从右往左找）

    // find_first_of / find_last_of
    std::string s3 = "Hello World";
    std::cout << s3.find_first_of("aeiou") << "\n";   // 1（'e'）

    // replace(起始位置, 替换长度, 新内容)
    std::string s4 = "I like cats";
    s4.replace(7, 4, "dogs");
    std::cout << s4 << "\n";                    // "I like dogs"

    // erase(起始位置, 长度)
    std::string s5 = "Hello World";
    s5.erase(5, 6);
    std::cout << s5 << "\n";                    // "Hello"

    // 全部替换（循环 + find + replace）
    std::string text = "cat dog cat bird cat";
    std::string from = "cat", to = "fox";
    std::size_t startPos = 0;
    while ((startPos = text.find(from, startPos)) != std::string::npos) {
        text.replace(startPos, from.length(), to);
        startPos += to.length();    // 跳过刚替换的内容，避免死循环
    }
    std::cout << text << "\n";                  // "fox dog fox bird fox"

    return 0;
}
```

## 11.5 遍历

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello";

    // 1) 下标
    for (std::size_t i = 0; i < s.size(); i++) {
        std::cout << s[i] << " ";
    }
    std::cout << "\n";

    // 2) 范围 for（只读）
    for (char c : s) {
        std::cout << c << " ";
    }
    std::cout << "\n";

    // 3) 范围 for（可修改，用引用）
    for (char& c : s) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    std::cout << s << "\n";        // HELLO

    // 4) 迭代器
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 5) 倒序
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << "\n";             // olleH

    return 0;
}
```

## 11.6 字符串与数字互转

```cpp
#include <iostream>
#include <string>
#include <sstream>      // 字符串流
#include <iomanip>

int main() {
    // 数字 → 字符串
    std::string a = std::to_string(42);
    std::string b = std::to_string(3.14159);
    std::string c = std::to_string(3.14159);
    std::cout << a << " " << b << "\n";

    // 用 ostringstream 做格式化
    std::ostringstream oss;
    oss << "结果: " << std::fixed << std::setprecision(2) << 3.14159;
    std::string formatted = oss.str();
    std::cout << formatted << "\n";         // "结果: 3.14"

    // 字符串 → 数字
    int i = std::stoi("123");
    long l = std::stol("123456789");
    long long ll = std::stoll("123456789012345");
    double d = std::stod("3.14");
    float f = std::stof("2.5f"    /* 遇到非数字停止 */);

    std::cout << i + 1 << " " << d * 2 << "\n";

    // ⚠️ 非法输入会抛异常
    try {
        int bad = std::stoi("abc");
    } catch (const std::invalid_argument& e) {
        std::cout << "转换失败: " << e.what() << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "超出范围: " << e.what() << "\n";
    }

    // 带位置参数：看转换到哪了
    std::string s = "42abc";
    std::size_t processed = 0;
    int num = std::stoi(s, &processed);
    std::cout << "转换了 " << num << "，消耗了 " << processed << " 个字符\n";

    // 用 istringstream 解析
    std::istringstream iss("10 20 30");
    int x, y, z;
    iss >> x >> y >> z;
    std::cout << x + y + z << "\n";        // 60

    return 0;
}
```

## 11.7 实用技巧合集

```cpp
#include <iostream>
#include <string>
#include <algorithm>    // std::transform, std::reverse
#include <cctype>       // std::toupper, std::tolower, std::isspace

int main() {
    // 1) 全部转大写
    std::string s1 = "hello world";
    std::string upper = s1;
    std::transform(upper.begin(), upper.end(), upper.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    std::cout << upper << "\n";     // HELLO WORLD

    // 2) 全部转小写
    std::string lower = "HELLO";
    std::transform(lower.begin(), lower.end(), lower.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    std::cout << lower << "\n";     // hello

    // 3) 反转
    std::string rev = "abcdef";
    std::reverse(rev.begin(), rev.end());
    std::cout << rev << "\n";       // fedcba

    // 4) 去掉首尾空格
    std::string s2 = "   hello   ";
    std::size_t first = s2.find_first_not_of(" \t\n\r");
    std::size_t last  = s2.find_last_not_of(" \t\n\r");
    std::string trimmed = (first == std::string::npos) ? "" : s2.substr(first, last - first + 1);
    std::cout << "[" << trimmed << "]\n";     // [hello]

    // 5) 分割字符串（按空格）
    std::string text = "I love C++ programming";
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        std::cout << "[" << word << "] ";
    }
    std::cout << "\n";

    // 6) 按指定分隔符分割
    std::string csv = "apple,banana,cherry";
    std::size_t start = 0, end;
    std::string delim = ",";
    while ((end = csv.find(delim, start)) != std::string::npos) {
        std::cout << csv.substr(start, end - start) << " | ";
        start = end + delim.length();
    }
    std::cout << csv.substr(start) << "\n";

    // 7) 判断是否全是数字
    std::string digits = "12345";
    bool allDigits = !digits.empty() &&
                     std::all_of(digits.begin(), digits.end(),
                                 [](unsigned char c) { return std::isdigit(c); });
    std::cout << "全是数字? " << std::boolalpha << allDigits << "\n";

    // 8) 重复字符串
    std::string star;
    for (int i = 0; i < 20; i++) star += '*';
    std::cout << star << "\n";

    // 9) 拼接字符串列表
    std::string result;
    for (const auto& w : {"a", "b", "c"}) {
        if (!result.empty()) result += ", ";
        result += w;
    }
    std::cout << result << "\n";

    return 0;
}
```

## 11.8 `std::string` 的内部原理（了解）

`std::string` 内部通常有一个指针指向堆上的字符缓冲，外加长度和容量。它会：

- **自动扩容**：当追加的字符超过容量时，重新分配更大的内存（通常翻倍），把旧内容拷过去
- **自动释放**：字符串析构时释放内存
- **小字符串优化（SSO）**：短的字符串（一般 ≤15 字符）直接存在对象内部，不分配堆内存，所以很短小的字符串操作极快

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hi";
    std::cout << "size = " << s.size() << "\n";         // 2
    std::cout << "capacity = " << s.capacity() << "\n"; // 通常 15（SSO）

    s.reserve(1000);        // 预分配容量，避免反复扩容
    std::cout << "capacity = " << s.capacity() << "\n"; // ≥ 1000

    // 循环前 reserve 能显著提速
    std::string big;
    big.reserve(100000);
    for (int i = 0; i < 10000; i++) big += "x";

    return 0;
}
```

## 11.9 练习

1. 输入一个字符串，统计其中字母、数字、空格、其他字符的个数。
2. 输入一个字符串，判断它是否是回文（忽略大小写）。
3. 输入一个句子，统计有多少个单词。
4. 输入一个字符串，把它反转输出。
5. 输入一个字符串，把其中所有小写字母变成大写。
6. 输入一个字符串，找出第一个不重复的字符。
7. 输入一个字符串，统计每个字符出现的次数。

**参考答案：**

```cpp
#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
#include <algorithm>

int main() {
    // 练习 1
    std::string s;
    std::cout << "请输入一个字符串: ";
    std::getline(std::cin, s);

    int letters = 0, digits = 0, spaces = 0, others = 0;
    for (unsigned char c : s) {
        if (std::isalpha(c))      letters++;
        else if (std::isdigit(c)) digits++;
        else if (std::isspace(c)) spaces++;
        else                      others++;
    }
    std::cout << "字母 " << letters << ", 数字 " << digits
              << ", 空格 " << spaces << ", 其他 " << others << "\n";

    // 练习 2
    std::string lower = s;
    std::transform(lower.begin(), lower.end(), lower.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    std::string reversed(lower.rbegin(), lower.rend());
    std::cout << "是回文? " << std::boolalpha << (lower == reversed) << "\n";

    // 练习 3
    std::istringstream iss(s);
    std::string w;
    int wordCount = 0;
    while (iss >> w) wordCount++;
    std::cout << "单词数: " << wordCount << "\n";

    // 练习 4
    std::string rev(s.rbegin(), s.rend());
    std::cout << "反转: " << rev << "\n";

    // 练习 5
    std::string up = s;
    std::transform(up.begin(), up.end(), up.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    std::cout << "大写: " << up << "\n";

    // 练习 6
    std::cout << "第一个不重复字符: ";
    bool found = false;
    for (std::size_t i = 0; i < s.size(); i++) {
        if (s.find(s[i]) == s.rfind(s[i])) {    // 只在同一位置出现
            std::cout << s[i] << "\n";
            found = true;
            break;
        }
    }
    if (!found) std::cout << "（不存在）\n";

    // 练习 7
    std::map<char, int> freq;
    for (char c : s) {
        if (c != ' ') freq[c]++;
    }
    std::cout << "字符频率:\n";
    for (const auto& pair : freq) {
        std::cout << "  '" << pair.first << "': " << pair.second << " 次\n";
    }

    return 0;
}
```

---

# 第 12 章 · `std::vector` 动态数组

**`std::vector` 是 C++ 中最常用的容器。** 它像一个"会自己长大的数组"。

## 12.1 为什么需要 `vector`？

C 数组的问题：

- 长度固定，定义后不能改
- 不知道长度时只能开一个"够大"的
- 传给函数会丢失长度信息

`std::vector` 解决了全部问题：**自动扩容、知道自己的大小、可以安全传递。**

## 12.2 基本操作

```cpp
#include <iostream>
#include <vector>       // 必须包含

int main() {
    // ===== 创建 =====
    std::vector<int> v1;                        // 空
    std::vector<int> v2 = {1, 2, 3, 4, 5};      // 初始化列表
    std::vector<int> v3(5);                     // 5 个元素，都是 0
    std::vector<int> v4(5, 42);                 // 5 个元素，都是 42
    std::vector<int> v5(v2);                    // 拷贝 v2
    std::vector<std::vector<int>> matrix(3, std::vector<int>(4, 0));  // 3x4 全 0

    // ===== 大小 =====
    std::cout << v2.size() << "\n";             // 5
    std::cout << v2.empty() << "\n";            // 0 (false)
    std::cout << v2.capacity() << "\n";         // 容量（≥ size）

    // ===== 添加 =====
    v1.push_back(10);           // 末尾加一个
    v1.push_back(20);
    v1.push_back(30);
    v1.emplace_back(40);        // C++11：原地构造，通常更快

    // ===== 访问 =====
    std::cout << v1[0] << "\n";        // 10（不检查越界）
    std::cout << v1.at(1) << "\n";     // 20（检查，越界抛异常）
    std::cout << v1.front() << "\n";   // 10
    std::cout << v1.back() << "\n";    // 40
    std::cout << v1.data()[2] << "\n"; // 30（拿到原始指针）

    // ===== 修改 =====
    v1[0] = 99;

    // ===== 删除 =====
    v1.pop_back();              // 删末尾（最快）
    // 删除中间某个：
    std::vector<int> v6 = {1, 2, 3, 4, 5};
    v6.erase(v6.begin() + 2);           // 删除下标 2（值 3）→ {1,2,4,5}
    v6.erase(v6.begin(), v6.begin()+2); // 删除 [0,2) → {4,5}

    // 全部清空
    v6.clear();                 // size 变 0，capacity 不变

    // ===== 遍历 =====
    for (std::size_t i = 0; i < v1.size(); i++) std::cout << v1[i] << " ";
    std::cout << "\n";

    for (int x : v1) std::cout << x << " ";
    std::cout << "\n";

    for (int& x : v1) x *= 2;           // 可修改
    for (const int& x : v1) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
```

## 12.3 `size` 与 `capacity`

这是理解 `vector` 性能的关键：

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    std::cout << "size\tcapacity\n";
    for (int i = 0; i < 20; i++) {
        v.push_back(i);
        std::cout << v.size() << "\t" << v.capacity() << "\n";
    }
    return 0;
}
```

**典型输出：**

```
size	capacity
1	1
2	2
3	4
4	4
5	8
6	8
7	8
8	8
9	16
10	16
...
17	32
```

**规律：容量不足时会翻倍（不同实现可能用 1.5 倍或 2 倍）。**

- **`size()`**：当前有几个元素
- **`capacity()`**：已经分配了能装几个元素的空间
- `size <= capacity` 永远成立

**为什么这样设计？** 如果每次加一个就重新分配一次、复制一遍，总代价是 O(n²)。按倍数增长（摊销分析）让 `push_back` 平均代价是 **O(1)**。

**`reserve` 预分配可以避免反复扩容：**

```cpp
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    constexpr int N = 10000000;

    // 不预分配
    auto t1 = std::chrono::high_resolution_clock::now();
    std::vector<int> v1;
    for (int i = 0; i < N; i++) v1.push_back(i);
    auto t2 = std::chrono::high_resolution_clock::now();

    // 预分配
    auto t3 = std::chrono::high_resolution_clock::now();
    std::vector<int> v2;
    v2.reserve(N);
    for (int i = 0; i < N; i++) v2.push_back(i);
    auto t4 = std::chrono::high_resolution_clock::now();

    auto ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    auto ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count();

    std::cout << "不预分配: " << ms1 << " ms\n";
    std::cout << "预分配:   " << ms2 << " ms\n";
    std::cout << "容量对比: " << v1.capacity() << " vs " << v2.capacity() << "\n";
    return 0;
}
```

**`reserve` 是 C++ 里最简单的性能优化之一，值得养成习惯。**

> **`reserve` vs `resize`：**
> - `reserve(n)`：只改 capacity，size 不变，**不创建元素**
> - `resize(n)`：改 size，**会创建/销毁元素**（新元素值初始化）

```cpp
std::vector<int> v;
v.reserve(10);
std::cout << v.size() << " " << v.capacity() << "\n";   // 0 10
v.resize(10);
std::cout << v.size() << " " << v.capacity() << "\n";   // 10 10
```

## 12.4 ⚠️ 迭代器失效（重大陷阱）

**`vector` 扩容时，所有元素会被搬到新内存，原来的指针/引用/迭代器全部失效！**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3};

    int* p = v.data();              // 拿到内部指针
    int& r = v[0];                  // 拿到引用

    std::cout << *p << " " << r << "\n";   // 1 1

    v.push_back(4);                 // ⚠️ 可能触发扩容！
    v.push_back(5);
    v.push_back(6);

    // std::cout << *p << "\n";     // ❌ 未定义行为：p 已失效
    // std::cout << r << "\n";      // ❌ 未定义行为：r 已失效

    // ✅ 正确做法：重新获取
    std::cout << v[0] << "\n";

    // 范围 for 里修改容器大小 → 灾难
    // for (int x : v) { if (x == 2) v.push_back(99); }   // ❌ 未定义行为
    // ✅ 正确：先记录要加的东西
    std::vector<int> toAdd;
    for (int x : v) { if (x == 2) toAdd.push_back(99); }
    for (int x : toAdd) v.push_back(x);

    return 0;
}
```

**哪些操作会让迭代器失效？**

| 操作 | 影响 |
|---|---|
| `push_back` / `emplace_back` | 若扩容，**全部**失效；否则只失效 `end()` |
| `insert` / `erase` | 插入/删除位置**之后**的全部失效 |
| `resize` / `reserve` | 若重新分配，**全部**失效 |
| `clear` | **全部**失效 |
| 只读操作（`[]`、`size`、遍历） | 不影响 |

**记住：不要长期持有 `vector` 元素的指针/引用，尤其是在还会 push_back 的时候。**

## 12.5 用 `erase` 删除元素（经典陷阱）

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // ❌ 错误：erase 后 i 自增会跳过元素
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
    for (std::size_t i = 0; i < v1.size(); i++) {
        if (v1[i] % 2 == 0) {
            v1.erase(v1.begin() + i);   // 删除后，后面的元素前移，i++ 跳过了下一个
        }
    }
    // 结果可能是 {1,3,5}，也可能漏删

    // ✅ 方法 1：不递增 i
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6};
    for (std::size_t i = 0; i < v2.size(); ) {
        if (v2[i] % 2 == 0) {
            v2.erase(v2.begin() + i);   // 不递增，继续检查同一位置
        } else {
            i++;
        }
    }
    for (int x : v2) std::cout << x << " ";
    std::cout << "\n";                  // 1 3 5

    // ✅ 方法 2：erase-remove 惯用法（最推荐，简洁且快）
    std::vector<int> v3 = {1, 2, 3, 4, 5, 6};
    v3.erase(std::remove_if(v3.begin(), v3.end(),
                            [](int x) { return x % 2 == 0; }),
             v3.end());
    for (int x : v3) std::cout << x << " ";
    std::cout << "\n";                  // 1 3 5

    // C++20 更简洁：
    // std::erase_if(v3, [](int x) { return x % 2 == 0; });

    return 0;
}
```

**`std::remove_if` 的工作原理**：它不真的删除，而是把要保留的元素挪到前面，返回新的逻辑结尾。然后用 `erase` 把尾巴砍掉。这叫 **erase-remove 惯用法**，要记住。

## 12.6 二维 `vector`

```cpp
#include <iostream>
#include <vector>

int main() {
    // 方法 1：直接初始化
    std::vector<std::vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // 方法 2：先定大小
    int rows = 3, cols = 4;
    std::vector<std::vector<int>> grid2(rows, std::vector<int>(cols, 0));

    // 访问
    std::cout << grid[1][2] << "\n";       // 6
    grid2[0][0] = 5;

    // 遍历
    for (const auto& row : grid) {
        for (int x : row) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }

    // 动态增长的行
    std::vector<std::vector<int>> triangle;
    for (int i = 0; i < 5; i++) {
        triangle.push_back(std::vector<int>(i + 1, i));
    }
    for (const auto& row : triangle) {
        for (int x : row) std::cout << x << " ";
        std::cout << "\n";
    }
    // 0
    // 1 1
    // 2 2 2
    // ...

    // 用一维 vector 模拟二维（性能更好，缓存友好）
    int R = 3, C = 4;
    std::vector<int> flat(R * C, 0);
    auto at = [&](int r, int c) -> int& { return flat[r * C + c]; };
    at(1, 2) = 99;
    std::cout << flat[1 * C + 2] << "\n";    // 99

    return 0;
}
```

> **性能提示**：`vector<vector<int>>` 的每一行是独立分配的内存，不连续。计算密集场景（如图像处理、矩阵运算）用**一维 vector + 索引计算**会快很多。

## 12.7 `vector` 作为函数参数

```cpp
#include <iostream>
#include <vector>

// ❌ 按值传递：整个 vector 被复制！慢
void bad(std::vector<int> v) {
    v.push_back(999);        // 改的是副本
}

// ✅ 只读：const 引用（不复制，且保护原数据）
void printAll(const std::vector<int>& v) {
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

// ✅ 要修改：普通引用
void doubleAll(std::vector<int>& v) {
    for (int& x : v) x *= 2;
}

// ✅ 要往里加东西（但不想改调用者的）：按值传递 + std::move 返回
std::vector<int> appendValue(std::vector<int> v, int val) {
    v.push_back(val);
    return v;
}

int main() {
    std::vector<int> data = {1, 2, 3};

    bad(data);
    std::cout << data.size() << "\n";      // 3（没变）

    printAll(data);                        // 1 2 3
    doubleAll(data);
    printAll(data);                        // 2 4 6

    data = appendValue(std::move(data), 99);   // std::move 避免复制
    printAll(data);                        // 2 4 6 99

    return 0;
}
```

**参数传递决策表（重要）：**

| 场景 | 写法 |
|---|---|
| 基本类型（int/double/char/bool，小） | `int x`（按值） |
| 大对象只读 | `const T& x` |
| 大对象要改 | `T& x` |
| 要"拿走"调用者的对象 | `T&& x` 或按值 + `std::move` |
| 要一份独立副本 | `T x`（按值） |

**记住：`const std::vector<int>&` 是你最常用的参数形式。**

## 12.8 `vector<bool>` 的特殊性（了解）

`std::vector<bool>` 是一个**特化版本**，它用位（bit）来存 bool，节省 8 倍空间，但**不是真的容器**：

- `v[0]` 返回的不是 `bool&`，而是一个代理对象
- 不能用 `bool* p = v.data();`
- 不能取元素地址

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<bool> flags = {true, false, true};
    std::cout << flags[0] << "\n";       // 可以这样用

    // bool* p = flags.data();           // ❌ 编译错误

    // 需要真正的 bool 数组时，用 deque 或 vector<char>
    std::vector<char> better = {1, 0, 1};
    char* p = better.data();             // ✅

    return 0;
}
```

## 12.9 常用操作速查

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9, 3};

    // 排序
    std::sort(v.begin(), v.end());                  // 升序：1 2 3 5 8 9
    std::sort(v.begin(), v.end(), std::greater<int>());  // 降序：9 8 5 3 2 1

    // 查找
    auto it = std::find(v.begin(), v.end(), 8);
    if (it != v.end()) {
        std::cout << "找到 8，下标 " << (it - v.begin()) << "\n";
    }

    // 最值
    std::cout << *std::max_element(v.begin(), v.end()) << "\n";   // 9
    std::cout << *std::min_element(v.begin(), v.end()) << "\n";   // 1

    // 求和
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "和: " << sum << "\n";

    // 反转
    std::reverse(v.begin(), v.end());

    // 去重（必须先排序）
    std::vector<int> d = {1, 1, 2, 3, 3, 3, 4};
    std::sort(d.begin(), d.end());
    d.erase(std::unique(d.begin(), d.end()), d.end());
    for (int x : d) std::cout << x << " ";    // 1 2 3 4
    std::cout << "\n";

    // 交换
    std::vector<int> a = {1, 2}, b = {3, 4};
    a.swap(b);                                 // a = {3,4}, b = {1,2}

    // 判空 + 最后一个元素的安全访问
    if (!v.empty()) {
        std::cout << "最后一个: " << v.back() << "\n";
    }

    // 拷贝
    std::vector<int> copied = v;

    return 0;
}
```

## 12.10 练习

1. 输入 n 个数存到 `vector`，输出最大值、最小值、平均值。
2. 输入一批整数，去掉所有重复元素后输出（保持原顺序）。
3. 输入一批整数，把偶数放到前面，奇数放到后面。
4. 输入 n 个数，找出第二大的数。
5. 用 `vector` 实现一个简单的栈（push / pop / top / empty）。
6. 输入一个矩阵（二维 vector），输出它的转置。

**参考答案：**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <limits>

int main() {
    // 练习 1
    int n;
    std::cout << "输入个数: ";
    std::cin >> n;
    std::vector<int> v(n);
    std::cout << "输入 " << n << " 个数: ";
    for (int& x : v) std::cin >> x;

    if (!v.empty()) {
        std::cout << "最大: " << *std::max_element(v.begin(), v.end()) << "\n";
        std::cout << "最小: " << *std::min_element(v.begin(), v.end()) << "\n";
        std::cout << "平均: " << (double)std::accumulate(v.begin(), v.end(), 0) / v.size() << "\n";
    }

    // 练习 2：保持原顺序去重
    std::vector<int> dup = {1, 3, 2, 3, 1, 4, 2, 5};
    std::vector<int> uniqueResult;
    std::set<int> seen;
    for (int x : dup) {
        if (seen.insert(x).second) {        // insert 返回 pair，second 表示是否成功插入
            uniqueResult.push_back(x);
        }
    }
    std::cout << "去重后: ";
    for (int x : uniqueResult) std::cout << x << " ";
    std::cout << "\n";                       // 1 3 2 4 5

    // 练习 3：偶数在前
    std::vector<int> mix = {1, 2, 3, 4, 5, 6, 7, 8};
    // 用 partition
    std::partition(mix.begin(), mix.end(), [](int x) { return x % 2 == 0; });
    std::cout << "偶数在前: ";
    for (int x : mix) std::cout << x << " ";
    std::cout << "\n";

    // 练习 4：第二大
    std::vector<int> nums = {5, 9, 3, 9, 7, 1};
    int first = std::numeric_limits<int>::min();
    int second = std::numeric_limits<int>::min();
    for (int x : nums) {
        if (x > first) {
            second = first;
            first = x;
        } else if (x > second && x != first) {
            second = x;
        }
    }
    std::cout << "最大: " << first << ", 第二大: " << second << "\n";

    // 练习 5：简单栈
    std::vector<int> stack;
    auto push = [&](int x) { stack.push_back(x); };
    auto pop  = [&]() {
        if (stack.empty()) { std::cout << "栈空\n"; return -1; }
        int top = stack.back();
        stack.pop_back();
        return top;
    };
    auto top = [&]() { return stack.empty() ? -1 : stack.back(); };
    auto empty = [&]() { return stack.empty(); };

    push(1); push(2); push(3);
    std::cout << "栈顶: " << top() << "\n";      // 3
    std::cout << "弹出: " << pop() << "\n";      // 3
    std::cout << "弹出: " << pop() << "\n";      // 2
    std::cout << "空? " << std::boolalpha << empty() << "\n";   // false

    // 练习 6：矩阵转置
    std::vector<std::vector<int>> m = {{1, 2, 3}, {4, 5, 6}};   // 2x3
    int rows = (int)m.size(), cols = (int)m[0].size();
    std::vector<std::vector<int>> t(cols, std::vector<int>(rows));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            t[j][i] = m[i][j];

    std::cout << "转置后 (3x2):\n";
    for (const auto& row : t) {
        for (int x : row) std::cout << x << " ";
        std::cout << "\n";
    }

    return 0;
}
```

---

# 第 13 章 · 引用与指针（C++ 的分水岭）

**这一章是 C++ 最重要的章节。** 前面所有内容都是"任何语言都有的基础"，从这里开始才是 C++ 的精髓。

**如果这一章第一遍没看懂，不要慌，这是正常的。** 多看几遍，多敲代码，结合画图理解内存，一定会通。

## 13.1 内存模型：先建立心智图像

把内存想象成一排编了号的抽屉：

```
地址:  0x1000  0x1004  0x1008  0x100C  0x1010
     ┌───────┬───────┬───────┬───────┬───────┐
     │       │       │       │       │       │
     └───────┴───────┴───────┴───────┴───────┘
```

- 每个抽屉 1 个字节，有自己的**地址**（编号）
- `int` 占 4 个抽屉（4 字节）
- **变量名只是给某个地址起的别名**，编译后就只剩地址了

```cpp
int a = 42;
```

```
      a（名字）
       ↓
   ┌───────┐
   │  42   │   地址 0x1000，占 4 字节
   └───────┘
```

**指针就是"存地址的变量"。** 上面的 `a` 的地址是 `0x1000`，那 `&a` 就是 `0x1000`，把这个值存起来就是指针。

## 13.2 取地址运算符 `&`

```cpp
#include <iostream>

int main() {
    int a = 42;

    std::cout << "a 的值: " << a << "\n";       // 42
    std::cout << "a 的地址: " << &a << "\n";    // 0x7ffd...（每次运行可能不同）

    // 打印成十进制更好看
    std::cout << "地址（十进制）: "
              << reinterpret_cast<unsigned long long>(&a) << "\n";

    return 0;
}
```

**`&a` 读作"a 的地址"。** 注意 `&` 有两个含义，看语境区分：

| 语境 | 含义 |
|---|---|
| `int x = 5; int* p = &x;` | **取地址**运算符（一元） |
| `int c = a & b;` | 按位与（二元） |
| `void f(int& x)` | **引用**声明 |

## 13.3 指针基础

### 声明与使用

```cpp
#include <iostream>

int main() {
    int a = 42;

    int* p = &a;      // p 是一个"指向 int 的指针"，存的是 a 的地址
    // int * p = &a;  // 这样写也行（* 靠哪边都可以）
    // int *p = &a;   // 推荐这种

    std::cout << "p 的值（地址）: " << p << "\n";     // 0x7ffd...
    std::cout << "*p 的值: " << *p << "\n";           // 42

    *p = 100;         // 通过指针修改 a
    std::cout << "a = " << a << "\n";                 // 100

    return 0;
}
```

**核心两个操作：**

| 写法 | 名称 | 含义 |
|---|---|---|
| `&a` | 取地址 | 得到 a 的地址 |
| `*p` | 解引用（dereference） | 得到 p 指向的那个值 |

**心智图：**

```
        a                          p
    ┌───────┐                 ┌───────────┐
    │  42   │ ←──── 指向 ──── │  0x1000   │
    └───────┘                 └───────────┘
     0x1000                     0x2000

    &a  →  0x1000
     p  →  0x1000
    *p  →  42  （顺着地址找到那个盒子里的值）
    &p  →  0x2000
```

### 指针的类型很重要

```cpp
int*    pi;    // 指向 int
double* pd;    // 指向 double
char*   pc;    // 指向 char
int**   ppi;   // 指向"指向 int 的指针"（二级指针）
```

**指针的类型决定了 `*p` 时读几个字节**：

- `int*` 解引用读 4 字节
- `double*` 解引用读 8 字节
- `char*` 解引用读 1 字节

也决定了 `p + 1` 移动多少字节：

```cpp
#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    int* p = arr;                 // 指向第一个元素
    std::cout << *p << "\n";      // 10
    std::cout << *(p + 1) << "\n";// 20
    std::cout << *(p + 2) << "\n";// 30

    // p + 1 不是地址 +1，而是 + sizeof(int) = 4 字节
    std::cout << "p     = " << p << "\n";
    std::cout << "p + 1 = " << (p + 1) << "\n";   // 地址差 4

    return 0;
}
```

> **这是理解指针算术的关键：`p + n` 表示"往后走 n 个元素"，不是 n 个字节。**

## 13.4 引用

**引用 = 变量的别名。** 它不是一个新对象，只是另一个名字。

```cpp
#include <iostream>

int main() {
    int a = 42;
    int& r = a;        // r 是 a 的引用（别名）

    std::cout << r << "\n";     // 42
    r = 100;                    // 等价于 a = 100
    std::cout << a << "\n";     // 100

    std::cout << &a << "\n";    // 地址相同！
    std::cout << &r << "\n";    // 和上面一样

    return 0;
}
```

**心智图：**

```
        a         r
         ↓        ↓
      ┌────────────┐
      │    42      │   同一个内存，两个名字
      └────────────┘
```

**引用的规则：**

1. **必须初始化**：`int& r;` ❌ 编译错误
2. **不能重新绑定**：`r = b;` 是"把 b 的值赋给 a"，不是"让 r 指向 b"
3. **没有"空引用"**：引用必须指向一个真实存在的对象

## 13.5 引用 vs 指针：核心对比

| | 引用 `&` | 指针 `*` |
|---|---|---|
| 必须初始化 | ✅ 是 | ❌ 否 |
| 可以为空 | ❌ 不能 | ✅ 可以（`nullptr`） |
| 可以重新绑定 | ❌ 不能 | ✅ 可以 |
| 语法 | 直接用（`r`） | 要解引用（`*p`） |
| 可否算术运算 | ❌ | ✅（`p+1`） |
| 底层实现 | 通常也是指针 | 指针 |
| 安全性 | **更安全** | 更容易出错 |

**⭐ 实践建议：默认用引用，只在必须时（可能为空、需要重新指向、需要算术）才用指针。**

### 经典对比示例

```cpp
#include <iostream>

// 指针版本：要检查空
void incrementPtr(int* p) {
    if (p != nullptr) {     // 必须检查
        (*p)++;
    }
}

// 引用版本：不用检查（引用保证有效）
void incrementRef(int& x) {
    x++;                    // 直接用，语法更清爽
}

int main() {
    int a = 5, b = 5;
    incrementPtr(&a);       // 调用时要加 &（取地址）
    incrementRef(b);        // 直接传（不用加 &）
    std::cout << a << " " << b << "\n";   // 6 6
    return 0;
}
```

## 13.6 `const` 与指针/引用的组合（重点难点）

这里有四种组合，必须分清：

```cpp
int a = 10;
int b = 20;

// 1) 指向 const 的指针（pointer to const）
const int* p1 = &a;      // 不能通过 p1 改 a
// *p1 = 30;             // ❌ 编译错误
p1 = &b;                 // ✅ p1 本身可以改指向

// 2) const 指针（const pointer）
int* const p2 = &a;      // p2 本身不能改指向
*p2 = 30;                // ✅ 可以改 a
// p2 = &b;              // ❌ 编译错误

// 3) 指向 const 的 const 指针
const int* const p3 = &a;
// *p3 = 40;             // ❌
// p3 = &b;              // ❌

// 4) const 引用（最常用！）
const int& r = a;        // 不能用 r 改 a
// r = 50;               // ❌
```

**记忆技巧：从右往左读，`const` 修饰它左边的东西（如果左边没有，就修饰右边）：**

```cpp
const int* p;      // p is a pointer to const int     → 不能改 *p
int const* p;      // 同上（两种写法等价！）
int* const p;      // p is a const pointer to int     → 不能改 p
const int* const p;// const pointer to const int      → 都不能改
```

**为什么 `const int*` 和 `int const*` 一样？** 因为 `const` 修饰的是 `int`，位置可以换。但 `int* const` 修饰的是 `p`，不能换。

### `const` 引用作为函数参数（极其重要）

```cpp
#include <iostream>
#include <string>
#include <vector>

struct BigData {
    int values[1000];
    std::string name;
};

// ❌ 按值：完整复制 1000 个 int + string，非常慢
void process1(BigData d) { }

// ❌ 非 const 引用：快，但可能被误改
void process2(BigData& d) { }

// ✅ const 引用：不复制（快）+ 保证不修改（安全）
void process3(const BigData& d) {
    // d.values[0] = 1;    // ❌ 编译错误，保护了原数据
    std::cout << d.name << "\n";   // ✅ 只读没问题
}

int main() {
    BigData data;
    data.name = "test";
    process3(data);
    return 0;
}
```

**⭐ 记住这条规则：函数参数中的大对象（`std::string`、`std::vector`、自定义类），一律用 `const T&`。**

### `const` 引用可以绑定临时值

```cpp
#include <iostream>
#include <string>

void print(const std::string& s) {
    std::cout << s << "\n";
}

int main() {
    print("Hello");                    // ✅ const 引用可以绑定字面量
    print(std::string("temp"));        // ✅ 可以绑定临时对象
    print("a" + std::string("b"));     // ✅

    // 非 const 引用不行：
    // void bad(std::string& s);
    // bad("Hello");                   // ❌ 编译错误

    const int& r = 42;                 // ✅ 允许，编译器会创建临时变量
    std::cout << r << "\n";

    return 0;
}
```

**这就是为什么函数参数喜欢用 `const T&`：它能接受字面量、临时对象、以及所有变量。**

## 13.7 `nullptr`（C++11）

**空指针**：不指向任何对象的指针。

```cpp
#include <iostream>

int main() {
    int* p = nullptr;                  // ✅ C++11 推荐

    // 老式写法（不推荐）：
    // int* p1 = NULL;                 // NULL 其实是 0，有类型歧义
    // int* p2 = 0;

    if (p == nullptr) {
        std::cout << "p 是空指针\n";
    }

    // ⚠️ 解引用空指针 = 崩溃
    // std::cout << *p;               // 💥 Segmentation fault

    // ✅ 正确用法：先检查
    if (p != nullptr) {
        std::cout << *p << "\n";
    } else {
        std::cout << "指针为空，跳过\n";
    }

    return 0;
}
```

**为什么 `nullptr` 比 `NULL` 好？**

```cpp
void f(int x)    { std::cout << "int 版本\n"; }
void f(char* p)  { std::cout << "指针版本\n"; }

int main() {
    f(NULL);        // ⚠️ NULL 是 0，调用 int 版本！很可能不是你想要
    f(nullptr);     // ✅ 明确调用指针版本
    return 0;
}
```

**`nullptr` 有专门类型 `std::nullptr_t`，只能转成指针，不会和整数混淆。**

## 13.8 指针算术与数组

**数组名在大多数情况下会"退化成"指向首元素的指针：**

```cpp
#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // 下面三种写法完全等价
    std::cout << arr[2] << "\n";        // 30
    std::cout << *(arr + 2) << "\n";    // 30
    std::cout << *(2 + arr) << "\n";    // 30（交换律也成立！）

    // arr[2] 其实被编译器翻译成 *(arr + 2)
    // 这也是为什么 2[arr] 居然合法（但别这么写）

    // 遍历
    int* p = arr;
    int* end = arr + 5;
    while (p < end) {
        std::cout << *p << " ";
        p++;                    // 指针前进一个元素
    }
    std::cout << "\n";

    // 用指针算下标
    int* q = arr + 3;
    std::cout << "下标: " << (q - arr) << "\n";   // 3

    // 数组名 vs 指针的区别
    std::cout << sizeof(arr) << "\n";   // 20（整个数组 5*4）
    std::cout << sizeof(p) << "\n";     // 8（指针大小，64 位）
    // arr = p;                         // ❌ 数组名不能赋值
    // arr++;                           // ❌ 数组名不是左值

    return 0;
}
```

**差异总结：**

| | 数组名 | 指针 |
|---|---|---|
| `sizeof` | 整个数组大小 | 指针大小（8） |
| 能否赋值/自增 | 不能 | 能 |
| 能否取地址 | `&arr` 是指向数组的指针 | `&p` 是二级指针 |

## 13.9 指针与函数

### 指针作为参数（可以修改调用者的变量）

```cpp
#include <iostream>

void swapPtr(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapRef(int& a, int& b) {      // 引用版本，更简洁
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2;
    swapPtr(&x, &y);
    std::cout << x << " " << y << "\n";     // 2 1
    swapRef(x, y);
    std::cout << x << " " << y << "\n";     // 1 2
    return 0;
}
```

### 返回指针（⚠️ 危险）

```cpp
// ❌ 返回局部变量的地址：局部变量已销毁
int* bad() {
    int local = 42;
    return &local;
}

// ✅ 返回传入的指针
int* identity(int* p) {
    return p;
}

// ✅ 返回堆内存（调用者负责 delete）
int* createOnHeap() {
    return new int(42);
}

// ✅ 返回静态变量（但所有调用共享）
int* counter() {
    static int n = 0;
    return &n;
}

// ❌ 返回数组的引用要小心（数组本身是局部的）
```

## 13.10 二级指针与指针的引用

```cpp
#include <iostream>

void setToNull(int** pp) {
    *pp = nullptr;         // 修改外层指针
}

void setToNull2(int*& p) {  // 指针的引用（更推荐，语法更清晰）
    p = nullptr;
}

int main() {
    int a = 5;
    int* p = &a;

    std::cout << (p != nullptr) << "\n";   // 1

    setToNull(&p);                          // 传指针的地址
    std::cout << (p == nullptr) << "\n";    // 1

    p = &a;
    setToNull2(p);                          // 传指针的引用
    std::cout << (p == nullptr) << "\n";    // 1

    return 0;
}
```

**经验：能用"指针的引用（`T*&`）"就不用二级指针（`T**`），可读性好得多。**

## 13.11 函数指针

**函数也有地址，可以存在指针里。**

```cpp
#include <iostream>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

// 参数是函数指针
int compute(int x, int y, int (*op)(int, int)) {
    return op(x, y);
}

int main() {
    // 声明函数指针
    int (*fp)(int, int) = add;
    std::cout << fp(3, 4) << "\n";          // 7
    std::cout << (*fp)(3, 4) << "\n";       // 7（两种写法等价）

    // 切换指向
    fp = sub;
    std::cout << fp(10, 3) << "\n";         // 7

    // 当参数传
    std::cout << compute(6, 2, add) << "\n";   // 8
    std::cout << compute(6, 2, mul) << "\n";   // 12

    // 用 typedef / using 简化
    using BinOp = int(*)(int, int);
    BinOp op = mul;
    std::cout << op(5, 5) << "\n";          // 25

    // 函数指针数组（写计算器很方便）
    BinOp ops[] = {add, sub, mul};
    for (auto f : ops) {
        std::cout << f(8, 2) << " ";
    }
    std::cout << "\n";                      // 10 6 16

    return 0;
}
```

> **现代 C++ 中，函数指针大多被 lambda 和 `std::function` 取代**（第 20 章讲）。但理解函数指针有助于理解底层机制。

## 13.12 为什么需要指针？（总结）

1. **动态内存**：运行时才知道要多少内存 → `new` / `delete`（第 22 章）
2. **多态**：通过基类指针调用派生类方法（第 17 章）
3. **可选值**：参数"可能没有"，用 `nullptr` 表示
4. **避免复制**：传大对象时传指针（现在更推荐引用）
5. **数据结构**：链表、树、图必须用指针连接节点
6. **与 C 库交互**：C 接口全是指针

## 13.13 链表实战（理解指针的最佳练习）

```cpp
#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head_;
    int size_;

public:
    LinkedList() : head_(nullptr), size_(0) {}

    ~LinkedList() {                  // 析构：释放所有节点
        Node* current = head_;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // 头插
    void pushFront(int value) {
        Node* node = new Node(value);
        node->next = head_;
        head_ = node;
        size_++;
    }

    // 尾插
    void pushBack(int value) {
        Node* node = new Node(value);
        if (head_ == nullptr) {
            head_ = node;
        } else {
            Node* current = head_;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
        size_++;
    }

    // 删除第一个匹配的值
    bool remove(int value) {
        if (head_ == nullptr) return false;

        if (head_->data == value) {
            Node* toDelete = head_;
            head_ = head_->next;
            delete toDelete;
            size_--;
            return true;
        }

        Node* current = head_;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
            size_--;
            return true;
        }
        return false;
    }

    // 反转
    void reverse() {
        Node* prev = nullptr;
        Node* current = head_;
        while (current != nullptr) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head_ = prev;
    }

    void print() const {
        Node* current = head_;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next) std::cout << " -> ";
            current = current->next;
        }
        std::cout << " -> null\n";
    }

    int size() const { return size_; }
};

int main() {
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushFront(0);
    list.print();               // 0 -> 1 -> 2 -> 3 -> null
    std::cout << "大小: " << list.size() << "\n";

    list.remove(2);
    list.print();               // 0 -> 1 -> 3 -> null

    list.reverse();
    list.print();               // 3 -> 1 -> 0 -> null

    return 0;                   // 析构函数自动清理所有节点
}
```

> **注意 `->` 运算符**：`p->data` 等价于 `(*p).data`。对于指针访问成员，用 `->` 更简洁。

## 13.14 练习

1. 写函数 `void swap(int* a, int* b)` 和 `void swap(int& a, int& b)`。
2. 写函数 `int findMax(const int* arr, int n)` 返回数组最大值。
3. 写函数 `void reverseArray(int* arr, int n)` 原地反转数组。
4. 写函数 `bool isPalindrome(const char* s)` 判断 C 字符串是否回文。
5. 用指针遍历一个字符串并统计元音字母个数。
6. 解释下面代码的问题：

```cpp
int* getValue() {
    int x = 10;
    return &x;
}

int& getRef() {
    int x = 20;
    return x;
}
```

**参考答案：**

```cpp
#include <iostream>
#include <cstring>

// 练习 1
void swapPtr(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}
void swapRef(int& a, int& b) {
    int t = a; a = b; b = t;
}

// 练习 2
int findMax(const int* arr, int n) {
    if (n <= 0) return 0;
    int maxV = arr[0];              // 等价于 *arr
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > maxV) maxV = *(arr + i);
    }
    return maxV;
}

// 练习 3
void reverseArray(int* arr, int n) {
    int* left = arr;
    int* right = arr + n - 1;
    while (left < right) {
        int t = *left;
        *left = *right;
        *right = t;
        left++;
        right--;
    }
}

// 练习 4
bool isPalindrome(const char* s) {
    if (s == nullptr) return false;
    const char* left = s;
    const char* right = s + std::strlen(s) - 1;
    while (left < right) {
        if (*left != *right) return false;
        left++;
        right--;
    }
    return true;
}

// 练习 5
int countVowels(const char* s) {
    int count = 0;
    for (const char* p = s; *p != '\0'; ++p) {      // 走到 '\0' 停
        char c = *p;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    int x = 1, y = 2;
    swapPtr(&x, &y);
    std::cout << x << " " << y << "\n";         // 2 1
    swapRef(x, y);
    std::cout << x << " " << y << "\n";         // 1 2

    int arr[] = {3, 9, 1, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "最大: " << findMax(arr, n) << "\n";

    reverseArray(arr, n);
    std::cout << "反转: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    std::cout << "level 是回文? " << std::boolalpha << isPalindrome("level") << "\n";
    std::cout << "hello 是回文? " << isPalindrome("hello") << "\n";

    std::cout << "元音数: " << countVowels("Hello World") << "\n";   // 3

    // 练习 6 的解答：
    // getValue() 返回局部变量 x 的地址。函数返回后 x 已被销毁，
    // 返回的指针是"悬空指针"（dangling pointer）。
    // 使用它 = 未定义行为。
    //
    // getRef() 更糟：返回局部变量的引用，同样是悬空引用。
    // 引用比指针更容易掩盖问题，因为没有 nullptr 检查，用起来就像正常变量一样，
    // 但指向的内存早已失效。这类 bug 可能"看起来正常"很久，然后在某次编译器
    // 升级或优化后突然崩溃。

    return 0;
}
```

---

# 第 14 章 · 结构体、枚举与联合体

## 14.1 结构体 `struct`

**结构体把多个不同类型的数据打包成一个整体。**

```cpp
#include <iostream>
#include <string>

// 定义结构体类型
struct Student {
    std::string name;
    int age;
    double score;
};                            // ⚠️ 别忘了分号！

int main() {
    // 创建对象（三种方式）
    Student s1;                             // 未初始化（成员是垃圾值）
    Student s2 = {"小明", 18, 95.5};        // 聚合初始化
    Student s3{"小红", 19, 88.0};           // 列表初始化（推荐）
    Student s4 = s2;                        // 拷贝

    // 访问成员：用点号
    s1.name = "小刚";
    s1.age = 20;
    s1.score = 78.5;

    std::cout << s2.name << " " << s2.age << " " << s2.score << "\n";

    // 打印整个结构体
    std::cout << s1.name << ", " << s1.age << " 岁, " << s1.score << " 分\n";

    // 结构化绑定（C++17）：一次拿到所有成员
    auto [name, age, score] = s2;
    std::cout << name << " " << age << " " << score << "\n";

    // 结构体数组
    Student class1[3] = {
        {"张三", 18, 90.0},
        {"李四", 19, 85.5},
        {"王五", 20, 92.0}
    };

    for (const auto& stu : class1) {
        std::cout << stu.name << ": " << stu.score << "\n";
    }

    return 0;
}
```

### 结构体在内存中的布局

```cpp
struct Point {
    int x;      // 4 字节
    int y;      // 4 字节
};
// sizeof(Point) == 8
```

```
  ┌───────┬───────┐
  │   x   │   y   │
  └───────┴───────┘
   0       4       8（字节偏移）
```

### ⚠️ 内存对齐与填充（padding）

```cpp
#include <iostream>

struct A {
    char c;     // 1 字节
    int i;      // 4 字节
    char d;     // 1 字节
};

struct B {
    int i;      // 4
    char c;     // 1
    char d;     // 1
};

int main() {
    std::cout << sizeof(A) << "\n";   // 12，不是 6！
    std::cout << sizeof(B) << "\n";   // 8，不是 6！
    return 0;
}
```

**为什么？** CPU 访问对齐的内存更快。编译器会在成员之间插入"填充字节"，让每个成员都对齐到自己的大小。

```
struct A 的内存:
  [c][pad][pad][pad][i][i][i][i][d][pad][pad][pad]   = 12 字节
   0  1   2   3    4  5  6  7   8   9  10  11

struct B 的内存:
  [i][i][i][i][c][d][pad][pad]                        = 8 字节
```

**结论：把大类型放前面、小类型放后面，可以减小结构体大小。** 在存储大量结构体时（比如几百万个），这个优化很有价值。

```cpp
// 查看偏移量
#include <cstddef>
std::cout << offsetof(A, i) << "\n";    // 4
```

## 14.2 结构体与函数

```cpp
#include <iostream>
#include <string>

struct Point {
    double x, y;
};

// 按值：复制（小结构体没问题）
double distanceFromOrigin(Point p) {
    return std::sqrt(p.x * p.x + p.y * p.y);
}

// const 引用：不复制（大结构体用这个）
void printPoint(const Point& p) {
    std::cout << "(" << p.x << ", " << p.y << ")\n";
}

// 引用：修改原对象
void movePoint(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

// 返回结构体（编译器会优化，不会有额外复制）
Point makePoint(double x, double y) {
    return {x, y};
}

int main() {
    Point p{3.0, 4.0};
    printPoint(p);
    std::cout << "距离原点: " << distanceFromOrigin(p) << "\n";

    movePoint(p, 1.0, 1.0);
    printPoint(p);                          // (4, 5)

    Point q = makePoint(0, 0);
    printPoint(q);

    return 0;
}
```

> 需要 `#include <cmath>` 才能用 `std::sqrt`。

## 14.3 结构体比较

**⚠️ 结构体默认不能直接用 `==` 比较！**

```cpp
struct Point { int x, y; };

Point a{1, 2}, b{1, 2};
// if (a == b) { }     // ❌ C++17 及以前：编译错误
```

**手动实现：**

```cpp
bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const Point& lhs, const Point& rhs) {
    return !(lhs == rhs);
}
```

> **C++20 起**，可以用 `= default` 让编译器自动生成：
> ```cpp
> struct Point {
>     int x, y;
>     bool operator==(const Point&) const = default;   // C++20
> };
> ```

## 14.4 枚举 `enum`

**枚举给一组整数起名字。**

### 传统枚举（unscoped enum）

```cpp
#include <iostream>

enum Color {
    RED,        // 0
    GREEN,      // 1
    BLUE        // 2
};

enum Status {
    OK = 200,
    NOT_FOUND = 404,
    ERROR = 500
};

int main() {
    Color c = RED;
    std::cout << c << "\n";             // 0

    c = BLUE;
    std::cout << c << "\n";             // 2

    // 可以显式指定值
    Status s = NOT_FOUND;
    std::cout << s << "\n";             // 404

    // 转成 int
    int i = static_cast<int>(c);

    // ⚠️ 传统枚举的名字会"泄漏"到外层作用域
    // RED 现在在整个 main 里都可见，可能和其他名字冲突

    return 0;
}
```

### 枚举类（scoped enum，C++11，推荐）

```cpp
#include <iostream>

enum class Color {
    Red,
    Green,
    Blue
};

enum class Status : int {       // 可以指定底层类型
    Ok = 200,
    NotFound = 404
};

// 可以给枚举加函数（传统枚举不行）
const char* toString(Color c) {
    switch (c) {
        case Color::Red:   return "红色";
        case Color::Green: return "绿色";
        case Color::Blue:  return "蓝色";
    }
    return "未知";
}

int main() {
    Color c = Color::Red;           // 必须加 Color:: 前缀
    std::cout << toString(c) << "\n";

    // std::cout << c;              // ❌ 枚举类不能隐式转 int

    std::cout << static_cast<int>(c) << "\n";    // ✅ 必须显式转

    // 两个不同枚举类不会混淆
    Status s = Status::Ok;
    // if (c == s) { }              // ❌ 编译错误：类型不同

    return 0;
}
```

**⭐ 建议：新代码一律用 `enum class`。**

**为什么？**

| 问题 | 传统 enum | `enum class` |
|---|---|---|
| 名字污染 | 会泄漏到外层 | 限定在枚举内 |
| 类型安全 | 和 int 隐式互转 | 必须显式转换 |
| 两个枚举冲突 | 名字不能重复 | 可以重复（如都有 `Ok`） |
| 底层类型 | 不能指定 | 可以指定 |

### 枚举的常见用法：状态机

```cpp
#include <iostream>
#include <string>

enum class GameState {
    Menu,
    Playing,
    Paused,
    GameOver
};

int main() {
    GameState state = GameState::Menu;

    for (int frame = 0; frame < 5; frame++) {
        switch (state) {
            case GameState::Menu:
                std::cout << "[菜单] 按开始\n";
                state = GameState::Playing;
                break;
            case GameState::Playing:
                std::cout << "[游戏中] 第 " << frame << " 帧\n";
                if (frame == 2) state = GameState::Paused;
                break;
            case GameState::Paused:
                std::cout << "[暂停]\n";
                state = GameState::Playing;
                break;
            case GameState::GameOver:
                std::cout << "[结束]\n";
                break;
        }
    }
    return 0;
}
```

## 14.5 联合体 `union`

**`union` 的成员共享同一块内存**，同一时间只有一个成员有效。

```cpp
#include <iostream>
#include <cstring>

union Value {
    int i;
    float f;
    char bytes[4];
};

int main() {
    Value v;
    v.i = 0x41424344;

    std::cout << "i = " << v.i << "\n";
    std::cout << "bytes = ";
    for (int k = 0; k < 4; k++) {
        std::cout << v.bytes[k] << " ";      // 读出字节表示
    }
    std::cout << "\n";

    v.f = 3.14f;                             // 覆盖了 i
    std::cout << "f = " << v.f << "\n";
    // 现在读 v.i 是未定义行为（读的不是"活跃成员"）

    std::cout << "sizeof(Value) = " << sizeof(Value) << "\n";   // 4
    return 0;
}
```

**用途：**

- 节省内存（同一块内存多种解释）
- 类型双关（查看浮点的位表示）——但**更推荐用 `std::bit_cast`（C++20）或 `memcpy`**
- 实现 `std::variant` 的底层

**⚠️ 现代 C++ 建议：**

- 需要"多种类型之一"时，用 **`std::variant`（C++17）**，类型安全
- `union` 主要用于极底层、嵌入式、与硬件寄存器交互

```cpp
#include <iostream>
#include <variant>
#include <string>

int main() {
    std::variant<int, double, std::string> v;

    v = 42;
    std::cout << std::get<int>(v) << "\n";         // 42

    v = 3.14;
    std::cout << std::get<double>(v) << "\n";      // 3.14

    v = std::string("hello");
    std::cout << std::get<std::string>(v) << "\n";

    // 检查当前是哪个类型
    if (std::holds_alternative<std::string>(v)) {
        std::cout << "现在是 string\n";
    }

    // 访问
    std::visit([](auto&& arg) {
        std::cout << "值: " << arg << "\n";
    }, v);

    // 安全取值（失败返回默认）
    std::cout << std::get_if<int>(&v) << "\n";     // nullptr（当前不是 int）

    return 0;
}
```

## 14.6 `std::pair` 与 `std::tuple`

```cpp
#include <iostream>
#include <utility>      // pair
#include <tuple>        // tuple
#include <string>

int main() {
    // pair：两个值
    std::pair<int, std::string> p1 = {1, "one"};
    std::pair<int, std::string> p2 = std::make_pair(2, "two");

    std::cout << p1.first << " " << p1.second << "\n";     // 1 one

    // 结构化绑定（C++17）
    auto [id, name] = p2;
    std::cout << id << " " << name << "\n";                // 2 two

    // 比较（按 first 再 second）
    std::cout << std::boolalpha << (p1 < p2) << "\n";      // true

    // tuple：任意多个值
    std::tuple<int, double, std::string> t{1, 3.14, "pi"};
    std::cout << std::get<0>(t) << " "
              << std::get<1>(t) << " "
              << std::get<2>(t) << "\n";

    // 结构化绑定
    auto [a, b, c] = t;
    std::cout << a << " " << b << " " << c << "\n";

    // std::tie：把 tuple 拆到已有变量
    int x;
    double y;
    std::string z;
    std::tie(x, y, z) = t;
    std::cout << x << " " << y << " " << z << "\n";

    // 用 tuple 返回多个值
    auto divide = [](int a, int b) {
        return std::make_tuple(a / b, a % b);
    };
    auto [quotient, remainder] = divide(17, 5);
    std::cout << "商: " << quotient << ", 余: " << remainder << "\n";   // 3, 2

    return 0;
}
```

## 14.7 结构体实战：复数

```cpp
#include <iostream>
#include <cmath>

struct Complex {
    double real;
    double imag;
};

Complex add(const Complex& a, const Complex& b) {
    return {a.real + b.real, a.imag + b.imag};
}

Complex multiply(const Complex& a, const Complex& b) {
    return {a.real * b.real - a.imag * b.imag,
            a.real * b.imag + a.imag * b.real};
}

double magnitude(const Complex& c) {
    return std::sqrt(c.real * c.real + c.imag * c.imag);
}

void print(const Complex& c) {
    if (c.imag >= 0)
        std::cout << c.real << " + " << c.imag << "i";
    else
        std::cout << c.real << " - " << -c.imag << "i";
}

int main() {
    Complex a{3, 4};
    Complex b{1, -2};

    std::cout << "a = "; print(a); std::cout << "\n";
    std::cout << "b = "; print(b); std::cout << "\n";

    std::cout << "a+b = "; print(add(a, b)); std::cout << "\n";
    std::cout << "a*b = "; print(multiply(a, b)); std::cout << "\n";
    std::cout << "|a| = " << magnitude(a) << "\n";

    return 0;
}
```

## 14.8 练习

1. 定义 `struct Rectangle { double width, height; }`，写函数计算面积和周长。
2. 定义 `struct Date { int year, month, day; }`，写函数判断日期是否合法。
3. 定义 `struct Student`（含姓名、三门课成绩），写函数计算平均分，并找出平均分最高的学生。
4. 定义 `enum class Direction { Up, Down, Left, Right }`，写函数返回相反方向。
5. 用 `std::pair` 写函数同时返回数组的最大值和最小值。
6. 定义 `struct Fraction { int num, den; }`（分数），实现分数的加减乘。

**参考答案：**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <numeric>
#include <cmath>

// 练习 1
struct Rectangle {
    double width, height;
};
double area(const Rectangle& r) { return r.width * r.height; }
double perimeter(const Rectangle& r) { return 2 * (r.width + r.height); }

// 练习 2
struct Date {
    int year, month, day;
};
bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
bool isValid(const Date& d) {
    if (d.year < 1 || d.month < 1 || d.month > 12 || d.day < 1) return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[d.month - 1];
    if (d.month == 2 && isLeap(d.year)) maxDay = 29;
    return d.day <= maxDay;
}

// 练习 3
struct Student {
    std::string name;
    int scores[3];
};
double average(const Student& s) {
    return (s.scores[0] + s.scores[1] + s.scores[2]) / 3.0;
}

// 练习 4
enum class Direction { Up, Down, Left, Right };
Direction opposite(Direction d) {
    switch (d) {
        case Direction::Up:    return Direction::Down;
        case Direction::Down:  return Direction::Up;
        case Direction::Left:  return Direction::Right;
        case Direction::Right: return Direction::Left;
    }
    return Direction::Up;
}
const char* dirName(Direction d) {
    switch (d) {
        case Direction::Up:    return "上";
        case Direction::Down:  return "下";
        case Direction::Left:  return "左";
        case Direction::Right: return "右";
    }
    return "?";
}

// 练习 5
std::pair<int, int> minMax(const int* arr, int n) {
    int mn = arr[0], mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }
    return {mn, mx};
}

// 练习 6
struct Fraction {
    int num, den;
};
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
Fraction simplify(Fraction f) {
    int g = gcd(std::abs(f.num), std::abs(f.den));
    if (g == 0) return f;
    Fraction r{f.num / g, f.den / g};
    if (r.den < 0) { r.num = -r.num; r.den = -r.den; }
    return r;
}
Fraction addFrac(Fraction a, Fraction b) {
    return simplify({a.num * b.den + b.num * a.den, a.den * b.den});
}
Fraction mulFrac(Fraction a, Fraction b) {
    return simplify({a.num * b.num, a.den * b.den});
}
Fraction subFrac(Fraction a, Fraction b) {
    return simplify({a.num * b.den - b.num * a.den, a.den * b.den});
}
void printFrac(const Fraction& f) {
    std::cout << f.num << "/" << f.den;
}

int main() {
    Rectangle r{4.5, 3.0};
    std::cout << "面积: " << area(r) << ", 周长: " << perimeter(r) << "\n";

    std::cout << std::boolalpha;
    std::cout << "2024-02-29 合法? " << isValid({2024, 2, 29}) << "\n";   // true
    std::cout << "2023-02-29 合法? " << isValid({2023, 2, 29}) << "\n";   // false
    std::cout << "2024-13-01 合法? " << isValid({2024, 13, 1}) << "\n";   // false

    std::vector<Student> students = {
        {"张三", {90, 85, 88}},
        {"李四", {95, 92, 98}},
        {"王五", {70, 75, 72}}
    };
    const Student* best = &students[0];
    for (const auto& s : students) {
        std::cout << s.name << " 平均分: " << average(s) << "\n";
        if (average(s) > average(*best)) best = &s;
    }
    std::cout << "最高: " << best->name << "\n";

    std::cout << "上的反面是 " << dirName(opposite(Direction::Up)) << "\n";

    int arr[] = {5, 2, 9, 1, 7};
    auto [mn, mx] = minMax(arr, 5);
    std::cout << "最小 " << mn << ", 最大 " << mx << "\n";

    Fraction f1{1, 2}, f2{1, 3};
    std::cout << "1/2 + 1/3 = "; printFrac(addFrac(f1, f2)); std::cout << "\n";   // 5/6
    std::cout << "1/2 * 1/3 = "; printFrac(mulFrac(f1, f2)); std::cout << "\n";   // 1/6
    std::cout << "1/2 - 1/3 = "; printFrac(subFrac(f1, f2)); std::cout << "\n";   // 1/6

    return 0;
}
```

---

# 第 15 章 · 类与对象（OOP 上）

**面向对象编程（OOP）的核心思想：把"数据"和"操作数据的函数"打包在一起。**

## 15.1 从结构体到类

第 14 章的 `struct Student` 有个问题：**任何人可以随意修改 `score`**：

```cpp
Student s{"小明", 18, 95.5};
s.score = -999;        // 没人拦得住，数据被破坏了
```

**类（class）加了"访问控制"：可以规定哪些成员是私有的，只能通过你提供的函数来改。**

```cpp
#include <iostream>
#include <string>
#include <stdexcept>

class Student {
private:                          // 私有：外部不能直接访问
    std::string name_;
    int age_;
    double score_;

public:                           // 公有：外部可以访问
    // 构造函数：创建对象时自动调用
    Student(const std::string& name, int age, double score)
        : name_(name), age_(age) {
        setScore(score);          // 用 setter 保证合法性
    }

    // getter（读取器）
    std::string getName() const { return name_; }
    int getAge() const { return age_; }
    double getScore() const { return score_; }

    // setter（设置器）：可以加验证
    void setScore(double score) {
        if (score < 0 || score > 100) {
            throw std::invalid_argument("分数必须在 0-100 之间");
        }
        score_ = score;
    }

    void setAge(int age) {
        if (age < 0 || age > 150) {
            throw std::invalid_argument("年龄不合法");
        }
        age_ = age;
    }

    void introduce() const {
        std::cout << "我叫 " << name_ << "，今年 " << age_
                  << " 岁，考了 " << score_ << " 分\n";
    }
};

int main() {
    Student s("小明", 18, 95.5);
    s.introduce();

    s.setScore(88.0);            // ✅ 通过 setter 改
    s.introduce();

    try {
        s.setScore(-10);         // ❌ 被拦截
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << "\n";
    }

    // s.score_ = 100;           // ❌ 编译错误：score_ 是私有
    // s.name_ = "hacker";       // ❌ 编译错误

    return 0;
}
```

**这就是"封装"（encapsulation）：数据藏起来，只暴露安全的操作接口。**

## 15.2 `class` 与 `struct` 的唯一区别

**在 C++ 中，`class` 和 `struct` 几乎完全一样，唯一区别是默认访问权限：**

| | 默认访问权限 |
|---|---|
| `struct` | `public` |
| `class` | `private` |

```cpp
struct S {
    int x;          // 默认 public
};

class C {
    int x;          // 默认 private
};

struct S2 {
private:
    int x;          // 显式指定也可以
};

class C2 {
public:
    int x;          // 显式指定也可以
};
```

**惯例：**

- **`struct`**：纯数据聚合（POD），所有成员公开，没有复杂逻辑
- **`class`**：有封装、有不变式（invariant）、有行为的类型

## 15.3 访问修饰符

```cpp
class Example {
public:
    int a;          // 任何地方都能访问

protected:
    int b;          // 只有本类和派生类能访问（第 17 章）

private:
    int c;          // 只有本类能访问

public:
    void show() {
        a = 1;
        b = 2;
        c = 3;      // 类内部可以访问所有成员
    }
};

int main() {
    Example e;
    e.a = 10;       // ✅
    // e.b = 20;    // ❌ protected
    // e.c = 30;    // ❌ private
    e.show();
    return 0;
}
```

**注意：访问权限是"编译期"概念，只是给编译器看的规则，不影响运行时性能。** 同类的不同对象之间可以互相访问私有成员：

```cpp
class Wallet {
private:
    int money_;
public:
    Wallet(int m) : money_(m) {}

    // 同类对象可以访问彼此的私有成员
    void transferTo(Wallet& other, int amount) {
        if (amount > money_) return;
        money_ -= amount;
        other.money_ += amount;      // ✅ 合法！
    }

    int getMoney() const { return money_; }
};

int main() {
    Wallet a(100), b(0);
    a.transferTo(b, 30);
    std::cout << a.getMoney() << " " << b.getMoney() << "\n";   // 70 30
    return 0;
}
```

## 15.4 成员函数与 `const`

**`const` 成员函数：承诺"我不修改对象"。**

```cpp
#include <iostream>

class Counter {
private:
    int count_;

public:
    Counter() : count_(0) {}

    void increment() {          // 非 const：可以修改
        count_++;
    }

    int getCount() const {      // const：承诺不修改
        // count_++;            // ❌ 编译错误
        return count_;
    }

    // ⚠️ const 和非 const 可以构成重载！
    int& getRef()             { return count_; }
    const int& getRef() const { return count_; }
};

int main() {
    Counter c;
    c.increment();
    std::cout << c.getCount() << "\n";   // 1

    const Counter cc;            // const 对象
    // cc.increment();           // ❌ 不能在 const 对象上调用非 const 成员函数
    std::cout << cc.getCount() << "\n";  // ✅ 可以调用 const 成员函数

    return 0;
}
```

**⭐ 规则：所有不修改对象的成员函数都应该标记为 `const`。**

原因：

1. 让 const 对象可用
2. 自我文档化
3. 编译器能帮你发现意外修改
4. 便于别人理解代码

**判断标准：这个函数会改成员变量吗？不会 → 加 `const`。**

## 15.5 构造函数详解

### 默认构造函数

**不接收参数的构造函数。** 如果你一个构造函数都没写，编译器会自动生成一个。

```cpp
#include <iostream>

class A {
public:
    int x;
    // 编译器自动生成 A() {} —— 但不初始化 x！
};

class B {
public:
    int x;
    B() : x(0) {}       // 手写默认构造函数
};

class C {
public:
    int x = 42;         // 成员初始化器（C++11），简单又安全
};

int main() {
    A a;
    std::cout << a.x << "\n";    // ⚠️ 垃圾值

    B b;
    std::cout << b.x << "\n";    // 0

    C c;
    std::cout << c.x << "\n";    // 42

    // 值初始化：加括号会清零
    A a2{};
    std::cout << a2.x << "\n";   // 0

    return 0;
}
```

> **⚠️ 一旦你写了任何构造函数，编译器就不再生成默认构造函数了：**

```cpp
class D {
public:
    int x;
    D(int v) : x(v) {}      // 写了这个
};

// D d;                     // ❌ 编译错误：没有默认构造函数
D d2(10);                   // ✅
D d3{10};                   // ✅

// 需要默认构造函数的话：
class E {
public:
    int x;
    E() : x(0) {}           // 显式写一个
    E(int v) : x(v) {}
    // 或者：E() = default;  // C++11，让编译器生成
};
```

### 成员初始化列表（必须掌握）

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name_;
    int age_;
    const int id_;              // const 成员
    int& ref_;                  // 引用成员

public:
    // ✅ 初始化列表：在进入函数体之前完成初始化
    Person(const std::string& name, int age, int id, int& r)
        : name_(name),          // 顺序应与声明顺序一致
          age_(age),
          id_(id),              // const 成员必须在这里初始化
          ref_(r)               // 引用成员必须在这里初始化
    {
        // 函数体里就是"赋值"，不是"初始化"了
    }

    void show() const {
        std::cout << name_ << " " << age_ << " " << id_ << " " << ref_ << "\n";
    }
};

int main() {
    int external = 100;
    Person p("小明", 18, 1001, external);
    p.show();
    return 0;
}
```

**⚠️ 初始化顺序由"成员声明顺序"决定，不是初始化列表的书写顺序！**

```cpp
class Bad {
    int a_;
    int b_;
public:
    // ⚠️ 危险：列表里 b_ 先写，但实际按声明顺序 a_ 先初始化
    Bad(int v) : b_(v), a_(b_ + 1) { }
    // a_ 先用 b_（此时 b_ 还没初始化！）
    void show() const { std::cout << a_ << " " << b_ << "\n"; }
};
```

**`-Wall` 会警告：`warning: 'Bad::a_' will be initialized after 'Bad::b_'`。看到就按声明顺序改写。**

**什么时候必须用初始化列表？**

1. `const` 成员
2. 引用成员
3. 没有默认构造函数的成员对象
4. 基类（第 17 章）

**最佳实践：所有成员都在初始化列表里初始化，函数体留空。**

### `explicit`：防止意外的隐式转换

```cpp
#include <iostream>

class Meters {
private:
    double value_;
public:
    // ⚠️ 不加 explicit：double 可以隐式转成 Meters
    Meters(double v) : value_(v) {}

    double value() const { return value_; }
};

class Kilometers {
private:
    double value_;
public:
    // ✅ 加 explicit：必须显式构造
    explicit Kilometers(double v) : value_(v) {}

    double value() const { return value_; }
};

void printMeters(Meters m) {
    std::cout << m.value() << " m\n";
}

void printKm(Kilometers k) {
    std::cout << k.value() << " km\n";
}

int main() {
    printMeters(5.0);              // ⚠️ 编译通过！5.0 被隐式转成 Meters(5.0)
    printMeters(Meters(5.0));      // ✅ 明确

    // printKm(5.0);               // ❌ 编译错误：explicit 阻止了隐式转换
    printKm(Kilometers(5.0));      // ✅ 必须显式

    return 0;
}
```

**⭐ 规则：单参数构造函数一律加 `explicit`，除非你确实想要隐式转换。**

## 15.6 委托构造函数（C++11）

**一个构造函数可以调用同类的另一个构造函数，避免重复代码。**

```cpp
#include <iostream>
#include <string>

class Student {
private:
    std::string name_;
    int age_;
    double score_;

public:
    // 主构造函数：所有初始化逻辑都在这里
    Student(const std::string& name, int age, double score)
        : name_(name), age_(age), score_(score) {
        std::cout << "创建学生: " << name_ << "\n";
    }

    // 委托：调用上面的主构造函数
    Student(const std::string& name) : Student(name, 0, 0.0) {}

    Student() : Student("未知", 0, 0.0) {}

    void show() const {
        std::cout << name_ << " " << age_ << " " << score_ << "\n";
    }
};

int main() {
    Student s1("小明", 18, 95.5);
    Student s2("小红");
    Student s3;
    s1.show();
    s2.show();
    s3.show();
    return 0;
}
```

## 15.7 类内成员初始化（C++11）

```cpp
#include <iostream>
#include <string>
#include <vector>

class Config {
private:
    int timeout_ = 30;                      // 默认值
    std::string name_ = "default";
    bool verbose_ = false;
    std::vector<int> data_ = {1, 2, 3};

public:
    Config() = default;                     // 使用类内默认值

    Config(int timeout) : timeout_(timeout) {}   // 覆盖 timeout_，其他用默认

    void show() const {
        std::cout << timeout_ << " " << name_ << " "
                  << verbose_ << " " << data_.size() << "\n";
    }
};

int main() {
    Config c1;
    c1.show();          // 30 default 0 3

    Config c2(60);
    c2.show();          // 60 default 0 3
    return 0;
}
```

**这比在构造函数里写一堆初始化清爽多了。**

## 15.8 `this` 指针

**每个非静态成员函数都有一个隐藏参数 `this`，指向调用它的那个对象。**

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name_;

public:
    Person(const std::string& name) {
        // this->name_ 指的是"这个对象的 name_"
        this->name_ = name;
    }

    // 返回自身引用，支持链式调用
    Person& setName(const std::string& name) {
        name_ = name;
        return *this;               // 返回当前对象
    }

    Person& setAge(int) { return *this; }

    void show() const {
        std::cout << name_ << "\n";
    }

    // 用 this 和参数名区分
    void compare(const std::string& name) {
        if (this->name_ == name) {
            std::cout << "同名\n";
        }
    }
};

int main() {
    Person p("小明");
    p.setName("小红").setAge(20).show();    // 链式调用

    // 成员名带下划线时，其实不太需要 this->
    // 但如果参数名和成员名一样，就必须用 this->
    return 0;
}
```

## 15.9 友元 `friend`

**`friend` 允许某个外部函数/类访问私有成员。**

```cpp
#include <iostream>

class Point {
private:
    double x_, y_;

public:
    Point(double x, double y) : x_(x), y_(y) {}

    // 声明友元函数
    friend double distance(const Point& a, const Point& b);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    // getter（如果不想用 friend 就用这个）
    double x() const { return x_; }
    double y() const { return y_; }
};

// 友元函数：可以访问私有成员
double distance(const Point& a, const Point& b) {
    double dx = a.x_ - b.x_;        // ✅ 能访问私有
    double dy = a.y_ - b.y_;
    return dx * dx + dy * dy;
}

// 重载 << 运算符（第 16 章会讲，这里先感受一下）
std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x_ << ", " << p.y_ << ")";
}

int main() {
    Point a(0, 0), b(3, 4);
    std::cout << "距离平方: " << distance(a, b) << "\n";   // 25
    std::cout << "a = " << a << ", b = " << b << "\n";     // (0,0) (3,4)
    return 0;
}
```

**注意：`friend` 是"我给你特权"，而不是"我抢你的权限"。它必须由类自己声明。**

**⭐ 建议：尽量少用 `friend`。** 优先提供 getter，只在运算符重载（`<<`、`+` 等）和紧密协作的类之间使用。

## 15.10 一个完整的类：银行账户

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

class BankAccount {
private:
    std::string owner_;
    std::string accountNumber_;
    double balance_;
    std::vector<std::string> history_;

    void record(const std::string& action) {
        history_.push_back(action);
    }

public:
    // 构造函数
    BankAccount(const std::string& owner, const std::string& number, double initial = 0.0)
        : owner_(owner), accountNumber_(number), balance_(0.0)
    {
        if (initial < 0) {
            throw std::invalid_argument("初始存款不能为负");
        }
        balance_ = initial;
        record("开户，存入 " + std::to_string(initial));
    }

    // 存钱
    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("存款金额必须为正");
        }
        balance_ += amount;
        record("存入 " + std::to_string(amount));
    }

    // 取钱
    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("取款金额必须为正");
        }
        if (amount > balance_) {
            throw std::runtime_error("余额不足");
        }
        balance_ -= amount;
        record("取出 " + std::to_string(amount));
    }

    // 转账
    void transferTo(BankAccount& target, double amount) {
        withdraw(amount);
        target.deposit(amount);
        record("转出 " + std::to_string(amount) + " 到 " + target.accountNumber_);
    }

    // 只读访问
    double balance() const { return balance_; }
    const std::string& owner() const { return owner_; }
    const std::string& accountNumber() const { return accountNumber_; }

    void printStatement() const {
        std::cout << "\n===== 账户流水 =====\n";
        std::cout << "户主: " << owner_ << "\n";
        std::cout << "账号: " << accountNumber_ << "\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "余额: " << balance_ << "\n";
        std::cout << "--- 交易记录 ---\n";
        for (const auto& h : history_) {
            std::cout << "  " << h << "\n";
        }
    }
};

int main() {
    try {
        BankAccount alice("Alice", "A001", 1000.0);
        BankAccount bob("Bob", "B001", 500.0);

        alice.deposit(200.0);
        alice.withdraw(150.0);
        alice.transferTo(bob, 300.0);

        alice.printStatement();
        bob.printStatement();

        // 试试非法操作
        alice.withdraw(999999.0);
    } catch (const std::exception& e) {
        std::cout << "\n错误: " << e.what() << "\n";
    }

    return 0;
}
```

**这个例子体现了 OOP 的核心价值：`balance_` 无法被外部直接改成负数或任意值，所有修改都经过验证。**

## 15.11 练习

1. 写一个 `Circle` 类，有私有半径，提供 `setRadius`（校验 > 0）、`getArea`、`getCircumference`。
2. 写一个 `Counter` 类，支持 `increment`、`decrement`、`reset`、`getValue`，最小值 0。
3. 写一个 `Stack` 类（用 `std::vector` 实现），支持 `push`、`pop`、`top`、`isEmpty`、`size`。
4. 写一个 `Temperature` 类，内部用摄氏度存储，提供 `getCelsius`、`getFahrenheit`、`setFahrenheit`。
5. 写一个 `Fraction` 类（分数），支持加减乘除、化简、输出。

**参考答案：**

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <numeric>

// 练习 1
class Circle {
private:
    static constexpr double kPi = 3.14159265358979323846;
    double radius_;
public:
    explicit Circle(double r) : radius_(1.0) { setRadius(r); }

    void setRadius(double r) {
        if (r <= 0) throw std::invalid_argument("半径必须为正");
        radius_ = r;
    }
    double getRadius() const { return radius_; }
    double getArea() const { return kPi * radius_ * radius_; }
    double getCircumference() const { return 2 * kPi * radius_; }
};

// 练习 2
class Counter {
private:
    int value_ = 0;
public:
    void increment() { value_++; }
    void decrement() { if (value_ > 0) value_--; }
    void reset() { value_ = 0; }
    int getValue() const { return value_; }
};

// 练习 3
class Stack {
private:
    std::vector<int> data_;
public:
    void push(int v) { data_.push_back(v); }

    int pop() {
        if (data_.empty()) throw std::runtime_error("栈为空");
        int v = data_.back();
        data_.pop_back();
        return v;
    }

    int top() const {
        if (data_.empty()) throw std::runtime_error("栈为空");
        return data_.back();
    }

    bool isEmpty() const { return data_.empty(); }
    std::size_t size() const { return data_.size(); }
};

// 练习 4
class Temperature {
private:
    double celsius_;
public:
    explicit Temperature(double c = 0.0) : celsius_(c) {}

    double getCelsius() const { return celsius_; }
    double getFahrenheit() const { return celsius_ * 9.0 / 5.0 + 32.0; }

    void setCelsius(double c) { celsius_ = c; }
    void setFahrenheit(double f) { celsius_ = (f - 32.0) * 5.0 / 9.0; }
};

// 练习 5
class Fraction {
private:
    int num_, den_;
    void simplify() {
        if (den_ == 0) throw std::invalid_argument("分母不能为 0");
        int g = std::gcd(std::abs(num_), std::abs(den_));
        if (g != 0) { num_ /= g; den_ /= g; }
        if (den_ < 0) { num_ = -num_; den_ = -den_; }
    }
public:
    Fraction(int n = 0, int d = 1) : num_(n), den_(d) { simplify(); }

    Fraction operator+(const Fraction& o) const {
        return Fraction(num_ * o.den_ + o.num_ * den_, den_ * o.den_);
    }
    Fraction operator-(const Fraction& o) const {
        return Fraction(num_ * o.den_ - o.num_ * den_, den_ * o.den_);
    }
    Fraction operator*(const Fraction& o) const {
        return Fraction(num_ * o.num_, den_ * o.den_);
    }
    Fraction operator/(const Fraction& o) const {
        if (o.num_ == 0) throw std::runtime_error("除以零");
        return Fraction(num_ * o.den_, den_ * o.num_);
    }

    void print() const { std::cout << num_ << "/" << den_; }
    double value() const { return static_cast<double>(num_) / den_; }
};

int main() {
    Circle c(5.0);
    std::cout << "面积: " << c.getArea() << ", 周长: " << c.getCircumference() << "\n";

    Counter cnt;
    cnt.increment(); cnt.increment(); cnt.increment();
    cnt.decrement();
    std::cout << "计数: " << cnt.getValue() << "\n";   // 2

    Stack st;
    st.push(1); st.push(2); st.push(3);
    std::cout << "栈顶: " << st.top() << ", 大小: " << st.size() << "\n";
    st.pop();
    std::cout << "弹出后栈顶: " << st.top() << "\n";

    Temperature t;
    t.setFahrenheit(212.0);
    std::cout << "212°F = " << t.getCelsius() << "°C\n";   // 100

    Fraction a(1, 2), b(1, 3);
    std::cout << "1/2 + 1/3 = "; (a + b).print(); std::cout << "\n";
    std::cout << "1/2 * 1/3 = "; (a * b).print(); std::cout << "\n";
    std::cout << "1/2 / 1/3 = "; (a / b).print(); std::cout << "\n";
    std::cout << "值: " << (a / b).value() << "\n";

    return 0;
}
```

---


# 第 16 章 · 构造函数、析构函数与运算符重载（OOP 中）

## 16.1 析构函数

**析构函数在对象销毁时自动调用**，用来清理资源。

```cpp
#include <iostream>
#include <string>

class Resource {
private:
    std::string name_;
    int* data_;

public:
    Resource(const std::string& name, int size)
        : name_(name), data_(new int[size])
    {
        std::cout << "构造: " << name_ << "\n";
    }

    ~Resource() {                       // 析构函数：名字是 ~类名
        delete[] data_;                 // 释放内存
        std::cout << "析构: " << name_ << "\n";
    }
};

int main() {
    std::cout << "--- 进入 main ---\n";
    {
        Resource r("A", 10);
        std::cout << "--- 块内 ---\n";
    }                                    // 离开作用域，析构自动调用
    std::cout << "--- 离开块 ---\n";

    Resource r2("B", 20);
    std::cout << "--- main 结束前 ---\n";
    return 0;                            // r2 在这里析构
}
```

**输出：**

```
--- 进入 main ---
构造: A
--- 块内 ---
析构: A
--- 离开块 ---
构造: B
--- main 结束前 ---
析构: B
```

**析构函数的规则：**

1. 名字是 `~类名`
2. **没有参数，没有返回值**
3. 一个类**只能有一个**析构函数
4. 不能重载
5. 不需要手动调用（自动调用），也不能手动调用（除非用 placement new 的罕见场景）
6. 如果没有资源需要释放，可以不写（编译器生成空的）

**这就是 C++ 最重要的机制：RAII（Resource Acquisition Is Initialization）——资源在构造时获取，在析构时释放。**

**RAII 的威力**：即使发生异常、提前 return、`break`，析构函数也一定会被调用。这让 C++ 的资源管理非常可靠。

```cpp
#include <iostream>
#include <fstream>
#include <stdexcept>

void processFile() {
    std::ofstream file("data.txt");       // 构造：打开文件
    file << "一些数据\n";

    if (true) {
        throw std::runtime_error("出错了！");
    }

    // 即使上面抛异常，file 的析构函数也会被调用，文件会被正确关闭
}   // ← file 析构，自动关闭文件
```

## 16.2 拷贝构造函数

**用同类型的另一个对象来创建新对象时调用。**

```cpp
#include <iostream>

class MyString {
private:
    char* data_;
    int length_;

public:
    MyString(const char* s) {
        length_ = std::strlen(s);
        data_ = new char[length_ + 1];
        std::strcpy(data_, s);
        std::cout << "普通构造: " << data_ << "\n";
    }

    // 拷贝构造函数
    MyString(const MyString& other) {
        length_ = other.length_;
        data_ = new char[length_ + 1];       // 分配新内存（深拷贝）
        std::strcpy(data_, other.data_);
        std::cout << "拷贝构造: " << data_ << "\n";
    }

    ~MyString() {
        delete[] data_;
    }

    const char* c_str() const { return data_; }
};

int main() {
    MyString a("Hello");
    MyString b = a;          // 拷贝构造
    MyString c(a);           // 也是拷贝构造
    std::cout << b.c_str() << " " << c.c_str() << "\n";
    return 0;
}
```

**什么时候调用拷贝构造？**

```cpp
MyString a("x");
MyString b = a;            // 1. 直接初始化
MyString c(a);             // 2. 括号初始化
void f(MyString s);        // 3. 按值传参时
f(a);
MyString g() { return a; } // 4. 按值返回时（编译器通常会优化掉）
```

### ⚠️ 浅拷贝 vs 深拷贝（核心概念）

**默认拷贝构造函数做的是"浅拷贝"——逐个成员复制。对指针来说，复制的是地址，不是指向的内容！**

```cpp
#include <iostream>
#include <cstring>

class BadString {
private:
    char* data_;
public:
    BadString(const char* s) {
        data_ = new char[std::strlen(s) + 1];
        std::strcpy(data_, s);
    }
    // 没有写拷贝构造 → 编译器生成"浅拷贝"
    ~BadString() { delete[] data_; }

    const char* c_str() const { return data_; }
};

int main() {
    BadString a("Hello");
    BadString b = a;         // ⚠️ 浅拷贝：b.data_ 和 a.data_ 指向同一块内存！

    std::cout << a.c_str() << " " << b.c_str() << "\n";

    return 0;
    // 💥 main 结束时：
    //    b 先析构 → delete[] data_
    //    a 后析构 → delete[] 同一块内存 → 双重释放（double free）→ 崩溃！
}
```

**内存图：**

```
浅拷贝（错误）:
   a.data_ ──┐
             ├──→ [H][e][l][l][o][\0]
   b.data_ ──┘
   ↑ 两个指针指向同一块内存，析构时释放两次

深拷贝（正确）:
   a.data_ ──→ [H][e][l][l][o][\0]
   b.data_ ──→ [H][e][l][l][o][\0]
   ↑ 各自独立，互不影响
```

**所以：如果类里有指针成员并管理着动态内存，你必须自己写拷贝构造函数做深拷贝。**

## 16.3 拷贝赋值运算符

```cpp
#include <iostream>
#include <cstring>

class MyString {
private:
    char* data_;
    int length_;

public:
    MyString(const char* s = "") {
        length_ = std::strlen(s);
        data_ = new char[length_ + 1];
        std::strcpy(data_, s);
    }

    // 拷贝构造
    MyString(const MyString& other) {
        length_ = other.length_;
        data_ = new char[length_ + 1];
        std::strcpy(data_, other.data_);
    }

    // 拷贝赋值运算符
    MyString& operator=(const MyString& other) {
        std::cout << "拷贝赋值\n";

        if (this == &other) {          // 1. 自我赋值检查（重要！）
            return *this;
        }

        delete[] data_;                // 2. 释放旧资源
        length_ = other.length_;       // 3. 分配新资源
        data_ = new char[length_ + 1];
        std::strcpy(data_, other.data_);

        return *this;                  // 4. 返回自身引用（支持链式赋值）
    }

    ~MyString() { delete[] data_; }

    const char* c_str() const { return data_; }
};

int main() {
    MyString a("Hello");
    MyString b("World");
    MyString c("X");

    b = a;              // 拷贝赋值
    std::cout << b.c_str() << "\n";   // Hello

    c = b = a;          // 链式赋值
    std::cout << c.c_str() << "\n";   // Hello

    a = a;              // 自我赋值（没有检查会崩溃！）
    std::cout << a.c_str() << "\n";
    return 0;
}
```

**⚠️ 为什么自我赋值检查是必须的？**

如果没有 `if (this == &other) return *this;`：

```
a = a;   →   delete[] data_;    // 释放了 a 的内存
             data_ = new ...;   // 重新分配
             strcpy(data_, other.data_);   // other 就是 a！
             // 但此时 other.data_ 已经被 delete 了  →  未定义行为
```

## 16.4 三法则 / 五法则 / 零法则

### 三法则（Rule of Three，C++98）

**如果你需要自定义析构函数、拷贝构造函数、拷贝赋值运算符中的任何一个，那么你三个都需要。**

因为它们总是"同时需要"：管理资源的类需要析构释放、拷贝构造深拷贝、拷贝赋值深拷贝。

### 五法则（Rule of Five，C++11）

加上移动构造和移动赋值（第 23 章）：

```cpp
class Resource {
public:
    Resource();                                  // 构造函数
    ~Resource();                                 // 1. 析构
    Resource(const Resource&);                   // 2. 拷贝构造
    Resource& operator=(const Resource&);        // 3. 拷贝赋值
    Resource(Resource&&) noexcept;               // 4. 移动构造（C++11）
    Resource& operator=(Resource&&) noexcept;    // 5. 移动赋值（C++11）
};
```

### ⭐ 零法则（Rule of Zero，现代 C++ 推荐）

**最好的做法：不要自己管理资源，用标准库的容器和智能指针，这样五个函数一个都不用写。**

```cpp
// ❌ 手写资源管理：要写 5 个特殊成员函数，还容易写错
class BadBuffer {
    int* data_;
public:
    BadBuffer(int size) : data_(new int[size]) {}
    ~BadBuffer() { delete[] data_; }
    BadBuffer(const BadBuffer& o) : data_(new int[o.size_]) { /* ... */ }
    // ... 还要写拷贝赋值、移动构造、移动赋值
};

// ✅ 零法则：用 vector，编译器生成的默认版本全都正确
class GoodBuffer {
    std::vector<int> data_;
public:
    explicit GoodBuffer(int size) : data_(size) {}
    // 不用写析构、拷贝、移动！编译器生成的全都对
};

// ✅ 用智能指针管理单个对象
#include <memory>
class GoodHolder {
    std::unique_ptr<int[]> data_;
public:
    explicit GoodHolder(int size) : data_(std::make_unique<int[]>(size)) {}
    // 同样什么都不用写
};
```

**⭐ 记住零法则：优先用 `std::vector`、`std::string`、`std::unique_ptr`、`std::shared_ptr`，你就永远不用手写析构/拷贝/移动。**

## 16.5 运算符重载

**让自定义类型也能用 `+`、`==`、`<<` 等运算符。**

```cpp
#include <iostream>

class Vector2D {
private:
    double x_, y_;

public:
    Vector2D(double x = 0, double y = 0) : x_(x), y_(y) {}

    // 成员函数形式的 + 
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x_ - other.x_, y_ - other.y_);
    }

    // 数乘
    Vector2D operator*(double scalar) const {
        return Vector2D(x_ * scalar, y_ * scalar);
    }

    // += （返回引用以支持链式）
    Vector2D& operator+=(const Vector2D& other) {
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    }

    // 取负
    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

    // 比较
    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    // 下标访问
    double operator[](int index) const {
        if (index == 0) return x_;
        if (index == 1) return y_;
        throw std::out_of_range("索引必须是 0 或 1");
    }

    // 函数调用运算符（让对象像函数一样用）
    double operator()() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    double x() const { return x_; }
    double y() const { return y_; }

    // 友元：输出运算符
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
};

// << 必须是全局函数（左操作数是 ostream）
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    return os << "(" << v.x_ << ", " << v.y_ << ")";
}

int main() {
    Vector2D a(1, 2), b(3, 4);

    std::cout << "a = " << a << "\n";              // (1, 2)
    std::cout << "a + b = " << a + b << "\n";      // (4, 6)
    std::cout << "a - b = " << a - b << "\n";      // (-2, -2)
    std::cout << "a * 3 = " << a * 3 << "\n";      // (3, 6)
    std::cout << "-a = " << -a << "\n";            // (-1, -2)

    Vector2D c = a;
    c += b;
    std::cout << "c = " << c << "\n";              // (4, 6)

    std::cout << "a == a? " << std::boolalpha << (a == a) << "\n";
    std::cout << "a.x = " << a[0] << ", a.y = " << a[1] << "\n";
    std::cout << "|a| = " << a() << "\n";          // 2.23607

    return 0;
}
```

## 16.6 哪些运算符可以重载

| 可以重载 | 不能重载 |
|---|---|
| `+ - * / % ^ & \| ~ !` | `::`（作用域） |
| `= < > += -= *= /=` | `.`（成员访问） |
| `<< >> >>= <<= == !=` | `.*`（成员指针） |
| `<= >= ++ -- && \|\|` | `?:`（三元） |
| `, -> ->* () []` | `sizeof` |
| `new delete new[] delete[]` | `typeid` |

## 16.7 成员函数 vs 全局函数

| 运算符 | 推荐形式 | 原因 |
|---|---|---|
| `= [] () ->` | **必须是成员** | 语言规定 |
| `+= -= *= /=` | 成员 | 修改左操作数 |
| `+ - * /` | 两者皆可（常见全局） | 支持 `2 + obj` 的写法 |
| `== != < >` | 两者皆可 | — |
| `<< >>` | **必须是全局** | 左操作数是 `ostream`/`istream` |
| `++ --` | 成员 | — |

**为什么 `+` 建议用全局？**

```cpp
class Complex { /* ... */ };

// 成员版本：a + 3 可以，但 3 + a 不行（3 是 int，没有 operator+）
Complex Complex::operator+(double d) const;

// 全局版本：两种都能用
Complex operator+(const Complex& c, double d);
Complex operator+(double d, const Complex& c);
```

> **C++20 起**，可以用 `operator<=>`（三路比较，即"飞船运算符"），一次定义 `== < > <= >=` 全部：

```cpp
// C++20
struct Point {
    int x, y;
    auto operator<=>(const Point&) const = default;   // 自动生成所有比较
};
```

## 16.8 完整的 `String` 类实现（五法则实战）

```cpp
#include <iostream>
#include <cstring>
#include <utility>

class MyString {
private:
    char* data_;
    std::size_t size_;

public:
    // 1) 普通构造函数
    MyString(const char* s = "") : data_(nullptr), size_(0) {
        size_ = std::strlen(s);
        data_ = new char[size_ + 1];
        std::strcpy(data_, s);
    }

    // 2) 析构函数
    ~MyString() {
        delete[] data_;
    }

    // 3) 拷贝构造函数（深拷贝）
    MyString(const MyString& other) : data_(nullptr), size_(other.size_) {
        data_ = new char[size_ + 1];
        std::strcpy(data_, other.data_);
    }

    // 4) 拷贝赋值
    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;      // 自我赋值检查
        MyString temp(other);                   // 拷贝构造（copy-and-swap 技巧）
        swap(temp);
        return *this;
    }

    // 5) 移动构造函数
    MyString(MyString&& other) noexcept
        : data_(other.data_), size_(other.size_)
    {
        other.data_ = nullptr;                  // 把源对象置空
        other.size_ = 0;
    }

    // 6) 移动赋值
    MyString& operator=(MyString&& other) noexcept {
        if (this == &other) return *this;
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
        return *this;
    }

    void swap(MyString& other) noexcept {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
    }

    // 访问
    const char* c_str() const { return data_ ? data_ : ""; }
    std::size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    char& operator[](std::size_t i) { return data_[i]; }
    const char& operator[](std::size_t i) const { return data_[i]; }

    // 拼接
    MyString operator+(const MyString& other) const {
        MyString result;
        delete[] result.data_;
        result.size_ = size_ + other.size_;
        result.data_ = new char[result.size_ + 1];
        std::strcpy(result.data_, data_);
        std::strcat(result.data_, other.data_);
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& s) {
        return os << s.c_str();
    }
};

int main() {
    MyString a("Hello");
    MyString b(" World");
    MyString c = a + b;
    std::cout << c << " (长度 " << c.size() << ")\n";

    MyString d = c;                    // 拷贝构造
    std::cout << d << "\n";

    MyString e;
    e = a;                             // 拷贝赋值
    std::cout << e << "\n";

    MyString f = std::move(d);         // 移动构造
    std::cout << f << "\n";
    std::cout << "移动后 d.size() = " << d.size() << "\n";   // 0

    return 0;
}
```

> 这个类是为了教学。**实际项目里直接用 `std::string`**，它比上面这个更快、更全、更安全。

## 16.9 练习

1. 给第 15 章的 `Fraction` 类加上运算符重载：`+ - * / == != < <<`。
2. 写一个 `DynamicArray` 类，内部用 `new[]` 管理数组，正确实现析构、拷贝构造、拷贝赋值。
3. 写一个 `Date` 类，重载 `++`（后一天）、`-`（两个日期相差天数）、`<<`。
4. 写一个 `Matrix` 类（2x2 矩阵），重载 `+ - *` 和 `<<`。

**参考答案（第 1 题）：**

```cpp
#include <iostream>
#include <numeric>
#include <cmath>
#include <stdexcept>

class Fraction {
private:
    long long num_, den_;

    void normalize() {
        if (den_ == 0) throw std::invalid_argument("分母不能为 0");
        if (den_ < 0) { num_ = -num_; den_ = -den_; }
        long long g = std::gcd(std::abs(num_), den_);
        if (g > 1) { num_ /= g; den_ /= g; }
    }

public:
    Fraction(long long n = 0, long long d = 1) : num_(n), den_(d) { normalize(); }

    long long num() const { return num_; }
    long long den() const { return den_; }
    double value() const { return static_cast<double>(num_) / den_; }

    Fraction operator+(const Fraction& o) const {
        return Fraction(num_ * o.den_ + o.num_ * den_, den_ * o.den_);
    }
    Fraction operator-(const Fraction& o) const {
        return Fraction(num_ * o.den_ - o.num_ * den_, den_ * o.den_);
    }
    Fraction operator*(const Fraction& o) const {
        return Fraction(num_ * o.num_, den_ * o.den_);
    }
    Fraction operator/(const Fraction& o) const {
        if (o.num_ == 0) throw std::runtime_error("除以零");
        return Fraction(num_ * o.den_, den_ * o.num_);
    }
    Fraction operator-() const { return Fraction(-num_, den_); }

    bool operator==(const Fraction& o) const { return num_ == o.num_ && den_ == o.den_; }
    bool operator!=(const Fraction& o) const { return !(*this == o); }
    bool operator<(const Fraction& o) const { return num_ * o.den_ < o.num_ * den_; }
    bool operator>(const Fraction& o) const { return o < *this; }
    bool operator<=(const Fraction& o) const { return !(o < *this); }
    bool operator>=(const Fraction& o) const { return !(*this < o); }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        if (f.den_ == 1) return os << f.num_;
        return os << f.num_ << "/" << f.den_;
    }
};

int main() {
    Fraction a(1, 2), b(1, 3), c(2, 4);

    std::cout << a << " + " << b << " = " << a + b << "\n";    // 5/6
    std::cout << a << " - " << b << " = " << a - b << "\n";    // 1/6
    std::cout << a << " * " << b << " = " << a * b << "\n";    // 1/6
    std::cout << a << " / " << b << " = " << a / b << "\n";    // 3/2
    std::cout << "-" << a << " = " << -a << "\n";              // -1/2

    std::cout << std::boolalpha;
    std::cout << a << " == " << c << " ? " << (a == c) << "\n";   // true（自动化简）
    std::cout << a << " < " << b << " ? " << (a < b) << "\n";     // false
    std::cout << b << " < " << a << " ? " << (b < a) << "\n";     // true

    return 0;
}
```

---

# 第 17 章 · 继承、虚函数与多态（OOP 下）

## 17.1 什么是继承？

**继承让一个类（派生类）自动拥有另一个类（基类）的成员。**

```cpp
#include <iostream>
#include <string>

// 基类（父类）
class Animal {
public:
    std::string name;

    void eat() const {
        std::cout << name << " 在吃东西\n";
    }

    void sleep() const {
        std::cout << name << " 在睡觉\n";
    }
};

// 派生类（子类）：继承 Animal
class Dog : public Animal {
public:
    void bark() const {
        std::cout << name << " 汪汪叫\n";       // 直接用了基类的 name
    }
};

int main() {
    Dog d;
    d.name = "旺财";        // 继承来的成员
    d.eat();                // 继承来的方法
    d.sleep();
    d.bark();               // 自己的方法

    return 0;
}
```

**关系：`Dog` **是一种** `Animal`（is-a 关系）。**

## 17.2 三种继承方式

```cpp
class Base { public: int a; protected: int b; private: int c; };

class D1 : public Base { };      // public 继承（最常用）
class D2 : protected Base { };
class D3 : private Base { };
```

| 继承方式 | 基类 public 成员 | 基类 protected 成员 | 基类 private 成员 |
|---|---|---|---|
| `public` | public | protected | **不可访问** |
| `protected` | protected | protected | **不可访问** |
| `private` | private | private | **不可访问** |

**⭐ 99% 的情况用 `public` 继承。** `private`/`protected` 继承是很罕见的技巧（用于"用继承实现组合"）。

**基类的 `private` 成员永远不能被派生类直接访问**，只能通过基类的 public/protected 函数访问。

```cpp
class Base {
private:
    int secret_ = 42;
protected:
    int shared_ = 10;
public:
    int open_ = 1;
    int getSecret() const { return secret_; }
};

class Derived : public Base {
public:
    void test() {
        // secret_ = 1;         // ❌ private，不可访问
        shared_ = 2;            // ✅ protected，可访问
        open_ = 3;              // ✅ public
        std::cout << getSecret() << "\n";   // ✅ 通过公有接口
    }
};
```

## 17.3 构造与析构顺序

```cpp
#include <iostream>

class Base {
public:
    Base()  { std::cout << "1. Base 构造\n"; }
    ~Base() { std::cout << "4. Base 析构\n"; }
};

class Member {
public:
    Member()  { std::cout << "2. Member 构造\n"; }
    ~Member() { std::cout << "3. Member 析构\n"; }
};

class Derived : public Base {
private:
    Member m_;              // 派生类的成员
public:
    Derived()  { std::cout << "   Derived 构造体\n"; }
    ~Derived() { std::cout << "   Derived 析构体\n"; }
};

int main() {
    std::cout << "--- 创建 Derived ---\n";
    Derived d;
    std::cout << "--- main 结束 ---\n";
    return 0;
}
```

**输出：**

```
--- 创建 Derived ---
1. Base 构造          ← 先基类
2. Member 构造        ← 再成员
   Derived 构造体     ← 最后自己的构造体
--- main 结束 ---
   Derived 析构体
3. Member 析构        ← 顺序完全相反
4. Base 析构
```

**记忆：构造从里到外（基类→成员→自己），析构从外到里（自己→成员→基类）。**

> 这就像盖房子和拆房子：先打地基（基类），再建墙（成员），最后装修（自己）；拆的时候反过来。

### 调用基类构造函数

```cpp
#include <iostream>
#include <string>

class Animal {
protected:
    std::string name_;
    int age_;
public:
    Animal(const std::string& name, int age) : name_(name), age_(age) {
        std::cout << "Animal 构造\n";
    }
    void show() const {
        std::cout << name_ << " (" << age_ << " 岁)\n";
    }
};

class Dog : public Animal {
private:
    std::string breed_;
public:
    // ✅ 在初始化列表里调用基类构造函数
    Dog(const std::string& name, int age, const std::string& breed)
        : Animal(name, age),      // 基类构造
          breed_(breed)           // 自己的成员
    {
        std::cout << "Dog 构造\n";
    }

    void showBreed() const {
        std::cout << name_ << " 是 " << breed_ << "\n";
    }
};

int main() {
    Dog d("旺财", 3, "柴犬");
    d.show();
    d.showBreed();
    return 0;
}
```

**如果没有显式调用基类构造函数，编译器会尝试调用基类的默认构造函数。如果基类没有默认构造函数，就编译错误。**

## 17.4 虚函数与多态（本章核心）

### 问题：为什么需要虚函数？

```cpp
#include <iostream>

class Animal {
public:
    void speak() const {
        std::cout << "动物发出声音\n";
    }
};

class Dog : public Animal {
public:
    void speak() const {           // 这其实是"隐藏"，不是"重写"
        std::cout << "汪汪！\n";
    }
};

int main() {
    Dog d;
    d.speak();                     // 汪汪！

    Animal* p = &d;                // 基类指针指向派生类对象
    p->speak();                    // ⚠️ 输出 "动物发出声音"！
    // 我们明明指向的是 Dog，为什么不叫？

    return 0;
}
```

**因为 `speak` 不是虚函数，编译器按"指针的静态类型"（`Animal*`）来决定调用哪个函数 —— 这叫"静态绑定"。**

**加上 `virtual` 就好了：**

```cpp
#include <iostream>

class Animal {
public:
    virtual void speak() const {        // ⭐ 加 virtual
        std::cout << "动物发出声音\n";
    }
    virtual ~Animal() = default;        // ⭐ 基类析构也必须 virtual！
};

class Dog : public Animal {
public:
    void speak() const override {       // ⭐ override 明确表示重写
        std::cout << "汪汪！\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "喵喵！\n";
    }
};

int main() {
    Dog d;
    Cat c;

    Animal* p1 = &d;
    Animal* p2 = &c;

    p1->speak();     // 汪汪！   ← 运行时根据真实类型决定
    p2->speak();     // 喵喵！

    // 用引用也一样
    Animal& r = d;
    r.speak();       // 汪汪！

    return 0;
}
```

**这就是多态（polymorphism）：同一个调用，根据对象的真实类型执行不同的代码。**

### 虚函数的工作原理（了解）

编译器会给有虚函数的类生成一张**虚函数表（vtable）**，每个对象里有一个隐藏指针指向它。

```
Dog 对象:
  ┌──────────────┐
  │ vptr ────────┼──→ Dog 的 vtable: [ &Dog::speak ]
  ├──────────────┤
  │ 数据成员...  │
  └──────────────┘

Cat 对象:
  ┌──────────────┐
  │ vptr ────────┼──→ Cat 的 vtable: [ &Cat::speak ]
  ├──────────────┤
  │ 数据成员...  │
  └──────────────┘
```

`p->speak()` 实际是"通过 vptr 找到 vtable，查表取出函数地址，然后调用"。这有**微小的运行时开销**（一次间接跳转），但换来巨大的灵活性。

## 17.5 `override` 与 `final`（C++11）

```cpp
#include <iostream>

class Base {
public:
    virtual void foo() const { }
    virtual void bar() { }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void foo() const override { }      // ✅ 正确重写
    // void foo() override { }         // ❌ 编译错误：签名不同（缺 const）
    //   不加 override 的话，这会静默地变成"新函数"，而不是重写！
    //   这就是 override 的价值：让编译器帮你抓错

    void bar() override final { }      // final：派生类不能再重写它
};

class More : public Derived {
public:
    // void bar() override { }         // ❌ 编译错误：bar 是 final
};

int main() {
    return 0;
}
```

**⭐ 规则：重写虚函数时，永远加上 `override`。** 它能在编译期抓住签名写错、`const` 漏写等问题。这是 C++11 最实用的改进之一。

**常见的静默错误：**

```cpp
class Base {
public:
    virtual void process(int x) { }
    virtual void other() const { }
};

class Derived : public Base {
public:
    void process(double x) override { }   // ❌ 参数类型不对，编译错误（好事！）
    void other() { }                       // ❌ 缺 const，但没写 override → 静默变成新函数！
};
```

## 17.6 虚析构函数（⚠️ 必须掌握）

**如果类可能被当作基类使用（有虚函数），析构函数必须是 `virtual`。**

```cpp
#include <iostream>

class Base {
public:
    Base()  { std::cout << "Base 构造\n"; }
    ~Base() { std::cout << "Base 析构\n"; }     // ❌ 不是 virtual！
};

class Derived : public Base {
private:
    int* data_;
public:
    Derived() : data_(new int[100]) { std::cout << "Derived 构造\n"; }
    ~Derived() {
        delete[] data_;
        std::cout << "Derived 析构\n";
    }
};

int main() {
    Base* p = new Derived();      // 基类指针指向派生类
    delete p;                     // 💥 只调用了 Base 的析构！Derived 的没调用
    return 0;
}
```

**输出：**

```
Base 构造
Derived 构造
Base 析构            ← Derived 的析构没有被调用！
```

**后果：`data_` 指向的 100 个 int 永远没被释放 → 内存泄漏。**

**加上 `virtual` 就对了：**

```cpp
class Base {
public:
    virtual ~Base() { std::cout << "Base 析构\n"; }
};
```

**现在 `delete p` 会先调用 `Derived::~Derived`，再调用 `Base::~Base`。**

**⭐ 铁律：只要一个类有虚函数，或者你打算通过基类指针 delete 派生类对象，析构函数就必须是 `virtual`。**

**省事写法：**

```cpp
class Base {
public:
    virtual ~Base() = default;
};
```

## 17.7 纯虚函数与抽象类

**纯虚函数 = 只声明不实现的虚函数。** 有纯虚函数的类是**抽象类**，不能直接实例化。

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// 抽象基类：定义"接口"
class Shape {
public:
    virtual double area() const = 0;            // 纯虚函数（= 0）
    virtual double perimeter() const = 0;
    virtual std::string name() const = 0;

    virtual void describe() const {
        std::cout << name() << ": 面积 = " << area()
                  << ", 周长 = " << perimeter() << "\n";
    }

    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    static constexpr double kPi = 3.14159265358979323846;
    double radius_;
public:
    explicit Circle(double r) : radius_(r) {}
    double area() const override { return kPi * radius_ * radius_; }
    double perimeter() const override { return 2 * kPi * radius_; }
    std::string name() const override { return "圆"; }
};

class Rectangle : public Shape {
private:
    double w_, h_;
public:
    Rectangle(double w, double h) : w_(w), h_(h) {}
    double area() const override { return w_ * h_; }
    double perimeter() const override { return 2 * (w_ + h_); }
    std::string name() const override { return "矩形"; }
};

class Triangle : public Shape {
private:
    double a_, b_, c_;
public:
    Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}
    double area() const override {
        double s = (a_ + b_ + c_) / 2;
        return std::sqrt(s * (s - a_) * (s - b_) * (s - c_));
    }
    double perimeter() const override { return a_ + b_ + c_; }
    std::string name() const override { return "三角形"; }
};

int main() {
    // Shape s;                              // ❌ 抽象类不能实例化

    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Triangle>(3.0, 4.0, 5.0));

    double totalArea = 0;
    for (const auto& shape : shapes) {
        shape->describe();               // 多态调用！
        totalArea += shape->area();
    }
    std::cout << "总面积: " << totalArea << "\n";

    return 0;                            // unique_ptr 自动 delete，虚析构保证正确
}
```

**这个例子展示了 OOP 的终极价值：**

- `Shape` 定义接口，不知道具体是什么形状
- 每个具体形状自己实现 `area()`
- 主循环**完全不需要知道**有哪些形状，也能正确计算
- **加一个新形状，主循环代码一行都不用改！**

这就是**开闭原则**（对扩展开放，对修改关闭）。

## 17.8 多态实战：员工工资系统

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>

class Employee {
protected:
    std::string name_;
    int id_;

public:
    Employee(const std::string& name, int id) : name_(name), id_(id) {}

    // 每个员工有自己独特的工资算法 → 纯虚函数
    virtual double calculateSalary() const = 0;
    virtual std::string role() const = 0;

    void printInfo() const {
        std::cout << std::left << std::setw(12) << role()
                  << std::setw(10) << name_
                  << "ID:" << std::setw(6) << id_
                  << std::fixed << std::setprecision(2)
                  << " 工资: " << calculateSalary() << "\n";
    }

    const std::string& name() const { return name_; }

    virtual ~Employee() = default;
};

// 正式员工：月薪
class SalariedEmployee : public Employee {
private:
    double monthlySalary_;
public:
    SalariedEmployee(const std::string& name, int id, double salary)
        : Employee(name, id), monthlySalary_(salary) {}

    double calculateSalary() const override { return monthlySalary_; }
    std::string role() const override { return "正式员工"; }
};

// 小时工：时薪 × 小时数
class HourlyEmployee : public Employee {
private:
    double hourlyRate_;
    double hoursWorked_;
public:
    HourlyEmployee(const std::string& name, int id, double rate, double hours)
        : Employee(name, id), hourlyRate_(rate), hoursWorked_(hours) {}

    double calculateSalary() const override {
        double normal = std::min(hoursWorked_, 160.0);
        double overtime = std::max(0.0, hoursWorked_ - 160.0);
        return normal * hourlyRate_ + overtime * hourlyRate_ * 1.5;   // 加班 1.5 倍
    }
    std::string role() const override { return "小时工"; }
};

// 销售：底薪 + 提成
class CommissionEmployee : public Employee {
private:
    double baseSalary_;
    double sales_;
    double commissionRate_;
public:
    CommissionEmployee(const std::string& name, int id, double base, double sales, double rate)
        : Employee(name, id), baseSalary_(base), sales_(sales), commissionRate_(rate) {}

    double calculateSalary() const override {
        return baseSalary_ + sales_ * commissionRate_;
    }
    std::string role() const override { return "销售人员"; }
};

int main() {
    std::vector<std::unique_ptr<Employee>> employees;
    employees.push_back(std::make_unique<SalariedEmployee>("张三", 1001, 15000));
    employees.push_back(std::make_unique<HourlyEmployee>("李四", 1002, 80, 180));
    employees.push_back(std::make_unique<CommissionEmployee>("王五", 1003, 5000, 200000, 0.05));

    std::cout << "===== 工资表 =====\n";
    double total = 0;
    for (const auto& e : employees) {
        e->printInfo();                      // 多态调用，各自算出正确结果
        total += e->calculateSalary();
    }
    std::cout << "-------------------\n";
    std::cout << "总支出: " << std::fixed << std::setprecision(2) << total << "\n";

    return 0;
}
```

## 17.9 向下转换：`dynamic_cast`

**基类指针 → 派生类指针**需要显式转换：

```cpp
#include <iostream>
#include <memory>

class Base {
public:
    virtual ~Base() = default;
};

class DerivedA : public Base {
public:
    void onlyA() { std::cout << "A 特有\n"; }
};

class DerivedB : public Base {
public:
    void onlyB() { std::cout << "B 特有\n"; }
};

int main() {
    Base* p = new DerivedA();

    // ✅ dynamic_cast：运行时检查，失败返回 nullptr
    DerivedA* pa = dynamic_cast<DerivedA*>(p);
    if (pa != nullptr) {
        pa->onlyA();                    // A 特有
    }

    DerivedB* pb = dynamic_cast<DerivedB*>(p);
    if (pb == nullptr) {
        std::cout << "p 不是 DerivedB\n";    // 走这里
    }

    // 引用版本的 dynamic_cast：失败抛 std::bad_cast
    try {
        DerivedA& ra = dynamic_cast<DerivedA&>(*p);
        ra.onlyA();
    } catch (const std::bad_cast& e) {
        std::cout << "转换失败\n";
    }

    // ⚠️ static_cast 不做检查（更快但危险）
    // DerivedB* bad = static_cast<DerivedB*>(p);   // 编译通过，但调用 onlyB 会崩

    delete p;
    return 0;
}
```

**`dynamic_cast` 的要求：基类必须有虚函数（多态类型）。它需要 `-frtti`（默认开启）。**

**性能提示**：`dynamic_cast` 有运行时开销。如果频繁使用，往往说明设计有问题（应该用虚函数而不是类型判断）。

**⚠️ 反模式：用 dynamic_cast 做类型分发**

```cpp
// ❌ 这样写等于放弃了多态的好处
for (auto& shape : shapes) {
    if (auto* c = dynamic_cast<Circle*>(shape.get())) {
        // 处理圆
    } else if (auto* r = dynamic_cast<Rectangle*>(shape.get())) {
        // 处理矩形
    }
    // 每加一个形状都要改这里！
}

// ✅ 正确：把行为做成虚函数
for (auto& shape : shapes) {
    shape->draw();      // 各画各的
}
```

## 17.10 继承 vs 组合

**继承是"是一个"（is-a），组合是"有一个"（has-a）。**

```cpp
// ❌ 错误的继承：汽车不是引擎
class Engine {
public:
    void start() { std::cout << "引擎启动\n"; }
};

class Car : public Engine { };     // ❌ 语义错误：Car 不是一个 Engine

// ✅ 正确的组合
class Car {
private:
    Engine engine_;                 // Car 有一个 Engine
public:
    void start() { engine_.start(); }
};
```

**⭐ 经验法则：优先用组合，而不是继承。**

**为什么？**

1. 继承是**最强的耦合**（派生类依赖基类的所有细节）
2. 继承层次深了难以理解和维护
3. 组合更灵活（可以运行时替换）
4. "是一个"关系其实比想象的少

**什么时候真的需要继承？**

- 需要多态（通过基类指针统一处理不同派生类）
- 派生类确实"是一种"基类，且能替代基类（**里氏替换原则**）

## 17.11 多重继承（了解，慎用）

```cpp
#include <iostream>

class Swimmer {
public:
    void swim() { std::cout << "游泳\n"; }
    virtual ~Swimmer() = default;
};

class Flyer {
public:
    void fly() { std::cout << "飞行\n"; }
    virtual ~Flyer() = default;
};

// 多重继承
class Duck : public Swimmer, public Flyer {
public:
    void quack() { std::cout << "嘎嘎\n"; }
};

int main() {
    Duck d;
    d.swim();
    d.fly();
    d.quack();
    return 0;
}
```

### ⚠️ 菱形继承问题

```cpp
class Animal { public: int age; };
class Mammal : public Animal { };
class Bird : public Animal { };
class Platypus : public Mammal, public Bird { };   // 鸭嘴兽
// Platypus 里有两份 age！访问时二义性
```

**解决：虚继承**

```cpp
class Animal { public: int age; };
class Mammal : virtual public Animal { };
class Bird : virtual public Animal { };
class Platypus : public Mammal, public Bird { };
// 现在只有一份 age
```

**⭐ 建议：除了"实现多个接口"（即多个纯抽象基类），尽量避免多重继承。** Java/C# 干脆禁止了多继承。

**接口式的多重继承是安全的：**

```cpp
class IPrintable {
public:
    virtual void print() const = 0;
    virtual ~IPrintable() = default;
};

class ISerializable {
public:
    virtual std::string serialize() const = 0;
    virtual ~ISerializable() = default;
};

class Document : public IPrintable, public ISerializable {
public:
    void print() const override { }
    std::string serialize() const override { return ""; }
};
```

## 17.12 练习

1. 定义基类 `Shape`（抽象），派生 `Circle`、`Rectangle`、`Square`，用 `vector<unique_ptr<Shape>>` 存起来并输出各自面积。
2. 定义基类 `Vehicle`，派生 `Car`、`Bike`、`Truck`，各自的 `wheels()` 返回轮子数。
3. 设计一个 `Account` 基类和 `SavingsAccount`、`CheckingAccount` 派生类，各自实现 `withdraw`（储蓄账户有最低余额要求）。
4. 定义 `Employee` 层次（如第 17.8 节的例子），再加一个 `Manager`（底薪 + 管理津贴）。
5. 下面代码有什么问题？

```cpp
class Base {
public:
    ~Base() { }
    virtual void foo() { }
};

class Derived : public Base {
    int* data_ = new int[100];
public:
    ~Derived() { delete[] data_; }
};

int main() {
    Base* p = new Derived();
    delete p;
}
```

**参考答案（第 1 题和第 5 题）：**

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// 练习 1
class Shape {
public:
    virtual double area() const = 0;
    virtual std::string name() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    static constexpr double kPi = 3.14159265358979323846;
    double r_;
public:
    explicit Circle(double r) : r_(r) {}
    double area() const override { return kPi * r_ * r_; }
    std::string name() const override { return "圆"; }
};

class Rectangle : public Shape {
    double w_, h_;
public:
    Rectangle(double w, double h) : w_(w), h_(h) {}
    double area() const override { return w_ * h_; }
    std::string name() const override { return "矩形"; }
};

class Square : public Rectangle {
public:
    explicit Square(double side) : Rectangle(side, side) {}
    std::string name() const override { return "正方形"; }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(3.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 5.0));
    shapes.push_back(std::make_unique<Square>(4.0));

    for (const auto& s : shapes) {
        std::cout << s->name() << " 面积 = " << s->area() << "\n";
    }
    return 0;
}

// 练习 5 的问题：
// Base 的析构函数不是 virtual。delete p 时（p 的静态类型是 Base*），
// 只调用 Base::~Base，Derived::~Derived 不会被调用，
// 导致 data_ 指向的 100 个 int 泄漏。
//
// 修复：class Base { public: virtual ~Base() = default; ... };
```

---

# 第 18 章 · 模板与泛型编程

**模板让你写"类型无关"的代码**：同一份代码，可以处理 `int`、`double`、`std::string` 或任何自定义类型。

## 18.1 问题引入

如果不用模板，你要写很多重复代码：

```cpp
int maxInt(int a, int b) { return a > b ? a : b; }
double maxDouble(double a, double b) { return a > b ? a : b; }
char maxChar(char a, char b) { return a > b ? a : b; }
std::string maxString(const std::string& a, const std::string& b) { return a > b ? a : b; }
// ... 每个类型都要写一遍
```

**用模板，一次搞定：**

```cpp
#include <iostream>
#include <string>

template <typename T>
T myMax(T a, T b) {
    return a > b ? a : b;
}

int main() {
    std::cout << myMax(3, 7) << "\n";                              // 7（T=int）
    std::cout << myMax(3.5, 2.1) << "\n";                          // 3.5（T=double）
    std::cout << myMax('a', 'z') << "\n";                          // z（T=char）
    std::cout << myMax(std::string("apple"), std::string("banana")) << "\n";   // banana

    // 显式指定类型
    std::cout << myMax<double>(3, 7) << "\n";                      // 7（转成 double）

    return 0;
}
```

**编译器在编译期为每个用到的类型生成一份代码（这个过程叫"实例化"）。**

## 18.2 函数模板细节

```cpp
#include <iostream>
#include <string>

// 1) 两个类型参数
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {       // C++11 尾置返回类型
    return a + b;
}

// C++14 起可以简写为：
template <typename T, typename U>
auto add2(T a, U b) {
    return a + b;                              // 返回类型自动推导
}

// 2) 非类型模板参数（编译期常量）
template <typename T, int N>
T arraySum(const T (&arr)[N]) {
    T sum = T{};
    for (int i = 0; i < N; i++) sum += arr[i];
    return sum;
}

// 3) 默认模板参数
template <typename T = int>
T defaultValue() {
    return T{};
}

// 4) 模板特化（为特定类型提供特殊实现）
template <typename T>
bool isEqual(T a, T b) {
    return a == b;
}

// 针对 double 的特化：浮点要容差比较
template <>
bool isEqual<double>(double a, double b) {
    return std::abs(a - b) < 1e-9;
}

int main() {
    std::cout << add(3, 4.5) << "\n";           // 7.5（返回 double）
    std::cout << add2(10, 20) << "\n";          // 30

    int arr[] = {1, 2, 3, 4, 5};
    std::cout << arraySum(arr) << "\n";          // 15（N 自动推导为 5）

    std::cout << defaultValue() << "\n";         // 0（T=int）
    std::cout << defaultValue<double>() << "\n"; // 0（T=double）

    std::cout << std::boolalpha;
    std::cout << isEqual(1, 1) << "\n";                     // true
    std::cout << isEqual(0.1 + 0.2, 0.3) << "\n";           // true（用了特化版本）

    return 0;
}
```

> `add` 用到了 `std::abs`，需要 `#include <cmath>`。

## 18.3 类模板

```cpp
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* data_;
    std::size_t size_;
    std::size_t capacity_;

    void grow() {
        std::size_t newCap = capacity_ == 0 ? 2 : capacity_ * 2;
        T* newData = new T[newCap];
        for (std::size_t i = 0; i < size_; i++) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCap;
    }

public:
    Stack() : data_(nullptr), size_(0), capacity_(0) {}

    ~Stack() { delete[] data_; }

    // 禁用拷贝（简化示例）
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(const T& value) {
        if (size_ == capacity_) grow();
        data_[size_++] = value;
    }

    T pop() {
        if (empty()) throw std::runtime_error("栈为空");
        return data_[--size_];
    }

    const T& top() const {
        if (empty()) throw std::runtime_error("栈为空");
        return data_[size_ - 1];
    }

    bool empty() const { return size_ == 0; }
    std::size_t size() const { return size_; }
};

int main() {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    std::cout << "栈顶: " << intStack.top() << ", 大小: " << intStack.size() << "\n";

    Stack<std::string> strStack;
    strStack.push("hello");
    strStack.push("world");
    std::cout << "栈顶: " << strStack.top() << "\n";

    Stack<double> dblStack;
    dblStack.push(3.14);
    std::cout << "栈顶: " << dblStack.top() << "\n";

    // 嵌套模板
    Stack<Stack<int>> nested;
    nested.push(intStack);
    std::cout << "嵌套栈大小: " << nested.size() << "\n";

    return 0;
}
```

**注意：类模板的成员函数定义通常要放在头文件里**（因为编译器在实例化时需要看到完整定义）。第 26 章会详细讲这个问题。

## 18.4 模板实例化与代码膨胀

```cpp
template <typename T>
T square(T x) { return x * x; }

int main() {
    square(1);        // 生成 square<int>
    square(1.0);      // 生成 square<double>
    square(1.0f);     // 生成 square<float>
    square('a');      // 生成 square<char>
    // 二进制里有 4 份代码
}
```

**这就是"模板代码膨胀"**。一般不是问题，但如果模板很大且用了很多类型，二进制会变大。

**缓解方法**：把与类型无关的代码抽出来放在非模板基类或普通函数里。

## 18.5 可变参数模板（C++11）

**接受任意数量、任意类型的参数。**

```cpp
#include <iostream>
#include <string>

// 递归终止
void print() {
    std::cout << "\n";
}

// 可变参数模板
template <typename T, typename... Rest>
void print(const T& first, const Rest&... rest) {
    std::cout << first;
    if (sizeof...(rest) > 0) std::cout << ", ";
    print(rest...);                     // 递归展开
}

int main() {
    print(1);
    print(1, 2.5);
    print("hello", 42, 3.14, 'x', std::string("end"));
    return 0;
}
```

**C++17 折叠表达式（更简洁）：**

```cpp
#include <iostream>

template <typename... Args>
auto sum(Args... args) {
    return (args + ...);            // 折叠表达式：((a + b) + c) + ...
}

template <typename... Args>
void printAll(Args&&... args) {
    ((std::cout << args << " "), ...);   // 逗号折叠
    std::cout << "\n";
}

int main() {
    std::cout << sum(1, 2, 3, 4, 5) << "\n";        // 15
    std::cout << sum(1.5, 2.5) << "\n";             // 4
    printAll(1, "two", 3.0, 'x');
    return 0;
}
```

## 18.6 模板与 `auto`、`decltype`

```cpp
#include <iostream>
#include <vector>

template <typename Container>
void printContainer(const Container& c) {
    // C++11：typename 必须写（表明 value_type 是类型）
    for (typename Container::value_type x : c) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

template <typename Container>
auto getFirst(const Container& c) -> decltype(c[0]) {
    return c[0];
}

// C++14 起简化：
template <typename Container>
auto getFirst2(const Container& c) {
    return c[0];
}

int main() {
    std::vector<int> v = {1, 2, 3};
    printContainer(v);

    std::cout << getFirst(v) << "\n";
    std::cout << getFirst2(v) << "\n";
    return 0;
}
```

## 18.7 `constexpr if`（C++17）

**在编译期做分支，不同分支的代码只编译相应的那个。**

```cpp
#include <iostream>
#include <type_traits>
#include <string>

template <typename T>
std::string describe(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        return "整数: " + std::to_string(value);
    } else if constexpr (std::is_floating_point_v<T>) {
        return "浮点: " + std::to_string(value);
    } else if constexpr (std::is_same_v<T, std::string>) {
        return "字符串: " + value;
    } else {
        return "未知类型";
    }
}

int main() {
    std::cout << describe(42) << "\n";                    // 整数: 42
    std::cout << describe(3.14) << "\n";                  // 浮点: 3.140000
    std::cout << describe(std::string("hi")) << "\n";     // 字符串: hi
    return 0;
}
```

**这和普通 `if` 的区别：** 普通 `if` 要求所有分支都能编译（即使不会执行）。`if constexpr` 只实例化命中的分支，其他分支被丢弃。

## 18.8 概念（Concepts，C++20）

**给模板参数加约束，报错信息更清晰。**

```cpp
// C++20
#include <concepts>
#include <iostream>

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
T add(T a, T b) {
    return a + b;
}

// 更简洁的写法
void printNumber(std::integral auto n) {
    std::cout << "整数: " << n << "\n";
}

int main() {
    std::cout << add(1, 2) << "\n";
    std::cout << add(1.5, 2.5) << "\n";
    // add("a", "b");    // ❌ 错误信息非常清晰：约束不满足
    printNumber(42);
    return 0;
}
```

**C++20 之前，模板报错信息有一屏那么长（著名的"模板天书"）。Concepts 大大改善了这个问题。**

> 如果编译器支持，用 `-std=c++20` 打开。

## 18.9 练习

1. 写函数模板 `T min3(T a, T b, T c)` 返回三个值中的最小值。
2. 写函数模板 `void swapValues(T& a, T& b)`。
3. 写函数模板 `int countIf(const std::vector<T>& v, bool (*pred)(const T&))`。
4. 写类模板 `Pair<K, V>`，有 `first`/`second` 成员和一个 `swap` 方法。
5. 写函数模板 `T sum(const std::vector<T>& v)` 求和。
6. 写类模板 `Matrix<T, Rows, Cols>`，支持 `at(r, c)` 和 `fill(v)`。

**参考答案：**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// 练习 1
template <typename T>
T min3(T a, T b, T c) {
    T m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

// 练习 2
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// 练习 3
template <typename T, typename Pred>
int countIf(const std::vector<T>& v, Pred pred) {
    int count = 0;
    for (const auto& x : v) {
        if (pred(x)) count++;
    }
    return count;
}

// 练习 4
template <typename K, typename V>
class Pair {
public:
    K first;
    V second;

    Pair(const K& k, const V& v) : first(k), second(v) {}

    void swap() {
        K temp = first;
        first = static_cast<K>(second);   // 仅当类型兼容时有意义
        second = static_cast<V>(temp);
    }

    void print() const {
        std::cout << "(" << first << ", " << second << ")\n";
    }
};

// 练习 5
template <typename T>
T sum(const std::vector<T>& v) {
    T result{};
    for (const auto& x : v) result += x;
    return result;
}

// 练习 6
template <typename T, int Rows, int Cols>
class Matrix {
private:
    T data_[Rows][Cols];
public:
    Matrix() { fill(T{}); }

    void fill(T value) {
        for (int r = 0; r < Rows; r++)
            for (int c = 0; c < Cols; c++)
                data_[r][c] = value;
    }

    T& at(int r, int c) {
        if (r < 0 || r >= Rows || c < 0 || c >= Cols)
            throw std::out_of_range("矩阵索引越界");
        return data_[r][c];
    }

    const T& at(int r, int c) const {
        if (r < 0 || r >= Rows || c < 0 || c >= Cols)
            throw std::out_of_range("矩阵索引越界");
        return data_[r][c];
    }

    void print() const {
        for (int r = 0; r < Rows; r++) {
            for (int c = 0; c < Cols; c++) std::cout << data_[r][c] << "\t";
            std::cout << "\n";
        }
    }
};

int main() {
    std::cout << min3(3, 1, 2) << "\n";              // 1
    std::cout << min3(3.5, 1.2, 2.8) << "\n";        // 1.2
    std::cout << min3(std::string("c"), std::string("a"), std::string("b")) << "\n";

    int x = 1, y = 2;
    swapValues(x, y);
    std::cout << x << " " << y << "\n";              // 2 1

    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    std::cout << "偶数个数: " << countIf(v, [](int n) { return n % 2 == 0; }) << "\n";   // 3
    std::cout << "大于3的个数: " << countIf(v, [](int n) { return n > 3; }) << "\n";     // 3

    Pair<int, std::string> p(1, "one");
    p.print();

    std::cout << "和: " << sum(v) << "\n";           // 21
    std::cout << "字符串和: " << sum(std::vector<std::string>{"a","b","c"}) << "\n";   // abc

    Matrix<int, 2, 3> m;
    m.fill(0);
    m.at(0, 0) = 1;
    m.at(1, 2) = 9;
    m.print();

    return 0;
}
```

> **注意练习 4 的 `Pair::swap` 只在 K 和 V 类型兼容时才有意义**（比如都是 int）。真正的 `std::pair` 不需要这个，因为 `std::swap` 已经够了。

---

# 第 19 章 · STL 容器

**STL（Standard Template Library，标准模板库）**是 C++ 最强大的武器库。核心三块：

1. **容器（containers）**：存数据的数据结构
2. **算法（algorithms）**：排序、查找、变换
3. **迭代器（iterators）**：连接容器和算法的桥梁

**先记住一句话：不要自己写数据结构，先用 STL。**

## 19.1 容器总览

| 容器 | 类型 | 特点 | 查找 | 插入 | 删除 |
|---|---|---|---|---|---|
| `vector` | 序列 | 动态数组，随机访问快 | O(n) | 尾部 O(1) | 尾部 O(1) |
| `array` | 序列 | 固定大小数组 | O(n) | — | — |
| `deque` | 序列 | 双端队列 | O(n) | 两端 O(1) | 两端 O(1) |
| `list` | 序列 | 双向链表 | O(n) | 任意 O(1) | 任意 O(1) |
| `forward_list` | 序列 | 单向链表 | O(n) | 任意 O(1) | 任意 O(1) |
| `set` | 关联 | 有序集合，去重 | O(log n) | O(log n) | O(log n) |
| `multiset` | 关联 | 有序集合，允许重复 | O(log n) | O(log n) | O(log n) |
| `map` | 关联 | 有序键值对 | O(log n) | O(log n) | O(log n) |
| `multimap` | 关联 | 有序键值对，键可重复 | O(log n) | O(log n) | O(log n) |
| `unordered_set` | 哈希 | 无序集合 | 平均 O(1) | 平均 O(1) | 平均 O(1) |
| `unordered_map` | 哈希 | 无序键值对 | 平均 O(1) | 平均 O(1) | 平均 O(1) |
| `stack` | 适配器 | 栈（LIFO） | — | 顶 O(1) | 顶 O(1) |
| `queue` | 适配器 | 队列（FIFO） | — | 尾 O(1) | 头 O(1) |
| `priority_queue` | 适配器 | 优先队列（堆） | — | O(log n) | O(log n) |

> **`vector` 是默认选择。** 不确定用哪个时就用 `vector`，它往往足够快。

## 19.2 `std::map`：有序键值对

```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    // 创建
    std::map<std::string, int> ages;
    std::map<std::string, int> init = {{"Alice", 25}, {"Bob", 30}};

    // 插入
    ages["Charlie"] = 35;                         // 用 []
    ages.insert({"Dave", 28});                    // 用 insert
    ages.insert(std::make_pair("Eve", 22));       // 用 make_pair
    ages.emplace("Frank", 40);                    // C++11 原地构造（推荐）

    // ⚠️ [] 的危险：如果 key 不存在，会自动创建并值初始化（0）！
    std::cout << "不存在的 key: " << ages["Nobody"] << "\n";   // 0
    std::cout << "现在 map 大小: " << ages.size() << "\n";     // 变大了！

    // 访问
    std::cout << ages.at("Alice") << "\n";        // 25（不存在会抛异常）
    std::cout << ages["Bob"] << "\n";             // 30

    // 检查是否存在（重要）
    if (ages.find("Alice") != ages.end()) {
        std::cout << "Alice 存在\n";
    }
    if (ages.count("Zoe") == 0) {
        std::cout << "Zoe 不存在\n";
    }

    // C++17：在 if 里定义变量
    if (auto it = ages.find("Bob"); it != ages.end()) {
        std::cout << "Bob: " << it->second << "\n";
    }

    // 安全地取值（不存在时用默认值）
    int age = 0;
    if (auto it = ages.find("Grace"); it != ages.end()) {
        age = it->second;
    }

    // 删除
    ages.erase("Nobody");

    // 遍历：自动按 key 排序！
    std::cout << "\n所有人（按名字排序）:\n";
    for (const auto& [name, age] : ages) {        // 结构化绑定（C++17）
        std::cout << "  " << name << ": " << age << "\n";
    }

    // 显式迭代器写法（C++17 之前）
    for (std::map<std::string, int>::const_iterator it = ages.begin(); it != ages.end(); ++it) {
        std::cout << it->first << " = " << it->second << "\n";
    }

    // 大小与清空
    std::cout << "大小: " << ages.size() << ", 空? " << std::boolalpha << ages.empty() << "\n";

    return 0;
}
```

**`map` 内部是红黑树，key 自动排序。**

### 修改值的几种方式

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> m = {{"a", 1}};

    // 1) 直接赋值
    m["a"] = 10;

    // 2) 通过迭代器
    auto it = m.find("a");
    if (it != m.end()) {
        it->second = 20;
    }

    // 3) C++17 try_emplace：只在 key 不存在时插入
    m.try_emplace("b", 5);        // 插入 b=5
    m.try_emplace("b", 99);       // 已存在，不修改

    // 4) insert_or_assign（C++17）：存在则覆盖
    m.insert_or_assign("b", 42);

    for (const auto& [k, v] : m) std::cout << k << "=" << v << " ";
    std::cout << "\n";            // a=20 b=42

    return 0;
}
```

## 19.3 `std::set`：有序集合

```cpp
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<int> s = {5, 2, 8, 2, 1, 5};        // 重复的会被忽略

    // 插入
    s.insert(3);
    s.insert(5);                                 // 已存在，无效
    s.emplace(7);

    // 自动排序 + 去重
    for (int x : s) std::cout << x << " ";
    std::cout << "\n";                           // 1 2 3 5 7 8

    // 查找
    if (s.find(3) != s.end()) std::cout << "找到 3\n";
    if (s.count(5)) std::cout << "5 存在\n";

    // ⭐ 检查是否存在的惯用法（C++20）
    // if (s.contains(3)) { }

    // 删除
    s.erase(3);

    // 大小
    std::cout << "大小: " << s.size() << "\n";

    // 范围查询（利用有序性）
    std::set<int> nums = {10, 20, 30, 40, 50};
    auto low = nums.lower_bound(25);     // 第一个 >= 25 的元素
    auto up  = nums.upper_bound(40);     // 第一个 > 40 的元素
    std::cout << "范围: ";
    for (auto it = low; it != up; ++it) std::cout << *it << " ";
    std::cout << "\n";                   // 30 40

    // 自定义排序规则
    std::set<int, std::greater<int>> desc = {3, 1, 4, 1, 5};
    for (int x : desc) std::cout << x << " ";
    std::cout << "\n";                   // 5 4 3 1

    return 0;
}
```

### `set` 去重的经典用法

```cpp
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    // 方法 1：用 set
    std::set<int> uniqueSet(v.begin(), v.end());
    std::vector<int> uniqueVec(uniqueSet.begin(), uniqueSet.end());
    // 结果：1 2 3 4 5 6 9（且已排序）

    // 方法 2：排序 + unique（更快，保持用 vector）
    std::vector<int> v2 = v;
    std::sort(v2.begin(), v2.end());
    v2.erase(std::unique(v2.begin(), v2.end()), v2.end());

    // 方法 3：保持原顺序去重（用 set 做辅助）
    std::set<int> seen;
    std::vector<int> ordered;
    for (int x : v) {
        if (seen.insert(x).second) {        // insert 返回 {迭代器, 是否成功}
            ordered.push_back(x);
        }
    }
    for (int x : ordered) std::cout << x << " ";
    std::cout << "\n";                      // 3 1 4 5 9 2 6

    return 0;
}
```

## 19.4 `std::unordered_map`：哈希表

**`unordered_map` 用哈希实现，平均 O(1) 查找，但不排序。**

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> scores;

    scores["Alice"] = 95;
    scores["Bob"] = 87;
    scores["Charlie"] = 92;
    scores.emplace("Dave", 78);

    // 查找 O(1)
    if (auto it = scores.find("Bob"); it != scores.end()) {
        std::cout << "Bob: " << it->second << "\n";
    }

    // 计数
    std::cout << scores.count("Alice") << "\n";   // 1

    // 遍历（顺序不确定！）
    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << "\n";
    }

    // 删除
    scores.erase("Dave");

    return 0;
}
```

### `map` vs `unordered_map`

| | `std::map` | `std::unordered_map` |
|---|---|---|
| 底层 | 红黑树 | 哈希表 |
| 查找 | O(log n) | 平均 O(1)，最坏 O(n) |
| 是否有序 | ✅ 按 key 排序 | ❌ 无序 |
| 内存 | 较小 | 通常更大 |
| 何时用 | 需要有序遍历/范围查询 | 只需要快速查找 |

**⭐ 日常最常用的就是 `unordered_map` 做计数/查找表。**

## 19.5 实用场景：找出数组中出现次数最多的元素

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 3, 2, 1, 4, 1, 3, 2, 1, 5};

    // 统计频率
    std::unordered_map<int, int> freq;
    for (int n : nums) {
        freq[n]++;              // 不存在时自动创建并置 0，然后 ++
    }

    // 找最大
    int mode = 0, maxCount = 0;
    for (const auto& [value, count] : freq) {
        if (count > maxCount) {
            maxCount = count;
            mode = value;
        }
    }
    std::cout << "众数: " << mode << "，出现 " << maxCount << " 次\n";

    // 也可以用 max_element
    auto it = std::max_element(freq.begin(), freq.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });
    std::cout << "众数: " << it->first << "，次数 " << it->second << "\n";

    return 0;
}
```

## 19.6 `std::stack`

```cpp
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "栈顶: " << s.top() << "\n";     // 3
    std::cout << "大小: " << s.size() << "\n";    // 3

    s.pop();                                       // 注意：pop 不返回值！
    std::cout << "弹出后栈顶: " << s.top() << "\n"; // 2

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";                             // 2 1

    // 经典应用：括号匹配
    auto checkBrackets = [](const std::string& expr) {
        std::stack<char> st;
        for (char c : expr) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (st.empty()) return false;
                char open = st.top();
                st.pop();
                if ((c == ')' && open != '(') ||
                    (c == ']' && open != '[') ||
                    (c == '}' && open != '{')) {
                    return false;
                }
            }
        }
        return st.empty();
    };

    std::cout << std::boolalpha;
    std::cout << checkBrackets("({[]})") << "\n";    // true
    std::cout << checkBrackets("([)]") << "\n";      // false
    std::cout << checkBrackets("(((") << "\n";       // false

    return 0;
}
```

## 19.7 `std::queue`

```cpp
#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> q;

    q.push("第一个");
    q.push("第二个");
    q.push("第三个");

    std::cout << "队首: " << q.front() << "\n";    // 第一个
    std::cout << "队尾: " << q.back() << "\n";     // 第三个

    q.pop();                                        // 移除队首
    std::cout << "出队后队首: " << q.front() << "\n";   // 第二个

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";

    // 经典应用：模拟银行排队
    std::queue<int> customers;
    for (int i = 1; i <= 5; i++) customers.push(i);

    int time = 0;
    while (!customers.empty()) {
        int id = customers.front();
        customers.pop();
        time += 3;                                  // 每人 3 分钟
        std::cout << "客户 " << id << " 在 " << time << " 分钟完成\n";
    }

    return 0;
}
```

## 19.8 `std::priority_queue`

**优先队列：每次取出的都是最大（或最小）的元素。**

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <string>

struct Task {
    std::string name;
    int priority;      // 数字越大越优先
};

// 自定义比较：priority_queue 默认是大顶堆
// 用 < 会得到最大堆，所以要让"优先级低"的排在前面
struct CompareTask {
    bool operator()(const Task& a, const Task& b) const {
        return a.priority < b.priority;      // 注意是 <，但得到最大堆
    }
};

int main() {
    // 默认：最大堆
    std::priority_queue<int> maxHeap;
    for (int n : {3, 1, 4, 1, 5, 9, 2, 6}) {
        maxHeap.push(n);
    }
    std::cout << "从大到小: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << "\n";                  // 9 6 5 4 3 2 1 1

    // 最小堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (int n : {3, 1, 4, 1, 5}) minHeap.push(n);
    std::cout << "从小到大: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << "\n";                  // 1 1 3 4 5

    // 自定义类型
    std::priority_queue<Task, std::vector<Task>, CompareTask> tasks;
    tasks.push({"写代码", 3});
    tasks.push({"修 bug", 5});
    tasks.push({"开会", 1});
    tasks.push({"部署上线", 4});

    std::cout << "\n按优先级处理:\n";
    while (!tasks.empty()) {
        std::cout << "  [" << tasks.top().priority << "] "
                  << tasks.top().name << "\n";
        tasks.pop();
    }

    return 0;
}
```

## 19.9 `std::deque`

**双端队列：两端都能 O(1) 插入/删除。**

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> d = {3, 4, 5};

    d.push_front(2);        // 头部插入 O(1)
    d.push_front(1);
    d.push_back(6);         // 尾部插入 O(1)
    d.push_back(7);

    for (int x : d) std::cout << x << " ";
    std::cout << "\n";      // 1 2 3 4 5 6 7

    d.pop_front();
    d.pop_back();

    // 支持随机访问
    std::cout << d[0] << " " << d.at(2) << "\n";

    for (int x : d) std::cout << x << " ";
    std::cout << "\n";      // 2 3 4 5 6

    return 0;
}
```

> **`vector` vs `deque`**：如果只在尾部操作，用 `vector`（更快、更省内存）。如果两端都要频繁操作，用 `deque`。

## 19.10 `std::list`

**双向链表：任意位置 O(1) 插入/删除，但不支持随机访问。**

```cpp
#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> l = {1, 2, 3, 4, 5};

    // 头部/尾部操作
    l.push_front(0);
    l.push_back(6);

    // 在中间插入（O(1)，但要先走到位置 O(n)）
    auto it = l.begin();
    std::advance(it, 3);            // 前进 3 步
    l.insert(it, 99);

    for (int x : l) std::cout << x << " ";
    std::cout << "\n";              // 0 1 2 99 3 4 5 6

    // 删除
    l.remove(99);                    // 删除所有值为 99 的元素
    l.remove_if([](int x) { return x % 2 == 0; });   // 删除所有偶数

    for (int x : l) std::cout << x << " ";
    std::cout << "\n";              // 1 3 5

    // 链表特有：splice（把另一个链表的节点移过来，O(1)）
    std::list<int> other = {10, 20, 30};
    l.splice(l.end(), other);       // other 全部并入 l
    for (int x : l) std::cout << x << " ";
    std::cout << "\n";              // 1 3 5 10 20 30
    std::cout << "other 现在大小: " << other.size() << "\n";   // 0

    // 链表特有：sort（因为不能用 std::sort，需要随机访问）
    l.sort();
    l.sort(std::greater<int>());    // 降序

    // 链表特有：reverse
    l.reverse();

    // 链表特有：unique（去重相邻的重复元素）
    std::list<int> dup = {1, 1, 2, 2, 2, 3, 1};
    dup.unique();
    for (int x : dup) std::cout << x << " ";
    std::cout << "\n";              // 1 2 3 1

    return 0;
}
```

> **⚠️ 实践建议：`std::list` 在现代 C++ 中很少用。** 因为 CPU 缓存的关系，`vector` 即使插入是 O(n) 也常常比 `list` 快。除非你有大量任意位置插入/删除，且元素很大，或者需要 `splice`。

## 19.11 `std::array` 与 C 数组、`vector` 的对比总结

| | C 数组 | `std::array` | `std::vector` |
|---|---|---|---|
| 大小 | 编译期固定 | 编译期固定 | 运行期可变 |
| 内存 | 栈（或静态） | 栈（或静态） | 堆 |
| 复制 | 不能整体复制 | ✅ | ✅ |
| 传函数 | 退化为指针 | 保留类型 | 保留类型 |
| 大小查询 | `sizeof` 技巧 | `.size()` | `.size()` |
| 越界检查 | 无 | `.at()` | `.at()` |
| 性能 | 最快 | 同 C 数组 | 略慢（堆分配） |
| 何时用 | 与 C 交互 | 固定小数组 | **默认选择** |

## 19.12 练习

1. 统计一段文本中每个单词出现的次数，输出出现最多的前 3 个。
2. 输入一批学生姓名和成绩，用 `map` 存储，支持按姓名查询成绩。
3. 判断一个字符串中的括号是否匹配（用 `stack`）。
4. 用 `priority_queue` 实现：给定一批数字，每次取最小的两个相加，把结果放回，直到只剩一个数（哈夫曼思想）。
5. 用 `set` 求两个数组的交集和并集。
6. 用 `deque` 实现一个"滑动窗口最大值"：给定数组和窗口大小 k，输出每个窗口的最大值。

**参考答案：**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <sstream>

int main() {
    // 练习 1
    std::string text = "the quick brown fox jumps over the lazy dog the fox";
    std::map<std::string, int> wordCount;
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) wordCount[word]++;

    std::vector<std::pair<std::string, int>> sorted(wordCount.begin(), wordCount.end());
    std::sort(sorted.begin(), sorted.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });

    std::cout << "出现最多的词:\n";
    for (int i = 0; i < 3 && i < (int)sorted.size(); i++) {
        std::cout << "  " << sorted[i].first << ": " << sorted[i].second << "\n";
    }

    // 练习 2
    std::map<std::string, int> grades = {
        {"张三", 90}, {"李四", 85}, {"王五", 92}
    };
    std::string name = "李四";
    if (auto it = grades.find(name); it != grades.end()) {
        std::cout << "\n" << name << " 的成绩: " << it->second << "\n";
    } else {
        std::cout << "\n没找到 " << name << "\n";
    }

    // 练习 3
    auto checkBrackets = [](const std::string& s) {
        std::stack<char> st;
        std::map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (pairs.count(c)) {
                if (st.empty() || st.top() != pairs[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    };
    std::cout << "\n括号匹配 ({[()]}) : " << std::boolalpha << checkBrackets("({[()]})") << "\n";
    std::cout << "括号匹配 ({[(])}) : " << checkBrackets("({[(])})") << "\n";

    // 练习 4：合并石子（哈夫曼思想）
    std::vector<int> stones = {4, 3, 2, 6};
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(stones.begin(), stones.end());
    int totalCost = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int merged = a + b;
        totalCost += merged;
        std::cout << "合并 " << a << " + " << b << " = " << merged << "\n";
        pq.push(merged);
    }
    std::cout << "总代价: " << totalCost << "\n\n";

    // 练习 5
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {4, 5, 6, 7};
    std::set<int> sa(a.begin(), a.end()), sb(b.begin(), b.end());

    std::vector<int> inter, uni;
    std::set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), std::back_inserter(inter));
    std::set_union(sa.begin(), sa.end(), sb.begin(), sb.end(), std::back_inserter(uni));

    std::cout << "交集: ";
    for (int x : inter) std::cout << x << " ";
    std::cout << "\n并集: ";
    for (int x : uni) std::cout << x << " ";
    std::cout << "\n\n";

    // 练习 6：滑动窗口最大值（用 deque 维护单调递减队列）
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::deque<int> dq;             // 存下标
    std::vector<int> result;

    for (int i = 0; i < (int)nums.size(); i++) {
        // 移除窗口外的
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        // 维护单调递减
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        // 窗口形成后记录
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }

    std::cout << "滑动窗口（k=" << k << "）最大值: ";
    for (int x : result) std::cout << x << " ";
    std::cout << "\n";              // 3 3 5 5 6 7

    return 0;
}
```

---

# 第 20 章 · STL 算法与 Lambda 表达式

## 20.1 为什么需要算法？

如果不用算法，你要手写各种循环：

```cpp
// 手写排序
for (int i = 0; i < n-1; i++)
    for (int j = 0; j < n-1-i; j++)
        if (arr[j] > arr[j+1]) std::swap(arr[j], arr[j+1]);

// 手写查找
int found = -1;
for (int i = 0; i < n; i++)
    if (arr[i] == target) { found = i; break; }
```

**用 STL 算法：**

```cpp
std::sort(arr.begin(), arr.end());                              // 排序
auto it = std::find(arr.begin(), arr.end(), target);            // 查找
```

**更快（高度优化）、更短、更不容易出错。**

## 20.2 需要一个头文件

```cpp
#include <algorithm>    // 大部分算法
#include <numeric>      // accumulate, iota, gcd
```

## 20.3 常用算法速查

### 查找类

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 2, 8, 2, 9, 1, 8};

    // find：找第一个等于 value 的
    auto it = std::find(v.begin(), v.end(), 8);
    if (it != v.end()) {
        std::cout << "找到 8，下标 " << (it - v.begin()) << "\n";   // 2
    }

    // find_if：找第一个满足条件的
    auto it2 = std::find_if(v.begin(), v.end(), [](int x) { return x > 6; });
    std::cout << "第一个 >6 的: " << *it2 << "\n";   // 8

    // count：计数
    std::cout << "8 出现 " << std::count(v.begin(), v.end(), 8) << " 次\n";   // 2

    // count_if：条件计数
    int evens = std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::cout << "偶数个数: " << evens << "\n";

    // all_of / any_of / none_of
    std::cout << std::boolalpha;
    std::cout << "全是正数? " << std::all_of(v.begin(), v.end(), [](int x){ return x > 0; }) << "\n";
    std::cout << "有偶数? "   << std::any_of(v.begin(), v.end(), [](int x){ return x % 2 == 0; }) << "\n";
    std::cout << "没有负数? " << std::none_of(v.begin(), v.end(), [](int x){ return x < 0; }) << "\n";

    // 有序容器才能用二分查找
    std::vector<int> sorted = {1, 2, 2, 5, 8, 8, 9};
    bool found = std::binary_search(sorted.begin(), sorted.end(), 5);
    std::cout << "5 存在? " << found << "\n";

    auto lb = std::lower_bound(sorted.begin(), sorted.end(), 8);   // 第一个 >= 8
    auto ub = std::upper_bound(sorted.begin(), sorted.end(), 8);   // 第一个 > 8
    std::cout << "8 的范围: [" << (lb - sorted.begin()) << ", " << (ub - sorted.begin()) << ")\n";

    // equal_range：一次拿到上下界
    auto [lo, hi] = std::equal_range(sorted.begin(), sorted.end(), 8);
    std::cout << "8 出现 " << (hi - lo) << " 次\n";

    return 0;
}
```

### 排序类

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string name;
    int score;
};

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9};

    // 升序
    std::sort(v.begin(), v.end());                     // 1 2 5 8 9

    // 降序
    std::sort(v.begin(), v.end(), std::greater<int>());   // 9 8 5 2 1

    // 自定义比较（lambda）
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    // 按绝对值排序
    std::vector<int> w = {-5, 2, -8, 1, 9};
    std::sort(w.begin(), w.end(), [](int a, int b) {
        return std::abs(a) < std::abs(b);
    });                                                  // 1 2 -5 -8 9

    // 排序结构体：按分数降序，分数相同按名字升序
    std::vector<Student> students = {
        {"张三", 90}, {"李四", 95}, {"王五", 90}, {"赵六", 88}
    };
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.score != b.score) return a.score > b.score;   // 分数高的在前
        return a.name < b.name;                              // 同名分数按名字
    });
    for (const auto& s : students) {
        std::cout << s.name << ": " << s.score << "\n";
    }

    // stable_sort：保持相等元素的相对顺序
    std::stable_sort(students.begin(), students.end(),
                     [](const Student& a, const Student& b) { return a.score > b.score; });

    // partial_sort：只排前 k 个
    std::vector<int> big = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    std::partial_sort(big.begin(), big.begin() + 3, big.end());
    // 前 3 个是 1 2 3，后面顺序不定

    // nth_element：找出第 n 小的元素放在正确位置（O(n)）
    std::vector<int> nums = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    std::nth_element(nums.begin(), nums.begin() + 4, nums.end());
    std::cout << "第 5 小: " << nums[4] << "\n";          // 5

    // 是否已排序
    std::cout << std::boolalpha << std::is_sorted(v.begin(), v.end()) << "\n";

    // 反转
    std::reverse(v.begin(), v.end());

    // 随机打乱
    // #include <random>
    // std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});

    return 0;
}
```

**⭐ 比较函数的语义：`comp(a, b)` 返回 `true` 表示 `a` 应该排在 `b` 前面。**

常见错误：

```cpp
// ❌ 错误：用了 <=（不是严格弱序，会导致未定义行为甚至崩溃）
std::sort(v.begin(), v.end(), [](int a, int b) { return a <= b; });

// ✅ 正确：用 <
std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
```

### 修改类

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // for_each：对每个元素做操作
    std::for_each(v.begin(), v.end(), [](int& x) { x *= 2; });
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";                     // 2 4 6 8 10

    // transform：变换并输出到另一个容器
    std::vector<int> squared(v.size());
    std::transform(v.begin(), v.end(), squared.begin(),
                   [](int x) { return x * x; });
    for (int x : squared) std::cout << x << " ";
    std::cout << "\n";                     // 4 16 36 64 100

    // 两个输入序列的 transform
    std::vector<int> a = {1, 2, 3}, b = {10, 20, 30}, c(3);
    std::transform(a.begin(), a.end(), b.begin(), c.begin(),
                   [](int x, int y) { return x + y; });
    for (int x : c) std::cout << x << " ";
    std::cout << "\n";                     // 11 22 33

    // fill：填充
    std::vector<int> f(5);
    std::fill(f.begin(), f.end(), 7);

    // iota：递增填充（<numeric>）
    // std::iota(f.begin(), f.end(), 1);   // 1 2 3 4 5

    // replace / replace_if
    std::vector<int> r = {1, 2, 3, 2, 1};
    std::replace(r.begin(), r.end(), 2, 99);           // 1 99 3 99 1
    std::replace_if(r.begin(), r.end(), [](int x) { return x > 50; }, 0);

    // remove / remove_if（配合 erase）
    std::vector<int> rm = {1, 2, 3, 4, 5, 6};
    rm.erase(std::remove(rm.begin(), rm.end(), 3), rm.end());           // 删 3
    rm.erase(std::remove_if(rm.begin(), rm.end(),
                            [](int x) { return x % 2 == 0; }), rm.end());  // 删偶数

    // unique（去重相邻重复，通常先 sort）
    std::vector<int> u = {1, 1, 2, 2, 3, 1};
    std::sort(u.begin(), u.end());
    u.erase(std::unique(u.begin(), u.end()), u.end());    // 1 2 3

    // rotate：循环移位
    std::vector<int> rot = {1, 2, 3, 4, 5};
    std::rotate(rot.begin(), rot.begin() + 2, rot.end());   // 3 4 5 1 2

    // swap_ranges
    std::vector<int> x = {1, 2, 3}, y = {7, 8, 9};
    std::swap_ranges(x.begin(), x.end(), y.begin());

    return 0;
}
```

### 数值类（`<numeric>`）

```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // accumulate：求和（初始值很重要！）
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "和: " << sum << "\n";              // 15

    // 求积
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    std::cout << "积: " << product << "\n";          // 120

    // 自定义操作：拼接字符串
    std::vector<std::string> words = {"a", "b", "c"};
    std::string joined = std::accumulate(words.begin(), words.end(), std::string(),
                                         [](const std::string& acc, const std::string& w) {
                                             return acc.empty() ? w : acc + "-" + w;
                                         });
    std::cout << joined << "\n";                     // a-b-c

    // 求平均（⚠️ 注意用 double 初始值）
    double avg = std::accumulate(v.begin(), v.end(), 0.0) / v.size();
    std::cout << "平均: " << avg << "\n";            // 3

    // iota：生成 1,2,3,...
    std::vector<int> seq(5);
    std::iota(seq.begin(), seq.end(), 1);
    for (int x : seq) std::cout << x << " ";
    std::cout << "\n";

    // inner_product：点积
    std::vector<int> a = {1, 2, 3}, b = {4, 5, 6};
    int dot = std::inner_product(a.begin(), a.end(), b.begin(), 0);
    std::cout << "点积: " << dot << "\n";            // 32

    // partial_sum：前缀和
    std::vector<int> prefix(5);
    std::partial_sum(v.begin(), v.end(), prefix.begin());
    for (int x : prefix) std::cout << x << " ";
    std::cout << "\n";                               // 1 3 6 10 15

    // adjacent_difference：相邻差
    std::vector<int> diff(5);
    std::adjacent_difference(v.begin(), v.end(), diff.begin());

    // gcd / lcm（C++17）
    std::cout << "gcd(48,18) = " << std::gcd(48, 18) << "\n";   // 6
    std::cout << "lcm(4,6) = " << std::lcm(4, 6) << "\n";       // 12

    return 0;
}
```

> ⚠️ **`accumulate` 的初始值类型决定结果类型！**
> ```cpp
> std::vector<double> d = {1.5, 2.5};
> auto r1 = std::accumulate(d.begin(), d.end(), 0);      // int！结果 4（截断）
> auto r2 = std::accumulate(d.begin(), d.end(), 0.0);    // double，结果 4.0 ✅
> ```

### 最值类

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9};

    std::cout << "最大: " << *std::max_element(v.begin(), v.end()) << "\n";   // 9
    std::cout << "最小: " << *std::min_element(v.begin(), v.end()) << "\n";   // 1

    // 同时拿两个
    auto [minIt, maxIt] = std::minmax_element(v.begin(), v.end());
    std::cout << "最小 " << *minIt << ", 最大 " << *maxIt << "\n";

    // 两个值比大小
    std::cout << std::max(3, 7) << " " << std::min(3, 7) << "\n";
    std::cout << std::clamp(15, 0, 10) << "\n";      // 10（C++17，把值限制在区间内）

    // 自定义比较
    std::vector<std::string> words = {"apple", "hi", "banana"};
    auto longest = std::max_element(words.begin(), words.end(),
        [](const std::string& a, const std::string& b) { return a.size() < b.size(); });
    std::cout << "最长的词: " << *longest << "\n";   // banana

    return 0;
}
```

## 20.4 Lambda 表达式（重点）

**Lambda 是"匿名的、就地定义的函数"。**

```cpp
[捕获列表](参数列表) -> 返回类型 {
    函数体
}
```

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 最简单的 lambda
    auto hello = []() {
        std::cout << "Hello from lambda\n";
    };
    hello();

    // 带参数和返回值
    auto add = [](int a, int b) {
        return a + b;                  // 返回类型自动推导
    };
    std::cout << add(3, 4) << "\n";    // 7

    // 显式指定返回类型
    auto divide = [](double a, double b) -> double {
        if (b == 0) return 0;
        return a / b;
    };

    // 立即调用（IIFE 风格）
    int x = [](int n) { return n * n; }(5);
    std::cout << x << "\n";            // 25

    // 配合算法
    std::vector<int> v = {5, 2, 8, 1, 9};
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";                 // 9 8 5 2 1

    return 0;
}
```

### 捕获列表（核心概念）

**Lambda 可以捕获外部变量。**

```cpp
#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    // [] 不捕获任何外部变量
    auto f1 = []() { return 1; };
    // auto f2 = []() { return a; };      // ❌ 编译错误

    // [=] 按值捕获所有用到的外部变量（只读副本）
    auto f3 = [=]() { return a + b; };
    std::cout << f3() << "\n";             // 30

    // [&] 按引用捕获所有用到的外部变量（可以修改原变量）
    auto f4 = [&]() { a += 5; return a; };
    std::cout << f4() << "\n";             // 15
    std::cout << "a = " << a << "\n";      // 15（原变量被改了）

    // 指定捕获
    auto f5 = [a]() { return a * 2; };            // 只按值捕获 a
    auto f6 = [&b]() { b *= 2; };                 // 只按引用捕获 b
    auto f7 = [a, &b]() { return a + b; };        // 混合
    auto f8 = [=, &b]() { b++; return a; };       // 默认按值，b 按引用
    auto f9 = [&, a]() { b++; return a; };        // 默认按引用，a 按值

    // 初始化捕获（C++14）：创建新变量
    auto f10 = [c = a * 100]() { return c; };
    std::cout << f10() << "\n";                    // 1500

    // 移动捕获（C++14）：把 unique_ptr 移进 lambda
    auto ptr = std::make_unique<int>(42);
    auto f11 = [p = std::move(ptr)]() { return *p; };
    std::cout << f11() << "\n";                    // 42

    // mutable：让按值捕获的变量可修改（改的是副本）
    auto counter = [count = 0]() mutable {
        return ++count;
    };
    std::cout << counter() << " " << counter() << " " << counter() << "\n";   // 1 2 3

    return 0;
}
```

**⭐ 捕获规则速记：**

| 写法 | 含义 |
|---|---|
| `[]` | 什么都不捕获 |
| `[=]` | 按值捕获所有用到的 |
| `[&]` | 按引用捕获所有用到的 |
| `[x]` | 按值捕获 x |
| `[&x]` | 按引用捕获 x |
| `[=, &x]` | 默认按值，x 按引用 |
| `[&, x]` | 默认按引用，x 按值 |
| `[x = expr]` | 初始化捕获（C++14） |
| `[p = std::move(q)]` | 移动捕获 |

### ⚠️ 捕获的致命陷阱：悬挂引用

```cpp
#include <iostream>
#include <functional>
#include <vector>

// ❌ 返回一个捕获了局部变量的 lambda
std::function<int()> badFactory() {
    int local = 42;
    return [&local]() { return local; };      // 💥 local 已销毁！
}

// ✅ 按值捕获
std::function<int()> goodFactory() {
    int local = 42;
    return [local]() { return local; };       // 安全（副本）
}

int main() {
    auto f = badFactory();
    // std::cout << f();     // ❌ 未定义行为

    auto g = goodFactory();
    std::cout << g() << "\n";    // 42 ✅

    // ⚠️ 另一种陷阱：引用捕获在循环里
    std::vector<std::function<int()>> funcs;
    for (int i = 0; i < 3; i++) {
        funcs.push_back([&i]() { return i; });   // ❌ 全捕获同一个 i
    }
    for (auto& fn : funcs) std::cout << fn() << " ";
    std::cout << "\n";           // 可能是 3 3 3（i 已经是 3）

    // ✅ 按值捕获
    std::vector<std::function<int()>> funcs2;
    for (int i = 0; i < 3; i++) {
        funcs2.push_back([i]() { return i; });   // 各捕获一份副本
    }
    for (auto& fn : funcs2) std::cout << fn() << " ";
    std::cout << "\n";           // 0 1 2 ✅

    return 0;
}
```

**⭐ 黄金法则：如果 lambda 的生命周期可能超过当前作用域，绝不要用 `[&]`。**

## 20.5 `std::function`

**`std::function` 是一个"通用函数包装器"，可以存任何可调用对象。**

```cpp
#include <iostream>
#include <functional>
#include <vector>
#include <string>

// 普通函数
int addOne(int x) { return x + 1; }

// 函数对象
struct MultiplyBy {
    int factor;
    int operator()(int x) const { return x * factor; }
};

int main() {
    // 存各种可调用对象
    std::function<int(int)> fn;

    fn = addOne;
    std::cout << fn(5) << "\n";                        // 6

    fn = MultiplyBy{3};
    std::cout << fn(5) << "\n";                        // 15

    fn = [](int x) { return x * x; };
    std::cout << fn(5) << "\n";                        // 25

    // 作为参数
    auto apply = [](int x, const std::function<int(int)>& f) {
        return f(x);
    };
    std::cout << apply(10, addOne) << "\n";            // 11
    std::cout << apply(10, [](int n) { return n - 1; }) << "\n";   // 9

    // 存到容器里
    std::vector<std::function<int(int)>> operations;
    operations.push_back(addOne);
    operations.push_back([](int x) { return x * 2; });
    operations.push_back(MultiplyBy{10});

    int value = 5;
    for (auto& op : operations) {
        value = op(value);
        std::cout << value << " ";
    }
    std::cout << "\n";                                 // 6 12 120

    // 检查是否为空
    std::function<void()> empty;
    if (!empty) {
        // 不会进这里
    }
    // empty();    // ❌ 抛 std::bad_function_call

    return 0;
}
```

**`std::function` vs 模板 vs 函数指针：**

| | 性能 | 灵活性 | 合适场景 |
|---|---|---|---|
| 模板参数 | 最快（内联） | 编译期确定 | 泛型算法 |
| 函数指针 | 快 | 不能捕获状态 | C 接口 |
| `std::function` | 较慢（类型擦除+堆分配） | 最灵活 | 需要存储/传递任意可调用对象 |

**性能提示**：`std::function` 有开销（间接调用，可能堆分配）。热路径上优先用模板或 `auto`。

## 20.6 函数对象（Functor）

**重载了 `operator()` 的类，可以像函数一样用。**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Accumulator {
private:
    int total_ = 0;
public:
    void operator()(int x) {
        total_ += x;
    }
    int total() const { return total_; }
};

class GreaterThan {
private:
    int threshold_;
public:
    explicit GreaterThan(int t) : threshold_(t) {}
    bool operator()(int x) const { return x > threshold_; }
};

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // 函数对象能保持状态
    Accumulator acc = std::for_each(v.begin(), v.end(), Accumulator());
    std::cout << "总和: " << acc.total() << "\n";      // 15

    // 带参数的函数对象
    int count = std::count_if(v.begin(), v.end(), GreaterThan(3));
    std::cout << "大于 3 的个数: " << count << "\n";   // 2

    // 标准库提供的函数对象
    std::sort(v.begin(), v.end(), std::greater<int>());      // 降序
    std::cout << std::plus<int>{}(3, 4) << "\n";             // 7
    std::cout << std::multiplies<int>{}(3, 4) << "\n";       // 12
    std::cout << std::negate<int>{}(3) << "\n";              // -3

    return 0;
}
```

**函数对象 vs Lambda：**

- Lambda 更简洁，日常首选
- 函数对象在需要复杂逻辑、多个重载、或者要 C++11 之前的兼容性时用
- 编译器对两者的优化通常一样好

## 20.7 实战：用算法重写常见任务

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>

int main() {
    std::vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // 任务 1：求和、平均值
    double avg = std::accumulate(v.begin(), v.end(), 0.0) / v.size();

    // 任务 2：找出所有偶数并平方
    std::vector<int> evenSquares;
    std::copy_if(v.begin(), v.end(), std::back_inserter(evenSquares),
                 [](int x) { return x % 2 == 0; });
    std::transform(evenSquares.begin(), evenSquares.end(), evenSquares.begin(),
                   [](int x) { return x * x; });
    std::cout << "偶数平方: ";
    for (int x : evenSquares) std::cout << x << " ";
    std::cout << "\n";     // 4 64 16 36

    // 任务 3：去重并排序
    std::vector<int> dup = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::sort(dup.begin(), dup.end());
    dup.erase(std::unique(dup.begin(), dup.end()), dup.end());
    std::cout << "去重排序: ";
    for (int x : dup) std::cout << x << " ";
    std::cout << "\n";     // 1 2 3 4 5 6 9

    // 任务 4：统计满足条件的元素
    int aboveAvg = std::count_if(v.begin(), v.end(),
                                 [avg](int x) { return x > avg; });
    std::cout << "高于平均的有 " << aboveAvg << " 个\n";

    // 任务 5：把字符串转成大写
    std::string s = "hello world";
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    std::cout << s << "\n";     // HELLO WORLD

    // 任务 6：检查是否所有元素都满足条件
    bool allPositive = std::all_of(v.begin(), v.end(), [](int x) { return x > 0; });
    std::cout << std::boolalpha << "全是正数? " << allPositive << "\n";

    // 任务 7：找出第一个满足条件的元素的位置
    auto it = std::find_if(v.begin(), v.end(), [](int x) { return x > 7; });
    if (it != v.end()) {
        std::cout << "第一个 >7 的是 " << *it << "，在下标 "
                  << (it - v.begin()) << "\n";
    }

    // 任务 8：分组成绩等级
    std::vector<int> scores = {95, 82, 71, 60, 45, 88, 93};
    std::map<std::string, int> gradeCount;
    std::for_each(scores.begin(), scores.end(), [&gradeCount](int s) {
        if (s >= 90)      gradeCount["优秀"]++;
        else if (s >= 80) gradeCount["良好"]++;
        else if (s >= 60) gradeCount["及格"]++;
        else              gradeCount["不及格"]++;
    });
    for (const auto& [grade, count] : gradeCount) {
        std::cout << grade << ": " << count << " 人\n";
    }

    return 0;
}
```

## 20.8 练习

1. 用算法找出 `vector<int>` 中的最大值和最小值及其下标。
2. 用 `std::transform` 把一个字符串转成全大写。
3. 用 lambda 和 `std::sort` 按字符串长度排序一个 `vector<string>`。
4. 用 `std::count_if` 统计一个 `vector<int>` 中能被 3 整除的数的个数。
5. 用 `std::accumulate` 计算 `vector<double>` 的平均值。
6. 用 `std::partition` 把 `vector<int>` 分成奇数和偶数两部分。
7. 给定一个单词列表，用算法找出所有长度大于 5 的单词并排序。

**参考答案：**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cctype>

int main() {
    // 练习 1
    std::vector<int> v = {5, 2, 8, 1, 9, 3};
    auto maxIt = std::max_element(v.begin(), v.end());
    auto minIt = std::min_element(v.begin(), v.end());
    std::cout << "最大 " << *maxIt << " 在下标 " << (maxIt - v.begin()) << "\n";
    std::cout << "最小 " << *minIt << " 在下标 " << (minIt - v.begin()) << "\n";

    // 练习 2
    std::string s = "Hello World 123";
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    std::cout << s << "\n";     // HELLO WORLD 123

    // 练习 3
    std::vector<std::string> words = {"banana", "hi", "apple", "cat", "elephant"};
    std::sort(words.begin(), words.end(),
              [](const std::string& a, const std::string& b) {
                  return a.size() < b.size();
              });
    for (const auto& w : words) std::cout << w << "(" << w.size() << ") ";
    std::cout << "\n";

    // 练习 4
    std::vector<int> nums = {1, 3, 6, 9, 10, 12, 15, 20};
    int divisibleBy3 = std::count_if(nums.begin(), nums.end(),
                                     [](int x) { return x % 3 == 0; });
    std::cout << "能被 3 整除: " << divisibleBy3 << " 个\n";   // 5

    // 练习 5
    std::vector<double> d = {1.5, 2.5, 3.0, 4.0};
    double avg = std::accumulate(d.begin(), d.end(), 0.0) / d.size();
    std::cout << "平均值: " << avg << "\n";     // 2.75

    // 练习 6
    std::vector<int> mixed = {1, 2, 3, 4, 5, 6, 7, 8};
    auto boundary = std::partition(mixed.begin(), mixed.end(),
                                   [](int x) { return x % 2 == 0; });
    std::cout << "偶数部分: ";
    for (auto it = mixed.begin(); it != boundary; ++it) std::cout << *it << " ";
    std::cout << "\n奇数部分: ";
    for (auto it = boundary; it != mixed.end(); ++it) std::cout << *it << " ";
    std::cout << "\n";

    // 练习 7
    std::vector<std::string> longWords;
    std::copy_if(words.begin(), words.end(), std::back_inserter(longWords),
                 [](const std::string& w) { return w.size() > 5; });
    std::sort(longWords.begin(), longWords.end());
    std::cout << "长度 >5 的单词: ";
    for (const auto& w : longWords) std::cout << w << " ";
    std::cout << "\n";         // banana elephant

    return 0;
}
```

---

# 第 21 章 · 迭代器与范围 for

## 21.1 什么是迭代器？

**迭代器是"遍历容器的通用指针"。** 它是容器和算法之间的桥梁。

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};

    // 迭代器遍历
    std::vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        std::cout << *it << " ";      // 像指针一样解引用
        ++it;                          // 像指针一样前进
    }
    std::cout << "\n";

    // 用 auto 简化
    for (auto it2 = v.begin(); it2 != v.end(); ++it2) {
        std::cout << *it2 << " ";
    }
    std::cout << "\n";

    return 0;
}
```

**`begin()` 指向第一个元素，`end()` 指向"最后一个元素的后面"（不是最后一个元素！）**

```
   v = [10][20][30][40][50]
        ↑                    ↑
     begin()              end()
                       （哨兵位置，不能解引用）
```

**为什么 `end()` 在最后一个之后？** 这样 `begin() == end()` 就自然表示"空容器"，循环条件 `it != end()` 也统一好看。

## 21.2 各类迭代器

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // 正向迭代器
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 反向迭代器
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";     // 5 4 3 2 1

    // const 迭代器（不能修改元素）
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << " ";
        // *it = 99;      // ❌ 编译错误
    }
    std::cout << "\n";

    // 常量反向
    for (auto it = v.crbegin(); it != v.crend(); ++it) { }

    // 修改元素
    for (auto it = v.begin(); it != v.end(); ++it) {
        *it *= 10;
    }
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";     // 10 20 30 40 50

    // 迭代器算术（vector 支持随机访问）
    auto it = v.begin();
    std::cout << *(it + 2) << "\n";        // 30
    std::cout << *(v.end() - 1) << "\n";   // 50
    std::cout << v.end() - v.begin() << "\n";   // 5（元素个数）

    return 0;
}
```

## 21.3 迭代器的五种类型（了解）

| 类型 | 能力 | 例子 |
|---|---|---|
| 输入迭代器 | 只读，单向，单遍 | `istream_iterator` |
| 输出迭代器 | 只写，单向，单遍 | `ostream_iterator`, `back_inserter` |
| 前向迭代器 | 读写，单向，多遍 | `forward_list` |
| 双向迭代器 | 读写，双向 | `list`, `set`, `map` |
| 随机访问迭代器 | 读写，任意跳转，支持 `[]` `+` `-` | `vector`, `deque`, `array` |

**为什么重要？** 因为某些算法需要特定的迭代器能力：

```cpp
std::sort(v.begin(), v.end());      // 需要随机访问 → std::list 不能用！
// std::sort(l.begin(), l.end());   // ❌ 编译错误

l.sort();                            // list 有自己的 sort（归并排序）
```

**这就是为什么 `std::list` 有自己的 `sort`、`reverse`、`unique`。**

## 21.4 范围 for 循环（C++11）

**最简洁的遍历方式。**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    // 数组
    int arr[] = {1, 2, 3};
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    // vector
    std::vector<std::string> words = {"hello", "world"};
    for (const std::string& w : words) std::cout << w << " ";
    std::cout << "\n";

    // map（结构化绑定）
    std::map<std::string, int> ages = {{"Alice", 25}, {"Bob", 30}};
    for (const auto& [name, age] : ages) {
        std::cout << name << ": " << age << "\n";
    }

    // 修改元素（用引用）
    std::vector<int> v = {1, 2, 3};
    for (int& x : v) x *= 2;
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";     // 2 4 6

    // 初始化列表
    for (int x : {10, 20, 30}) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
```

### ⭐ `for (auto x : v)` vs `for (const auto& x : v)`

```cpp
std::vector<std::string> words = {"a", "b", "c"};

// ❌ 拷贝：每个 string 都被完整复制一次（慢！）
for (auto w : words) { }

// ✅ const 引用：不复制，只能读（推荐，只读时用）
for (const auto& w : words) { }

// ✅ 引用：不复制，可以改
for (auto& w : words) { w += "!"; }

// ✅ 拷贝：确实需要独立副本时
for (auto w : words) { w += "!"; }        // 改的是副本，原容器不变
```

**⭐ 记住：只读用 `const auto&`，要改用 `auto&`，基本类型（int/double）可以直接 `auto`。**

### ⚠️ 范围 for 的陷阱

```cpp
#include <iostream>
#include <vector>
#include <string>

std::vector<int>& getTempVector() {
    static std::vector<int> v = {1, 2, 3};
    return v;
}

int main() {
    // ❌ 陷阱 1：在循环里修改容器大小
    std::vector<int> v = {1, 2, 3};
    // for (int x : v) { v.push_back(x); }    // 未定义行为！

    // ⚠️ 陷阱 2：范围 for 遍历时 erase
    // for (auto it : v) { }  // 别想用范围 for 做删除，用显式迭代器

    // ⚠️ 陷阱 3：遍历一个返回临时对象又不用引用的函数
    // for (int x : getTempVector()) { }      // ✅ 这个其实没问题（生命周期延长）

    // ⚠️ 陷阱 4：修改元素但忘了 &
    std::vector<int> w = {1, 2, 3};
    for (int x : w) { x *= 10; }             // ❌ 改的是副本！
    for (int x : w) std::cout << x << " ";
    std::cout << "\n";                        // 1 2 3（没变）

    for (int& x : w) { x *= 10; }            // ✅
    for (int x : w) std::cout << x << " ";
    std::cout << "\n";                        // 10 20 30

    return 0;
}
```

## 21.5 迭代器适配器

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // back_inserter：往容器尾部插入
    std::vector<int> dest;
    std::copy(v.begin(), v.end(), std::back_inserter(dest));    // dest = {1,2,3,4,5}

    // front_inserter：往头部插入（需要 push_front）
    std::list<int> lst;
    std::copy(v.begin(), v.end(), std::front_inserter(lst));    // lst = 5,4,3,2,1

    // inserter：在指定位置插入
    std::vector<int> v2 = {1, 5};
    std::copy(v.begin() + 1, v.begin() + 4, std::inserter(v2, v2.begin() + 1));
    // v2 = {1, 2, 3, 4, 5}

    // ostream_iterator：输出到流
    std::cout << "输出: ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    // istream_iterator：从流读取
    // std::vector<int> input{std::istream_iterator<int>(std::cin),
    //                        std::istream_iterator<int>()};

    // reverse_iterator
    std::vector<int> rev(v.rbegin(), v.rend());    // {5,4,3,2,1}

    // move_iterator：移动元素而不是复制
    std::vector<std::string> src = {"a", "b", "c"};
    std::vector<std::string> dst(std::make_move_iterator(src.begin()),
                                 std::make_move_iterator(src.end()));

    return 0;
}
```

## 21.6 `std::advance`、`std::next`、`std::distance`

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};

    auto it = v.begin();

    // advance：就地前进 n 步（对 vector 是 O(1)，对 list 是 O(n)）
    std::advance(it, 2);
    std::cout << *it << "\n";          // 30

    // next：返回前进 n 步后的迭代器（不改原迭代器）
    auto it2 = std::next(v.begin(), 3);
    std::cout << *it2 << "\n";         // 40

    // prev：后退
    auto it3 = std::prev(v.end(), 1);
    std::cout << *it3 << "\n";         // 50

    // distance：两个迭代器之间有多少元素
    std::cout << std::distance(v.begin(), v.end()) << "\n";   // 5

    // 对链表也适用
    std::list<int> l = {1, 2, 3, 4, 5};
    auto lit = l.begin();
    std::advance(lit, 3);              // 对 list 是 O(n)
    std::cout << *lit << "\n";         // 4

    return 0;
}
```

## 21.7 迭代器 vs 下标

| | 下标 `v[i]` | 迭代器 `it` |
|---|---|---|
| 支持容器 | 只有 `vector`/`deque`/`array`/`string` | 所有容器 |
| 语法 | 简洁 | 稍繁 |
| 越界检查 | 无 | 无 |
| 通用性 | 低 | 高（算法都用它） |
| 适用 | 需要随机访问、下标有意义时 | 遍历、传算法 |

**实践建议：**

- **遍历所有元素** → 范围 for
- **需要下标/随机访问** → 下标
- **传给 STL 算法** → 迭代器
- **需要在遍历中删除** → 迭代器（`it = v.erase(it)`）

## 21.8 遍历中安全删除元素

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    // vector：erase 返回下一个有效迭代器
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    for (auto it = v.begin(); it != v.end(); ) {
        if (*it % 2 == 0) {
            it = v.erase(it);       // ✅ erase 返回下一个位置
        } else {
            ++it;
        }
    }
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";              // 1 3 5

    // map：C++11 起 erase 也返回下一个迭代器
    std::map<std::string, int> ages = {{"a", 1}, {"b", 2}, {"c", 3}};
    for (auto it = ages.begin(); it != ages.end(); ) {
        if (it->second % 2 == 0) {
            it = ages.erase(it);
        } else {
            ++it;
        }
    }
    for (const auto& [k, val] : ages) std::cout << k << "=" << val << " ";
    std::cout << "\n";              // a=1 c=3

    // 更现代的做法（C++20）：erase_if
    // std::erase_if(v, [](int x) { return x > 3; });
    // std::erase_if(ages, [](const auto& p) { return p.second > 2; });

    return 0;
}
```

**⚠️ 不要这样做：**

```cpp
// ❌ 错误：erase 之后 it 失效，++it 是未定义行为
for (auto it = v.begin(); it != v.end(); ++it) {
    if (*it % 2 == 0) v.erase(it);
}
```

## 21.9 练习

1. 用迭代器遍历一个 `vector<int>`，把所有负数变成正数。
2. 用反向迭代器输出一个字符串。
3. 用 `std::copy` 和 `back_inserter` 把一个 `vector` 中所有大于 5 的元素复制到另一个。
4. 用迭代器删除 `map` 中值小于 60 的条目。
5. 手写一个模板函数 `void printAll(Iterator begin, Iterator end)` 打印任意容器。

**参考答案：**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>

// 练习 5
template <typename Iterator>
void printAll(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main() {
    // 练习 1
    std::vector<int> v = {-1, 2, -3, 4, -5};
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (*it < 0) *it = -*it;
    }
    printAll(v.begin(), v.end());       // 1 2 3 4 5

    // 练习 2
    std::string s = "Hello";
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << "\n";                  // olleH

    // 练习 3
    std::vector<int> src = {3, 7, 1, 9, 4, 8};
    std::vector<int> dst;
    std::copy_if(src.begin(), src.end(), std::back_inserter(dst),
                 [](int x) { return x > 5; });
    printAll(dst.begin(), dst.end());   // 7 9 8

    // 练习 4
    std::map<std::string, int> scores = {
        {"张三", 90}, {"李四", 55}, {"王五", 72},
        {"赵六", 45}, {"钱七", 88}
    };
    for (auto it = scores.begin(); it != scores.end(); ) {
        if (it->second < 60) {
            it = scores.erase(it);
        } else {
            ++it;
        }
    }
    std::cout << "及格的人:\n";
    for (const auto& [name, score] : scores) {
        std::cout << "  " << name << ": " << score << "\n";
    }

    // 练习 5 演示：适用于任何容器
    std::vector<double> dv = {1.1, 2.2, 3.3};
    printAll(dv.begin(), dv.end());

    std::string str = "abc";
    printAll(str.begin(), str.end());

    int arr[] = {9, 8, 7};
    printAll(std::begin(arr), std::end(arr));

    return 0;
}
```

---

# 第 22 章 · 动态内存与智能指针

## 22.1 内存分区

C++ 程序的内存大致分几块：

```
高地址
  ┌──────────────┐
  │   栈 (stack) │  ← 局部变量、函数参数。自动管理，大小有限（通常 1-8 MB）
  │      ↓       │     向下增长
  ├──────────────┤
  │      ↑       │
  │   堆 (heap)  │  ← new/malloc 分配。手动管理（或智能指针），空间大
  ├──────────────┤
  │  BSS/数据段  │  ← 全局变量、static 变量
  ├──────────────┤
  │   代码段     │  ← 程序指令（只读）
  └──────────────┘
低地址
```

**栈上的东西自动释放，堆上的东西要手动管理（或用智能指针）。**

## 22.2 `new` 和 `delete`

```cpp
#include <iostream>

int main() {
    // 分配单个对象
    int* p = new int(42);           // 在堆上创建 int，值为 42
    std::cout << *p << "\n";        // 42
    *p = 100;
    delete p;                        // 释放
    p = nullptr;                     // 好习惯：置空，避免悬空指针

    // 不初始化
    int* q = new int;                // 值是垃圾
    delete q;

    // 默认初始化
    int* r = new int();              // 值为 0
    delete r;

    // 数组
    int* arr = new int[10];          // 10 个 int（未初始化）
    for (int i = 0; i < 10; i++) arr[i] = i;
    delete[] arr;                    // ⚠️ 数组要用 delete[]！

    // 值初始化数组
    int* zeros = new int[10]();      // 全 0
    delete[] zeros;

    // 自定义类型
    std::string* s = new std::string("hello");
    std::cout << *s << "\n";
    delete s;
    s = nullptr;

    return 0;
}
```

**⭐ 铁律：**

| 分配方式 | 释放方式 |
|---|---|
| `new T` | `delete p` |
| `new T[n]` | `delete[] p` |

**`new` 配 `delete`，`new[]` 配 `delete[]`，绝不能混！** 混用是未定义行为。

## 22.3 常见内存错误（务必认识）

### 1. 内存泄漏（Memory Leak）

```cpp
void leak() {
    int* p = new int[1000];
    // 忘了 delete[] ！
}   // p 是局部变量被销毁了，但堆上那 1000 个 int 永远无法访问了
```

**症状**：程序运行越久占用内存越多，最终被系统杀掉。

**检查工具**：`-fsanitize=address`（AddressSanitizer），或 Valgrind（Linux）。

### 2. 悬空指针（Dangling Pointer）

```cpp
int* p = new int(42);
delete p;
// *p = 10;         // ❌ 访问已释放的内存（use-after-free）
p = nullptr;        // ✅ 及时置空，这样后面 p != nullptr 检查有用
```

### 3. 双重释放（Double Free）

```cpp
int* p = new int(42);
delete p;
delete p;           // 💥 崩溃或未定义行为
```

### 4. 越界访问

```cpp
int* arr = new int[10];
arr[10] = 1;        // ❌ 越界
delete[] arr;
```

### 5. 返回局部变量的地址

```cpp
int* bad() {
    int local = 42;
    return &local;   // ❌ local 已销毁
}
```

### 6. `new` 失败

```cpp
// 默认情况下 new 失败会抛 std::bad_alloc
try {
    int* huge = new int[1000000000000ULL];
} catch (const std::bad_alloc& e) {
    std::cout << "内存不足: " << e.what() << "\n";
}

// nothrow 版本：失败返回 nullptr
int* p = new (std::nothrow) int[1000000000000ULL];
if (p == nullptr) {
    std::cout << "分配失败\n";
}
```

### 用 AddressSanitizer 抓这些 bug

```bash
g++ -std=c++17 -g -fsanitize=address,undefined main.cpp -o main
./main
```

**输出的报错会精确到行号**，比如：

```
==1234==ERROR: AddressSanitizer: heap-use-after-free on address 0x...
READ of size 4 at 0x... thread T0
    #0 0x... in main main.cpp:5
```

**⭐ 强烈建议：所有开发中的 C++ 程序都加上 `-fsanitize=address,undefined`。**

## 22.4 智能指针（现代 C++ 的答案）

**智能指针 = 自动管理内存的指针。** 出作用域时自动 `delete`，不用你操心。

需要 `#include <memory>`。

### `std::unique_ptr`：独占所有权

```cpp
#include <iostream>
#include <memory>
#include <string>

class Resource {
    std::string name_;
public:
    explicit Resource(const std::string& name) : name_(name) {
        std::cout << "获取资源: " << name_ << "\n";
    }
    ~Resource() {
        std::cout << "释放资源: " << name_ << "\n";
    }
    void use() const { std::cout << "使用 " << name_ << "\n"; }
};

int main() {
    {
        // ✅ 推荐用 make_unique 创建
        std::unique_ptr<Resource> p = std::make_unique<Resource>("A");
        p->use();
        // 不需要 delete！离开作用域自动释放
    }
    std::cout << "--- 出了作用域 ---\n";

    // 独占所有权：不能复制！
    auto p2 = std::make_unique<Resource>("B");
    // std::unique_ptr<Resource> p3 = p2;              // ❌ 编译错误
    std::unique_ptr<Resource> p4 = std::move(p2);      // ✅ 移动（转移所有权）
    // 现在 p2 是空的，p4 拥有对象

    if (p2 == nullptr) {
        std::cout << "p2 已经空了\n";
    }
    p4->use();
    std::cout << "p4 是否为空? " << std::boolalpha << (p4 == nullptr) << "\n";

    // 数组版本
    auto arr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; i++) arr[i] = i * i;
    for (int i = 0; i < 5; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    // 释放所有权（交给别人管理）
    Resource* raw = p4.release();      // p4 变空，raw 指向对象
    delete raw;                         // 现在要手动删了

    // 重置（释放当前对象，可选接管新对象）
    auto p5 = std::make_unique<Resource>("C");
    p5.reset();                         // 释放 C
    p5.reset(new Resource("D"));        // 接管 D

    return 0;
}
```

**`unique_ptr` 是零开销的**：它的大小和裸指针一样，性能也一样。**默认就用它。**

### `std::shared_ptr`：共享所有权

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Resource {
    std::string name_;
public:
    explicit Resource(const std::string& name) : name_(name) {
        std::cout << "创建 " << name_ << "\n";
    }
    ~Resource() {
        std::cout << "销毁 " << name_ << "\n";
    }
    void use() const { std::cout << "使用 " << name_ << "\n"; }
    const std::string& name() const { return name_; }
};

int main() {
    auto p1 = std::make_shared<Resource>("共享资源");
    std::cout << "引用计数: " << p1.use_count() << "\n";    // 1

    {
        auto p2 = p1;                    // ✅ 可以复制！
        std::cout << "引用计数: " << p1.use_count() << "\n";   // 2

        std::vector<std::shared_ptr<Resource>> vec;
        vec.push_back(p1);
        std::cout << "引用计数: " << p1.use_count() << "\n";   // 3
    }                                     // p2 和 vec 销毁

    std::cout << "引用计数: " << p1.use_count() << "\n";    // 1
    p1->use();

    std::cout << "--- p1 即将销毁 ---\n";
    return 0;
    // 引用计数归 0 时，对象才真正被销毁
}
```

**引用计数归 0 才释放。**

### ⚠️ `shared_ptr` 的循环引用问题

```cpp
#include <iostream>
#include <memory>

struct Node {
    std::string name;
    std::shared_ptr<Node> next;      // ❌ 用 shared_ptr 会循环引用
    // std::weak_ptr<Node> next;     // ✅ 改用 weak_ptr

    explicit Node(const std::string& n) : name(n) {
        std::cout << "创建 " << name << "\n";
    }
    ~Node() { std::cout << "销毁 " << name << "\n"; }
};

int main() {
    {
        auto a = std::make_shared<Node>("A");
        auto b = std::make_shared<Node>("B");

        a->next = b;      // b 的引用计数 = 2
        b->next = a;      // a 的引用计数 = 2
    }
    // 离开作用域：a 和 b 的引用计数都从 2 减到 1，都不为 0
    // → 谁也不会被销毁 → 内存泄漏！
    std::cout << "--- 出了作用域，但没有看到销毁输出 ---\n";
    return 0;
}
```

**解决：用 `std::weak_ptr` 打破循环。**

### `std::weak_ptr`：不增加引用计数的观察者

```cpp
#include <iostream>
#include <memory>

struct Node {
    std::string name;
    std::weak_ptr<Node> next;        // ✅ weak_ptr 不增加引用计数

    explicit Node(const std::string& n) : name(n) {
        std::cout << "创建 " << name << "\n";
    }
    ~Node() { std::cout << "销毁 " << name << "\n"; }
};

int main() {
    {
        auto a = std::make_shared<Node>("A");
        auto b = std::make_shared<Node>("B");

        a->next = b;                 // weak_ptr，引用计数不变
        b->next = a;

        // 访问 weak_ptr：要先 lock() 提升为 shared_ptr
        if (auto locked = a->next.lock()) {
            std::cout << "a->next 是 " << locked->name << "\n";
        }

        std::cout << "a 引用计数: " << a.use_count() << "\n";   // 1
    }
    // 现在能正确销毁了
    std::cout << "--- 正确销毁 ---\n";

    // weak_ptr 的其他用法
    auto sp = std::make_shared<int>(42);
    std::weak_ptr<int> wp = sp;
    std::cout << "过期? " << std::boolalpha << wp.expired() << "\n";   // false
    sp.reset();
    std::cout << "过期? " << wp.expired() << "\n";                     // true
    if (auto locked = wp.lock()) {
        // 不会进这里
    } else {
        std::cout << "对象已销毁\n";
    }

    return 0;
}
```

### 三种智能指针对比

| | `unique_ptr` | `shared_ptr` | `weak_ptr` |
|---|---|---|---|
| 所有权 | 独占 | 共享 | 不拥有 |
| 可否复制 | ❌（只能移动） | ✅ | ✅ |
| 开销 | 零（同裸指针） | 大（引用计数 + 控制块） | 中 |
| 何时用 | **默认选择** | 确实需要共享时 | 打破循环、观察者模式 |

**⭐ 选择顺序：`unique_ptr` → 需要共享才用 `shared_ptr` → 需要打破循环才用 `weak_ptr`。**

## 22.5 `make_unique` / `make_shared` 的好处

```cpp
// ❌ 用 new
std::shared_ptr<Foo> p1(new Foo(1, 2, 3));

// ✅ 用 make_shared
auto p2 = std::make_shared<Foo>(1, 2, 3);
```

**好处：**

1. **更简洁**，不用重复写类型
2. **异常安全**：`new Foo()` 成功但 `shared_ptr` 构造失败时会泄漏；`make_shared` 不会
3. **`make_shared` 更快**：一次分配（对象 + 控制块在一起）而不是两次
4. **`make_unique` 不存在类型名重复的隐患**

> **`make_shared` 的一个小缺点**：因为对象和控制块在一起，只要有一个 `weak_ptr` 存在，整块内存（包括对象）就不能释放。极少数场景下（大对象 + 长寿命 weak_ptr）需要用 `shared_ptr<T>(new T)`。

## 22.6 智能指针作为函数参数/返回值

```cpp
#include <iostream>
#include <memory>

class Widget {
public:
    void draw() { std::cout << "画 Widget\n"; }
};

// 1) 只观察，不涉及所有权 → 用裸指针或引用（不要用智能指针！）
void observe(const Widget& w) {
    // w.draw();  // 但 draw 不是 const
}
void observePtr(Widget* w) {
    if (w) w->draw();
}

// 2) 只是想读取 unique_ptr 指向的对象
void readOnly(const std::unique_ptr<Widget>& w) {   // 但要传智能指针本身
    if (w) w->draw();
}

// 3) 要转移所有权 → 按值接收 unique_ptr
void takeOwnership(std::unique_ptr<Widget> w) {
    w->draw();
}   // 这里销毁

// 4) 要共享所有权 → 按值接收 shared_ptr
void share(std::shared_ptr<Widget> w) {
    std::cout << "引用计数: " << w.use_count() << "\n";
}

// 5) 工厂函数：返回 unique_ptr
std::unique_ptr<Widget> createWidget() {
    return std::make_unique<Widget>();
}

int main() {
    auto w = std::make_unique<Widget>();

    observePtr(w.get());          // ✅ .get() 拿裸指针（不转移所有权）
    observe(*w);
    readOnly(w);

    // takeOwnership(w);          // ❌ 不能复制
    takeOwnership(std::move(w));  // ✅ 转移所有权
    // w 现在是空的

    auto s = std::make_shared<Widget>();
    share(s);                     // 引用计数暂时变 2

    auto w2 = createWidget();     // 接收工厂返回的 unique_ptr
    w2->draw();

    return 0;
}
```

**⭐ 重要原则：函数参数不要滥用智能指针。**

| 你想表达 | 参数类型 |
|---|---|
| "我要用一下，不管生命周期" | `T&` 或 `const T&` 或 `T*` |
| "我要接过来管理" | `std::unique_ptr<T>`（按值） |
| "我要参与共享" | `std::shared_ptr<T>`（按值） |
| "我要看看这个智能指针是否为空" | `const std::unique_ptr<T>&` |

## 22.7 数组与 `new[]` 的替代方案

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <array>

int main() {
    // C++17 之前：手动管理
    int* raw = new int[100];
    // ... 用 ...
    delete[] raw;

    // ✅ 方案 1：vector（最常用）
    std::vector<int> v(100);

    // ✅ 方案 2：unique_ptr 数组
    auto arr = std::make_unique<int[]>(100);
    arr[0] = 42;

    // ✅ 方案 3：固定大小用 array
    std::array<int, 100> a{};

    // ⚠️ 不要用 shared_ptr<int[]>（C++17 才支持，而且不常用）
    // auto sp = std::make_shared<int[]>(100);   // C++20

    return 0;
}
```

## 22.8 完整对比：手写 vs 智能指针

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Employee {
    std::string name_;
    double salary_;
public:
    Employee(const std::string& n, double s) : name_(n), salary_(s) {}
    const std::string& name() const { return name_; }
    double salary() const { return salary_; }
    void raise(double pct) { salary_ *= (1 + pct / 100); }
};

int main() {
    // ❌ 手动管理：容易泄漏，异常不安全
    {
        std::vector<Employee*> staff;
        staff.push_back(new Employee("A", 1000));
        staff.push_back(new Employee("B", 2000));

        // 如果这里抛异常...
        // throw std::runtime_error("oops");

        for (auto* e : staff) delete e;      // 别忘了
    }

    // ✅ 智能指针：自动、异常安全
    {
        std::vector<std::unique_ptr<Employee>> staff;
        staff.push_back(std::make_unique<Employee>("A", 1000));
        staff.push_back(std::make_unique<Employee>("B", 2000));
        staff.emplace_back(std::make_unique<Employee>("C", 3000));

        // 抛异常也没事，unique_ptr 会清理
        // throw std::runtime_error("oops");

        for (const auto& e : staff) {
            std::cout << e->name() << ": " << e->salary() << "\n";
        }
    }   // 自动全部释放

    return 0;
}
```

## 22.9 练习

1. 用 `unique_ptr` 管理一个动态数组，实现"填充 1..n 并打印"。
2. 用 `shared_ptr` 让两个对象共享同一个资源，打印引用计数的变化。
3. 写一个工厂函数返回 `unique_ptr` 指向的对象。
4. 用 `weak_ptr` 实现一个简单的缓存：能检查对象是否还活着。
5. 找出下面代码的所有问题：

```cpp
void f() {
    int* a = new int[10];
    int* b = a;
    delete a;
    delete[] b;
}
```

**参考答案：**

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class ExpensiveResource {
public:
    std::string name;
    explicit ExpensiveResource(const std::string& n) : name(n) {
        std::cout << "  构造 " << name << "\n";
    }
    ~ExpensiveResource() {
        std::cout << "  析构 " << name << "\n";
    }
};

// 练习 3
std::unique_ptr<ExpensiveResource> createResource(const std::string& name) {
    return std::make_unique<ExpensiveResource>(name);
}

// 练习 4：简单的缓存
class ResourceCache {
private:
    std::vector<std::weak_ptr<ExpensiveResource>> cache_;
public:
    void add(const std::shared_ptr<ExpensiveResource>& res) {
        cache_.push_back(res);
    }

    void printAlive() const {
        std::cout << "缓存中仍存活的资源: ";
        bool any = false;
        for (const auto& wp : cache_) {
            if (auto sp = wp.lock()) {
                std::cout << sp->name << " ";
                any = true;
            }
        }
        if (!any) std::cout << "（无）";
        std::cout << "\n";
    }
};

int main() {
    // 练习 1
    std::cout << "=== 练习 1 ===\n";
    constexpr int N = 5;
    auto arr = std::make_unique<int[]>(N);
    for (int i = 0; i < N; i++) arr[i] = i + 1;
    for (int i = 0; i < N; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    // 练习 2
    std::cout << "\n=== 练习 2 ===\n";
    {
        auto shared = std::make_shared<ExpensiveResource>("共享");
        std::cout << "计数: " << shared.use_count() << "\n";      // 1
        {
            auto copy1 = shared;
            auto copy2 = shared;
            std::cout << "计数: " << shared.use_count() << "\n";  // 3
        }
        std::cout << "计数: " << shared.use_count() << "\n";      // 1
    }

    // 练习 3
    std::cout << "\n=== 练习 3 ===\n";
    {
        auto res = createResource("工厂创建");
        std::cout << "名字: " << res->name << "\n";
    }

    // 练习 4
    std::cout << "\n=== 练习 4 ===\n";
    ResourceCache cache;
    {
        auto r1 = std::make_shared<ExpensiveResource>("R1");
        auto r2 = std::make_shared<ExpensiveResource>("R2");
        cache.add(r1);
        cache.add(r2);
        cache.printAlive();      // R1 R2
    }
    cache.printAlive();          // 无（都销毁了）

    // 练习 5 的问题：
    std::cout << "\n=== 练习 5 问题分析 ===\n";
    std::cout << "1) new int[10] 分配的是数组，必须用 delete[]，但代码里用了 delete a —— 不匹配，未定义行为\n";
    std::cout << "2) a 和 b 指向同一块内存，delete a 之后 b 成为悬空指针\n";
    std::cout << "3) delete[] b 是二次释放（double free）—— 未定义行为，通常崩溃\n";
    std::cout << "正确写法：只用 int* a = new int[10]; delete[] a; 不要 b\n";

    return 0;
}
```

---

# 第 23 章 · 移动语义与右值引用

**这是现代 C++ 最"高级"的话题之一。理解它能让你写出高性能代码，也能看懂标准库的设计。**

**如果第一遍看不懂，可以先跳过**，等用过 STL 一段时间后再回来看。

## 23.1 问题：不必要的复制

```cpp
#include <iostream>
#include <vector>
#include <string>

std::vector<int> createBigVector() {
    std::vector<int> v(1000000, 42);
    return v;                        // 返回时会不会复制 100 万个 int？
}

int main() {
    std::vector<int> data = createBigVector();
    std::cout << data.size() << "\n";
    return 0;
}
```

**在 C++11 之前，这会复制一份（或者靠编译器优化）。C++11 之后，可以用"移动"直接转移内部指针。**

## 23.2 左值 vs 右值

```cpp
int a = 10;
//  a 是左值（lvalue）：有名字，有地址，能取 &a
// 10 是右值（rvalue）：临时的，没有名字，不能取地址
```

**判断方法：**

- **左值**：能出现在 `=` 左边的，有持久身份的东西（变量、引用返回、解引用）
- **右值**：临时的、即将销毁的东西（字面量、临时对象、返回值的表达式）

```cpp
#include <iostream>
#include <string>

int main() {
    int a = 10;
    int b = a;              // a 是左值，b 是左值

    int c = a + 5;          // (a + 5) 是右值

    std::string s1 = "hello";
    std::string s2 = s1;              // s1 是左值
    std::string s3 = s1 + " world";   // (s1 + " world") 是右值（临时 string）

    // 函数返回值
    auto makeString = []() { return std::string("temp"); };
    std::string s4 = makeString();    // makeString() 返回的是右值

    // 取地址
    std::cout << &a << "\n";          // ✅ 左值可以取地址
    // std::cout << &(a + 5);         // ❌ 右值不能取地址
    // std::cout << &10;              // ❌

    // 左值引用 vs 右值引用
    int& lref = a;                    // 左值引用绑定左值
    // int& bad = 10;                 // ❌ 非 const 左值引用不能绑定右值

    const int& clref = 10;            // ✅ const 左值引用可以绑定右值
    int&& rref = 10;                  // ✅ 右值引用绑定右值
    int&& rref2 = a + 5;              // ✅
    // int&& bad2 = a;                // ❌ 右值引用不能绑定左值

    return 0;
}
```

**`T&&` 是右值引用（rvalue reference），C++11 新增。**

## 23.3 移动构造与移动赋值

**移动 = "偷走"源对象的资源，而不是复制一份。**

```cpp
#include <iostream>
#include <cstring>
#include <utility>       // std::move

class Buffer {
private:
    char* data_;
    std::size_t size_;

public:
    explicit Buffer(std::size_t size)
        : data_(new char[size]), size_(size)
    {
        std::cout << "构造 (" << size_ << " 字节)\n";
    }

    ~Buffer() {
        delete[] data_;
    }

    // 拷贝构造：深拷贝
    Buffer(const Buffer& other)
        : data_(new char[other.size_]), size_(other.size_)
    {
        std::memcpy(data_, other.data_, size_);
        std::cout << "拷贝构造 (" << size_ << " 字节) ← 慢\n";
    }

    // ⭐ 移动构造：直接偷指针
    Buffer(Buffer&& other) noexcept
        : data_(other.data_), size_(other.size_)
    {
        other.data_ = nullptr;        // 让源对象不再拥有资源
        other.size_ = 0;
        std::cout << "移动构造 (" << size_ << " 字节) ← 快\n";
    }

    // 拷贝赋值
    Buffer& operator=(const Buffer& other) {
        if (this == &other) return *this;
        delete[] data_;
        size_ = other.size_;
        data_ = new char[size_];
        std::memcpy(data_, other.data_, size_);
        std::cout << "拷贝赋值\n";
        return *this;
    }

    // ⭐ 移动赋值
    Buffer& operator=(Buffer&& other) noexcept {
        if (this == &other) return *this;
        delete[] data_;                 // 释放自己的
        data_ = other.data_;            // 偷走别人的
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
        std::cout << "移动赋值\n";
        return *this;
    }

    std::size_t size() const { return size_; }
};

Buffer createBuffer(std::size_t n) {
    return Buffer(n);
}

int main() {
    std::cout << "=== 拷贝 ===\n";
    Buffer a(1024);
    Buffer b = a;                // 拷贝构造（慢）

    std::cout << "\n=== 移动 ===\n";
    Buffer c = std::move(a);     // 移动构造（快）—— 显式移动
    std::cout << "a.size() = " << a.size() << "（已被掏空）\n";
    std::cout << "c.size() = " << c.size() << "\n";

    std::cout << "\n=== 从函数返回（自动优化） ===\n";
    Buffer d = createBuffer(2048);   // 通常被 RVO 优化掉，连移动都省了

    std::cout << "\n=== 移动赋值 ===\n";
    Buffer e(10);
    e = std::move(c);            // 移动赋值

    return 0;
}
```

**关键点：**

1. `Buffer(Buffer&& other) noexcept` —— 参数是右值引用
2. 直接偷指针，不分配新内存
3. **把源对象置为有效但空的状态**（`other.data_ = nullptr`）
4. **标记 `noexcept`**（非常重要，见下文）

## 23.4 `std::move`

**`std::move` 本身不移动任何东西！它只是一个类型转换：把左值转成右值引用。**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main() {
    std::string a = "Hello, this is a fairly long string";
    std::string b = std::move(a);      // 现在 a 的内容被"移"到 b

    std::cout << "b = " << b << "\n";
    std::cout << "a = [" << a << "] (长度 " << a.size() << ")\n";
    // a 是"有效但未指定"的状态，通常是空的
    // ⚠️ 不要依赖 a 的具体内容，只能安全地给它赋新值或销毁

    a = "重新赋值没问题";               // ✅ 可以对它重新赋值
    std::cout << "a = " << a << "\n";

    // vector 的移动
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = std::move(v1);   // 移动：O(1)，只转移内部指针
    std::cout << "v2.size() = " << v2.size() << "\n";   // 5
    std::cout << "v1.size() = " << v1.size() << "\n";   // 0

    // 放进容器（避免复制）
    std::vector<std::string> vec;
    std::string big = "非常长的字符串...";
    vec.push_back(std::move(big));          // 移动进去
    vec.emplace_back("直接构造");            // 更好：原地构造

    return 0;
}
```

**⚠️ `std::move` 之后的变量不要再用（除了重新赋值）：**

```cpp
std::string s = "hello";
std::string t = std::move(s);
std::cout << s.size();       // ⚠️ 未指定行为，通常输出 0，但标准不保证
std::cout << s[0];           // ❌ 危险！
```

## 23.5 为什么移动构造要 `noexcept`

**因为 `std::vector` 扩容时，如果元素的移动构造可能抛异常，vector 会退而求其次用拷贝构造**（为了保证强异常安全保证）。

```cpp
#include <iostream>
#include <vector>
#include <string>

class Tracked {
    std::string name_;
public:
    explicit Tracked(std::string name) : name_(std::move(name)) {}

    Tracked(const Tracked& other) : name_(other.name_) {
        std::cout << "  拷贝\n";
    }

    // 没有 noexcept
    Tracked(Tracked&& other) : name_(std::move(other.name_)) {
        std::cout << "  移动（无 noexcept）\n";
    }
};

class TrackedNoexcept {
    std::string name_;
public:
    explicit TrackedNoexcept(std::string name) : name_(std::move(name)) {}

    TrackedNoexcept(const TrackedNoexcept& other) : name_(other.name_) {
        std::cout << "  拷贝\n";
    }

    // 有 noexcept
    TrackedNoexcept(TrackedNoexcept&& other) noexcept : name_(std::move(other.name_)) {
        std::cout << "  移动（有 noexcept）✅\n";
    }
};

int main() {
    std::cout << "=== 无 noexcept 的移动 ===" << std::endl;
    std::vector<Tracked> v1;
    v1.reserve(2);
    v1.emplace_back("a");
    v1.emplace_back("b");
    std::cout << "触发扩容（会看到拷贝！）:\n";
    v1.emplace_back("c");        // 扩容 → 用拷贝而不是移动

    std::cout << "\n=== 有 noexcept 的移动 ===\n";
    std::vector<TrackedNoexcept> v2;
    v2.reserve(2);
    v2.emplace_back("a");
    v2.emplace_back("b");
    std::cout << "触发扩容（用移动）:\n";
    v2.emplace_back("c");        // 扩容 → 用移动

    return 0;
}
```

**⭐ 规则：移动构造和移动赋值一律加 `noexcept`。** 你的类会被 `std::vector` 更高效地处理。

## 23.6 返回值优化（RVO / NRVO）

```cpp
#include <iostream>
#include <string>

class Big {
public:
    Big() { std::cout << "默认构造\n"; }
    Big(const Big&) { std::cout << "拷贝构造\n"; }
    Big(Big&&) noexcept { std::cout << "移动构造\n"; }
};

Big makeRVO() {
    return Big();                 // RVO：直接在调用者的空间构造，零拷贝零移动
}

Big makeNRVO() {
    Big local;
    return local;                 // NRVO：具名返回值优化
}

Big makeMove() {
    Big local;
    return std::move(local);      // ❌ 手动 move 反而阻止了 NRVO！
}

int main() {
    std::cout << "--- makeRVO ---\n";
    Big a = makeRVO();            // 输出：默认构造（没有拷贝/移动！）

    std::cout << "--- makeNRVO ---\n";
    Big b = makeNRVO();           // 输出：默认构造

    std::cout << "--- makeMove ---\n";
    Big c = makeMove();           // 输出：默认构造 + 移动构造

    return 0;
}
```

**⭐ 结论：直接 `return obj;`，不要写 `return std::move(obj);`。** 编译器比你更懂怎么优化。

## 23.7 完美转发（进阶）

```cpp
#include <iostream>
#include <utility>
#include <string>

// ❌ 会丢失右值性：参数变成左值
void processBad(std::string s) {
    // 无论传进来什么，s 都是一个新的拷贝
}

// ⚠️ 转发引用 + perfect forwarding
template <typename T>
void wrapper(T&& arg) {                       // T&& 在模板里是"转发引用"
    process(std::forward<T>(arg));            // 保持原始的左右值性
}

void process(const std::string& s) {
    std::cout << "左值版本: " << s << "\n";
}

void process(std::string&& s) {
    std::cout << "右值版本: " << s << "\n";
}

int main() {
    std::string lv = "左值";
    wrapper(lv);                    // T = std::string&，转发为左值
    wrapper(std::string("临时"));    // T = std::string，转发为右值
    wrapper("字面量");               // T = const char(&)[...]？

    // 这解释了为什么 std::make_unique / emplace_back 那么高效：
    // 它们用完美转发把参数原样传给构造函数，一次拷贝都不多
    return 0;
}
```

> **⚠️ `T&&` 的两个含义：**
> - 在**具体类型**上下文（`void f(Widget&& w)`）：右值引用
> - 在**模板参数推导**上下文（`template<typename T> void f(T&& x)`）：**转发引用（universal reference）**，可以绑定左值和右值

## 23.8 `emplace_back` vs `push_back`

```cpp
#include <iostream>
#include <vector>
#include <string>

class Item {
    std::string name_;
    int value_;
public:
    Item(const std::string& n, int v) : name_(n), value_(v) {
        std::cout << "构造 " << name_ << "\n";
    }
    Item(const Item& o) : name_(o.name_), value_(o.value_) {
        std::cout << "拷贝 " << name_ << "\n";
    }
    Item(Item&& o) noexcept : name_(std::move(o.name_)), value_(o.value_) {
        std::cout << "移动 " << name_ << "\n";
    }
};

int main() {
    std::vector<Item> v;
    v.reserve(10);

    std::cout << "--- push_back(临时对象) ---\n";
    v.push_back(Item("A", 1));          // 构造 + 移动（编译器可能优化掉移动）

    std::cout << "\n--- push_back(已有对象) ---\n";
    Item existing("B", 2);
    v.push_back(existing);              // 拷贝
    v.push_back(std::move(existing));   // 移动

    std::cout << "\n--- emplace_back ---\n";
    v.emplace_back("C", 3);             // ⭐ 直接在 vector 内存里构造，零拷贝零移动

    std::cout << "\n大小: " << v.size() << "\n";
    return 0;
}
```

**⭐ 规则：优先用 `emplace_back` 直接传构造参数，它避免了临时对象的创建。**

```cpp
v.push_back(Item("A", 1));    // 构造临时 Item，再移动/拷贝进 vector
v.emplace_back("A", 1);       // 直接在 vector 里构造，一步到位 ✅
```

> ⚠️ 但如果已经有对象了，`push_back(std::move(obj))` 和 `emplace_back(std::move(obj))` 差不多。而且 `emplace_back` 有时会因为隐式转换带来意外（比如 `emplace_back(5)` 对 `vector<vector<int>>` 会构造 5 个元素）。

## 23.9 五法则完整示例

```cpp
#include <iostream>
#include <utility>
#include <cstring>

class String {
private:
    char* data_;
    std::size_t size_;

public:
    // 1. 普通构造
    explicit String(const char* s = "")
        : data_(new char[std::strlen(s) + 1]), size_(std::strlen(s))
    {
        std::strcpy(data_, s);
    }

    // 2. 析构
    ~String() { delete[] data_; }

    // 3. 拷贝构造
    String(const String& o) : data_(new char[o.size_ + 1]), size_(o.size_) {
        std::strcpy(data_, o.data_);
    }

    // 4. 拷贝赋值（copy-and-swap 惯用法）
    String& operator=(const String& o) {
        if (this != &o) {
            String temp(o);       // 先拷贝（如果失败，原对象不受影响）
            swap(temp);           // 再交换
        }
        return *this;             // temp 析构，释放旧数据
    }

    // 5. 移动构造
    String(String&& o) noexcept : data_(o.data_), size_(o.size_) {
        o.data_ = nullptr;
        o.size_ = 0;
    }

    // 6. 移动赋值
    String& operator=(String&& o) noexcept {
        if (this != &o) {
            delete[] data_;
            data_ = o.data_;
            size_ = o.size_;
            o.data_ = nullptr;
            o.size_ = 0;
        }
        return *this;
    }

    void swap(String& o) noexcept {
        std::swap(data_, o.data_);
        std::swap(size_, o.size_);
    }

    const char* c_str() const { return data_ ? data_ : ""; }
    std::size_t size() const { return size_; }

    // 简化：拷贝赋值也可以用这个（"五法则"其实只需写 4 个 + swap）
};

int main() {
    String a("Hello");
    String b = a;                 // 拷贝构造
    String c = std::move(a);      // 移动构造

    std::cout << "b = " << b.c_str() << "\n";
    std::cout << "c = " << c.c_str() << "\n";
    std::cout << "a.size() = " << a.size() << "（被掏空）\n";

    String d("X");
    d = b;                        // 拷贝赋值
    d = std::move(c);             // 移动赋值

    return 0;
}
```

## 23.10 什么时候该关心移动语义？

**日常写代码时**：

- ✅ 用 `std::vector`、`std::string` 等标准库类型 —— **它们已经实现了移动，你自动享受好处**
- ✅ 用 `emplace_back` 代替 `push_back(临时对象)`
- ✅ 通过 `std::move` 把大对象放进容器，避免复制
- ✅ 从函数返回值直接 `return obj;`

**写自己的类时**：

- ✅ 优先遵守**零法则**（用标准库成员，什么都不用写）
- ⚠️ 只有当你**手动管理资源**（裸指针、文件句柄、socket）时，才需要写五法则
- ✅ 如果写了移动构造，记得加 `noexcept`

## 23.11 练习

1. 写一个 `Buffer` 类，实现五法则，并在 main 里演示拷贝和移动的区别。
2. 用 `std::move` 把一个 `vector<string>` 的内容高效地转移到另一个。
3. 解释为什么 `return std::move(local);` 是坏习惯。
4. 写一个模板函数 `template<typename T> void swapValues(T& a, T& b)`，用移动语义优化。
5. 用 `emplace_back` 优化下面的代码：

```cpp
std::vector<std::pair<int, std::string>> v;
v.push_back(std::make_pair(1, "one"));
v.push_back(std::make_pair(2, "two"));
```

**参考答案：**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cstring>

// 练习 1
class Buffer {
private:
    char* data_;
    std::size_t size_;
public:
    explicit Buffer(std::size_t n) : data_(new char[n]), size_(n) {
        std::cout << "构造 " << size_ << " 字节\n";
    }
    ~Buffer() { delete[] data_; }

    Buffer(const Buffer& o) : data_(new char[o.size_]), size_(o.size_) {
        std::memcpy(data_, o.data_, size_);
        std::cout << "拷贝 " << size_ << " 字节\n";
    }
    Buffer(Buffer&& o) noexcept : data_(o.data_), size_(o.size_) {
        o.data_ = nullptr;
        o.size_ = 0;
        std::cout << "移动 " << size_ << " 字节\n";
    }
    Buffer& operator=(const Buffer& o) {
        if (this != &o) {
            delete[] data_;
            size_ = o.size_;
            data_ = new char[size_];
            std::memcpy(data_, o.data_, size_);
        }
        return *this;
    }
    Buffer& operator=(Buffer&& o) noexcept {
        if (this != &o) {
            delete[] data_;
            data_ = o.data_;
            size_ = o.size_;
            o.data_ = nullptr;
            o.size_ = 0;
        }
        return *this;
    }
    std::size_t size() const { return size_; }
};

// 练习 4
template <typename T>
void swapValues(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

int main() {
    // 练习 1
    std::cout << "=== 练习 1 ===\n";
    Buffer b1(1024);
    Buffer b2 = b1;                  // 拷贝
    Buffer b3 = std::move(b1);       // 移动
    std::cout << "移动后 b1.size() = " << b1.size() << "\n";

    // 练习 2
    std::cout << "\n=== 练习 2 ===\n";
    std::vector<std::string> src;
    for (int i = 0; i < 5; i++) src.push_back("字符串" + std::to_string(i));
    std::vector<std::string> dst = std::move(src);   // O(1) 转移
    std::cout << "src.size() = " << src.size() << ", dst.size() = " << dst.size() << "\n";
    for (const auto& s : dst) std::cout << s << " ";
    std::cout << "\n";

    // 练习 3 回答
    std::cout << "\n=== 练习 3 ===\n";
    std::cout << "return std::move(local) 会阻止 NRVO（具名返回值优化）。\n";
    std::cout << "NRVO 能让对象直接在调用者的空间里构造，连移动都不需要。\n";
    std::cout << "加了 std::move 后，编译器被迫执行一次移动构造，反而更慢。\n";
    std::cout << "正确做法：直接 return local;\n";

    // 练习 4
    std::cout << "\n=== 练习 4 ===\n";
    std::string x = "aaa", y = "bbb";
    swapValues(x, y);
    std::cout << x << " " << y << "\n";

    Buffer p(100), q(200);
    swapValues(p, q);                // 用移动交换，不复制数据
    std::cout << "交换后 p.size() = " << p.size() << ", q.size() = " << q.size() << "\n";

    // 练习 5
    std::cout << "\n=== 练习 5 ===\n";
    std::vector<std::pair<int, std::string>> v;
    // ❌ 原写法：构造临时 pair，再移动/拷贝
    v.push_back(std::make_pair(1, "one"));
    // ✅ 优化：直接用构造参数原地构造
    v.emplace_back(2, "two");
    v.emplace_back(3, "three");

    for (const auto& [id, name] : v) {
        std::cout << id << "=" << name << " ";
    }
    std::cout << "\n";

    return 0;
}
```

---


# 第 24 章 · 异常处理

## 24.1 为什么需要异常？

不用异常的话，错误处理会污染正常逻辑：

```cpp
// ❌ 错误码方式：调用者容易忘记检查，且代码混乱
int divide(int a, int b, int* result) {
    if (b == 0) return -1;
    *result = a / b;
    return 0;
}

int main() {
    int r;
    if (divide(10, 0, &r) != 0) {
        // 处理错误
    }
    // 深层调用时，每层都要检查并传递错误码，非常啰嗦
}
```

**异常把"正常流程"和"错误处理"分开了：**

```cpp
#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("除数不能为 0");    // 抛出
    }
    return a / b;
}

int main() {
    try {
        std::cout << divide(10, 2) << "\n";     // 5
        std::cout << divide(10, 0) << "\n";     // 抛异常，跳到 catch
        std::cout << "这行不会执行\n";
    } catch (const std::invalid_argument& e) {  // 捕获
        std::cout << "错误: " << e.what() << "\n";
    }
    std::cout << "程序继续\n";
    return 0;
}
```

## 24.2 `try` / `catch` / `throw`

```cpp
#include <iostream>
#include <stdexcept>
#include <string>

double safeDivide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("除以零");
    }
    return a / b;
}

void process(int value) {
    if (value < 0) {
        throw std::out_of_range("value 不能为负");
    }
    std::cout << "处理 " << value << "\n";
}

int main() {
    // 基本用法
    try {
        std::cout << safeDivide(10, 2) << "\n";
        std::cout << safeDivide(10, 0) << "\n";   // 抛出
    } catch (const std::exception& e) {
        std::cout << "捕获: " << e.what() << "\n";
    }

    // 多个 catch（从上往下匹配）
    try {
        process(-1);
    } catch (const std::out_of_range& e) {
        std::cout << "范围错误: " << e.what() << "\n";
    } catch (const std::runtime_error& e) {
        std::cout << "运行时错误: " << e.what() << "\n";
    } catch (const std::exception& e) {           // 兜底
        std::cout << "其他标准异常: " << e.what() << "\n";
    } catch (...) {                                // 捕获所有（包括非标准异常）
        std::cout << "未知异常\n";
    }

    // ⭐ 捕获顺序很重要：派生类必须在基类之前！
    // 如果把 catch (const std::exception&) 写在前面，
    // 后面的 catch 永远不会被执行

    std::cout << "程序正常结束\n";
    return 0;
}
```

## 24.3 标准异常类层次

```
std::exception                     ← 所有标准异常的基类
├── std::logic_error               ← 逻辑错误（可以在编码时避免）
│   ├── std::invalid_argument         参数无效
│   ├── std::domain_error             定义域错误
│   ├── std::length_error             超出最大长度
│   └── std::out_of_range             越界
├── std::runtime_error             ← 运行时错误（难以预防）
│   ├── std::range_error              范围错误
│   ├── std::overflow_error           上溢
│   └── std::underflow_error          下溢
├── std::bad_alloc                 ← new 失败
├── std::bad_cast                  ← dynamic_cast 引用失败
├── std::bad_typeid
└── std::ios_base::failure         ← 流操作失败
```

**常用示例：**

```cpp
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <memory>

int main() {
    // invalid_argument：参数不合法
    try {
        throw std::invalid_argument("年龄不能为负");
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    // out_of_range：.at() 越界
    try {
        std::vector<int> v = {1, 2, 3};
        std::cout << v.at(10) << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "越界: " << e.what() << "\n";
    }

    // stoi 的异常
    try {
        std::cout << std::stoi("abc") << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "解析失败: " << e.what() << "\n";
    }

    // stoi 溢出
    try {
        std::cout << std::stoi("99999999999999999999") << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "超出范围: " << e.what() << "\n";
    }

    // bad_alloc
    try {
        auto huge = std::make_unique<char[]>(1ULL << 60);
    } catch (const std::bad_alloc& e) {
        std::cout << "内存不足: " << e.what() << "\n";
    }

    return 0;
}
```

## 24.4 自定义异常类

```cpp
#include <iostream>
#include <stdexcept>
#include <string>

// 继承 std::exception 或其派生类
class FileError : public std::runtime_error {
public:
    explicit FileError(const std::string& msg)
        : std::runtime_error("文件错误: " + msg) {}
};

class NetworkError : public std::runtime_error {
private:
    int errorCode_;
public:
    NetworkError(const std::string& msg, int code)
        : std::runtime_error(msg), errorCode_(code) {}

    int code() const { return errorCode_; }
};

class ValidationError : public std::invalid_argument {
private:
    std::string field_;
public:
    ValidationError(const std::string& field, const std::string& msg)
        : std::invalid_argument(msg), field_(field) {}

    const std::string& field() const { return field_; }
};

void loadFile(const std::string& path) {
    if (path.empty()) {
        throw FileError("路径为空");
    }
    if (path == "/missing") {
        throw FileError("文件不存在: " + path);
    }
    std::cout << "加载成功: " << path << "\n";
}

void connect(const std::string& host) {
    if (host == "bad") {
        throw NetworkError("连接被拒绝", 111);
    }
    std::cout << "已连接: " << host << "\n";
}

void validateAge(int age) {
    if (age < 0) {
        throw ValidationError("age", "年龄不能为负数");
    }
    std::cout << "年龄合法: " << age << "\n";
}

int main() {
    try {
        loadFile("/missing");
    } catch (const FileError& e) {
        std::cout << "捕获 FileError: " << e.what() << "\n";
    }

    try {
        connect("bad");
    } catch (const NetworkError& e) {
        std::cout << "捕获 NetworkError: " << e.what()
                  << " (代码 " << e.code() << ")\n";
    }

    try {
        validateAge(-5);
    } catch (const ValidationError& e) {
        std::cout << "字段 '" << e.field() << "' 错误: " << e.what() << "\n";
    } catch (const std::invalid_argument& e) {
        // 也可以用基类捕获派生类异常
        std::cout << "参数错误: " << e.what() << "\n";
    }

    return 0;
}
```

**⭐ 自定义异常的建议：**

1. 继承 `std::exception` 或其合适的派生类
2. 提供有意义的 `what()` 消息
3. 可以带上额外信息（错误码、字段名）
4. 异常类应该尽量简单，不要抛异常

## 24.5 栈展开（Stack Unwinding）与 RAII

**异常抛出后，函数调用栈会一层层"展开"，每层的局部对象都会被正确析构。**

```cpp
#include <iostream>
#include <memory>
#include <stdexcept>

class Tracker {
    std::string name_;
public:
    explicit Tracker(std::string name) : name_(std::move(name)) {
        std::cout << "  构造 " << name_ << "\n";
    }
    ~Tracker() {
        std::cout << "  析构 " << name_ << "\n";
    }
};

void level3() {
    Tracker t3("level3");
    std::cout << "  level3 抛异常\n";
    throw std::runtime_error("来自 level3 的错误");
}

void level2() {
    Tracker t2("level2");
    auto ptr = std::make_unique<int>(42);     // 堆资源
    level3();
    std::cout << "  这行不会执行\n";
}

void level1() {
    Tracker t1("level1");
    level2();
}

int main() {
    try {
        Tracker tmain("main");
        level1();
    } catch (const std::exception& e) {
        std::cout << "捕获: " << e.what() << "\n";
    }
    std::cout << "程序继续\n";
    return 0;
}
```

**输出：**

```
  构造 main
  构造 level1
  构造 level2
  构造 level3
  level3 抛异常
  析构 level3      ← 栈展开，逐层析构
  析构 level2
  析构 level1
捕获: 来自 level3 的错误
  析构 main
程序继续
```

**⭐ 这就是 RAII 的价值：即使抛异常，资源也能被正确释放。这就是为什么应该用 `std::vector`、`std::string`、`unique_ptr` 而不是裸 `new`。**

## 24.6 异常安全保证

写代码时应该考虑"异常发生时，我的对象处于什么状态"。

| 级别 | 保证 | 说明 |
|---|---|---|
| **基本保证** | 对象处于有效状态，无资源泄漏 | 最低要求 |
| **强保证** | 操作要么完全成功，要么完全不变（事务语义） | 更好 |
| **不抛保证** | 承诺不抛异常（`noexcept`） | 最强 |

**实现强保证的利器：copy-and-swap**

```cpp
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>

class DataStore {
private:
    std::vector<int> data_;

public:
    // 强保证：要么全加成功，要么什么都不变
    void addAll(const std::vector<int>& items) {
        std::vector<int> newData = data_;       // 1. 先复制（如果抛异常，data_ 不变）
        for (int x : items) {
            if (x < 0) {
                throw std::invalid_argument("不能加负数");   // 此时 data_ 完好无损
            }
            newData.push_back(x);
        }
        data_ = std::move(newData);              // 2. 最后一步不抛异常地替换
    }

    std::size_t size() const { return data_.size(); }
    void print() const {
        for (int x : data_) std::cout << x << " ";
        std::cout << "\n";
    }
};

int main() {
    DataStore store;
    store.addAll({1, 2, 3});
    store.print();                    // 1 2 3

    try {
        store.addAll({4, 5, -1, 6});  // 会失败
    } catch (const std::exception& e) {
        std::cout << "失败: " << e.what() << "\n";
    }

    store.print();                    // 1 2 3 ← 完全没变（强保证）
    return 0;
}
```

## 24.7 `noexcept`

```cpp
#include <iostream>

// 承诺不抛异常
void safeFunction() noexcept {
    // throw std::runtime_error("x");   // 如果真抛了，程序直接 terminate
}

// 条件 noexcept
template <typename T>
void wrapper(T&& x) noexcept(noexcept(process(x))) { }

int main() {
    // noexcept 是运算符：检查表达式是否承诺不抛
    std::cout << std::boolalpha;
    std::cout << noexcept(safeFunction()) << "\n";     // true

    // 哪些操作是 noexcept 的
    std::cout << "vector 默认构造: " << noexcept(std::vector<int>()) << "\n";
    std::cout << "int 赋值: " << noexcept(int{}) << "\n";

    return 0;
}
```

**什么时候用 `noexcept`？**

1. **移动构造/移动赋值** —— 让 `vector` 扩容时用移动而不是拷贝
2. `swap` 函数
3. 析构函数（默认就是 `noexcept`）
4. 简单的 getter

**⚠️ 不要滥用 `noexcept`**：如果你承诺了不抛，但实际抛了，程序会立即 `std::terminate()`（连栈展开都不做）。

## 24.8 什么时候用异常，什么时候不用

**✅ 适合用异常：**

- 罕见但严重的错误（文件不存在、网络断开、内存不足）
- 构造函数失败（无法返回错误码）
- 深层调用中的错误传播
- 库的公开接口

**❌ 不适合用异常：**

- **正常的控制流**（比如遍历到尾、查找未命中）
- 性能关键的紧密循环（异常有开销，虽然只在抛出时）
- 可以轻松预防的错误（比如先检查再除）
- 跨语言边界（C 接口）
- 析构函数里（可能导致 terminate）

```cpp
// ✅ 查找失败是正常情况，返回迭代器/optional，不抛异常
auto it = map.find(key);
if (it != map.end()) { /* 找到了 */ }

// ❌ 不要为了控制流抛异常
try {
    while (true) {
        process(nextItem());     // 用异常表示"没有更多了"
    }
} catch (const NoMoreItems&) { }
```

## 24.9 一个完整的异常处理示例

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>

struct Config {
    std::string host;
    int port = 0;
    int timeout = 30;
};

class ConfigError : public std::runtime_error {
public:
    explicit ConfigError(const std::string& msg) : std::runtime_error(msg) {}
};

int parsePort(const std::string& value) {
    try {
        int port = std::stoi(value);
        if (port < 1 || port > 65535) {
            throw ConfigError("端口超出范围: " + value);
        }
        return port;
    } catch (const std::invalid_argument&) {
        throw ConfigError("端口不是数字: " + value);
    } catch (const std::out_of_range&) {
        throw ConfigError("端口数值过大: " + value);
    }
}

Config loadConfig(std::istream& input) {
    Config cfg;
    std::string line;
    int lineNum = 0;

    while (std::getline(input, line)) {
        lineNum++;
        if (line.empty() || line[0] == '#') continue;

        auto pos = line.find('=');
        if (pos == std::string::npos) {
            throw ConfigError("第 " + std::to_string(lineNum) + " 行格式错误: " + line);
        }

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        // 去空格
        auto trim = [](std::string& s) {
            auto b = s.find_first_not_of(" \t");
            auto e = s.find_last_not_of(" \t");
            s = (b == std::string::npos) ? "" : s.substr(b, e - b + 1);
        };
        trim(key);
        trim(value);

        if (key == "host")         cfg.host = value;
        else if (key == "port")    cfg.port = parsePort(value);
        else if (key == "timeout") cfg.timeout = std::stoi(value);
        else throw ConfigError("未知配置项 '" + key + "' (第 " + std::to_string(lineNum) + " 行)");
    }

    if (cfg.host.empty()) throw ConfigError("缺少必需的 host 配置");
    if (cfg.port == 0)    throw ConfigError("缺少必需的 port 配置");

    return cfg;
}

int main() {
    const char* goodConfig =
        "# 服务器配置\n"
        "host = localhost\n"
        " port = 8080 \n"
        "timeout = 60\n";

    const char* badConfig =
        "host = localhost\n"
        "port = abc\n";

    const char* badPort =
        "host = localhost\n"
        "port = 99999\n";

    for (const char* cfgText : {goodConfig, badConfig, badPort}) {
        std::cout << "===== 尝试加载配置 =====\n";
        std::istringstream iss(cfgText);
        try {
            Config cfg = loadConfig(iss);
            std::cout << "成功! host=" << cfg.host
                      << " port=" << cfg.port
                      << " timeout=" << cfg.timeout << "\n";
        } catch (const ConfigError& e) {
            std::cout << "配置错误: " << e.what() << "\n";
        } catch (const std::exception& e) {
            std::cout << "意外错误: " << e.what() << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
```

## 24.10 练习

1. 写函数 `int safeDivide(int a, int b)`，除零时抛 `std::invalid_argument`，调用方捕获并打印消息。
2. 写自定义异常 `InsufficientFundsError`（含余额和请求金额），在取款时抛出。
3. 写函数从 `vector<int>` 中按索引取值，越界抛 `std::out_of_range`。
4. 写一个 RAII 类 `FileHandle`，构造时打开文件（失败抛异常），析构时关闭。
5. 让下面的代码具备"强异常安全保证"：

```cpp
class Account {
    double balance_;
    std::vector<std::string> log_;
public:
    void transfer(double amount, Account& target) {
        balance_ -= amount;          // 如果这里之后抛异常，钱就"消失"了
        log_.push_back("transfer out");
        target.balance_ += amount;
        target.log_.push_back("transfer in");
    }
};
```

**参考答案：**

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>

// 练习 1
int safeDivide(int a, int b) {
    if (b == 0) throw std::invalid_argument("除数不能为 0");
    return a / b;
}

// 练习 2
class InsufficientFundsError : public std::runtime_error {
private:
    double balance_;
    double requested_;
public:
    InsufficientFundsError(double balance, double requested)
        : std::runtime_error("余额不足：当前 " + std::to_string(balance) +
                             "，请求 " + std::to_string(requested)),
          balance_(balance), requested_(requested) {}

    double balance() const { return balance_; }
    double requested() const { return requested_; }
};

// 练习 3
int getAt(const std::vector<int>& v, std::size_t index) {
    if (index >= v.size()) {
        throw std::out_of_range("索引 " + std::to_string(index) +
                                " 越界，大小 " + std::to_string(v.size()));
    }
    return v[index];
}

// 练习 4
class FileHandle {
private:
    std::FILE* file_;
    std::string path_;
public:
    explicit FileHandle(const std::string& path, const char* mode = "r")
        : file_(nullptr), path_(path)
    {
        file_ = std::fopen(path.c_str(), mode);
        if (file_ == nullptr) {
            throw std::runtime_error("无法打开文件: " + path);
        }
        std::cout << "  打开文件: " << path_ << "\n";
    }

    ~FileHandle() {
        if (file_ != nullptr) {
            std::fclose(file_);
            std::cout << "  关闭文件: " << path_ << "\n";
        }
    }

    // 禁用拷贝（文件句柄不能被复制）
    FileHandle(const FileHandle&) = delete;
    FileHandle& operator=(const FileHandle&) = delete;

    // 允许移动
    FileHandle(FileHandle&& o) noexcept : file_(o.file_), path_(std::move(o.path_)) {
        o.file_ = nullptr;
    }

    std::FILE* get() const { return file_; }
};

// 练习 5：强异常安全版本
class Account {
private:
    double balance_;
    std::vector<std::string> log_;

public:
    explicit Account(double balance) : balance_(balance) {}

    double balance() const { return balance_; }

    // 强保证：要么全部成功，要么完全不变
    void transfer(double amount, Account& target) {
        if (amount <= 0) {
            throw std::invalid_argument("转账金额必须为正");
        }
        if (amount > balance_) {
            throw InsufficientFundsError(balance_, amount);
        }

        // 先做所有可能失败的操作（这里 push_back 可能因为内存不足失败）
        std::vector<std::string> newLog = log_;
        std::vector<std::string> newTargetLog = target.log_;
        newLog.push_back("transfer out " + std::to_string(amount));
        newTargetLog.push_back("transfer in " + std::to_string(amount));

        // 到这里为止都没修改任何东西，下面是不抛异常的状态更新
        balance_ -= amount;
        target.balance_ += amount;
        log_ = std::move(newLog);
        target.log_ = std::move(newTargetLog);
    }

    void printLog() const {
        std::cout << "  余额: " << balance_ << "\n";
        for (const auto& entry : log_) {
            std::cout << "    " << entry << "\n";
        }
    }
};

int main() {
    // 练习 1
    try {
        std::cout << safeDivide(10, 3) << "\n";
        std::cout << safeDivide(10, 0) << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "错误: " << e.what() << "\n";
    }

    // 练习 2
    try {
        double balance = 100;
        double request = 500;
        if (request > balance) {
            throw InsufficientFundsError(balance, request);
        }
    } catch (const InsufficientFundsError& e) {
        std::cout << e.what() << "\n";
        std::cout << "缺 " << (e.requested() - e.balance()) << " 元\n";
    }

    // 练习 3
    std::vector<int> v = {1, 2, 3};
    try {
        std::cout << getAt(v, 1) << "\n";     // 2
        std::cout << getAt(v, 10) << "\n";    // 抛异常
    } catch (const std::out_of_range& e) {
        std::cout << "越界: " << e.what() << "\n";
    }

    // 练习 4
    try {
        FileHandle f("test_raii.txt", "w");
        std::fputs("hello", f.get());
        // 即使这里抛异常，文件也会被正确关闭
    } catch (const std::exception& e) {
        std::cout << "文件错误: " << e.what() << "\n";
    }

    try {
        FileHandle f("/不存在的目录/x.txt");
    } catch (const std::exception& e) {
        std::cout << "预期错误: " << e.what() << "\n";
    }

    // 练习 5
    Account a(1000), b(500);
    try {
        a.transfer(300, b);
        std::cout << "\n转账成功:\n";
        std::cout << "A:"; a.printLog();
        std::cout << "B:"; b.printLog();

        a.transfer(10000, b);     // 失败，两个账户都不变
    } catch (const std::exception& e) {
        std::cout << "\n转账失败: " << e.what() << "\n";
        std::cout << "A:"; a.printLog();     // 应该和上面一样，没变
        std::cout << "B:"; b.printLog();
    }

    return 0;
}
```

> 需要 `#include <cstdio>` 才能用 `std::fopen`。

---

# 第 25 章 · 文件读写

## 25.1 三个文件流类

```cpp
#include <fstream>

std::ifstream   // 输入文件流（读文件）
std::ofstream   // 输出文件流（写文件）
std::fstream    // 读写文件流
```

## 25.2 写文件

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // ===== 写文件（覆盖模式）=====
    {
        std::ofstream out("output.txt");        // 默认会截断（覆盖）已有内容

        if (!out.is_open()) {
            std::cerr << "无法打开文件！\n";
            return 1;
        }

        out << "第一行\n";
        out << "第二行\n";
        out << "数字: " << 42 << "\n";
        out << "小数: " << 3.14159 << "\n";

        // 文件在 out 析构时自动关闭
    }   // ← 这里自动关闭

    // ===== 追加模式 =====
    {
        std::ofstream out("output.txt", std::ios::app);   // append
        out << "追加的一行\n";
    }

    // ===== 一次性写多行 =====
    {
        std::vector<std::string> lines = {"aaa", "bbb", "ccc"};
        std::ofstream out("lines.txt");
        for (const auto& line : lines) {
            out << line << "\n";
        }
    }

    // ===== 二进制写 =====
    {
        std::ofstream out("data.bin", std::ios::binary);
        int numbers[] = {1, 2, 3, 4, 5};
        out.write(reinterpret_cast<const char*>(numbers), sizeof(numbers));
    }

    std::cout << "写入完成\n";
    return 0;
}
```

**⚠️ 注意：`out` 没关闭时，内容可能还在缓冲区里！如果你在 `out` 还活着的时候读同一个文件，可能读不到内容。**

```cpp
std::ofstream out("f.txt");
out << "data";
// 此时读 f.txt 可能读不到 "data"，因为还在缓冲区

out.close();        // 手动关闭（或者用作用域）
// 现在可以读了

// 或者
out.flush();        // 只刷新缓冲区，不关闭
```

## 25.3 读文件

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // 先准备一个文件
    {
        std::ofstream out("read_test.txt");
        out << "第一行 hello\n";
        out << "第二行 world\n";
        out << "123 456 789\n";
    }

    // ===== 方式 1：按行读取（推荐）=====
    {
        std::ifstream in("read_test.txt");
        if (!in) {
            std::cerr << "无法打开\n";
            return 1;
        }

        std::string line;
        int lineNum = 0;
        while (std::getline(in, line)) {          // getline 返回流，为空时转 false
            lineNum++;
            std::cout << lineNum << ": " << line << "\n";
        }
    }

    // ===== 方式 2：按单词/数值读取 =====
    {
        std::ifstream in("read_test.txt");
        std::string word;
        int count = 0;
        while (in >> word) {                      // >> 跳过空白
            count++;
        }
        std::cout << "单词数: " << count << "\n";
    }

    // ===== 方式 3：逐字符读取 =====
    {
        std::ifstream in("read_test.txt");
        char c;
        int charCount = 0;
        while (in.get(c)) {
            charCount++;
        }
        std::cout << "字符数: " << charCount << "\n";
    }

    // ===== 方式 4：一次读整个文件 =====
    {
        std::ifstream in("read_test.txt");
        std::ostringstream ss;
        ss << in.rdbuf();                         // 把整个文件缓冲搬过来
        std::string content = ss.str();
        std::cout << "文件总长度: " << content.size() << " 字节\n";
    }

    // ===== 方式 5：读固定数量的字节（二进制）=====
    {
        std::ifstream in("read_test.txt", std::ios::binary);
        char buffer[10];
        in.read(buffer, sizeof(buffer));
        std::streamsize bytesRead = in.gcount();   // 实际读了多少
        std::cout << "读了 " << bytesRead << " 字节\n";
    }

    return 0;
}
```

## 25.4 文件打开模式

| 模式 | 含义 |
|---|---|
| `std::ios::in` | 读 |
| `std::ios::out` | 写（`ofstream` 默认） |
| `std::ios::app` | 追加到末尾 |
| `std::ios::ate` | 打开后定位到末尾（但可写任意位置） |
| `std::ios::trunc` | 截断（清空，`ofstream` 默认） |
| `std::ios::binary` | 二进制模式（不做换行转换） |

**可以组合：**

```cpp
std::fstream file("data.txt", std::ios::in | std::ios::out);        // 读写
std::ofstream log("app.log", std::ios::out | std::ios::app);         // 追加
std::fstream bin("d.bin", std::ios::in | std::ios::out | std::ios::binary);
```

**⭐ Windows 上必须注意：**

**Windows 默认是文本模式，会把 `\n` 转换成 `\r\n`（写入时）和反过来（读取时）。这在读写二进制文件时会破坏数据！**

```cpp
// 写二进制必须加 std::ios::binary
std::ofstream out("image.png", std::ios::binary);
```

## 25.5 错误处理

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 打开失败检测
    std::ifstream in("不存在的文件.txt");

    if (!in) {                              // 或 if (in.fail())
        std::cout << "打开失败\n";
    }

    if (in.is_open()) {
        std::cout << "已打开\n";
    } else {
        std::cout << "未打开\n";
    }

    // 检查各种状态
    std::ifstream f("read_test.txt");
    if (!f) return 1;

    std::cout << "\n初始状态:\n";
    std::cout << "good: " << std::boolalpha << f.good() << "\n";   // true
    std::cout << "eof:  " << f.eof() << "\n";                      // false

    std::string line;
    while (std::getline(f, line)) { }

    std::cout << "\n读到文件尾后:\n";
    std::cout << "good: " << f.good() << "\n";     // false
    std::cout << "eof:  " << f.eof() << "\n";      // true
    std::cout << "fail: " << f.fail() << "\n";     // true
    std::cout << "bad:  " << f.bad() << "\n";      // false

    // 清除状态以便重用
    f.clear();
    f.seekg(0);                                     // 回到开头
    if (std::getline(f, line)) {
        std::cout << "\n重新读取第一行: " << line << "\n";
    }

    // ⚠️ 打开失败的流要先 clear 再 open
    std::ifstream g;
    g.open("不存在.txt");                            // 失败
    g.clear();                                       // 清除错误状态
    g.open("read_test.txt");                         // 现在可以重试
    if (std::getline(g, line)) {
        std::cout << "第二次尝试成功: " << line << "\n";
    }

    return 0;
}
```

> **注意**：上面的例子依赖 `read_test.txt` 存在。完整代码里应该先创建它。

## 25.6 文件指针定位

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // 准备一个文件
    {
        std::ofstream out("seek_test.txt");
        out << "0123456789ABCDEFGHIJ";          // 20 个字符
    }

    std::ifstream in("seek_test.txt");

    // tellg：当前读取位置
    std::cout << "初始位置: " << in.tellg() << "\n";       // 0

    // seekg：跳转
    in.seekg(5);
    std::string buf(3, '\0');
    in.read(&buf[0], 3);
    std::cout << "位置 5 读 3 个字符: " << buf << "\n";     // 567

    // 从末尾定位
    in.seekg(-4, std::ios::end);
    in.read(&buf[0], 3);
    std::cout << "末尾前 4 个: " << buf << "\n";            // HIJ

    // 文件大小
    in.seekg(0, std::ios::end);
    std::cout << "文件大小: " << in.tellg() << " 字节\n";    // 20

    in.seekg(0, std::ios::beg);

    // seekp / tellp 用于写入定位
    std::fstream io("seek_test.txt", std::ios::in | std::ios::out);
    io.seekp(0);
    io << "XY";                                             // 修改前两个字符
    io.seekg(0);
    std::string all;
    std::getline(io, all);
    std::cout << "修改后: " << all << "\n";                 // XY23456789ABCDEFGHIJ

    return 0;
}
```

## 25.7 CSV 文件处理

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Record {
    std::string name;
    int age;
    double score;
};

// 分割一行 CSV
std::vector<std::string> split(const std::string& line, char delim) {
    std::vector<std::string> parts;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, delim)) {
        parts.push_back(item);
    }
    return parts;
}

int main() {
    // ===== 写 CSV =====
    {
        std::ofstream out("students.csv");
        out << "姓名,年龄,成绩\n";
        out << "张三,18,95.5\n";
        out << "李四,19,88.0\n";
        out << "王五,20,92.5\n";
    }

    // ===== 读 CSV =====
    {
        std::ifstream in("students.csv");
        if (!in) {
            std::cerr << "无法打开 students.csv\n";
            return 1;
        }

        std::string line;
        std::vector<Record> records;
        bool isHeader = true;

        while (std::getline(in, line)) {
            if (line.empty()) continue;

            if (isHeader) {
                isHeader = false;
                continue;                    // 跳过表头
            }

            auto parts = split(line, ',');
            if (parts.size() != 3) {
                std::cerr << "格式错误: " << line << "\n";
                continue;
            }

            try {
                records.push_back({parts[0], std::stoi(parts[1]), std::stod(parts[2])});
            } catch (const std::exception& e) {
                std::cerr << "解析失败 '" << line << "': " << e.what() << "\n";
            }
        }

        std::cout << "读取了 " << records.size() << " 条记录:\n";
        double total = 0;
        for (const auto& r : records) {
            std::cout << "  " << r.name << ", " << r.age << " 岁, "
                      << r.score << " 分\n";
            total += r.score;
        }
        if (!records.empty()) {
            std::cout << "平均分: " << total / records.size() << "\n";
        }
    }

    return 0;
}
```

## 25.8 二进制文件

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

struct Pixel {
    unsigned char r, g, b;
};

struct Header {
    char magic[4];       // "PPMF"
    int width;
    int height;
};

int main() {
    // ===== 写二进制 =====
    {
        std::ofstream out("image.bin", std::ios::binary);
        if (!out) return 1;

        Header h;
        std::memcpy(h.magic, "PPMF", 4);
        h.width = 3;
        h.height = 2;

        // 写结构体（按字节）
        out.write(reinterpret_cast<const char*>(&h), sizeof(h));

        // 写像素数据
        std::vector<Pixel> pixels = {
            {255, 0, 0}, {0, 255, 0}, {0, 0, 255},
            {255, 255, 0}, {0, 255, 255}, {255, 0, 255}
        };
        out.write(reinterpret_cast<const char*>(pixels.data()),
                  pixels.size() * sizeof(Pixel));
    }

    // ===== 读二进制 =====
    {
        std::ifstream in("image.bin", std::ios::binary);
        if (!in) return 1;

        Header h;
        in.read(reinterpret_cast<char*>(&h), sizeof(h));

        std::cout << "magic: " << std::string(h.magic, 4) << "\n";
        std::cout << "尺寸: " << h.width << "x" << h.height << "\n";

        std::vector<Pixel> pixels(h.width * h.height);
        in.read(reinterpret_cast<char*>(pixels.data()),
                pixels.size() * sizeof(Pixel));

        std::cout << "读到 " << in.gcount() << " 字节的像素数据\n";
        for (const auto& p : pixels) {
            std::cout << "RGB(" << (int)p.r << "," << (int)p.g
                      << "," << (int)p.b << ") ";
        }
        std::cout << "\n";
    }

    return 0;
}
```

> **⚠️ 直接读写结构体有可移植性问题**：不同编译器/平台的结构体可能有不同的填充字节（padding），字节序（endianness）也可能不同。
>
> **可移植做法**：逐个字段序列化。

```cpp
// 可移植的写法
out.write(h.magic, 4);
int w = h.width;
out.write(reinterpret_cast<const char*>(&w), 4);   // 但仍有字节序问题
// 彻底可移植：手动写字节
```

## 25.9 处理大文件

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // ===== 逐块读取大文件 =====
    {
        std::ofstream out("big.txt");
        for (int i = 0; i < 100000; i++) {
            out << "行号 " << i << " 的一些内容\n";
        }
    }

    // 分块读（内存友好）
    {
        std::ifstream in("big.txt", std::ios::binary);
        constexpr std::size_t BUFFER_SIZE = 4096;
        std::vector<char> buffer(BUFFER_SIZE);

        std::size_t totalBytes = 0;
        std::size_t totalLines = 0;

        while (in) {
            in.read(buffer.data(), BUFFER_SIZE);
            std::streamsize bytesRead = in.gcount();
            totalBytes += bytesRead;

            for (std::streamsize i = 0; i < bytesRead; i++) {
                if (buffer[i] == '\n') totalLines++;
            }
        }
        std::cout << "总字节: " << totalBytes << ", 总行数: " << totalLines << "\n";
    }

    return 0;
}
```

## 25.10 练习

1. 写一个程序，把用户输入的多行文本保存到文件，输入空行时结束。
2. 写函数 `int countLines(const std::string& filename)` 统计文件行数。
3. 读取一个文件，统计其中每个单词出现的次数，按次数降序输出。
4. 写一个程序，把一个文本文件的每一行前面加上行号，输出到新文件。
5. 写一个程序，把一个文件复制到另一个文件（支持二进制）。
6. 实现一个简单的日志系统：支持写入带时间戳的日志行，支持追加模式。

**参考答案：**

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <ctime>

// 练习 2
int countLines(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return -1;
    int count = 0;
    std::string line;
    while (std::getline(in, line)) count++;
    return count;
}

// 练习 5
bool copyFile(const std::string& src, const std::string& dst) {
    std::ifstream in(src, std::ios::binary);
    if (!in) return false;
    std::ofstream out(dst, std::ios::binary);
    if (!out) return false;
    out << in.rdbuf();
    return out.good();
}

// 练习 6
class Logger {
private:
    std::ofstream file_;
public:
    explicit Logger(const std::string& filename, bool append = true)
        : file_(filename, append ? (std::ios::out | std::ios::app) : std::ios::out)
    {
        if (!file_) throw std::runtime_error("无法打开日志文件: " + filename);
    }

    void log(const std::string& level, const std::string& message) {
        auto now = std::chrono::system_clock::now();
        auto t = std::chrono::system_clock::to_time_t(now);
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                      now.time_since_epoch()) % 1000;

        std::tm tmBuf{};
#if defined(_WIN32)
        localtime_s(&tmBuf, &t);
#else
        localtime_r(&t, &tmBuf);
#endif

        file_ << std::put_time(&tmBuf, "%Y-%m-%d %H:%M:%S")
              << '.' << std::setfill('0') << std::setw(3) << ms.count()
              << " [" << level << "] " << message << "\n";
        file_.flush();
    }

    void info(const std::string& msg)  { log("INFO", msg); }
    void warn(const std::string& msg)  { log("WARN", msg); }
    void error(const std::string& msg) { log("ERROR", msg); }
};

int main() {
    // 练习 1
    std::cout << "请输入多行文本（空行结束）:\n";
    {
        std::ofstream out("user_input.txt");
        std::string line;
        while (std::getline(std::cin, line) && !line.empty()) {
            out << line << "\n";
        }
    }
    std::cout << "已保存到 user_input.txt\n\n";

    // 练习 2
    std::cout << "user_input.txt 行数: " << countLines("user_input.txt") << "\n\n";

    // 练习 3
    {
        std::ofstream out("words.txt");
        out << "the quick brown fox jumps over the lazy dog the fox\n";
        out << "a quick brown dog\n";
    }

    std::ifstream in("words.txt");
    std::map<std::string, int> freq;
    std::string word;
    while (in >> word) freq[word]++;

    std::vector<std::pair<std::string, int>> sorted(freq.begin(), freq.end());
    std::sort(sorted.begin(), sorted.end(),
              [](const auto& a, const auto& b) {
                  if (a.second != b.second) return a.second > b.second;
                  return a.first < b.first;
              });

    std::cout << "词频统计（降序）:\n";
    for (const auto& [w, c] : sorted) {
        std::cout << "  " << w << ": " << c << "\n";
    }
    std::cout << "\n";

    // 练习 4
    {
        std::ifstream src("words.txt");
        std::ofstream dst("words_numbered.txt");
        std::string line;
        int num = 1;
        while (std::getline(src, line)) {
            dst << std::setw(4) << num++ << " | " << line << "\n";
        }
    }
    std::cout << "已生成 words_numbered.txt\n";

    // 练习 5
    if (copyFile("words.txt", "words_copy.txt")) {
        std::cout << "复制成功\n";
    }

    // 练习 6
    Logger logger("app.log");
    logger.info("程序启动");
    logger.warn("这是一个警告");
    logger.error("发生了一个错误");
    logger.info("程序结束");
    std::cout << "日志已写入 app.log\n";

    return 0;
}
```

---

# 第 26 章 · 头文件与多文件项目

**真实项目不可能把几千行代码塞进一个 `.cpp`。这一章讲怎么组织多文件项目。**

## 26.1 为什么需要多文件？

- **可维护性**：每个文件几百行，容易看懂
- **编译速度**：改一个文件只重编那个文件
- **复用**：写好的模块可以在别的项目里用
- **团队协作**：多人可以改不同文件

## 26.2 一个最小的多文件项目

**目录结构：**

```
project/
├── main.cpp
├── math_utils.h        ← 声明（接口）
└── math_utils.cpp      ← 定义（实现）
```

**`math_utils.h`（头文件，放声明）：**

```cpp
#ifndef MATH_UTILS_H          // 头文件保护（防止重复包含）
#define MATH_UTILS_H

// 函数声明
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

// 常量
constexpr double PI = 3.14159265358979;

// 类声明
class Calculator {
private:
    int memory_;
public:
    Calculator();
    int addToMemory(int value);
    int getMemory() const;
    void clear();
};

#endif // MATH_UTILS_H
```

**`math_utils.cpp`（源文件，放实现）：**

```cpp
#include "math_utils.h"      // 包含自己的头文件
#include <stdexcept>

// 函数定义
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

double divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("除数不能为 0");
    }
    return static_cast<double>(a) / b;
}

// 类成员函数定义（用 :: 指明属于哪个类）
Calculator::Calculator() : memory_(0) { }

int Calculator::addToMemory(int value) {
    memory_ += value;
    return memory_;
}

int Calculator::getMemory() const { return memory_; }

void Calculator::clear() { memory_ = 0; }
```

**`main.cpp`：**

```cpp
#include <iostream>
#include "math_utils.h"      // 用双引号包含自己的头文件

int main() {
    std::cout << add(3, 4) << "\n";
    std::cout << divide(10, 3) << "\n";
    std::cout << "PI = " << PI << "\n";

    Calculator calc;
    calc.addToMemory(10);
    calc.addToMemory(20);
    std::cout << "内存: " << calc.getMemory() << "\n";

    return 0;
}
```

**编译（关键！）：**

```bash
# 方式 1：一次编译所有 .cpp（简单，适合小项目）
g++ -std=c++17 -Wall main.cpp math_utils.cpp -o app

# 方式 2：分别编译成 .o，再链接（大项目更快）
g++ -std=c++17 -Wall -c main.cpp        -o main.o
g++ -std=c++17 -Wall -c math_utils.cpp  -o math_utils.o
g++ main.o math_utils.o -o app
```

> **`-c` 表示"只编译，不链接"，生成目标文件 `.o`（Windows 上是 `.obj`）。**

## 26.3 ⭐ 头文件保护（必须理解）

**同一个头文件可能被包含多次，导致重复定义。**

```cpp
// a.h
struct Foo { int x; };

// b.h
#include "a.h"

// main.cpp
#include "a.h"
#include "b.h"        // b.h 又包含了一次 a.h
// ❌ 如果没有保护，Foo 被定义了两次 → 编译错误
```

**三种保护方式：**

### 方式 1：`#ifndef` 守卫（最通用、最兼容）

```cpp
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

// ... 内容 ...

#endif // MATH_UTILS_H
```

**工作方式**：第一次包含时 `MATH_UTILS_H` 未定义，`#define` 它并编译内容；第二次包含时它已定义，整个内容被跳过。

**宏名要唯一**，惯例是用文件名大写 + 下划线。

### 方式 2：`#pragma once`（更简洁，几乎所有编译器都支持）

```cpp
#pragma once

// ... 内容 ...
```

**更短，不容易写错宏名，但严格来说不是标准 C++（不过 GCC/Clang/MSVC 都支持）。**

### 方式 3：两者都写

```cpp
#pragma once
#ifndef MATH_UTILS_H
#define MATH_UTILS_H
// ...
#endif
```

> **⭐ 实践建议：用 `#pragma once`（简洁），或者用 `#ifndef` 守卫（最保险）。** 不要在同一个项目里混用两种风格。

## 26.4 声明 vs 定义（核心概念）

| | 声明（declaration） | 定义（definition） |
|---|---|---|
| 作用 | 告诉编译器"有这么个东西" | 真正创建它 |
| 函数 | `int add(int, int);` | `int add(int a, int b) { return a+b; }` |
| 变量 | `extern int x;` | `int x = 10;` |
| 类 | `class Foo;`（前向声明） | `class Foo { ... };` |
| 能出现几次 | **可以多次** | **只能一次**（ODR 规则） |

**ODR（One Definition Rule，单一定义规则）：一个实体在整个程序中只能被定义一次。**

**这就是为什么：**

- 头文件里放**声明**（可以被多次包含）
- `.cpp` 里放**定义**（只编译一次）

**⚠️ 头文件里定义全局变量会导致链接错误：**

```cpp
// ❌ bad.h
int globalCounter = 0;        // 如果被多个 .cpp 包含 → 重复定义错误

// ✅ 正确做法 1：用 inline（C++17）
inline int globalCounter = 0;

// ✅ 正确做法 2：用 extern 声明 + 一个 .cpp 里定义
// config.h
extern int globalCounter;     // 声明
// config.cpp
int globalCounter = 0;        // 定义（只在这里）

// ✅ 正确做法 3：用 constexpr（默认内部链接，每个 TU 一份副本但没关系）
constexpr int MAX_SIZE = 100;

// ✅ 正确做法 4：用函数返回（避免全局状态）
inline int& globalCounter() {
    static int value = 0;
    return value;
}
```

## 26.5 `#include` 的两种写法

```cpp
#include <iostream>        // 尖括号：系统/标准库头文件
#include "my_header.h"     // 双引号：自己的头文件
```

**搜索路径：**

- `< >`：只搜索系统包含目录（`-I` 指定的也算）
- `" "`：**先搜索当前文件所在目录**，再搜索系统目录

**实践：**

- 标准库和第三方库 → `< >`
- 自己项目的头文件 → `" "`

## 26.6 前向声明（减少编译依赖）

**如果只需要用到某个类型的指针或引用，不需要完整定义，可以用前向声明。**

```cpp
// ❌ 差：包含了整个 heavy.h，编译慢
#include "heavy.h"

class A {
    HeavyClass* ptr;      // 只需要指针
};

// ✅ 好：前向声明就够了
class HeavyClass;         // 前向声明

class A {
    HeavyClass* ptr;      // 指针只需知道类型存在
    // HeavyClass obj;    // ❌ 这是成员对象，需要完整定义
};
```

**前向声明的限制：**

- ✅ 可以声明该类型的指针/引用
- ✅ 可以声明返回该类型的函数
- ❌ 不能定义该类型的对象
- ❌ 不能访问它的成员
- ❌ 不能继承它

**优势**：头文件更轻，改 `heavy.h` 不需要重编包含 `a.h` 的文件。

## 26.7 模板的分离问题（重要陷阱）

**普通函数可以声明放 `.h`、定义放 `.cpp`，但模板不行！**

```cpp
// ❌ 这样会链接错误
// mytemplate.h
template <typename T>
T add(T a, T b);          // 声明

// mytemplate.cpp
template <typename T>
T add(T a, T b) { return a + b; }    // 定义

// main.cpp
#include "mytemplate.h"
add(1, 2);                // 💥 链接错误：undefined reference to `int add<int>(int, int)`
```

**为什么？** 因为模板不是代码，是"生成代码的模板"。编译器在 `main.cpp` 里看到 `add(1,2)` 时需要**看到定义**才能生成 `add<int>`。但定义在另一个 `.cpp` 里，`main.cpp` 看不到。

### 解决方案

**方案 1：定义也放头文件（最简单，最常用）**

```cpp
// mytemplate.h
#pragma once

template <typename T>
T add(T a, T b) {
    return a + b;         // 定义直接在头文件里
}
```

**方案 2：在 `.cpp` 末尾显式实例化**

```cpp
// mytemplate.cpp
template <typename T>
T add(T a, T b) { return a + b; }

// 显式实例化你需要的类型
template int add<int>(int, int);
template double add<double>(double, double);
```

**方案 3：把模板定义放 `.tpp` / `.ipp` 文件，在 `.h` 末尾 include**

```cpp
// mytemplate.h
#pragma once
template <typename T>
T add(T a, T b);

#include "mytemplate.tpp"    // 在末尾包含实现

// mytemplate.tpp
template <typename T>
T add(T a, T b) { return a + b; }
```

**⭐ 日常做法：模板全放头文件。方案 3 适合实现很长的情况。**

## 26.8 一个中等规模项目的目录结构

```
myproject/
├── CMakeLists.txt           # 构建配置（见下一章）
├── README.md
├── .gitignore
├── include/                 # 公开头文件
│   └── mylib/
│       ├── calculator.h
│       ├── string_utils.h
│       └── logger.h
├── src/                     # 实现
│   ├── calculator.cpp
│   ├── string_utils.cpp
│   ├── logger.cpp
│   └── main.cpp
├── tests/                   # 测试
│   └── test_calculator.cpp
├── examples/                # 使用示例
│   └── demo.cpp
└── build/                   # 构建产物（不提交到 git）
```

**`main.cpp` 里的包含：**

```cpp
#include "mylib/calculator.h"      // 需要 -Iinclude
```

**编译：**

```bash
g++ -std=c++17 -Wall -Iinclude src/*.cpp -o build/app
```

> **`-Iinclude`** 表示"把 `include` 目录加入头文件搜索路径"。

## 26.9 头文件里该放什么

**✅ 应该放：**

- 函数声明
- 类定义（成员变量 + 成员函数声明）
- 模板定义
- 内联函数定义
- 常量（`constexpr`）
- 类型别名（`using`）
- 枚举定义
- 宏定义（谨慎使用）

**❌ 不应该放：**

- 普通函数的定义（会导致重复定义，除非是 `inline`）
- 全局变量的定义（用 `extern` 声明或 `inline` 变量）
- `using namespace std;`（会污染所有包含它的文件！）
- 大段实现代码（编译慢）

```cpp
// ❌ 头文件里的灾难
#pragma once
using namespace std;          // 所有包含这个头的文件都被污染

int globalVar = 0;            // 重复定义错误

void helper() { }             // 重复定义错误（除非 inline）

// ✅ 正确
#pragma once
#include <string>

int computeHash(const std::string& s);       // 声明

inline int square(int x) { return x * x; }   // inline 可以放头文件

constexpr int MAX = 100;                     // constexpr 可以

namespace mylib {                            // 用自己的命名空间
    extern int globalVar;                    // 声明
}
```

## 26.10 完整的多文件示例

**`include/shapes/shape.h`：**

```cpp
#pragma once
#include <string>

namespace shapes {

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string name() const = 0;
    virtual ~Shape() = default;
};

}  // namespace shapes
```

**`include/shapes/circle.h`：**

```cpp
#pragma once
#include "shapes/shape.h"

namespace shapes {

class Circle : public Shape {
private:
    double radius_;
public:
    explicit Circle(double radius);
    double area() const override;
    double perimeter() const override;
    std::string name() const override { return "圆"; }
    double radius() const { return radius_; }
};

}  // namespace shapes
```

**`src/shapes/circle.cpp`：**

```cpp
#include "shapes/circle.h"
#include <cmath>
#include <stdexcept>

namespace shapes {

// 圆周率。注意：不要用 M_PI —— 它是 GCC 的扩展，MSVC（Visual Studio）上不存在，
// 需要 #define _USE_MATH_DEFINES 才能用。自己定义 constexpr 常量最省事。
constexpr double kPi = 3.14159265358979323846;

Circle::Circle(double radius) : radius_(radius) {
    if (radius <= 0) {
        throw std::invalid_argument("半径必须为正");
    }
}

double Circle::area() const {
    return kPi * radius_ * radius_;
}

double Circle::perimeter() const {
    return 2 * kPi * radius_;
}

}  // namespace shapes
```

**`src/main.cpp`：**

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include "shapes/circle.h"

using shapes::Circle;
using shapes::Shape;

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));

    for (const auto& s : shapes) {
        std::cout << s->name() << " 面积 = " << s->area() << "\n";
    }
    return 0;
}
```

**编译：**

```bash
g++ -std=c++17 -Wall -Iinclude src/main.cpp src/shapes/circle.cpp -o build/app
```

## 26.11 练习

1. 把第 8 章的数学函数拆成一个 `math_utils.h` + `math_utils.cpp` + `main.cpp` 项目。
2. 写一个 `StringUtils` 模块（头文件 + 实现），提供 `toUpper`、`trim`、`split` 函数。
3. 给下面的头文件加上保护，并解释为什么需要：

```cpp
struct Point { int x, y; };
int distance(Point a, Point b);
```

4. 解释为什么下面代码会链接错误：

```cpp
// myfunc.h
template <typename T>
T doubler(T x);

// myfunc.cpp
template <typename T>
T doubler(T x) { return x * 2; }

// main.cpp
#include "myfunc.h"
int main() { return doubler(5); }
```

**参考答案（第 1、2 题）：**

**`math_utils.h`：**

```cpp
#pragma once

namespace mathutils {

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);
int factorial(int n);
bool isPrime(int n);

constexpr double PI = 3.14159265358979;

}  // namespace mathutils
```

**`math_utils.cpp`：**

```cpp
#include "math_utils.h"
#include <stdexcept>

namespace mathutils {

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

double divide(int a, int b) {
    if (b == 0) throw std::invalid_argument("除数不能为 0");
    return static_cast<double>(a) / b;
}

int factorial(int n) {
    if (n < 0) throw std::invalid_argument("阶乘参数不能为负");
    int result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

}  // namespace mathutils
```

**`string_utils.h`：**

```cpp
#pragma once
#include <string>
#include <vector>

namespace strutils {

std::string toUpper(const std::string& s);
std::string toLower(const std::string& s);
std::string trim(const std::string& s);
std::vector<std::string> split(const std::string& s, char delim);
std::string join(const std::vector<std::string>& parts, const std::string& sep);
bool startsWith(const std::string& s, const std::string& prefix);
bool endsWith(const std::string& s, const std::string& suffix);
std::string replaceAll(const std::string& s,
                       const std::string& from,
                       const std::string& to);

}  // namespace strutils
```

**`string_utils.cpp`：**

```cpp
#include "string_utils.h"
#include <algorithm>
#include <cctype>
#include <sstream>

namespace strutils {

std::string toUpper(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}

std::string toLower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

std::string trim(const std::string& s) {
    auto first = s.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    auto last = s.find_last_not_of(" \t\n\r");
    return s.substr(first, last - first + 1);
}

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> parts;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        parts.push_back(item);
    }
    return parts;
}

std::string join(const std::vector<std::string>& parts, const std::string& sep) {
    std::string result;
    for (std::size_t i = 0; i < parts.size(); i++) {
        if (i > 0) result += sep;
        result += parts[i];
    }
    return result;
}

bool startsWith(const std::string& s, const std::string& prefix) {
    return s.size() >= prefix.size() &&
           s.compare(0, prefix.size(), prefix) == 0;
}

bool endsWith(const std::string& s, const std::string& suffix) {
    return s.size() >= suffix.size() &&
           s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
}

std::string replaceAll(const std::string& s,
                       const std::string& from,
                       const std::string& to) {
    if (from.empty()) return s;
    std::string result = s;
    std::size_t pos = 0;
    while ((pos = result.find(from, pos)) != std::string::npos) {
        result.replace(pos, from.size(), to);
        pos += to.size();
    }
    return result;
}

}  // namespace strutils
```

**`main.cpp`：**

```cpp
#include <iostream>
#include "math_utils.h"
#include "string_utils.h"

int main() {
    using namespace mathutils;      // 在 .cpp 里可以（不要在头文件里）
    using namespace strutils;

    std::cout << "5 + 3 = " << add(5, 3) << "\n";
    std::cout << "5! = " << factorial(5) << "\n";
    std::cout << "17 是质数? " << std::boolalpha << isPrime(17) << "\n";

    std::cout << toUpper("hello world") << "\n";
    std::cout << "[" << trim("   spaced   ") << "]\n";

    auto parts = split("a,b,c,d", ',');
    std::cout << "分割后 " << parts.size() << " 部分\n";
    std::cout << join(parts, " | ") << "\n";

    std::cout << replaceAll("cat dog cat", "cat", "fox") << "\n";

    return 0;
}
```

**编译：**

```bash
g++ -std=c++17 -Wall -I. main.cpp math_utils.cpp string_utils.cpp -o app
```

**第 4 题的解答**：模板 `doubler` 的定义在 `myfunc.cpp` 里，但 `main.cpp` 只看到声明。编译器在编译 `main.cpp` 时，看到 `doubler(5)` 需要**实例化** `doubler<int>`，但看不到函数体，只能生成一个"外部引用"。链接时，`myfunc.o` 里并没有 `doubler<int>` 这个符号（因为没人调用它，模板也就没被实例化），于是链接器报 `undefined reference`。

**修复**：把模板定义移到 `.h` 里，或者在 `myfunc.cpp` 里加 `template int doubler<int>(int);`。

---

# 第 27 章 · 命名空间与 const 完全指南

## 27.1 命名空间的作用

**问题：不同库里的同名函数/类会冲突。**

```cpp
// libA.h
void print(int x);

// libB.h
void print(const std::string& s);      // 冲突！
```

**用命名空间隔离：**

```cpp
// libA.h
namespace libA {
    void print(int x);
}

// libB.h
namespace libB {
    void print(const std::string& s);
}

// 使用
libA::print(42);
libB::print("hello");
```

## 27.2 定义和使用

```cpp
#include <iostream>
#include <string>

// 定义命名空间
namespace geometry {

    constexpr double PI = 3.14159265358979;

    struct Point {
        double x, y;
    };

    double distance(const Point& a, const Point& b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    class Circle {
    public:
        explicit Circle(double r) : r_(r) {}
        double area() const { return PI * r_ * r_; }
    private:
        double r_;
    };

    // 嵌套命名空间
    namespace detail {
        inline double square(double x) { return x * x; }
    }
}

int main() {
    // 完全限定名
    geometry::Point p1{0, 0};
    geometry::Point p2{3, 4};
    std::cout << geometry::distance(p1, p2) << "\n";     // 5

    geometry::Circle c(5.0);
    std::cout << c.area() << "\n";

    // using 声明：引入单个名字
    using geometry::distance;
    std::cout << distance(p1, p2) << "\n";

    // using 指令：引入整个命名空间
    using namespace geometry;
    Circle c2(3.0);
    std::cout << c2.area() << "\n";

    // 命名空间别名
    namespace geo = geometry;
    geo::Point p3{1, 1};

    // C++17 嵌套命名空间简写
    // namespace a::b::c { }  等价于 namespace a { namespace b { namespace c {

    return 0;
}
```

> 需要 `#include <cmath>`。

## 27.3 `using namespace` 的陷阱

```cpp
#include <iostream>
#include <algorithm>

using namespace std;      // ⚠️ 在全局作用域使用（不推荐）

int main() {
    // 现在 std 里所有名字都可见
    cout << "hello" << endl;      // 不用写 std::

    // 问题 1：名字冲突
    // 如果你自己写了个 count 函数...
    // int count = 5;
    // std::count(...)  // 可能产生歧义

    // 问题 2：C++17 的 std::size 会和变量名冲突
    // int size = 10;
    // std::cout << size;         // 可能报错

    // 问题 3：C++20 引入了更多名字，可能和你的旧代码冲突

    return 0;
}
```

**⭐ 规则：**

- ❌ **绝不在头文件里写 `using namespace`**（会污染所有包含它的文件）
- ⚠️ 在 `.cpp` 文件的函数内部用可以接受
- ✅ 用 `using std::cout;` 这种**单个名字声明**代替
- ✅ 用命名空间别名（`namespace fs = std::filesystem;`）
- ✅ 引用自己的命名空间时，在 `.cpp` 里用 `using namespace mylib;` 是常见的

**推荐写法：**

```cpp
#include <iostream>
#include <vector>
#include <string>

// 只引入需要的
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<string> names = {"a", "b"};
    for (const auto& n : names) cout << n << endl;
    return 0;
}
```

## 27.4 匿名命名空间（替代文件级 static）

```cpp
// mymodule.cpp

namespace {
    // 这里的名字只在本 .cpp 文件内可见
    // 相当于给它们"内部链接"，其他 .cpp 文件看不到

    int internalCounter = 0;

    void helperFunction() {
        internalCounter++;
    }

    constexpr int kMagicNumber = 42;
}

int publicFunction() {
    helperFunction();
    return internalCounter + kMagicNumber;
}
```

**在 C++ 中，匿名命名空间比文件级 `static` 更推荐：**

```cpp
// 旧风格（C 语言遗留）
static int counter = 0;
static void helper() { }

// ✅ 现代 C++ 风格
namespace {
    int counter = 0;
    void helper() { }
}
```

**为什么更好？** 匿名命名空间里的东西可以做模板参数（`static` 函数在 C++11 前不行），而且语义更清晰。

## 27.5 `const` 完全指南

**`const` 是 C++ 中最重要的关键字之一。把它用对，能避免大量 bug。**

### 1. 常量变量

```cpp
const int MAX = 100;
const double PI = 3.14159;
const std::string NAME = "app";

// MAX = 200;        // ❌ 编译错误
```

### 2. `const` 与指针（第 13 章已讲，这里复习）

```cpp
int a = 1, b = 2;

const int* p1 = &a;         // 指向常量的指针（不能改 *p1，可以改 p1）
int* const p2 = &a;         // 常量指针（可以改 *p2，不能改 p2）
const int* const p3 = &a;   // 都不能改
```

**读法：从右往左读。**

- `const int* p` → p is a pointer to const int
- `int* const p` → p is a const pointer to int

### 3. `const` 引用（最常用）

```cpp
#include <iostream>
#include <string>
#include <vector>

// ✅ 大对象参数的标准写法
void process(const std::string& s);
void process(const std::vector<int>& v);
void process(const MyClass& obj);

// ✅ 可以绑定临时值
const int& r = 42;
const std::string& s = "literal";
```

### 4. `const` 成员函数

```cpp
class Widget {
    int value_ = 0;
    mutable int cacheHits_ = 0;      // mutable：即使在 const 函数里也能改
public:
    int getValue() const { return value_; }              // ✅
    int getValueMutable() const {
        cacheHits_++;                                     // ✅ 因为 mutable
        return value_;
    }
    void setValue(int v) { value_ = v; }                 // 非 const
};

int main() {
    const Widget w;
    // w.setValue(1);         // ❌
    w.getValue();             // ✅
    return 0;
}
```

### 5. `const` 返回值

```cpp
class Container {
    std::vector<int> data_;
public:
    // 按值返回：加 const 意义不大（C++11 后反而可能阻止移动）
    const int getSize() const;          // ⚠️ 不推荐这样写

    // 返回引用：加 const 防止调用者修改内部状态
    const std::vector<int>& data() const { return data_; }   // ✅
};
```

> **⚠️ 对按值返回的类型加 `const` 是过时习惯**，它会阻止移动语义。写 `int getSize() const;` 就好。

### 6. `const` 与 `constexpr`

```cpp
const int a = 10;             // 可能是编译期，也可能是运行期
constexpr int b = 20;         // 一定是编译期

int getInput();
const int c = getInput();     // 运行期才知道
// constexpr int d = getInput();  // ❌ 编译错误
```

### 7. `const` 参数传值（无意义）

```cpp
// ❌ const 对按值参数无意义（函数内部本来就有副本）
void f(const int x);          // 声明里的 const 被忽略

// 只在定义里写才有意义（防止函数内误改）
void g(int x) {
    // x = 10; 允许
}

void h(const int x) {
    // x = 10;  // ❌ 防止误改
}
```

### 8. `const` 最佳实践总结

| 位置 | 建议 | 例子 |
|---|---|---|
| 局部常量 | 用 `constexpr`，不行再用 `const` | `constexpr int MAX = 100;` |
| 函数参数（大对象） | **必须** `const T&` | `f(const std::string& s)` |
| 函数参数（小类型） | 按值，不加 const | `f(int x)` |
| 成员函数（不改状态） | **必须** 加 `const` | `int size() const;` |
| 返回引用（保护内部） | 加 `const` | `const T& get() const;` |
| 成员变量（可缓存） | 慎用 `mutable` | `mutable int cache_;` |
| 指针 | 优先 `const T*` | `const char* name;` |

## 27.6 代码规范：一个完整的示例

```cpp
// ===== include/config.h =====
#pragma once
#include <string>
#include <cstdint>

namespace app {

struct Config {
    std::string host = "localhost";
    std::uint16_t port = 8080;
    int timeoutSeconds = 30;
    bool verbose = false;
};

// 声明
Config loadConfig(const std::string& path);
void printConfig(const Config& config);

namespace detail {
    // 内部实现细节，外部不应该直接用
    bool validatePort(std::uint16_t port);
}

}  // namespace app
```

```cpp
// ===== src/config.cpp =====
#include "include/config.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

namespace {

// 匿名命名空间：只在本文件可见
constexpr std::uint16_t kMinPort = 1;
constexpr std::uint16_t kMaxPort = 65535;

std::string trim(const std::string& s) {
    auto first = s.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    auto last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, last - first + 1);
}

}  // namespace

namespace app {

namespace detail {

bool validatePort(std::uint16_t port) {
    return port >= kMinPort && port <= kMaxPort;
}

}  // namespace detail

Config loadConfig(const std::string& path) {
    std::ifstream in(path);
    if (!in) {
        throw std::runtime_error("无法打开配置文件: " + path);
    }

    Config config;
    std::string line;
    int lineNum = 0;

    while (std::getline(in, line)) {
        lineNum++;
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;

        auto pos = line.find('=');
        if (pos == std::string::npos) {
            throw std::runtime_error("第 " + std::to_string(lineNum) + " 行格式错误");
        }

        std::string key = trim(line.substr(0, pos));
        std::string value = trim(line.substr(pos + 1));

        if (key == "host") {
            config.host = value;
        } else if (key == "port") {
            int port = std::stoi(value);
            if (!detail::validatePort(static_cast<std::uint16_t>(port))) {
                throw std::runtime_error("端口不合法: " + value);
            }
            config.port = static_cast<std::uint16_t>(port);
        } else if (key == "timeout") {
            config.timeoutSeconds = std::stoi(value);
        } else if (key == "verbose") {
            config.verbose = (value == "true" || value == "1");
        }
    }

    return config;
}

void printConfig(const Config& config) {
    std::cout << "配置:\n"
              << "  host    = " << config.host << "\n"
              << "  port    = " << config.port << "\n"
              << "  timeout = " << config.timeoutSeconds << "\n"
              << "  verbose = " << std::boolalpha << config.verbose << "\n";
}

}  // namespace app
```

> 需要 `#include <cstdint>` 使用 `std::uint16_t`，并用 `-I.` 编译。

## 27.7 练习

1. 创建一个 `math` 命名空间，包含 `add`、`sub`、`PI`，并在 main 里用三种方式访问（完全限定、using 声明、using 指令）。
2. 用匿名命名空间把一些辅助函数限制在文件内。
3. 给一个类添加 `const` 成员函数 `size()`、`empty()`，以及非 const 的 `add()`。
4. 解释下面代码的错误：

```cpp
class Foo {
public:
    int getValue() { return value_; }
private:
    int value_;
};

void print(const Foo& f) {
    std::cout << f.getValue();
}
```

**参考答案（第 4 题）：**

`print` 接收 `const Foo&`，但 `getValue()` 不是 `const` 成员函数。C++ 不允许在 const 对象上调用非 const 成员函数（因为那可能修改对象）。修复：把 `getValue()` 声明为 `int getValue() const { return value_; }`。

---

# 第 28 章 · 编译、链接与调试

## 28.1 从源码到程序的四个阶段

```
  main.cpp
     │
     │  ① 预处理（Preprocessing）
     │     展开 #include、处理 #define、去掉注释
     ↓
  main.i（预处理后的代码）
     │
     │  ② 编译（Compilation）
     │     C++ → 汇编代码，做语法检查、优化
     ↓
  main.s（汇编代码）
     │
     │  ③ 汇编（Assembly）
     │     汇编 → 机器码
     ↓
  main.o（目标文件）
     │
     │  ④ 链接（Linking）
     │     合并多个 .o，解析符号引用，加入库
     ↓
  app.exe（可执行文件）
```

**理解这四个阶段，能帮你读懂链接错误。**

### 只看预处理结果

```bash
g++ -E main.cpp -o main.i
# 或者只看前面 100 行
g++ -E main.cpp | head -100
```

### 只看汇编

```bash
g++ -S main.cpp -o main.s
```

### 只编译不链接

```bash
g++ -c main.cpp -o main.o
```

### 查看目标文件的符号

```bash
nm main.o              # Linux/Git Bash
nm -C main.o           # -C 还原 C++ 名字（demangle）
```

**会看到 `T`（已定义的函数）、`U`（未定义，需要链接）、`t`（内部的）等标记。**

## 28.2 完整的编译命令详解

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -O2 -g -Iinclude -Llib -lmylib \
    src/main.cpp src/utils.cpp -o build/app
```

| 选项 | 含义 |
|---|---|
| `-std=c++17` | 使用 C++17 标准（也支持 `c++11`/`c++14`/`c++20`/`c++23`/`gnu++17`） |
| `-Wall` | 打开常见警告 |
| `-Wextra` | 打开额外警告 |
| `-Wpedantic` | 严格符合标准，报告非标准扩展 |
| `-Werror` | 把警告当成错误（CI 上很有用） |
| `-Wshadow` | 警告变量遮蔽 |
| `-Wconversion` | 警告隐式类型转换（可能丢精度） |
| `-O0` | 不优化（默认，方便调试） |
| `-O1` `-O2` `-O3` | 逐级优化（发布用 `-O2` 或 `-O3`） |
| `-Os` | 优化体积 |
| `-g` | 生成调试信息（`-g` 或 `-g3`） |
| `-I<dir>` | 添加头文件搜索目录 |
| `-L<dir>` | 添加库搜索目录 |
| `-l<name>` | 链接名为 `name` 的库（`-lm` 链接 libm） |
| `-o <file>` | 指定输出文件名 |
| `-D<MACRO>` | 定义宏（如 `-DDEBUG`） |
| `-pthread` | 启用线程支持 |
| `-fsanitize=address` | AddressSanitizer（内存错误检测） |
| `-fsanitize=undefined` | UndefinedBehaviorSanitizer |
| `-fsanitize=thread` | ThreadSanitizer（数据竞争检测） |
| `-fno-omit-frame-pointer` | 保留栈帧指针（配合 sanitizer） |

### ⭐ 推荐的编译配置

**开发时（重点：能抓到 bug）：**

```bash
g++ -std=c++17 -Wall -Wextra -Wshadow -g \
    -fsanitize=address,undefined -fno-omit-frame-pointer \
    main.cpp -o app
```

**发布时（重点：快）：**

```bash
g++ -std=c++17 -O2 -DNDEBUG main.cpp -o app
```

> **`-DNDEBUG`** 会禁用 `assert`（见 28.6 节）。

### 💡 用 Visual Studio 的读者看这里

**你不需要敲上面这些命令。** Visual Studio 把编译和链接全包装在 Debug/Release 两个配置里了：

| 你想做的事 | Visual Studio 操作 | 等价 g++ 选项 |
|---|---|---|
| 编译并运行 | `Ctrl + F5` | `g++ ... -o app && ./app` |
| 只编译不运行 | `Ctrl + Shift + B` | `g++ -c ...` |
| 调试版（不优化 + 调试信息） | 配置选 **Debug**，`F5` | `-O0 -g` |
| 发布版（优化） | 配置选 **Release** | `-O2 -DNDEBUG` |
| 打开警告 | 项目属性 → C/C++ → 常规 → 警告等级 = **`/W4`** | `-Wall -Wextra` |
| 把警告当错误 | 项目属性 → C/C++ → 常规 → 将警告视为错误 = 是 | `-Werror` |
| 语言标准 | 项目属性 → C/C++ → 语言 → **ISO C++17** | `-std=c++17` |
| 附加包含目录 | 项目属性 → C/C++ → 常规 → 附加包含目录 | `-I` |
| 定义宏 | 项目属性 → C/C++ → 预处理器 → 预处理器定义 | `-D` |
| 地址消毒器 | 项目属性 → C/C++ → 常规 → 启用地址擦除器 | `-fsanitize=address` |

**⚠️ 强烈建议先把"警告等级"调到 `/W4`。** MSVC 默认是 `/W3`，会漏掉一些真 bug 的警告。教程里所有提到 `-Wall -Wextra` 的地方，对应到 VS 就是 `/W4`。

**想学命令行？** 开始菜单搜索 **"x64 Native Tools Command Prompt for VS 2022"**，在那个终端里可以使用 `cl` 命令：

```bat
cl /std:c++17 /W4 /EHsc /Zi main.cpp /Fe:app.exe
app.exe
```

| cl 选项 | 含义 | g++ 对应 |
|---|---|---|
| `/std:c++17` | C++ 标准 | `-std=c++17` |
| `/W4` | 警告等级 4 | `-Wall -Wextra` |
| `/EHsc` | 标准 C++ 异常模型（**基本都要加**） | 无 |
| `/Zi` | 生成调试信息 | `-g` |
| `/O2` | 优化 | `-O2` |
| `/Fe:app.exe` | 输出的 exe 名 | `-o app` |
| `/I<dir>` | 包含目录 | `-I` |
| `/D<MACRO>` | 定义宏 | `-D` |
| `/c` | 只编译不链接 | `-c` |

## 28.3 编译错误 vs 链接错误

### 编译错误（Compile Error）

**原因**：语法错、类型错、找不到声明、拼写错。

```
main.cpp:5:12: error: 'cout' was not declared in this scope
    5 |     std::cout << "hello" << std::endl;
      |            ^~~~
main.cpp:3:1: note: 'std::cout' is defined in header '<iostream>'; did you forget to '#include <iostream>'?
```

**读错误的方法：**

1. 看**文件名:行号:列号**
2. 看 `error:` 后面那句话（**只读第一条错误！**）
3. 后面的错误常常是第一条的连锁反应
4. `note:` 是提示，经常直接告诉你答案

> **💡 Visual Studio / MSVC 的报错格式不一样：**
>
> ```
> main.cpp(5,12): error C2039: "cout": 不是 "std" 的成员
> main.cpp(5,12): message : 是否忘记了添加 "#include <iostream>"?
> ```
>
> 格式是 `文件(行,列): error 错误码: 说明`。对照表：
>
> | MSVC 错误码 | 大概含义 |
> |---|---|
> | `C2065` | 未声明的标识符（忘了 include 或拼错） |
> | `C2039` | 不是某类的成员 |
> | `C2143` | 语法错误，缺少 `;` 之类 |
> | `C2447` | 函数定义语法错误（常是括号/分号问题） |
> | `C3861` | 找不到标识符（函数名拼错） |
> | `C2664` | 参数类型不匹配 |
> | `C2784` / `C2780` | 模板参数推导失败 |
> | `C2440` | 类型转换失败 |
> | `C4996` | 使用了不安全的 C 函数（如 `strcpy`），见 [1.6.10](#1610-其他容易踩的小坑) |
> | `C1010` | 忘了 `#include "pch.h"`，见 [1.6.5](#165--预编译头pchh问题) |
> | `LNK2005` | 重复定义（常见：多个 `main`） |
> | `LNK2019` | 无法解析的外部符号 = 未定义引用 |
> | `LNK1169` | 找到一个或多个多重定义的符号 |
>
> **在 Visual Studio 里读错误的正确姿势**：看**"错误列表"窗口**（`视图 → 错误列表`），双击一行跳转到代码。
>
> ⚠️ **一定要把左上角的筛选从"生成 + IntelliSense"改成只看"生成"**。IntelliSense 的错误是编辑器猜的，经常误报，而"生成"才是真正的编译器输出。

**常见编译错误：**

| 错误信息 | 原因 |
|---|---|
| `expected ';' before ...` | 上一行漏分号 |
| `'xxx' was not declared in this scope` | 没声明/没 include/拼错 |
| `no matching function for call to ...` | 参数类型不对 |
| `invalid conversion from ... to ...` | 类型不兼容 |
| `cannot convert 'std::string' to 'const char*'` | 需要 `.c_str()` |
| `expected '}' at end of input` | 花括号不配对 |
| `redefinition of 'xxx'` | 重复定义 |
| `'xxx' does not name a type` | 头文件没包含或拼错 |
| `no member named 'xxx' in 'yyy'` | 成员名错或访问权限问题 |
| `passing 'const X' as 'this' argument discards qualifiers` | 在 const 对象上调非 const 方法 |

### 链接错误（Link Error）

**原因**：编译都通过了，但最终组装时找不到某个函数/变量的定义。

```
/usr/bin/ld: main.o: in function `main':
main.cpp:(.text+0x15): undefined reference to `add(int, int)'
collect2: error: ld returned 1 exit status
```

**`undefined reference to XXX`** 是最常见的链接错误。

**可能原因：**

1. **忘了把某个 `.cpp` 加进编译命令**

```bash
# ❌ 忘了 utils.cpp
g++ main.cpp -o app

# ✅
g++ main.cpp utils.cpp -o app
```

2. **函数声明了但没实现**

3. **模板定义放在了 `.cpp` 里**（见第 26.7 节）

4. **忘了链接库**

```bash
# ❌
g++ main.cpp -o app
# ✅ 需要数学库
g++ main.cpp -lm -o app
```

5. **C/C++ 混合编程没有 `extern "C"`**

6. **名字修饰（name mangling）问题**

```bash
# 看真实的符号名（C++ 会修饰名字）
nm main.o | grep add
# 输出可能是：U _Z3addii       ← add(int, int) 被修饰成这样

# 还原成人能看懂的
nm -C main.o | grep add
# 输出：U add(int, int)
```

7. **重复定义**：`multiple definition of 'xxx'`

```
/usr/bin/ld: utils.o: in function `helper()':
utils.cpp:(.text+0x0): multiple definition of `helper()'
main.o:main.cpp:(.text+0x0): first defined here
```

**原因**：头文件里定义了非 inline 函数，被多个 `.cpp` 包含。

## 28.4 用 `gdb` 调试

> **💡 用 Visual Studio 的读者可以跳过这一节。** 你的调试器是图形界面的，比 gdb 好用得多，用法见 [1.6.7 节](#167-用-visual-studio-调试代替第-28-章的-gdb)。下面是 gdb 速查（供命令行用户参考）。

**调试器能让你"暂停程序、看变量的值、一步步执行"。**

### 编译时加 `-g`

```bash
g++ -std=c++17 -g -O0 main.cpp -o app
```

> **`-O0` 很重要**：优化后变量可能被合并/删除，调试会很难受。

### 基本命令

```bash
gdb ./app           # Linux / MinGW
gdb ./app.exe       # Windows MinGW
```

**进入 gdb 后的命令：**

| 命令 | 缩写 | 作用 |
|---|---|---|
| `run` | `r` | 运行程序（可带参数 `run arg1 arg2`） |
| `break main.cpp:12` | `b 12` | 在第 12 行设断点 |
| `break functionName` | `b func` | 在函数入口设断点 |
| `continue` | `c` | 继续运行到下一个断点 |
| `next` | `n` | 执行下一行（**不进入**函数） |
| `step` | `s` | 执行下一行（**进入**函数） |
| `finish` | | 执行到当前函数返回 |
| `print x` | `p x` | 打印变量 x 的值 |
| `print *ptr` | `p *ptr` | 打印指针指向的值 |
| `print arr[0]@5` | | 打印数组前 5 个元素 |
| `info locals` | `i lo` | 显示所有局部变量 |
| `info breakpoints` | `i b` | 列出所有断点 |
| `delete 1` | `d 1` | 删除 1 号断点 |
| `backtrace` | `bt` | 显示调用栈（**崩溃时救命**） |
| `frame 2` | `f 2` | 切换到调用栈的第 2 层 |
| `watch x` | | 当 x 改变时暂停 |
| `list` | `l` | 显示源码 |
| `quit` | `q` | 退出 |

### 调试示例

```cpp
// debug_demo.cpp
#include <iostream>
#include <vector>

int findMax(const std::vector<int>& v) {
    int maxVal = v[0];
    for (std::size_t i = 0; i < v.size(); i++) {
        if (v[i] > maxVal) {
            maxVal = v[i];
        }
    }
    return maxVal;
}

int main() {
    std::vector<int> data = {3, 7, 2, 9, 1};
    int result = findMax(data);
    std::cout << "最大值: " << result << "\n";
    return 0;
}
```

```bash
g++ -std=c++17 -g -O0 debug_demo.cpp -o debug_demo
gdb ./debug_demo
```

**gdb 会话：**

```
(gdb) break findMax
Breakpoint 1 at 0x...: file debug_demo.cpp, line 6.
(gdb) run
Breakpoint 1, findMax (v=std::vector of length 5, capacity 5 = {...}) at debug_demo.cpp:6
6	    int maxVal = v[0];
(gdb) print v.size()
$1 = 5
(gdb) next
7	    for (std::size_t i = 0; i < v.size(); i++) {
(gdb) next
8	        if (v[i] > maxVal) {
(gdb) print maxVal
$2 = 3
(gdb) print i
$3 = 0
(gdb) continue
最大值: 9
[Inferior 1 exited normally]
(gdb) quit
```

### 崩溃时用 `bt` 找位置

```bash
gdb ./app
(gdb) run
Program received signal SIGSEGV, Segmentation fault.
0x00005555555551a9 in buggyFunction (p=0x0) at main.cpp:15
15	    std::cout << *p << "\n";
(gdb) backtrace
#0  buggyFunction (p=0x0) at main.cpp:15
#1  0x0000555555555203 in main () at main.cpp:25
```

**一眼就看出：`p` 是空指针（`0x0`），你在解引用它。**

## 28.5 用 AddressSanitizer 抓内存 bug（比 gdb 更好用）

```bash
g++ -std=c++17 -g -fsanitize=address,undefined main.cpp -o app
./app
```

**示例：越界访问**

```cpp
#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i <= 5; i++) {       // i=5 越界！
        std::cout << arr[i] << "\n";
    }
    return 0;
}
```

**运行输出：**

```
1
2
3
4
5
=================================================================
==12345==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffd...
READ of size 4 at 0x7ffd... thread T0
    #0 0x... in main /home/user/main.cpp:6
    #1 0x... in __libc_start_main
...
Address 0x7ffd... is located in stack of thread T0 at offset 32 in frame
    #0 0x... in main /home/user/main.cpp:3

  This frame has 1 object(s):
    [32, 52) 'arr' (line 3) <== Memory access at offset 52 overflows this variable
```

**它直接告诉你：`arr` 在第 3 行，越界访问发生在第 6 行。** 这比 gdb 手动调试快 10 倍。

**能检测的问题：**

- 堆/栈越界读写
- use-after-free（使用已释放内存）
- double-free（重复释放）
- 内存泄漏（`ASAN_OPTIONS=detect_leaks=1`）
- 未初始化读取（MSan）
- 有符号整数溢出、除零、误导性移位（UBSan）

## 28.6 `assert` 断言

```cpp
#include <iostream>
#include <cassert>
#include <vector>

double average(const std::vector<int>& v) {
    assert(!v.empty() && "average() 不能接收空 vector");   // 调试期检查
    int sum = 0;
    for (int x : v) sum += x;
    return static_cast<double>(sum) / v.size();
}

int main() {
    std::vector<int> v = {1, 2, 3};
    std::cout << average(v) << "\n";

    // std::vector<int> empty;
    // std::cout << average(empty);   // assert 失败，程序中止并打印位置
    return 0;
}
```

**`assert` 的特点：**

1. **只在 Debug 版有效**：定义了 `NDEBUG` 宏后（如 `-DNDEBUG`）会被完全移除
2. **失败时直接 `abort`**，不抛异常
3. 用来检查**"我认为这里一定成立"的假设**
4. **不要用它检查用户输入**（那是运行期错误，应该用异常或返回码）

```cpp
// ✅ 用 assert：内部不变量
assert(index < size_);

// ❌ 不要用 assert：用户输入
// assert(age >= 0);      // 发布版会被删掉，用户输入就没检查了
if (age < 0) throw std::invalid_argument("年龄不能为负");   // ✅
```

## 28.7 打印调试（最朴素但有效）

```cpp
#include <iostream>
#include <vector>

// 用宏方便开关
#ifdef DEBUG
    #define LOG(msg) std::cerr << "[DEBUG] " << __FILE__ << ":" << __LINE__ \
                              << " " << msg << "\n"
#else
    #define LOG(msg)
#endif

int main() {
    LOG("程序开始");

    std::vector<int> v = {1, 2, 3};
    LOG("vector 大小: " << v.size());

    return 0;
}
```

**编译：**

```bash
g++ -DDEBUG main.cpp -o app     # 开启日志
g++ main.cpp -o app             # 关闭日志
```

**`__FILE__` 和 `__LINE__` 是预定义宏**，展开成当前文件名和行号，非常方便定位。

**为什么用 `std::cerr` 而不是 `cout`？** `cerr` 是无缓冲的，且和 `cout` 分开，不会打乱正常输出，重定向时也能分开。

## 28.8 性能分析与优化

### 计时

```cpp
#include <iostream>
#include <chrono>
#include <vector>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    // 要测的代码
    std::vector<int> v;
    for (int i = 0; i < 10000000; i++) v.push_back(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "耗时: " << ms << " ms\n";

    return 0;
}
```

### `perf`（Linux）

```bash
perf record ./app
perf report
```

### 优化的一般顺序

1. **先用 `-O2` 编译**（很多"慢"其实是没开优化）
2. **用 profiler 找出热点**（不要凭感觉猜！）
3. **优化热点**：
   - 减少不必要的拷贝（用 `const&`、`std::move`、`emplace_back`）
   - `reserve` 预分配
   - 用更合适的数据结构
   - 改善内存局部性
4. **再测一遍**，确认真的变快了

**⭐ 过早优化是万恶之源。先让它正确，再让它快。**

## 28.9 Makefile 入门

**当编译命令变长，用 Makefile 管理。**

```makefile
# Makefile
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
SRCDIR   := src
BUILDDIR := build
TARGET   := $(BUILDDIR)/app

SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILDDIR)

.PHONY: all run clean
```

> **⚠️ Makefile 里的缩进必须是 Tab，不能是空格！**

**使用：**

```bash
make          # 编译
make run      # 编译并运行
make clean    # 清理
```

**Windows 提示**：需要安装 `mingw32-make`（MSYS2 里 `pacman -S mingw-w64-x86_64-make`），命令是 `mingw32-make`。

## 28.10 CMake 入门（现代 C++ 的标准选择）

**CMake 是跨平台的构建系统生成器，几乎所有 C++ 项目都用它。**

**`CMakeLists.txt`：**

```cmake
cmake_minimum_required(VERSION 3.16)

project(MyApp VERSION 1.0 LANGUAGES CXX)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 编译选项
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wshadow)
endif()

# Debug 配置
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fsanitize=address,undefined")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

# 收集源文件
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# 创建可执行文件
add_executable(myapp ${SOURCES})

# 头文件目录
target_include_directories(myapp PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include")
```

**构建流程：**

```bash
# 1. 生成构建文件（在单独的 build 目录）
cmake -B build -DCMAKE_BUILD_TYPE=Debug

# 2. 编译
cmake --build build

# 3. 运行
./build/myapp          # Linux
.\build\myapp.exe      # Windows

# 发布版
cmake -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```

> Windows 上如果没有 Make，可以用 `cmake -B build -G "MinGW Makefiles"`。

## 28.11 常见问题排查清单

| 症状 | 排查方向 |
|---|---|
| `'xxx' was not declared` | 忘了 `#include` 或拼错 |
| `undefined reference` | 忘了编译某个 `.cpp`、模板定义在 `.cpp`、忘了 `-l` |
| `multiple definition` | 头文件里放了非 inline 的定义 |
| 程序崩溃、无输出 | 用 `-fsanitize=address` 重编，或 `gdb` + `bt` |
| 结果不对但能跑 | 打印中间值、用 `assert` 检查假设 |
| 在 A 机器能跑 B 机器不能 | 未定义行为、依赖了编译器扩展、浮点差异 |
| Debug 能跑 Release 崩溃 | 未定义行为（优化会暴露它）、竞态条件 |
| 内存一直涨 | 内存泄漏，用 `-fsanitize=address` 或 Valgrind |
| 编译特别慢 | 减少头文件依赖、用前向声明、并行编译 `-j` |

## 28.12 练习

1. 用 `g++ -E` 看一个简单程序预处理后的结果，找出 `#include <iostream>` 展开成了多少行。
2. 故意制造一个链接错误（忘写一个函数定义），观察报错信息。
3. 用 `-fsanitize=address` 编一个越界访问的程序，观察报错。
4. 用 gdb 给一个程序设断点，单步执行，查看变量。
5. 写一个 Makefile 编译包含 3 个 `.cpp` 的项目。
6. 写一个 `CMakeLists.txt` 并成功构建。

---

# 第 29 章 · 实战项目一：命令行待办清单

**这一章把前面学的几乎所有知识串起来，做一个真实可用的程序。**

## 29.1 需求分析

**功能：**

1. 添加待办事项（带优先级）
2. 列出所有事项（按优先级/时间排序）
3. 标记完成
4. 删除事项
5. 保存到文件 / 从文件加载
6. 统计信息

**技术点：**

- 类设计（`TodoItem`、`TodoList`）
- `std::vector` 容器
- 文件读写
- 异常处理
- 输入验证
- 枚举、`std::optional`
- 算法（排序、查找）

## 29.2 完整代码

**单文件版本（方便直接编译）：**

```cpp
// todo.cpp
// 编译: g++ -std=c++17 -Wall -Wextra -g todo.cpp -o todo

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <optional>
#include <iomanip>
#include <ctime>
#include <limits>

// ============================================================
// 工具函数
// ============================================================

namespace utils {

std::string trim(const std::string& s) {
    auto first = s.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    auto last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, last - first + 1);
}

// 获取今天的日期字符串 YYYY-MM-DD
std::string today() {
    std::time_t t = std::time(nullptr);
    std::tm tmBuf{};
#if defined(_WIN32)
    localtime_s(&tmBuf, &t);
#else
    localtime_r(&t, &tmBuf);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tmBuf, "%Y-%m-%d");
    return oss.str();
}

// 安全读取一行
std::string readLine(const std::string& prompt) {
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);
    return trim(line);
}

// 安全读取整数
std::optional<int> readInt(const std::string& prompt) {
    std::string line = readLine(prompt);
    if (line.empty()) return std::nullopt;
    try {
        std::size_t pos = 0;
        int value = std::stoi(line, &pos);
        if (pos != line.size()) return std::nullopt;   // 有残余字符
        return value;
    } catch (const std::exception&) {
        return std::nullopt;
    }
}

// 转义 CSV 字段（把逗号和引号处理掉）
std::string escapeCsv(const std::string& s) {
    if (s.find_first_of(",\"\n") == std::string::npos) return s;
    std::string result = "\"";
    for (char c : s) {
        if (c == '"') result += "\"\"";
        else result += c;
    }
    result += "\"";
    return result;
}

}  // namespace utils

// ============================================================
// 优先级枚举
// ============================================================

enum class Priority {
    Low = 1,
    Medium = 2,
    High = 3
};

std::string priorityToString(Priority p) {
    switch (p) {
        case Priority::High:   return "高";
        case Priority::Medium: return "中";
        case Priority::Low:    return "低";
    }
    return "?";
}

std::optional<Priority> priorityFromString(const std::string& s) {
    if (s == "高" || s == "high" || s == "3" || s == "h") return Priority::High;
    if (s == "中" || s == "medium" || s == "2" || s == "m") return Priority::Medium;
    if (s == "低" || s == "low" || s == "1" || s == "l") return Priority::Low;
    return std::nullopt;
}

// ============================================================
// 待办事项
// ============================================================

class TodoItem {
private:
    int id_;
    std::string title_;
    Priority priority_;
    bool done_;
    std::string createdAt_;

public:
    TodoItem(int id, const std::string& title, Priority priority, bool done = false,
             const std::string& createdAt = "")
        : id_(id), title_(title), priority_(priority), done_(done),
          createdAt_(createdAt.empty() ? utils::today() : createdAt)
    {
        if (title.empty()) {
            throw std::invalid_argument("待办标题不能为空");
        }
    }

    int id() const { return id_; }
    const std::string& title() const { return title_; }
    Priority priority() const { return priority_; }
    bool isDone() const { return done_; }
    const std::string& createdAt() const { return createdAt_; }

    void setDone(bool done) { done_ = done; }
    void setTitle(const std::string& title) {
        if (title.empty()) throw std::invalid_argument("标题不能为空");
        title_ = title;
    }
    void setPriority(Priority p) { priority_ = p; }

    // 数值越大优先级越高，用于排序
    int priorityValue() const { return static_cast<int>(priority_); }

    // 格式化成一行显示
    std::string format() const {
        std::ostringstream oss;
        oss << "[" << (done_ ? "✓" : " ") << "] "
            << "#" << std::setw(3) << std::setfill('0') << id_ << " "
            << "[" << priorityToString(priority_) << "] "
            << std::left << std::setw(30) << std::setfill(' ') << title_
            << " (" << createdAt_ << ")";
        return oss.str();
    }

    // 序列化成 CSV 行
    std::string toCsv() const {
        std::ostringstream oss;
        oss << id_ << ","
            << utils::escapeCsv(title_) << ","
            << static_cast<int>(priority_) << ","
            << (done_ ? 1 : 0) << ","
            << createdAt_;
        return oss.str();
    }

    // 从 CSV 字段构造
    static TodoItem fromFields(const std::vector<std::string>& fields) {
        if (fields.size() < 5) {
            throw std::runtime_error("CSV 字段不足");
        }
        int id = std::stoi(fields[0]);
        std::string title = fields[1];
        int prio = std::stoi(fields[2]);
        if (prio < 1 || prio > 3) throw std::runtime_error("优先级不合法");
        bool done = (fields[3] == "1");
        return TodoItem(id, title, static_cast<Priority>(prio), done, fields[4]);
    }
};

// ============================================================
// 待办清单
// ============================================================

class TodoList {
private:
    std::vector<TodoItem> items_;
    int nextId_ = 1;
    std::string filename_;

    // 解析一行 CSV（支持引号转义）
    static std::vector<std::string> parseCsvLine(const std::string& line) {
        std::vector<std::string> fields;
        std::string field;
        bool inQuotes = false;

        for (std::size_t i = 0; i < line.size(); i++) {
            char c = line[i];
            if (inQuotes) {
                if (c == '"') {
                    if (i + 1 < line.size() && line[i + 1] == '"') {
                        field += '"';
                        i++;
                    } else {
                        inQuotes = false;
                    }
                } else {
                    field += c;
                }
            } else {
                if (c == '"') {
                    inQuotes = true;
                } else if (c == ',') {
                    fields.push_back(field);
                    field.clear();
                } else {
                    field += c;
                }
            }
        }
        fields.push_back(field);
        return fields;
    }

public:
    explicit TodoList(const std::string& filename) : filename_(filename) {}

    // ---------- 基本操作 ----------

    TodoItem& add(const std::string& title, Priority priority) {
        TodoItem item(nextId_++, title, priority);
        items_.push_back(item);
        return items_.back();
    }

    bool remove(int id) {
        auto it = std::find_if(items_.begin(), items_.end(),
                               [id](const TodoItem& i) { return i.id() == id; });
        if (it == items_.end()) return false;
        items_.erase(it);
        return true;
    }

    TodoItem* find(int id) {
        auto it = std::find_if(items_.begin(), items_.end(),
                               [id](const TodoItem& i) { return i.id() == id; });
        return (it == items_.end()) ? nullptr : &(*it);
    }

    bool markDone(int id, bool done = true) {
        if (auto* item = find(id)) {
            item->setDone(done);
            return true;
        }
        return false;
    }

    const std::vector<TodoItem>& items() const { return items_; }
    std::size_t size() const { return items_.size(); }
    bool empty() const { return items_.empty(); }

    // ---------- 查询/统计 ----------

    std::vector<TodoItem> pending() const {
        std::vector<TodoItem> result;
        std::copy_if(items_.begin(), items_.end(), std::back_inserter(result),
                     [](const TodoItem& i) { return !i.isDone(); });
        return result;
    }

    std::vector<TodoItem> completed() const {
        std::vector<TodoItem> result;
        std::copy_if(items_.begin(), items_.end(), std::back_inserter(result),
                     [](const TodoItem& i) { return i.isDone(); });
        return result;
    }

    void sortByPriority(bool descending = true) {
        std::sort(items_.begin(), items_.end(),
                  [descending](const TodoItem& a, const TodoItem& b) {
                      if (a.isDone() != b.isDone()) {
                          return !a.isDone();      // 未完成的排前面
                      }
                      if (descending) {
                          return a.priorityValue() > b.priorityValue();
                      }
                      return a.priorityValue() < b.priorityValue();
                  });
    }

    void sortById() {
        std::sort(items_.begin(), items_.end(),
                  [](const TodoItem& a, const TodoItem& b) {
                      return a.id() < b.id();
                  });
    }

    std::size_t countByPriority(Priority p) const {
        return std::count_if(items_.begin(), items_.end(),
                             [p](const TodoItem& i) { return i.priority() == p; });
    }

    // ---------- 持久化 ----------

    void save() const {
        std::ofstream out(filename_);
        if (!out) {
            throw std::runtime_error("无法写入文件: " + filename_);
        }
        out << "# id,title,priority,done,createdAt\n";
        for (const auto& item : items_) {
            out << item.toCsv() << "\n";
        }
        if (!out) {
            throw std::runtime_error("写入文件时出错: " + filename_);
        }
    }

    void load() {
        std::ifstream in(filename_);
        if (!in) {
            // 文件不存在不是错误，只是空清单
            return;
        }

        items_.clear();
        nextId_ = 1;

        std::string line;
        int lineNum = 0;
        int errorCount = 0;

        while (std::getline(in, line)) {
            lineNum++;
            if (line.empty() || line[0] == '#') continue;

            try {
                auto fields = parseCsvLine(line);
                TodoItem item = TodoItem::fromFields(fields);
                items_.push_back(item);
                if (item.id() >= nextId_) {
                    nextId_ = item.id() + 1;
                }
            } catch (const std::exception& e) {
                errorCount++;
                std::cerr << "警告: 第 " << lineNum << " 行解析失败（已跳过）: "
                          << e.what() << "\n";
            }
        }

        if (errorCount > 0) {
            std::cerr << "共跳过 " << errorCount << " 行有问题的数据\n";
        }
    }

    // ---------- 显示 ----------

    void printAll(const std::string& title = "全部待办") const {
        std::cout << "\n===== " << title << " (" << items_.size() << " 项) =====\n";
        if (items_.empty()) {
            std::cout << "  （空）\n";
            return;
        }
        for (const auto& item : items_) {
            std::cout << "  " << item.format() << "\n";
        }
    }

    void printStats() const {
        std::size_t doneCount = completed().size();
        std::size_t pendingCount = items_.size() - doneCount;

        std::cout << "\n===== 统计 =====\n";
        std::cout << "  总数:     " << items_.size() << "\n";
        std::cout << "  未完成:   " << pendingCount << "\n";
        std::cout << "  已完成:   " << doneCount << "\n";
        std::cout << "  完成率:   ";
        if (items_.empty()) {
            std::cout << "N/A\n";
        } else {
            std::cout << std::fixed << std::setprecision(1)
                      << (100.0 * doneCount / items_.size()) << "%\n";
        }
        std::cout << "  高优先级: " << countByPriority(Priority::High) << "\n";
        std::cout << "  中优先级: " << countByPriority(Priority::Medium) << "\n";
        std::cout << "  低优先级: " << countByPriority(Priority::Low) << "\n";
    }
};

// ============================================================
// 交互界面
// ============================================================

void printMenu() {
    std::cout << "\n╔══════════════════════════════╗\n"
              << "║      待办清单管理            ║\n"
              << "╠══════════════════════════════╣\n"
              << "║  1. 查看所有待办             ║\n"
              << "║  2. 添加待办                 ║\n"
              << "║  3. 标记完成                 ║\n"
              << "║  4. 删除待办                 ║\n"
              << "║  5. 按优先级排序             ║\n"
              << "║  6. 查看未完成               ║\n"
              << "║  7. 查看统计                 ║\n"
              << "║  8. 保存                     ║\n"
              << "║  0. 保存并退出               ║\n"
              << "╚══════════════════════════════╝\n";
}

void handleAdd(TodoList& list) {
    std::string title = utils::readLine("请输入待办内容: ");
    if (title.empty()) {
        std::cout << "已取消（内容为空）\n";
        return;
    }

    std::cout << "优先级 (1=低 2=中 3=高，直接回车默认为中): ";
    std::string prioInput = utils::readLine("");
    Priority priority = Priority::Medium;
    if (!prioInput.empty()) {
        auto parsed = priorityFromString(prioInput);
        if (!parsed) {
            std::cout << "优先级无效，使用默认值「中」\n";
        } else {
            priority = *parsed;
        }
    }

    try {
        const auto& item = list.add(title, priority);
        std::cout << "✓ 已添加 #" << item.id() << " " << item.title() << "\n";
    } catch (const std::exception& e) {
        std::cout << "✗ 添加失败: " << e.what() << "\n";
    }
}

void handleMarkDone(TodoList& list) {
    if (list.empty()) {
        std::cout << "清单是空的\n";
        return;
    }
    list.printAll();
    auto id = utils::readInt("请输入要标记的编号: ");
    if (!id) {
        std::cout << "输入无效\n";
        return;
    }
    if (list.markDone(*id)) {
        std::cout << "✓ 已标记 #" << *id << " 为完成\n";
    } else {
        std::cout << "✗ 找不到编号 #" << *id << "\n";
    }
}

void handleRemove(TodoList& list) {
    if (list.empty()) {
        std::cout << "清单是空的\n";
        return;
    }
    list.printAll();
    auto id = utils::readInt("请输入要删除的编号: ");
    if (!id) {
        std::cout << "输入无效\n";
        return;
    }

    auto* item = list.find(*id);
    if (item == nullptr) {
        std::cout << "✗ 找不到编号 #" << *id << "\n";
        return;
    }

    std::string confirm = utils::readLine(
        "确认删除『" + item->title() + "』? (y/N): ");
    if (confirm == "y" || confirm == "Y") {
        list.remove(*id);
        std::cout << "✓ 已删除\n";
    } else {
        std::cout << "已取消\n";
    }
}

int main(int argc, char* argv[]) {
    // 支持自定义数据文件路径
    std::string dataFile = (argc > 1) ? argv[1] : "todo_data.csv";

    std::cout << "待办清单程序 (数据文件: " << dataFile << ")\n";

    TodoList list(dataFile);

    try {
        list.load();
        std::cout << "已加载 " << list.size() << " 条待办\n";
    } catch (const std::exception& e) {
        std::cerr << "加载失败: " << e.what() << "\n";
        std::cerr << "将以空清单启动\n";
    }

    bool running = true;
    while (running) {
        printMenu();
        auto choice = utils::readInt("请选择: ");

        if (!choice) {
            std::cout << "输入无效，请输入数字\n";
            continue;
        }

        try {
            switch (*choice) {
                case 1:
                    list.printAll();
                    break;

                case 2:
                    handleAdd(list);
                    break;

                case 3:
                    handleMarkDone(list);
                    break;

                case 4:
                    handleRemove(list);
                    break;

                case 5: {
                    std::string order = utils::readLine(
                        "排序方向 (1=优先级从高到低 2=从低到高): ");
                    list.sortByPriority(order != "2");
                    list.printAll("按优先级排序");
                    break;
                }

                case 6: {
                    auto pending = list.pending();
                    std::cout << "\n===== 未完成 (" << pending.size() << " 项) =====\n";
                    if (pending.empty()) {
                        std::cout << "  🎉 全部完成了！\n";
                    } else {
                        for (const auto& item : pending) {
                            std::cout << "  " << item.format() << "\n";
                        }
                    }
                    break;
                }

                case 7:
                    list.printStats();
                    break;

                case 8:
                    list.save();
                    std::cout << "✓ 已保存到 " << dataFile << "\n";
                    break;

                case 0:
                    list.save();
                    std::cout << "✓ 已保存，再见！\n";
                    running = false;
                    break;

                default:
                    std::cout << "无效选项，请输入 0-8\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "✗ 操作失败: " << e.what() << "\n";
        }
    }

    return 0;
}
```

## 29.3 编译和运行

**命令行（g++ / MinGW）：**

```bash
g++ -std=c++17 -Wall -Wextra -g todo.cpp -o todo
./todo
# 或者指定数据文件
./todo my_todos.csv
```

**Visual Studio：**

1. 新建**空项目**，项目名 `TodoList`
2. 项目属性里设置 **C++ 语言标准 = ISO C++17**，命令行加 **`/utf-8`**（重要，因为程序里有中文输出）
3. `源文件 → 添加 → 新建项 → C++ 文件`，命名 `todo.cpp`，把上面的代码**完整**复制进去
4. 按 `Ctrl + F5` 运行

> ⚠️ **中文显示注意**：这个程序有大量中文输出（菜单、提示）。如果你没在项目属性里加 `/utf-8`，会看到一堆乱码。详见 [1.6.2 节](#162--中文乱码问题)。

> **数据文件位置**：程序会在**当前工作目录**创建 `todo_data.csv`。在 Visual Studio 里按 `Ctrl + F5` 时，工作目录默认是**项目目录**（`.vcxproj` 所在处），不是 `x64\Debug\`。想确认的话，程序启动时会打印文件名，退出后去项目文件夹里找。

> **⚠️ 输入中文**：Windows 控制台默认用 GBK 读取输入。如果你在 VS 里用 `/utf-8` 编译，但输入中文标题时出现乱码，可以在 `main` 开头加：
> ```cpp
> #include <windows.h>
> SetConsoleCP(65001);          // 输入用 UTF-8
> SetConsoleOutputCP(65001);    // 输出用 UTF-8
> ```
> 或者干脆用英文标题测试功能。

**使用示例：**

```
待办清单程序 (数据文件: todo_data.csv)
已加载 0 条待办

╔══════════════════════════════╗
║      待办清单管理            ║
...
请选择: 2
请输入待办内容: 学习 C++ 指针
优先级 (1=低 2=中 3=高，直接回车默认为中): 3
✓ 已添加 #001 学习 C++ 指针

请选择: 2
请输入待办内容: 买牛奶
优先级 (1=低 2=中 3=高，直接回车默认为中):
✓ 已添加 #002 买牛奶

请选择: 1

===== 全部待办 (2 项) =====
  [ ] #001 [高] 学习 C++ 指针                  (2024-01-15)
  [ ] #002 [中] 买牛奶                          (2024-01-15)

请选择: 5
排序方向 (1=优先级从高到低 2=从低到高): 1

===== 按优先级排序 (2 项) =====
  [ ] #001 [高] 学习 C++ 指针                  (2024-01-15)
  [ ] #002 [中] 买牛奶                          (2024-01-15)

请选择: 3

===== 全部待办 (2 项) =====
  [ ] #001 [高] 学习 C++ 指针                  (2024-01-15)
  [ ] #002 [中] 买牛奶                          (2024-01-15)
请输入要标记的编号: 2
✓ 已标记 #002 为完成

请选择: 7

===== 统计 =====
  总数:     2
  未完成:   1
  已完成:   1
  完成率:   50.0%
  高优先级: 1
  中优先级: 1
  低优先级: 0

请选择: 0
✓ 已保存，再见！
```

**生成的 `todo_data.csv`：**

```
# id,title,priority,done,createdAt
1,学习 C++ 指针,3,0,2024-01-15
2,买牛奶,2,1,2024-01-15
```

## 29.4 这个项目用到的知识点回顾

| 知识点 | 用在哪里 |
|---|---|
| 类与封装 | `TodoItem`、`TodoList` |
| 构造函数与验证 | `TodoItem` 构造函数检查空标题 |
| 枚举类 | `Priority` |
| `std::vector` | `items_` |
| `std::optional` | `readInt` 返回值、`priorityFromString` |
| 异常处理 | 文件操作、参数验证 |
| 文件读写 | `save()` / `load()` |
| 字符串处理 | `trim`、`escapeCsv`、`parseCsvLine` |
| STL 算法 | `find_if`、`sort`、`copy_if`、`count_if` |
| Lambda | 各种比较器和谓词 |
| 引用与 const | 参数传递、`const` 成员函数 |
| 命名空间 | `utils`、匿名命名空间思想 |
| `switch` | 菜单分发 |
| 输入验证 | `readLine`、`readInt` |
| 格式化输出 | `std::setw`、`std::setfill` |

## 29.5 扩展练习

1. **添加截止日期**：给 `TodoItem` 加 `dueDate` 字段，支持按截止日期排序，标记逾期项。
2. **添加标签**：支持给待办打标签（如 `#工作` `#生活`），能按标签过滤。
3. **添加搜索**：支持按关键字搜索标题。
4. **添加撤销**：记录操作历史，支持撤销上一步。
5. **拆分多文件**：把 `TodoItem`、`TodoList`、`utils`、`main` 拆成独立文件，写 Makefile。
6. **添加单元测试**：给 `TodoList` 写测试（可以先用简单的 `assert`）。
7. **添加彩色输出**：用 ANSI 转义序列给不同优先级上色。

**扩展 7 的提示：**

```cpp
namespace color {
    constexpr const char* RESET  = "\033[0m";
    constexpr const char* RED    = "\033[31m";
    constexpr const char* GREEN  = "\033[32m";
    constexpr const char* YELLOW = "\033[33m";
    constexpr const char* BLUE   = "\033[34m";
    constexpr const char* BOLD   = "\033[1m";
}

// 使用
std::cout << color::RED << "高优先级" << color::RESET << "\n";
```

---

# 第 30 章 · 实战项目二：矩阵运算库

**这个项目练习：模板、运算符重载、异常、RAII、测试。**

## 30.1 需求

实现一个 `Matrix<T>` 模板类：

- 动态大小的二维矩阵
- 构造、拷贝、移动
- 元素访问（带边界检查）
- 矩阵加法、减法、乘法、数乘
- 转置、行列式、单位矩阵
- 输出格式化
- 异常安全

## 30.2 完整代码

**编译说明（Visual Studio）：** 新建空项目 → 设置 C++17 + `/utf-8` → 添加 `matrix.cpp` → `Ctrl + F5`。这个程序自带 30 个测试，全部通过会打印 `🎉 全部测试通过！`。

```cpp
// matrix.cpp
// 编译: g++ -std=c++17 -Wall -Wextra -g matrix.cpp -o matrix

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <cmath>
#include <numeric>
#include <sstream>
#include <algorithm>

// ============================================================
// 矩阵异常
// ============================================================

class MatrixError : public std::runtime_error {
public:
    explicit MatrixError(const std::string& msg)
        : std::runtime_error("矩阵错误: " + msg) {}
};

class DimensionMismatch : public MatrixError {
public:
    DimensionMismatch(std::size_t r1, std::size_t c1,
                      std::size_t r2, std::size_t c2)
        : MatrixError("维度不匹配: (" + std::to_string(r1) + "x" + std::to_string(c1)
                      + ") vs (" + std::to_string(r2) + "x" + std::to_string(c2) + ")") {}
};

// ============================================================
// 矩阵类模板
// ============================================================

template <typename T>
class Matrix {
private:
    std::size_t rows_;
    std::size_t cols_;
    std::vector<T> data_;          // 一维存储，行优先

    std::size_t index(std::size_t r, std::size_t c) const {
        return r * cols_ + c;
    }

    void checkBounds(std::size_t r, std::size_t c) const {
        if (r >= rows_ || c >= cols_) {
            std::ostringstream oss;
            oss << "索引 (" << r << ", " << c << ") 越界，矩阵大小 "
                << rows_ << "x" << cols_;
            throw std::out_of_range(oss.str());
        }
    }

    static void checkSameSize(const Matrix& a, const Matrix& b) {
        if (a.rows_ != b.rows_ || a.cols_ != b.cols_) {
            throw DimensionMismatch(a.rows_, a.cols_, b.rows_, b.cols_);
        }
    }

public:
    // ---------- 构造 ----------

    Matrix() : rows_(0), cols_(0) {}

    Matrix(std::size_t rows, std::size_t cols, const T& initial = T{})
        : rows_(rows), cols_(cols), data_(rows * cols, initial)
    {
        if (rows == 0 || cols == 0) {
            throw MatrixError("矩阵维度必须大于 0");
        }
    }

    // 从初始化列表构造
    Matrix(std::initializer_list<std::initializer_list<T>> init) {
        rows_ = init.size();
        if (rows_ == 0) throw MatrixError("不能构造空矩阵");

        cols_ = init.begin()->size();
        if (cols_ == 0) throw MatrixError("每行至少要有 1 个元素");

        data_.reserve(rows_ * cols_);
        for (const auto& row : init) {
            if (row.size() != cols_) {
                throw MatrixError("每行的列数必须相同");
            }
            for (const auto& value : row) {
                data_.push_back(value);
            }
        }
    }

    // 拷贝/移动由编译器生成的版本已经正确（零法则！）
    Matrix(const Matrix&) = default;
    Matrix& operator=(const Matrix&) = default;
    Matrix(Matrix&&) noexcept = default;
    Matrix& operator=(Matrix&&) noexcept = default;
    ~Matrix() = default;

    // ---------- 静态工厂 ----------

    static Matrix identity(std::size_t n) {
        Matrix result(n, n, T{});
        for (std::size_t i = 0; i < n; i++) {
            result(i, i) = T{1};
        }
        return result;
    }

    static Matrix zeros(std::size_t rows, std::size_t cols) {
        return Matrix(rows, cols, T{});
    }

    static Matrix ones(std::size_t rows, std::size_t cols) {
        return Matrix(rows, cols, T{1});
    }

    // ---------- 访问 ----------

    std::size_t rows() const { return rows_; }
    std::size_t cols() const { return cols_; }
    std::size_t size() const { return data_.size(); }
    bool empty() const { return data_.empty(); }

    // 不检查（快）
    T& operator()(std::size_t r, std::size_t c) { return data_[index(r, c)]; }
    const T& operator()(std::size_t r, std::size_t c) const {
        return data_[index(r, c)];
    }

    // 检查（安全）
    T& at(std::size_t r, std::size_t c) {
        checkBounds(r, c);
        return data_[index(r, c)];
    }
    const T& at(std::size_t r, std::size_t c) const {
        checkBounds(r, c);
        return data_[index(r, c)];
    }

    // ---------- 算术运算 ----------

    Matrix operator+(const Matrix& other) const {
        checkSameSize(*this, other);
        Matrix result(rows_, cols_);
        for (std::size_t i = 0; i < data_.size(); i++) {
            result.data_[i] = data_[i] + other.data_[i];
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        checkSameSize(*this, other);
        Matrix result(rows_, cols_);
        for (std::size_t i = 0; i < data_.size(); i++) {
            result.data_[i] = data_[i] - other.data_[i];
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols_ != other.rows_) {
            throw DimensionMismatch(rows_, cols_, other.rows_, other.cols_);
        }

        Matrix result(rows_, other.cols_, T{});

        // 优化：i-k-j 顺序对缓存更友好（相比 i-j-k）
        for (std::size_t i = 0; i < rows_; i++) {
            for (std::size_t k = 0; k < cols_; k++) {
                T a = data_[index(i, k)];
                if (a == T{}) continue;              // 跳过 0（对稀疏矩阵有效）
                for (std::size_t j = 0; j < other.cols_; j++) {
                    result.data_[result.index(i, j)] += a * other.data_[other.index(k, j)];
                }
            }
        }
        return result;
    }

    // 数乘
    Matrix operator*(const T& scalar) const {
        Matrix result(rows_, cols_);
        for (std::size_t i = 0; i < data_.size(); i++) {
            result.data_[i] = data_[i] * scalar;
        }
        return result;
    }

    // 复合赋值
    Matrix& operator+=(const Matrix& other) {
        checkSameSize(*this, other);
        for (std::size_t i = 0; i < data_.size(); i++) {
            data_[i] += other.data_[i];
        }
        return *this;
    }

    Matrix& operator-=(const Matrix& other) {
        checkSameSize(*this, other);
        for (std::size_t i = 0; i < data_.size(); i++) {
            data_[i] -= other.data_[i];
        }
        return *this;
    }

    Matrix& operator*=(const T& scalar) {
        for (auto& value : data_) value *= scalar;
        return *this;
    }

    // 一元负号
    Matrix operator-() const {
        Matrix result(rows_, cols_);
        for (std::size_t i = 0; i < data_.size(); i++) {
            result.data_[i] = -data_[i];
        }
        return result;
    }

    // 相等比较
    bool operator==(const Matrix& other) const {
        return rows_ == other.rows_ && cols_ == other.cols_ &&
               data_ == other.data_;
    }

    bool operator!=(const Matrix& other) const { return !(*this == other); }

    // ---------- 变换 ----------

    Matrix transpose() const {
        Matrix result(cols_, rows_);
        for (std::size_t i = 0; i < rows_; i++) {
            for (std::size_t j = 0; j < cols_; j++) {
                result.data_[result.index(j, i)] = data_[index(i, j)];
            }
        }
        return result;
    }

    // 只对数值类型有意义
    T trace() const {
        if (rows_ != cols_) {
            throw MatrixError("只有方阵才有迹");
        }
        T sum = T{};
        for (std::size_t i = 0; i < rows_; i++) {
            sum += data_[index(i, i)];
        }
        return sum;
    }

    // 高斯消元法求行列式（只对方阵）
    T determinant() const {
        if (rows_ != cols_) {
            throw MatrixError("只有方阵才有行列式");
        }

        std::size_t n = rows_;
        if (n == 0) return T{1};
        if (n == 1) return data_[0];

        // 复制一份（用 double 做中间计算，避免整数除法问题）
        std::vector<double> m(n * n);
        for (std::size_t i = 0; i < n * n; i++) {
            m[i] = static_cast<double>(data_[i]);
        }

        double det = 1.0;
        for (std::size_t i = 0; i < n; i++) {
            // 找主元
            std::size_t pivot = i;
            for (std::size_t k = i + 1; k < n; k++) {
                if (std::fabs(m[k * n + i]) > std::fabs(m[pivot * n + i])) {
                    pivot = k;
                }
            }

            if (std::fabs(m[pivot * n + i]) < 1e-12) {
                return T{};                       // 奇异矩阵
            }

            if (pivot != i) {
                for (std::size_t j = 0; j < n; j++) {
                    std::swap(m[i * n + j], m[pivot * n + j]);
                }
                det = -det;                       // 交换行改变符号
            }

            det *= m[i * n + i];

            for (std::size_t k = i + 1; k < n; k++) {
                double factor = m[k * n + i] / m[i * n + i];
                for (std::size_t j = i; j < n; j++) {
                    m[k * n + j] -= factor * m[i * n + j];
                }
            }
        }

        return static_cast<T>(det);
    }

    // 逐元素操作
    Matrix map(const std::function<T(const T&)>& f) const {
        Matrix result(rows_, cols_);
        for (std::size_t i = 0; i < data_.size(); i++) {
            result.data_[i] = f(data_[i]);
        }
        return result;
    }

    T sum() const {
        return std::accumulate(data_.begin(), data_.end(), T{});
    }

    T maxElement() const {
        if (data_.empty()) throw MatrixError("空矩阵没有最大值");
        return *std::max_element(data_.begin(), data_.end());
    }

    T minElement() const {
        if (data_.empty()) throw MatrixError("空矩阵没有最小值");
        return *std::min_element(data_.begin(), data_.end());
    }

    // ---------- 输出 ----------

    void print(const std::string& title = "") const {
        if (!title.empty()) {
            std::cout << title << " (" << rows_ << "x" << cols_ << "):\n";
        }
        for (std::size_t i = 0; i < rows_; i++) {
            std::cout << "  [";
            for (std::size_t j = 0; j < cols_; j++) {
                std::cout << std::setw(8) << std::fixed << std::setprecision(2)
                          << static_cast<double>(data_[index(i, j)]);
                if (j + 1 < cols_) std::cout << " ";
            }
            std::cout << " ]\n";
        }
    }
};

// 数乘的对称版本：scalar * matrix
template <typename T>
Matrix<T> operator*(const T& scalar, const Matrix<T>& m) {
    return m * scalar;
}

// 输出运算符
template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) {
    for (std::size_t i = 0; i < m.rows(); i++) {
        for (std::size_t j = 0; j < m.cols(); j++) {
            os << m(i, j);
            if (j + 1 < m.cols()) os << " ";
        }
        if (i + 1 < m.rows()) os << "\n";
    }
    return os;
}

// ============================================================
// 演示与测试
// ============================================================

static int testsPassed = 0;
static int testsFailed = 0;

void check(bool condition, const std::string& testName) {
    if (condition) {
        std::cout << "  ✓ " << testName << "\n";
        testsPassed++;
    } else {
        std::cout << "  ✗ " << testName << " 失败！\n";
        testsFailed++;
    }
}

void testConstruction() {
    std::cout << "\n[测试] 构造\n";

    Matrix<int> m1(2, 3);
    check(m1.rows() == 2 && m1.cols() == 3, "按尺寸构造");
    check(m1(0, 0) == 0, "默认值为 0");

    Matrix<int> m2(2, 2, 5);
    check(m2(1, 1) == 5, "指定初始值");

    Matrix<int> m3 = {{1, 2, 3}, {4, 5, 6}};
    check(m3.rows() == 2 && m3.cols() == 3, "初始化列表构造");
    check(m3(1, 2) == 6, "初始化列表内容正确");

    Matrix<int> id = Matrix<int>::identity(3);
    check(id(0, 0) == 1 && id(0, 1) == 0 && id(2, 2) == 1, "单位矩阵");

    bool threw = false;
    try {
        Matrix<int> bad(0, 5);
    } catch (const MatrixError&) {
        threw = true;
    }
    check(threw, "零维度抛异常");

    threw = false;
    try {
        Matrix<int> bad = {{1, 2}, {3}};
    } catch (const MatrixError&) {
        threw = true;
    }
    check(threw, "不规则初始化列表抛异常");
}

void testArithmetic() {
    std::cout << "\n[测试] 算术运算\n";

    Matrix<int> a = {{1, 2}, {3, 4}};
    Matrix<int> b = {{5, 6}, {7, 8}};

    Matrix<int> sum = a + b;
    check(sum(0, 0) == 6 && sum(1, 1) == 12, "加法");

    Matrix<int> diff = b - a;
    check(diff(0, 0) == 4 && diff(1, 1) == 4, "减法");

    Matrix<int> prod = a * b;
    // [1 2] [5 6]   [1*5+2*7  1*6+2*8]   [19 22]
    // [3 4] [7 8] = [3*5+4*7  3*6+4*8] = [43 50]
    check(prod(0, 0) == 19 && prod(0, 1) == 22 &&
          prod(1, 0) == 43 && prod(1, 1) == 50, "矩阵乘法");

    Matrix<int> scaled = a * 3;
    check(scaled(0, 0) == 3 && scaled(1, 1) == 12, "数乘");

    Matrix<int> scaled2 = 3 * a;
    check(scaled2 == scaled, "数乘交换律");

    Matrix<int> neg = -a;
    check(neg(0, 0) == -1, "一元负号");

    Matrix<int> acc = a;
    acc += b;
    check(acc == sum, "复合加法赋值");

    // 维度不匹配
    Matrix<int> c = {{1, 2, 3}};
    bool threw = false;
    try {
        auto bad = a + c;
    } catch (const DimensionMismatch&) {
        threw = true;
    }
    check(threw, "加法维度检查");

    threw = false;
    try {
        auto bad = a * c;      // (2x2) * (1x3) 不合法
    } catch (const DimensionMismatch&) {
        threw = true;
    }
    check(threw, "乘法维度检查");
}

void testTranspose() {
    std::cout << "\n[测试] 转置\n";

    Matrix<int> m = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int> t = m.transpose();

    check(t.rows() == 3 && t.cols() == 2, "转置后尺寸");
    check(t(0, 0) == 1 && t(0, 1) == 4, "转置内容");
    check(t(2, 0) == 3 && t(2, 1) == 6, "转置内容 2");

    Matrix<int> tt = t.transpose();
    check(tt == m, "转置两次回到原矩阵");
}

void testDeterminant() {
    std::cout << "\n[测试] 行列式\n";

    Matrix<double> m1 = {{1, 2}, {3, 4}};
    check(std::fabs(m1.determinant() - (-2.0)) < 1e-9, "2x2 行列式");

    Matrix<double> m2 = {{6, 1, 1}, {4, -2, 5}, {2, 8, 7}};
    check(std::fabs(m2.determinant() - (-306.0)) < 1e-9, "3x3 行列式");

    Matrix<double> singular = {{1, 2}, {2, 4}};
    check(std::fabs(singular.determinant()) < 1e-9, "奇异矩阵行列式为 0");

    Matrix<double> id = Matrix<double>::identity(4);
    check(std::fabs(id.determinant() - 1.0) < 1e-9, "单位矩阵行列式为 1");
}

void testStatistics() {
    std::cout << "\n[测试] 统计\n";

    Matrix<int> m = {{1, 2, 3}, {4, 5, 6}};
    check(m.sum() == 21, "求和");
    check(m.maxElement() == 6, "最大值");
    check(m.minElement() == 1, "最小值");
    check(m.trace() == 1 + 5 + 0, "迹（非方阵会抛异常）");
}

void testTrace() {
    std::cout << "\n[测试] 迹\n";

    Matrix<int> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    check(m.trace() == 15, "3x3 迹");

    bool threw = false;
    try {
        Matrix<int> nonSquare = {{1, 2, 3}, {4, 5, 6}};
        nonSquare.trace();
    } catch (const MatrixError&) {
        threw = true;
    }
    check(threw, "非方阵求迹抛异常");
}

void runTests() {
    std::cout << "╔══════════════════════════════════╗\n"
              << "║       矩阵库测试套件             ║\n"
              << "╚══════════════════════════════════╝\n";

    testConstruction();
    testArithmetic();
    testTranspose();
    testDeterminant();
    testTrace();
    testStatistics();

    std::cout << "\n══════════════════════════════════\n";
    std::cout << "通过: " << testsPassed << ", 失败: " << testsFailed << "\n";
    if (testsFailed == 0) {
        std::cout << "🎉 全部测试通过！\n";
    }
}

void runDemo() {
    std::cout << "\n╔══════════════════════════════════╗\n"
              << "║       矩阵库演示                 ║\n"
              << "╚══════════════════════════════════╝\n";

    Matrix<double> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 10}};
    Matrix<double> b = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    a.print("矩阵 A");
    b.print("矩阵 B（单位矩阵）");

    (a + b).print("A + B");
    (a * b).print("A × B");
    (a * 2.0).print("A × 2");
    a.transpose().print("A 的转置");

    std::cout << "\nA 的行列式: " << a.determinant() << "\n";
    std::cout << "A 的迹:     " << a.trace() << "\n";
    std::cout << "A 的元素和: " << a.sum() << "\n";

    // 应用：解线性方程组 Ax = b（2x2 示例，用克莱姆法则）
    std::cout << "\n--- 解线性方程组 ---\n";
    Matrix<double> coef = {{2, 1}, {1, 3}};
    Matrix<double> rhs = {{5}, {10}};
    coef.print("系数矩阵");
    rhs.print("右端向量");

    double detA = coef.determinant();
    if (std::fabs(detA) > 1e-12) {
        Matrix<double> x1 = {{5, 1}, {10, 3}};
        Matrix<double> x2 = {{2, 5}, {1, 10}};
        std::cout << "解: x = " << x1.determinant() / detA
                  << ", y = " << x2.determinant() / detA << "\n";
        std::cout << "验证: 2*1 + 1*3 = " << 2 * (x1.determinant() / detA) + 1 * (x2.determinant() / detA)
                  << " (应为 5)\n";
    } else {
        std::cout << "系数矩阵奇异，无唯一解\n";
    }
}

int main() {
    try {
        runTests();
        runDemo();
    } catch (const std::exception& e) {
        std::cerr << "程序异常: " << e.what() << "\n";
        return 1;
    }
    return testsFailed == 0 ? 0 : 1;
}
```

> **注意**：需要 `#include <functional>` 使用 `std::function`。

## 30.3 这个项目用到的知识点

| 知识点 | 用在哪里 |
|---|---|
| **类模板** | `Matrix<T>` |
| **零法则** | `= default` 拷贝/移动 |
| **运算符重载** | `+ - * += -= == () <<` |
| **异常层次** | `MatrixError` → `DimensionMismatch` |
| **`initializer_list`** | `Matrix<int> m = {{1,2},{3,4}}` |
| **一维存储二维** | `data_[r * cols_ + c]`（缓存友好） |
| **STL 算法** | `accumulate`、`max_element`、`std::swap` |
| **Lambda** | `map` 方法的参数 |
| **`std::function`** | `map` 的参数类型 |
| **模板函数** | `operator*`（scalar 在左）、`operator<<` |
| **异常安全** | 所有操作要么成功要么抛异常，不留半成品 |
| **边界检查** | `at()` vs `()` |
| **性能意识** | i-k-j 循环顺序、跳过零元素 |

## 30.4 扩展练习

1. **矩阵求逆**：用高斯-约当消元法实现 `inverse()`。
2. **LU 分解**：实现 LU 分解并用于解方程。
3. **行/列操作**：`swapRows()`、`scaleRow()`、`addRow()`。
4. **子矩阵**：`subMatrix(r0, c0, rows, cols)`。
5. **矩阵拼接**：水平/垂直拼接两个矩阵。
6. **缓存优化**：实现分块矩阵乘法（blocked multiplication），对比性能。
7. **`std::complex` 支持**：让 `Matrix<std::complex<double>>` 也能工作，测试一下哪些方法会失败。
8. **序列化**：支持把矩阵存到文件再读回来。

**扩展 1 的提示：**

```cpp
Matrix<double> inverse() const {
    if (rows_ != cols_) throw MatrixError("只有方阵可求逆");
    std::size_t n = rows_;

    // 构造增广矩阵 [A | I]
    Matrix<double> aug(n, 2 * n, 0.0);
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < n; j++) {
            aug(i, j) = static_cast<double>((*this)(i, j));
        }
        aug(i, n + i) = 1.0;
    }

    // 高斯-约当消元
    for (std::size_t i = 0; i < n; i++) {
        // 找主元
        std::size_t pivot = i;
        for (std::size_t k = i + 1; k < n; k++) {
            if (std::fabs(aug(k, i)) > std::fabs(aug(pivot, i))) pivot = k;
        }
        if (std::fabs(aug(pivot, i)) < 1e-12) {
            throw MatrixError("矩阵不可逆（奇异）");
        }
        if (pivot != i) {
            for (std::size_t j = 0; j < 2 * n; j++) {
                std::swap(aug(i, j), aug(pivot, j));
            }
        }
        // 归一化当前行
        double divisor = aug(i, i);
        for (std::size_t j = 0; j < 2 * n; j++) aug(i, j) /= divisor;
        // 消去其他行
        for (std::size_t k = 0; k < n; k++) {
            if (k == i) continue;
            double factor = aug(k, i);
            for (std::size_t j = 0; j < 2 * n; j++) {
                aug(k, j) -= factor * aug(i, j);
            }
        }
    }

    // 取出右半部分
    Matrix<double> result(n, n);
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < n; j++) {
            result(i, j) = aug(i, n + j);
        }
    }
    return result;
}
```

---

# 附录 A · 常见错误与报错解读

## A.1 编译错误

### `expected ';' before 'X'`

```
main.cpp:5:15: error: expected ';' before 'return'
```

**原因**：上一行漏了分号。

```cpp
int x = 10        // ❌ 漏了 ;
return 0;
```

### `'X' was not declared in this scope`

```
main.cpp:6:5: error: 'cout' was not declared in this scope
```

**原因**（按可能性排序）：

1. 忘了 `#include <iostream>`
2. 忘了写 `std::` 前缀
3. 变量名拼错
4. 变量定义在后面的作用域

### `no matching function for call to 'X'`

```
error: no matching function for call to 'max(int, double)'
```

**原因**：参数类型不匹配。

```cpp
std::max(1, 2.5);          // ❌ int 和 double 类型不同
std::max(1.0, 2.5);        // ✅
std::max<double>(1, 2.5);  // ✅ 显式指定
```

### `cannot convert 'std::string' to 'const char*'`

```cpp
std::string s = "hello";
std::printf("%s", s);          // ❌
std::printf("%s", s.c_str());  // ✅
```

### `invalid use of incomplete type` / `'X' does not name a type`

**原因**：忘了 `#include`，或者只有前向声明却要使用完整类型。

### `passing 'const X' as 'this' argument discards qualifiers`

```cpp
class Foo {
    int getValue() { return v_; }        // ❌ 少 const
};

void f(const Foo& foo) {
    foo.getValue();                       // 编译错误
}
```

**修复**：`int getValue() const { return v_; }`

### `redefinition of 'X'`

**原因**：重复定义（在同一个作用域里定义两次同名变量/函数）。

### `'X' cannot be used as a function`

**原因**：把变量当函数调用，或者变量名和函数名冲突。

### `control reaches end of non-void function`

```cpp
int f(int x) {
    if (x > 0) return 1;
    // ❌ x <= 0 时没有返回值
}
```

**修复**：确保所有路径都有 `return`。

## A.2 链接错误

### `undefined reference to 'X'`

**排查清单：**

1. 实现了吗？（声明了但没写函数体）
2. 加进编译命令了吗？
   ```bash
   g++ main.cpp utils.cpp -o app    # ← utils.cpp 不能忘
   ```
3. 是模板吗？（模板定义必须在头文件，见 26.7）
4. 忘了链接库？
   ```bash
   g++ main.cpp -lm -o app          # 数学库
   g++ main.cpp -pthread -o app     # 线程库
   ```
5. 函数签名不一致？（`const`、参数类型、命名空间）

### `multiple definition of 'X'`

**原因**：头文件里定义了非 `inline` 的函数或全局变量。

```cpp
// ❌ bad.h
int helper() { return 42; }        // 被多个 .cpp 包含 → 重复定义

// ✅ 方案 1
inline int helper() { return 42; }

// ✅ 方案 2：声明放 .h，定义放 .cpp
// bad.h
int helper();
// bad.cpp
int helper() { return 42; }
```

## A.3 运行时错误

### `Segmentation fault` / 程序崩溃

**常见原因：**

| 原因 | 例子 |
|---|---|
| 空指针解引用 | `int* p = nullptr; *p = 1;` |
| 数组越界 | `int a[3]; a[10] = 1;` |
| 使用已释放内存 | `delete p; *p = 1;` |
| 重复释放 | `delete p; delete p;` |
| 栈溢出（无限递归） | `void f() { f(); }` |
| 访问已销毁的局部对象 | 返回局部变量地址 |

**排查：用 `-fsanitize=address` 重编**

```bash
g++ -std=c++17 -g -fsanitize=address,undefined main.cpp -o app
./app
```

**或者用 gdb：**

```bash
gdb ./app
(gdb) run
# 崩溃后
(gdb) bt          # 看调用栈
```

### `std::bad_alloc`

内存不足。检查是否有无限增长的容器、泄漏、或申请了过大的数组。

### `terminate called after throwing an instance of 'X'`

**原因**：异常被抛出但没有被 `catch`。

**修复**：加 `try-catch`，或在 `main` 里加一个总兜底：

```cpp
int main() {
    try {
        // 全部逻辑
    } catch (const std::exception& e) {
        std::cerr << "错误: " << e.what() << "\n";
        return 1;
    } catch (...) {
        std::cerr << "未知错误\n";
        return 1;
    }
    return 0;
}
```

### 程序输出乱的 / 不输出

**原因**：缓冲区没刷新，或者用了 `std::endl` 之外的方式。

```cpp
std::cout << "hello";      // 可能还在缓冲区
std::cout << "hello\n";    // 也可能还在缓冲区（终端通常行缓冲，会刷新）

// 强制刷新
std::cout << "hello" << std::flush;
std::cout.flush();
```

**调试时用 `std::cerr`**（无缓冲，立即输出）。

### 程序"能跑但结果不对"

**排查方法：**

1. **打印中间值**（最有效）
2. **用 `assert` 检查假设**
3. **把代码简化到最小复现**
4. **检查整数除法**（`5 / 2 == 2`）
5. **检查未初始化变量**
6. **检查边界条件**（`<` 还是 `<=`）
7. **用 `-Wall -Wextra` 重编**（很多 bug 编译器会警告）

## A.4 未定义行为（UB）—— 最危险的一类

**未定义行为 = 标准没有规定会发生什么。程序可能：正常、输出垃圾、崩溃、或者看起来正常但在别处出问题。**

**常见 UB：**

```cpp
// 1. 有符号整数溢出
int x = INT_MAX;
x++;                          // UB

// 2. 数组越界
int a[5];
a[10] = 1;                    // UB

// 3. 空指针解引用
int* p = nullptr;
*p = 1;                       // UB

// 4. 使用未初始化变量
int y;
std::cout << y;               // UB

// 5. 同一个表达式里多次修改同一变量
int i = 0;
i = i++ + ++i;                // UB

// 6. 除零（整数）
int z = 1 / 0;                // UB

// 7. 访问已释放内存
int* q = new int(1);
delete q;
std::cout << *q;              // UB

// 8. 返回局部变量的引用/指针
int& f() { int x = 1; return x; }   // UB

// 9. 移位超过位宽
int s = 1 << 40;              // UB（int 只有 32 位）

// 10. 违反严格别名规则
float f2 = 3.14f;
int* ip = reinterpret_cast<int*>(&f2);
*ip = 0;                      // UB
```

**⭐ 为什么 UB 特别可怕？因为编译器会"假设你不会 UB"，从而做各种优化。** 一段看起来正常的 UB 代码，在 `-O0` 能跑，在 `-O2` 就崩了。

**防范：**

1. 用 `-fsanitize=address,undefined` 编译
2. 用 `-Wall -Wextra` 打开警告
3. 用标准库容器代替裸数组
4. 用智能指针代替裸 `new/delete`
5. 初始化所有变量

## A.5 编译选项诊断表

| 症状 | 试这个 |
|---|---|
| 不知道哪里 UB | `-fsanitize=address,undefined` |
| 智能提示说错但能编译 | 关掉 VS Code 的 error squiggles |
| 模板报错看不懂 | 升级到 C++20 用 concepts；或从第一条错误读起 |
| `-Wall` 一堆警告 | 逐条看，**警告常常就是 bug** |
| Release 崩溃 Debug 正常 | 几乎肯定是 UB，用 sanitizer 查 |

---

# 附录 B · 常用标准库速查表

## B.1 头文件一览

| 头文件 | 提供 |
|---|---|
| `<iostream>` | `cin` `cout` `cerr` `clog` |
| `<iomanip>` | `setw` `setprecision` `fixed` `hex` |
| `<fstream>` | `ifstream` `ofstream` `fstream` |
| `<sstream>` | `istringstream` `ostringstream` `stringstream` |
| `<string>` | `std::string` |
| `<vector>` | `std::vector` |
| `<array>` | `std::array` |
| `<deque>` | `std::deque` |
| `<list>` | `std::list` |
| `<forward_list>` | `std::forward_list` |
| `<map>` | `std::map` `std::multimap` |
| `<set>` | `std::set` `std::multiset` |
| `<unordered_map>` | `std::unordered_map` |
| `<unordered_set>` | `std::unordered_set` |
| `<stack>` | `std::stack` |
| `<queue>` | `std::queue` `std::priority_queue` |
| `<algorithm>` | `sort` `find` `count` `transform` 等 |
| `<numeric>` | `accumulate` `iota` `gcd` `lcm` |
| `<memory>` | `unique_ptr` `shared_ptr` `weak_ptr` `make_unique` |
| `<utility>` | `pair` `move` `forward` `swap` |
| `<tuple>` | `tuple` `make_tuple` `tie` |
| `<optional>` | `std::optional` (C++17) |
| `<variant>` | `std::variant` (C++17) |
| `<any>` | `std::any` (C++17) |
| `<functional>` | `std::function` `std::greater` |
| `<stdexcept>` | 标准异常类 |
| `<cmath>` | `sqrt` `pow` `abs` `sin` `floor` |
| `<cstdlib>` | `rand` `srand` `atoi` `exit` |
| `<ctime>` | `time` `localtime` |
| `<chrono>` | 时间测量 |
| `<random>` | 现代随机数 |
| `<cstring>` | `strlen` `strcpy` `strcmp` |
| `<cctype>` | `isalpha` `isdigit` `toupper` `tolower` |
| `<cstdint>` | `int32_t` `uint64_t` 等固定宽度整数 |
| `<limits>` | `numeric_limits<T>::max()` 等 |
| `<thread>` | 线程 |
| `<mutex>` | 互斥锁 |
| `<atomic>` | 原子操作 |
| `<filesystem>` | 文件系统操作 (C++17) |

## B.2 `std::string` 常用成员

```cpp
s.size() / s.length()      // 长度
s.empty()                  // 是否为空
s.clear()                  // 清空
s[i] / s.at(i)             // 访问
s.front() / s.back()       // 首/尾
s += str / s.append(str)   // 追加
s.push_back(c)             // 追加字符
s.insert(pos, str)         // 插入
s.erase(pos, len)          // 删除
s.replace(pos, len, str)   // 替换
s.substr(pos, len)         // 子串
s.find(str)                // 查找（返回 npos 表示没找到）
s.rfind(str)               // 从右查找
s.find_first_of(chars)     // 找第一个属于 charset 的字符
s.compare(str)             // 比较
s.c_str()                  // 转 const char*
s.data()                   // 原始指针
s.begin() / s.end()        // 迭代器
s.rbegin() / s.rend()      // 反向迭代器
```

## B.3 `std::vector` 常用成员

```cpp
v.size() / v.empty()       // 大小/空
v.capacity()               // 容量
v.reserve(n)               // 预分配容量
v.resize(n)                // 改大小
v.shrink_to_fit()          // 释放多余容量 (C++11)
v[i] / v.at(i)             // 访问
v.front() / v.back()       // 首/尾
v.data()                   // 原始指针
v.push_back(x)             // 尾部添加
v.emplace_back(args...)    // 尾部原地构造
v.pop_back()               // 删尾部
v.insert(it, x)            // 插入
v.emplace(it, args...)     // 原地插入
v.erase(it)                // 删除
v.clear()                  // 清空
v.swap(other)              // 交换
v.begin() / v.end()        // 迭代器
v.rbegin() / v.rend()      // 反向迭代器
```

## B.4 `<algorithm>` 常用算法

```cpp
// 查找
std::find(b, e, val)                  // 找值
std::find_if(b, e, pred)              // 找满足条件的
std::find_first_of(b, e, b2, e2)      // 找任一匹配
std::adjacent_find(b, e)              // 找相邻重复
std::search(b, e, b2, e2)             // 找子序列
std::count(b, e, val)                 // 计数
std::count_if(b, e, pred)             // 条件计数
std::all_of / any_of / none_of        // 全/任一/无
std::binary_search(b, e, val)         // 二分查找（需有序）
std::lower_bound / upper_bound        // 下界/上界
std::equal_range(b, e, val)           // 上下界

// 排序
std::sort(b, e)                       // 排序
std::sort(b, e, comp)                 // 自定义比较
std::stable_sort(b, e)                // 稳定排序
std::partial_sort(b, mid, e)          // 只排前 k 个
std::nth_element(b, nth, e)           // 第 n 小
std::is_sorted(b, e)                  // 是否已排序
std::reverse(b, e)                    // 反转
std::rotate(b, mid, e)                // 旋转
std::shuffle(b, e, gen)               // 随机打乱

// 修改
std::copy(b, e, dest)                 // 复制
std::copy_if(b, e, dest, pred)        // 条件复制
std::copy_n(b, n, dest)               // 复制 n 个
std::move(b, e, dest)                 // 移动
std::fill(b, e, val)                  // 填充
std::fill_n(b, n, val)                // 填充 n 个
std::transform(b, e, dest, f)         // 变换
std::transform(b1, e1, b2, dest, f)   // 双序列变换
std::replace(b, e, old, new)          // 替换
std::replace_if(b, e, pred, new)      // 条件替换
std::remove(b, e, val)                // 移除（配合 erase）
std::remove_if(b, e, pred)            // 条件移除
std::unique(b, e)                     // 去重（相邻）
std::swap_ranges(b1, e1, b2)          // 交换范围

// 最值
std::min(a, b) / std::max(a, b)       // 两值比较
std::min_element(b, e)                // 最小元素
std::max_element(b, e)                // 最大元素
std::minmax_element(b, e)             // 同时拿两个
std::clamp(v, lo, hi)                 // 限制范围 (C++17)

// 集合（需有序）
std::set_union / set_intersection
std::set_difference / set_symmetric_difference
std::includes / merge

// 堆
std::make_heap / push_heap / pop_heap
std::sort_heap / is_heap
```

## B.5 格式化输出

```cpp
#include <iomanip>

std::setw(n)               // 字段宽度（只影响下一次输出）
std::setfill(c)            // 填充字符
std::left / std::right / std::internal
std::setprecision(n)       // 精度
std::fixed                 // 定点（小数位）
std::scientific            // 科学计数法
std::defaultfloat          // 默认
std::hex / std::dec / std::oct        // 进制
std::showbase / std::noshowbase       // 显示 0x 前缀
std::uppercase / std::nouppercase     // 大写十六进制
std::boolalpha / std::noboolalpha     // true/false vs 1/0
std::showpoint / std::noshowpoint     // 强制小数点
```

## B.6 字符串与数字转换

```cpp
// 数字 → 字符串
std::to_string(42)                    // int
std::to_string(3.14)                  // double
std::to_string(true)                  // "1"
// 自定义格式用 ostringstream

// 字符串 → 数字（会抛异常）
std::stoi("42")                       // int
std::stol("42")                       // long
std::stoll("42")                      // long long
std::stoul / std::stoull              // unsigned
std::stof / std::stod / std::stold    // float/double/long double

// 带位置参数
std::size_t pos;
int n = std::stoi("42abc", &pos);     // n=42, pos=2

// 带进制
int hex = std::stoi("FF", nullptr, 16);   // 255
```

---

# 附录 C · 术语中英对照表

| 中文 | 英文 | 说明 |
|---|---|---|
| 变量 | variable | 存数据的具名内存 |
| 常量 | constant | 不可改的值 |
| 函数 | function | 可复用的代码块 |
| 参数 | parameter / argument | 形参 / 实参 |
| 返回值 | return value | 函数交出的结果 |
| 声明 | declaration | 告诉编译器"有这个东西" |
| 定义 | definition | 真正创建它 |
| 初始化 | initialization | 定义时给初值 |
| 赋值 | assignment | 之后改变值 |
| 作用域 | scope | 名字可见的范围 |
| 生命周期 | lifetime | 对象存在的时期 |
| 表达式 | expression | 有值的代码片段 |
| 语句 | statement | 以分号结尾的指令 |
| 运算符 | operator | `+ - * /` 等 |
| 操作数 | operand | 运算符作用的对象 |
| 类型 | type | 数据的种类 |
| 类型转换 | conversion / cast | 从一种类型到另一种 |
| 隐式转换 | implicit conversion | 编译器自动做的 |
| 显式转换 | explicit cast | 你主动写的 |
| 窄化 | narrowing | 会丢数据的转换 |
| 溢出 | overflow | 超出类型范围 |
| 未定义行为 | undefined behavior (UB) | 标准没规定的行为 |
| 数组 | array | 同类型元素的连续集合 |
| 下标 | index / subscript | 元素位置（从 0 开始） |
| 越界 | out of bounds | 访问范围之外 |
| 指针 | pointer | 存地址的变量 |
| 引用 | reference | 变量的别名 |
| 解引用 | dereference | `*p` |
| 取地址 | address-of | `&x` |
| 空指针 | null pointer | `nullptr` |
| 悬空指针 | dangling pointer | 指向已释放内存 |
| 野指针 | wild pointer | 未初始化的指针 |
| 结构体 | struct | 数据聚合 |
| 类 | class | 数据+行为的封装 |
| 对象 | object | 类的实例 |
| 实例 | instance | 具体的对象 |
| 成员 | member | 类里的变量或函数 |
| 方法 | method | 成员函数 |
| 构造函数 | constructor | 创建对象时调用 |
| 析构函数 | destructor | 销毁对象时调用 |
| 拷贝构造 | copy constructor | 用同类对象创建 |
| 移动构造 | move constructor | 转移资源 |
| 封装 | encapsulation | 隐藏实现细节 |
| 继承 | inheritance | 派生类获得基类成员 |
| 基类 / 父类 | base class / superclass | 被继承的类 |
| 派生类 / 子类 | derived class / subclass | 继承的类 |
| 多态 | polymorphism | 同一接口不同实现 |
| 虚函数 | virtual function | 可被重写的函数 |
| 纯虚函数 | pure virtual function | `= 0`，必须重写 |
| 抽象类 | abstract class | 有纯虚函数的类 |
| 接口 | interface | 只有纯虚函数的类 |
| 重写 | override | 派生类重新实现 |
| 重载 | overload | 同名不同参数 |
| 运算符重载 | operator overloading | 让自定义类型支持运算符 |
| 模板 | template | 类型参数化的代码 |
| 泛型编程 | generic programming | 写类型无关的代码 |
| 实例化 | instantiation | 用具体类型生成代码 |
| 容器 | container | 存数据的结构 |
| 迭代器 | iterator | 遍历容器的通用指针 |
| 算法 | algorithm | 对区间做操作的函数 |
| Lambda | lambda expression | 匿名函数 |
| 闭包 | closure | 带捕获的 lambda |
| 捕获 | capture | lambda 获取外部变量 |
| 谓词 | predicate | 返回 bool 的函数 |
| 智能指针 | smart pointer | 自动管理内存的指针 |
| 所有权 | ownership | 谁负责释放资源 |
| 左值 | lvalue | 有名字有地址的表达式 |
| 右值 | rvalue | 临时的、将销毁的 |
| 右值引用 | rvalue reference | `T&&` |
| 移动语义 | move semantics | 转移而非复制资源 |
| 完美转发 | perfect forwarding | 保持参数的值类别 |
| 异常 | exception | 错误传播机制 |
| 抛出 | throw | 引发异常 |
| 捕获 | catch | 处理异常 |
| 栈展开 | stack unwinding | 异常时逐层析构 |
| 异常安全 | exception safety | 异常时的状态保证 |
| 资源泄漏 | resource leak | 资源没被释放 |
| 内存泄漏 | memory leak | 堆内存没释放 |
| 双重释放 | double free | 释放同一内存两次 |
| 命名空间 | namespace | 名字的隔离域 |
| 头文件 | header file | `.h`，放声明 |
| 源文件 | source file | `.cpp`，放实现 |
| 编译 | compile | 源码 → 目标文件 |
| 链接 | link | 目标文件 → 可执行 |
| 目标文件 | object file | `.o` / `.obj` |
| 前置声明 | forward declaration | 只说类型存在 |
| 包含保护 | include guard | 防止重复包含 |
| 单一定义规则 | ODR | 一个实体只能定义一次 |
| 断言 | assertion | `assert`，调试期检查 |
| 调试器 | debugger | `gdb` 等 |
| 断点 | breakpoint | 程序暂停的位置 |
| 调用栈 | call stack | 函数调用链 |
| 优化 | optimization | 让代码更快 |
| 内联 | inline | 把函数展开到调用处 |
| 缓冲区 | buffer | 临时存数据的区域 |
| 流 | stream | 数据流动的抽象 |
| 序列化 | serialization | 把对象转成字节 |
| 反序列化 | deserialization | 从字节恢复对象 |

---

# 附录 D · 学习路线与练习建议

## D.1 推荐的 8 周学习计划

### 第 1 周：基础语法

- **读**：第 0-5 章
- **目标**：能写简单的输入输出程序
- **练习**：10 道基础题（温度转换、面积计算、简单判断）
- **自测**：不看教程，手写一个"输入两个数输出和差积商"的程序

### 第 2 周：控制流与函数

- **读**：第 6-9 章
- **目标**：掌握分支、循环、函数
- **练习**：
  - 打印各种图形（菱形、金字塔）
  - 判断素数、求最大公约数
  - 写 5 个以上的小函数并用它们组合成大程序
- **自测**：实现一个"猜数字游戏"和一个"打印九九乘法表"

### 第 3 周：数组、字符串、vector

- **读**：第 10-12 章
- **目标**：能处理一组数据
- **练习**：
  - 排序（冒泡、选择、插入）
  - 统计词频
  - 矩阵转置
- **自测**：写一个"学生成绩管理"程序（添加、查询、排序、统计）

### 第 4 周：指针与引用（最难的一周）

- **读**：第 13 章
- **目标**：理解内存模型
- **练习**：
  - 手写 `swap`（指针版和引用版）
  - 用指针遍历数组、字符串
  - 实现链表（**必做**，反复做三遍）
- **自测**：能画出指针的内存图，解释 `*p`、`&x`、`p+1` 的含义

### 第 5 周：结构体与类

- **读**：第 14-16 章
- **目标**：会设计简单的类
- **练习**：
  - `Point`、`Rectangle`、`Circle`
  - `Fraction`（分数类，带运算符重载）
  - `BankAccount`（银行账户）
- **自测**：写一个 `MyString` 类，实现拷贝构造和析构

### 第 6 周：继承与多态

- **读**：第 17 章
- **目标**：理解 OOP 三支柱
- **练习**：
  - 形状系统（`Shape` + 各种形状）
  - 员工工资系统
  - 动物叫声系统
- **自测**：解释"为什么基类析构函数要 virtual"

### 第 7 周：STL

- **读**：第 18-21 章
- **目标**：熟练使用容器和算法
- **练习**：
  - 用 `map` 做词频统计
  - 用 `set` 去重
  - 用 `stack` 做括号匹配
  - 用 lambda + `sort` 做多条件排序
- **自测**：把之前的练习用 STL 重写一遍，对比代码量

### 第 8 周：现代 C++ 与项目

- **读**：第 22-28 章
- **目标**：能写安全的现代 C++ 代码
- **练习**：
  - 用 `unique_ptr` 重写链表
  - 给项目拆分多文件、写 Makefile
  - 用 `-fsanitize=address` 检查之前的代码
- **自测**：完整实现第 29 章的待办清单，并加上 2-3 个扩展功能

## D.2 各阶段的"自测标准"

**入门（第 1-3 周后）：**

- [ ] 能不看资料写出 Hello World
- [ ] 能解释 `#include`、`main`、`;` 的作用
- [ ] 会用 `if`、`for`、`while`、函数
- [ ] 能处理 `vector` 的增删改查

**进阶（第 4-6 周后）：**

- [ ] 能画图解释指针和引用
- [ ] 能写出正确的链表
- [ ] 能设计一个带封装的类
- [ ] 理解虚函数和多态
- [ ] 知道为什么要用 `const&` 传参

**熟练（第 7-8 周后）：**

- [ ] 能用 STL 解决问题，而不是手写循环
- [ ] 会用智能指针，不写裸 `new/delete`
- [ ] 能拆分多文件项目
- [ ] 会用 `-fsanitize` 和 `gdb` 调试
- [ ] 能读懂编译错误和链接错误

## D.3 常见学习障碍与对策

### 障碍 1："指针完全看不懂"

**对策：**

1. **画图**。每写一段指针代码就画出内存图（方框 + 箭头）
2. **用打印验证**：
   ```cpp
   int a = 42;
   int* p = &a;
   std::cout << "a 的值: " << a << "\n";
   std::cout << "a 的地址: " << &a << "\n";
   std::cout << "p 的值(地址): " << p << "\n";
   std::cout << "p 自己的地址: " << &p << "\n";
   std::cout << "p 指向的值: " << *p << "\n";
   ```
3. **手写链表三遍**。第一遍照着抄，第二遍合上书写，第三遍给别人讲一遍
4. **接受"第一遍看不懂是正常的"**

### 障碍 2："报错一长串，完全看不懂"

**对策：**

1. **只读第一条 `error:`**，后面的常常是连锁反应
2. **看行号**，去那一行和**上一行**找问题
3. **看 `note:`**，它经常直接给答案
4. 把**报错信息完整复制到搜索引擎**（去掉路径和具体变量名）
5. 记住高频错误（见[附录 A](#附录-a--常见错误与报错解读)）

### 障碍 3："看懂了但自己写不出来"

**对策：**

1. **这是正常现象**，说明你在"读代码"而不是"写代码"
2. **合上教程，从空白文件开始写**
3. **先写注释**（列出步骤），再把注释翻译成代码
4. **写完再对比教程**，找出差异
5. **每天至少写 30 分钟代码**（读 1 小时不如写 30 分钟）

### 障碍 4："学到类就晕了"

**对策：**

1. **从需求出发**，而不是从语法出发。问自己："我要描述什么？它有什么数据？它能做什么？"
2. **先写结构体，再慢慢加函数，最后加封装**
3. **从最简单的类开始**（`Point`、`Counter`）
4. **画类图**（方框里写上成员变量和成员函数）

### 障碍 5："学了 STL 就不想手写数据结构了"

**对策：** 这是**好事**！生产代码就该用 STL。但为了理解原理，至少手写一遍：动态数组、链表、栈、二叉搜索树、哈希表。

## D.4 练习题资源

| 资源 | 特点 |
|---|---|
| [LeetCode](https://leetcode.cn/) | 算法题，中文，有题解 |
| [洛谷](https://www.luogu.com.cn/) | 中文，从入门到竞赛 |
| [Codeforces](https://codeforces.com/) | 英文，竞赛题 |
| [HackerRank C++](https://www.hackerrank.com/domains/cpp) | C++ 专项练习 |
| [Exercism C++ Track](https://exercism.org/tracks/cpp) | 有导师点评 |
| [牛客网](https://www.nowcoder.com/) | 中文，有 C++ 专项 |

## D.5 推荐书籍（按顺序）

| 阶段 | 书名 | 说明 |
|---|---|---|
| 入门 | 《C++ Primer（第 5 版）》 | **最权威的入门书**，厚但值得 |
| 入门 | 《C++ 程序设计教程》 | 国内教材，讲得慢 |
| 进阶 | 《Effective C++》 | 55 个条款，教你"怎么写得对" |
| 进阶 | 《Effective Modern C++》 | C++11/14 的最佳实践 |
| 进阶 | 《C++ 沉思录》 | 深入理解设计 |
| 深入 | 《深度探索 C++ 对象模型》 | 虚函数、内存布局的底层 |
| 深入 | 《C++ Templates》 | 模板元编程 |
| 参考 | [cppreference.com](https://zh.cppreference.com/) | **在线标准库文档，必备** |

## D.6 一些忠告

1. **别追求"读完全部再动手"。** 边学边写，第 3 章学完就写第 3 章的代码。

2. **别怕犯低级错误。** 漏分号、变量名拼错、忘记 `#include`，这是所有人的日常。

3. **别跳过指针和内存。** 它们是 C++ 的根基。跳过的话，后面学的都是空中楼阁。

4. **别把 C++ 当 Python 写。** 比如：不要到处 `new`，用 `vector`；不要传大对象值，用 `const&`。

5. **别只写"玩具代码"。** 每学完几章，就做一个小项目（哪怕只有 200 行）。

6. **别一个人死磕。** 卡住超过 1 小时就：查文档 → 搜索 → 简化到最小复现 → 问人。

7. **代码是写给人看的。** 变量命名、注释、格式，比你想的重要得多。

8. **用好工具。** `-Wall -Wextra -fsanitize=address,undefined` 能帮你抓到 80% 的 bug。

9. **学 C++ 很慢是正常的。** 它是一门庞大且复杂的语言。别人用 3 个月，你用 6 个月也完全没问题。

10. **坚持比聪明重要。** 每天 1 小时，坚持 3 个月，你会超过 90% 半途而废的人。

---

## 结语

到这里，你已经走完了一遍 C++ 的主干。

**回头看看你学了多少东西：**

从"什么是编译器"开始，到变量、控制流、函数、数组、指针、类、继承、多态、模板、STL、智能指针、移动语义、异常、文件、多文件工程、调试工具……最后完成了两个真实项目。

**接下来该做什么？**

1. **不要把这份教程丢到一边。** 它是你的参考手册，遇到问题回来查。

2. **选一个方向深入：**
   - **游戏开发**：学 SDL2 / SFML / Unreal Engine
   - **系统编程**：学 Linux 系统调用、多线程、网络编程
   - **算法竞赛**：刷 LeetCode / Codeforces
   - **工具开发**：学 Qt / ImGui 做 GUI
   - **高性能计算**：学 SIMD、CUDA、并行算法
   - **底层/嵌入式**：学 ARM、RTOS、驱动

3. **读别人的代码。** 找一个开源 C++ 项目（比如 [fmt](https://github.com/fmtlib/fmt)、[spdlog](https://github.com/gabime/spdlog)、[nlohmann/json](https://github.com/nlohmann/json)），从简单的看起。

4. **写一个"自己的项目"。** 一个你想做的东西 —— 不管是游戏、工具还是玩具。**只有做自己想做的东西，你才会真的学下去。**

祝你好运。C++ 很难，但学会它之后，你会发现几乎所有其他语言都变得简单了。

---

*教程结束。共 30 章 + 4 个附录。*
