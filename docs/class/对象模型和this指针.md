**成员变量和成员函数分开存储**

类内的成员变量和成员函数分开存储，只有非静态成员变量才属于类的对象上

```
class Person
{
	// 空对象占用一个字节的内存空间，是为了区分空对象占内存的位置
}；

class Person
{
	int m_A;// 非静态成员变量属于类的对象 此时这个对象占用4个字节空间
};

class Person
{
	int m_A;
	static int m_B;// 静态成员变量不属于类的对象，此时这个对象占用4个字节空间
};
int Person::m_B = 0;

class Person
{
	int m_A;
	
	void func(){}// 成员函数不属于类的对象，此时这个对象占用4个字节空间
};
```

**this**指针

每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码

C++提供this指针，可以区分不同对象的调用

**this指针指向被调用的成员函数所属的对象**

this指针是隐含每一个非静态成员函数内的一种指针

不需要定义，直接使用

**用途**

- 当形参和成员变量同名时，可用this指针区分
- 在类的非静态成员函数中返回对象本身，可使用return *this

```
class Person{
public:
	Person(int age)
	{
		this -> age = age;
	}
	
	Person& addAge(Person &p)
	{
		this->age += p.age;
		// this是对象的指针，所以要返回*this
		return *this;
	}
	int age;
};

void test()
{
	Person p(10);
	Person p2(10);
	p2.addAge(p).addAge(p);
}
```

**空指针访问成员函数**

C++中空指针也可以调用成员函数，如果用到this指针，需要加判断

```
class Person
{
public:
	void showClassName(){}
	void showPersonAge()
	{
		if (this == NULL)
		{
			return;
		}
		count << m_Age << endl;
	}
	int m_Age;
};

void test()
{
	Person *p = NULL;
	// 可以调用
	p->showClassName();
	// 不能调用
	p->showPersonAge();
}
```

**const修饰成员函数**

**常函数**

- 成员函数后加const后称为**常函数**
- 常函数内不可以修改成员属性
- 成员属性声明时加关键字mutable后，在常函数中依然可以修改

**常对象**

- 声明对象前加const称该对象为常对象
- 常对象只能调用常函数

```
class Person
{
public:
  // 加const之后修饰的是this指向，让指针指向的值也不可修改，const Person * const this
	void showPerson() const
	{
		// this指针的本质是指针常量，指针的指向是不能修改的（Person * const this）
		// m_A = 1;
		this -> m_B = 1;// 可以修改
	}
	
	int m_A;
	mutable int m_B;// 即使在常函数中，也可以修改这个值
};

void test()
{
	const Person p;//加const之后变成常对象
	p.m_A = 1;// 错误代码，不能修改
	p.m_B = 2;// 正确代码，在常对象下也可以修改
	
	p.showPerson();// 常对象只能调用常函数
}
```

