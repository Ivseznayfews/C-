#include <iostream>
#include <vector>

int main() {
	/* 有符号与无符号
	   有符号（signed）：能表示负数，默认就是有符号
	   无符号（unsigned）：只能表示非负数，但正数范围翻倍 */
	int a = -100;   // 有符号，可以取负数
	unsigned int b = 100;   // 无符号，只能取非负数，不能取负数
	unsigned int c = 4000000000u;   // 无符号，取值范围更大，上限约42亿
	// int d = 4000000000;   // 有符号，取值范围有限，上限约21亿，超出范围会导致溢出

	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n";

	// 无符号数的经典陷阱
	unsigned int x = 0;
	x = x - 1;   // 0 减 1，不是 -1
	std::cout << x << "\n";   // 输出 4294967295（2^32 - 1），溢出后变为最大值
	// 因为无符号数"不能是负数"，减到 0 以下就会回绕到最大值。

	// 另一个经典陷阱
	std::vector<int> v = { 1, 2, 3 };
	/* v.size()返回的是无符号数
	下面这个循环永远不会结束（或者行为诡异），因为 i 永远不会小于 0
	for (int i = 0; i < v.size() - 1; i++) { … }
	正确写法：用有符号的 int 接收，或者用 ptrdiff_t */
	int n = static_cast<int>(v.size());   // 将无符号数转换为有符号数
	for (int i = 0; i < n - 1; i++) {
		std::cout << v[i] << " " << "\n";
	}
	std::cout << "\n";
	return 0;
	/* 为什么？当 v 为空时 v.size() 是 0，v.size() - 1 在无符号算术下变成 4294967295，i < 4294967295 恒真。

      结论：日常写代码优先用有符号 int，只在明确需要位运算/超大正数时用 unsigned。*/
}