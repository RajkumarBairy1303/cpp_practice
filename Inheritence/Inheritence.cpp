// Inheritence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>

/*Example 1 */
//class person
//{
//public:
//	std::string m_name;
//	int m_age;
//
//	person() :m_name{ "" }, m_age{ 0 }
//	{
//	}
//};
//
//class BaseBallPlayer : protected person
//{
//public:
//	int m_score;
//	BaseBallPlayer() :m_score{ 0 }
//	{
//
//	}
//
//	const std::string getName() const  { return m_name; }
//	void setName(std::string strname) { m_name = strname; }
//};
//
//int main()
//{
//	BaseBallPlayer player;
//	player.setName("Jorden");
//	std::cout << player.getName().c_str() << std::endl;
//	return 0;
//}

/* Order of construction of derived classes */

//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	Base()
//	{
//		std::cout << "Base class constructor : " << std::endl;
//	}
//};
//
//class Derived : public Base
//{
//public:
//	Derived()
//	{
//		std::cout << "Derived class constructor : " << std::endl;
//	}
//};
//
//int main()
//{
//	Base base; // It calls the base class constructor only.
//
//	Derived derived; //It calls the base class first and derived class second;
//
//	return 0;
//}

/* Constructors and initialization of derived classes 

    Base class initialization:

	1.Memory for base is set aside
	2.The appropriate Base constructor is called
	3.The member initializer list initializes variables
	4.The body of the constructor executes
	5.Control is returned to the caller

	Derived class Initialization

	1.Memory for derived is set aside (enough for both the Base and Derived portions)
	2.The appropriate Derived constructor is called
	3.The Base object is constructed first using the appropriate Base constructor. If no base constructor is specified, the default constructor will be used.
	4.The member initializer list initializes variables
	5.The body of the constructor executes
	6.Control is returned to the caller


*/

//#include <iostream>
//using namespace std;
//
//class Base
//{
//
//	int m_id;
//public:
//	Base():m_id{0}
//	{
//		std::cout << "Base constructor : " << std::endl;
//	}
//};
//
//class Derived : private Base
//{
//public:
//	double m_cost;
//	Derived():m_cost { m_cost }{}
//};
//
//int main()
//{
//	std::cout << "Base class size : " << sizeof(Base) << std::endl;
//	std::cout << "Derived class size : " << sizeof(Derived) << std::endl;
//	return 0;
//}

/* Example */

//#include <iostream>
//#include <string>
//using namespace std;
//
//class fruit
//{
//	std::string m_strname;
//	std::string m_strcolor;
//
//public:
//	fruit(std::string strname = "", std::string strcolor = "") :m_strname{ strname }, m_strcolor{ strcolor }
//	{
//
//	}
//
//	const std::string getName() const { return m_strname; }
//	const std::string getcolor() const { return m_strcolor; }
//};
//
//class Apple : public fruit
//{
//	double m_dfiber;
//public:
//	Apple()
//	{
//		std::cout << "Apple constructor : " << std::endl;
//	}
//
//	Apple(std::string strname, std::string strcolor, double dfiber) :fruit{ strname, strcolor },m_dfiber { dfiber }{ }
//
//	const std::string print() const
//	{
//		return "Apple("+ getName() + "," + getcolor() + ","+to_string(m_dfiber) + ")";
//	}
//};
//
//class Banana : public fruit
//{
//public:
//	Banana()
//	{
//		std::cout << "banana constructor : " << std::endl;
//	}
//	Banana(std::string strname,std::string strcolor):fruit{strname, strcolor}
//	{
//
//	}
//
//	const std::string print() const
//	{
//		return "Banana("+ getName()+ "," + getcolor() + ")";
//	}
//};
//
//int main()
//{
//	const Apple a{ "Red delicious", "red", 4.2 };
//	std::cout << a.print().c_str() << '\n';
//
//	const Banana b{ "Cavendish", "yellow" };
//	std::cout << b.print().c_str() << '\n';
//
//	return 0;
//}

/* 
**************Calling inherited functions and overriding**************

*/