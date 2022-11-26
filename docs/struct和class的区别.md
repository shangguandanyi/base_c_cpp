**默认的访问权限不同**

**struct** 默认是**public**

**class** 默认是**private**

```
class C1
{
	int m_A;// 默认权限是私有
};

struct C2
{
	int m_A;// 默认权限是公共
};

C1 c1;
c1.m_A = 100;// 错误代码，不能访问

struct C2 c2;
c2.m_A = 100;// 正确代码，可以访问
```