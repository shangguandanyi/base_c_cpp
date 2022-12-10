#include <iostream>
#include <memory>

using namespace std;

// std::enable_shared_from_this用法
struct Good : std::enable_shared_from_this<Good>
{
	std::shared_ptr<Good> get_ptr()
	{
		return shared_from_this();
	}
};

struct Bad
{
	std::shared_ptr<Bad> get_ptr()
	{
		return std::shared_ptr<Bad>(this);
	}

	~Bad()
	{
		std::cout << "Bad::~Bad() called." << std::endl;
	}
};

void test01()
{
	std::shared_ptr<Good> gp1 = std::make_shared<Good>();
	std::cout << "gp1 use count: " << gp1.use_count() << std::endl;
	std::shared_ptr<Good> gp2 = gp1->get_ptr();
	std::cout << "gp2 use count: " << gp2.use_count() << std::endl;
	std::cout << "gp2 use count: " << gp1.use_count() << std::endl;

	// 错误用法一
	try
	{
		Good not_good;
		std::shared_ptr<Good> gp3 = not_good.get_ptr();
	}
	catch (std::bad_weak_ptr &e)
	{
		std::cout << "e: " << e.what() << std::endl;
	}
}

// 错误用法二 重复释放
void test02()
{
	std::shared_ptr<Bad> bp1 = std::make_shared<Bad>();
	std::cout << "bp1 use count: " << bp1.use_count() << std::endl;
	std::shared_ptr<Bad> bp2 = bp1->get_ptr();
	std::cout << "bp2 use count: " << bp2.use_count() << std::endl;

}

int main(int argc, char const *argv[])
{
	test01();
	test02();
	return 0;
}
