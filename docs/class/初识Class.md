```
class Circle
{
// 访问权限
public:
		int m_r;// 半径
		//获取圆的周长
		double calculateZC()
		{
			return 2 * PI * m_r;
		}
};
// 实例化一个对象
Circle c1;
c1.m_r = 10;
c1.calculateZC();
```

```
class Student
{
public:
	string m_Name;
	int m_Id;// 学号
	
	void showStudent()
	{
		cout << m_Name << m_Id << end;
	}
	
	void setName(string name)
	{
		m_Name = name;
	}
	
	void setId(int id)
	{
		m_Id = id;
	}
};

Student s1;
s1.m_Name="aa";
s1.m_Id = 1;
s1.showStudent();
```

```
// 访问权限
public,private,protected
public 		成员 类内可以访问 类外可以访问
protected 成员 类内可以访问 类外不可以访问 子类可以访问父类中的protected内容
private 	成员 类内可以反问 类外不可以访问 子类不能访问父类中的private内容

class Person
{
public:
	string m_Name;

protected:
	string m_Car;

private:
	int m_Password;
	
public:
	void func()
	{
		m_Name = "a";
		m_Car = "b";
		m_Password = 123456;
	}
};

int main()
{
	Persion p1;
	p1.m_Name = "a";
	p1.m_Car = "b"; // 不能访问
	p1.m_Password = 1;// 不能访问
}
```

