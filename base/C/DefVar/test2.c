#include <stdio.h>
// ##__VA_ARGS__ 宏前面加上##的作用在于，当可变参数的个数为0时，这里的##起到把前面多余的","去掉的作用,否则会编译出错
#define LOG(...) printf("123 + %s = %d\n", __VA_ARGS__)
#define LOG2(...) printf("123 + s = d\n", ##__VA_ARGS__)

int main(int argc, char const *argv[])
{
	LOG("3", 123 + 3);
	LOG2();
	return 0;
}
