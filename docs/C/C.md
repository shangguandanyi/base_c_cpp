**宏定义说明**

1. 宏名一般大写，以便于与变量区别
2. 宏定义可以是常数，表达式等
3. 宏定义不作语法检查，只有在编译被宏展开后的源程序才会报错
4. 宏定义不是C语言，不在行末加分号
5. 宏名有效范围从定义到本源文件结束
6. 可以用#undef命令终止宏定义的作用域
7. 在宏定义中，可以引用已定义的宏名
8. 不重视作用域，即使在函数中定义，也可以全文件使用
9. 宏定义的常量，没有数据类型



**宏函数**

经常把一些短小而又频繁使用的函数写成宏函数，这是由于宏函数没有普通函数参数压栈、跳转、返回等的开销，可以调高程序运行的效率。

宏通过使用参数，可以创建外形和作用都与函数类似地类函数宏，宏的参数也用圆括号括起来。

```
#define SUM(x,y)((x) + (y))
void test()
{
	int ret = SUM(10 + 20)
}
```

**条件编译**

满足一定条件时才编译，即对这部分源程序行指定编译条件

```
# 测试存在

# ifdef 标识符
	程序段1
# else
	程序段2
#endif


#测试不存在

# ifndef 标识符
	程序段1
# else
	程序段2
#endif


# 根据表达式定义

# if 表达式
	程序段1
# else
	程序段2
#endif
```

**特殊的预定义宏**

```
__FILE__ 宏所在文件的源文件名
__LINE__ 宏所在行的行号
__DATE__ 代码编译的日期
__TIME__ 代码编译的时间
```

**结构体中属性的偏移**

```
#include <stddef.h>

struct Person
{
	char a;
	int b;
	char buf[64];
	int d;
};

struct Person p = {'a', 10, "hello world", 1000};
// 计算结构体中属性的偏移
offsetof(struct Person, d);
// 打印d的值
*(int*)((char*)&p1 + offsetof(struct Person, d)));
```

**格式化字符串**

sprintf

```
#include <stdio.h>

int sprintf(char *str, const char *format, ...);
根据参数format字符串来转换并格式化数据，然后将结果输出到str指定的空间中，直到出现字符串结束符‘\0’为止
str: 字符串首地址
format: 字符串格式
返回的是字符串的长度


char buf[1024] = { 0 };
sprintf(buf, "今天是%d年%d月", 2021, 8)

memset(buf, 0 ,1024);
char str1[] = "hello";
char str2[] = "world";
sprintf(buf, "%s%s", str1, str2);

memset(buf, 0 ,1024);
int num = 100;
sprintf(buf, "%d", num);


```

