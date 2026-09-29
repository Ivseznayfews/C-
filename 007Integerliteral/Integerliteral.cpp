#include <iostream>

int main() {
    int a = 42;              // 十进制
    int b = 0b101010;        // 二进制（C++14）：等于42
    int c = 052;             // 八进制（以0开头）：等于42
    int d = 0x2A;            // 十六进制：等于42

    long long e = 100000000000LL;                    // LL后缀表示long long
    unsigned f = 100u;                               // u后缀表示unsigned
    unsigned long long g = 0xFFFFFFFFFFFFFFFFULL;

    // 数字分割符（C++14），方便读大数：
    int h = 1'000'000;       // 等于1000000
    int i = 0xFF'FF'FF;      // 十六进制也能分组

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n";
    std::cout << "d = " << d << "\n";
    std::cout << "e = " << e << "\n";
    std::cout << "f = " << f << "\n";
    std::cout << "g = " << g << "\n";
    std::cout << "h = " << h << "\n";
    std::cout << "i = " << i << "\n";
}