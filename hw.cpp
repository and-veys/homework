#include <iostream>
template <class T>
class Pair1
{
private:
	T m_first;
	T m_second;
public:
	Pair1(T f, T s):m_first(f), m_second(s){};
	T first() const {return m_first;}
	T second() const {return m_second;}
};
template <class T1, class T2>
class Pair
{
private:
	T1 m_first;
	T2 m_second;
public:
	Pair(T1 f, T2 s):m_first(f), m_second(s){};
	T1 first() const {return m_first;}
	T2 second() const {return m_second;}
};
template <class T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(std::string f, T s):Pair<std::string, T>(f, s){}	
};
int main()
{
	std::cout << "_____Exercise #1_____" << std::endl;
	{		
		Pair1<int> p1(6, 9);
		std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
		const Pair1<double> p2(3.4, 7.8);
		std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}	
	std::cout << "_____Exercise #2_____" << std::endl;
	{
		Pair<int, double> p1(6, 7.8);
		std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
		const Pair<double, int> p2(3.4, 5);
		std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	}
	std::cout << "_____Exercise #3_____" << std::endl;
	{
		StringValuePair<int> svp("Amazing", 7);
		std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	}
    return 0;
}

