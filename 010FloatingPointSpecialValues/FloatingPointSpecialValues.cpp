#include <iostream>
#include <limits>
#include <cmath>

int main() {
    double inf = 1.0 / 0.0;    // 无限大
    double nan = 0.0 / 0.0;    // 非数（NaN）
    double neg_inf = -1.0 / 0.0; // 负无限大

    std::cout << "inf = " << inf << std::endl;
    std::cout << "nan = " << nan << std::endl;
    std::cout << "neg_inf = " << neg_inf << std::endl;
    std::cout << "1/0 > 1000 ?" << (inf > 1000 ) << std::endl;   // 1
    std::cout << "0/0 > 1000 ?" << (nan > 1000 ) << std::endl;   // 0 ， NaN不等于自己

    // 正确检查NaN
    if (std::isnan(nan)) {
        std::cout << "nan 确实是 NaN" << std::endl;
    }

    // 检查无穷
    if (std::isinf(inf)) {
        std::cout << "inf 确实是无穷大" << std::endl;
    }

    // 检查负无穷
    if (std::isinf(neg_inf)) {
        std::cout << "neg_inf 确实是负无穷大" << std::endl;
    }

    // 检查是否有限
    if (std::isfinite(inf)) {
        std::cout << "inf 是有限的" << std::endl;
    } else {
        std::cout << "inf 不是有限的" << std::endl;
    }

    return 0;
}