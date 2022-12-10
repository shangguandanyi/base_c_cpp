#include <iostream>
#include <memory>

struct C
{
	int *data;
};

void test01()
{
	auto deleter = [](int *p)
	{std::cout << "[deleter called!]" << std::endl; delete p; };

	std::cout << "use count: " << std::endl;

	std::shared_ptr<int> p1;
	std::cout << "p1: " << p1.use_count() << std::endl;

	std::shared_ptr<int> p2{nullptr};
	std::cout << "p2: " << p2.use_count() << std::endl;

	std::shared_ptr<int> p3(new int);
	std::cout << "p3: " << p3.use_count() << std::endl;

	std::shared_ptr<int> p4(new int, deleter);
	std::cout << "p4: " << p4.use_count() << std::endl;

	std::shared_ptr<int> p5(new int, [](int *p){delete p;}, std::allocator<int>());
	std::cout << "p5: " << p5.use_count() << std::endl;

	std::shared_ptr<int> p6(p5);
	std::cout << "p6: " << p6.use_count() << std::endl;

	std::shared_ptr<int> p7(std::move(p6));
	std::cout << "p7: " << p7.use_count() << std::endl;
	std::cout << "p6: " << p6.use_count() << std::endl;

	std::shared_ptr<int> p8(std::unique_ptr<int>(new int));
	std::cout << "p8: " << p8.use_count() << std::endl;

	std::shared_ptr<struct C> obj(new C);
	std::shared_ptr<int> p9 (obj, obj->data);
	std::cout << "p9: " << p9.use_count() << std::endl;
}

// shared_ptr 赋值
void test02()
{
	std::shared_ptr<int> foo;
	std::cout << "foo: " << foo.use_count() << std::endl;
	std::shared_ptr<int> bar{new int{10}};
	std::cout << "bar: " << *bar << std::endl;
	foo = bar;
	std::cout << "foo: " << *foo << std::endl;
	std::cout << "bar: " << bar.use_count() << std::endl;

	bar = std::make_shared<int>(20);
	std::cout << "bar: " << *bar << std::endl;

	std::unique_ptr<int> unique(new int(30));
	foo = std::move(unique);
	std::cout << "foo: " << *foo << std::endl;
}

void test03()
{
	// swap 交换
	std::shared_ptr<int> foo(new int(30));
	std::shared_ptr<int> bar(new int(20));
	foo.swap(bar);
	std::cout << "foo: " << *foo << std::endl;
	std::cout << "bar: " << *bar << std::endl;
}

void test04()
{
	// reset
	std::shared_ptr<int> foo;
	foo.reset(new int(10));

	std::cout << "foo: " << *foo << std::endl;

	foo.reset();
	std::cout << "foo use count: " << foo.use_count() << std::endl;

	foo.reset(new int);
	std::cout << "foo use count: " << foo.use_count() << std::endl;
}

void test05()
{
	// check unique
	std::shared_ptr<int> foo;
	std::shared_ptr<int> bar(new int);
	std::cout << "unique check: " << std::endl;
	std::cout << "foo: " << foo.unique() << std::endl;
	foo = bar;
	std::cout << "foo: " << foo.unique() << std::endl;
	bar = nullptr;
	std::cout << "foo: " << foo.unique() << std::endl;
}

struct A
{
	static const char* static_type;
	const char* dynamic_type;
	A()
	{
		dynamic_type = static_type;
	}
};
const char* A::static_type = "class A";

struct B: A
{
	static const char* static_type;
	B()
	{
		dynamic_type = static_type;
	}
};
const char* B::static_type = "class B";

void test06()
{
	// static_pointer_cast
	std::shared_ptr<A> foo;
	std::shared_ptr<B> bar;

	foo = std::make_shared<A>();
	std::cout << "foo's static type: " << foo->static_type << ", foo's dynamic type: " << foo->dynamic_type << std::endl;

	// 父类转子类,强制转换,不进行类型检查
	bar = std::static_pointer_cast<B>(foo);
	std::cout << "bar's static type: " << bar->static_type << ", bar's dynamic type: " << bar->dynamic_type << std::endl;

	// 子类转父类,动态转换,进行类型检查
	foo = std::dynamic_pointer_cast<A>(bar);
	std::cout << "foo's static type: " << foo->static_type << ", foo's dynamic type: " << foo->dynamic_type << std::endl;
}

int main(int argc, char const *argv[])
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	return 0;
}
