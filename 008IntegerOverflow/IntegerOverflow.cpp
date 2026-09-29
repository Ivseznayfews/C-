#include <iostream>
#include <climits>   // 提供INT_MAX和INT_MIN等宏定义

// 防范方法
bool willOverflow(int a, int b) {
    if (b > 0 && a > INT_MAX - b) return true;   // 正数溢出
    if (b < 0 && a < INT_MIN - b) return true;   // 负数溢出
    return false;
}

int main() {
    std::cout << "int的最大值: " << INT_MAX << "\n";   // 2147483647

    int big = INT_MAX + 1;   // ❌溢出，未定义行为
    std::cout << "big = " << big << "\n";  // 输出结果不可预测，通常输出-2147483648，但无法保证

    // 防范方法
    int a = 2000000000;
    int b = 2000000000;
    if (willOverflow(a, b)) {
        std::cout << "加法会溢出，无法执行！\n";
        long long r = static_cast<long long>(a) + static_cast<long long>(b);  // 使用long long进行计算
        std::cout << "计算结果为: " << r << "\n";
    } 

    return 0;
}