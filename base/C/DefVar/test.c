#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	double y;
} f_args;

double f_base(int x, double y)
{
	printf("x = %d, y = %.2f\n", x, y);
	return y;
}

double var_f(f_args in)
{
	int x = in.x ? in.x : 4;
	double y = in.y ? in.y : 3.1415;
	return f_base(x, y);
}

#define f(...) var_f((f_args){__VA_ARGS__})

void test01()
{
	f(3, 8);
	f(.x = 1, 2.3);
	f(2);
	f(.y = 4.3556);
}

int main(int argc, char const *argv[])
{
	test01();
	return 0;
}
