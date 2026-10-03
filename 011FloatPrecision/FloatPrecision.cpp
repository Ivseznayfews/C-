#include <iostream>
#include <iomanip>

int main() {
    double pi = 3.14159265358979323846;

    std::cout << pi << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << pi << std::endl;

    std::cout << std::setprecision(5) << pi << std::endl;

    std::cout << std::scientific << pi << std::endl;

    std::printf("%.3f\n", pi);
    return 0;
}