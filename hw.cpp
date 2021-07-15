#include <iostream>
#include <cerrno>
#include <cmath>
class Power
{
private:
	double basis{};
	double exponent{};
public:
	Power(){}
	Power(double b, double e) : basis(b), exponent(e){}
	void set(double b, double e);
	void calculate();
	
};
void Power::calculate()
{
	errno=0;
	double res = pow(basis, exponent);
	if(errno==0)
		std::cout << basis << "^" << exponent << " = " << res << std::endl;
	else
		std::cout << basis << "^" << exponent << " = " << "ERROR_OF_POW" << std::endl;
}
void Power::set(double b, double e)
{
	basis = b;
	exponent = e;
}
class RGBA
{
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
public:
	RGBA():m_red(0), m_green(0), m_blue(0), m_alpha(255){}
	RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a):m_red(r), m_green(g), m_blue(b), m_alpha(a){}
	void print();
};
void RGBA::print()
{
	printf("RED=%d GREEN=%d BLUE=%d ALPHA=%d\n", m_red, m_green, m_blue, m_alpha);
}
class Stack
{
private:
	int array[10];
	unsigned char size;
public:
	void reset();
	bool push(int a);
	int pop();
	void print();	
};
void Stack::reset()
{
	for(int i=0; i<sizeof(array); i++)
		array[i]=0;
	size = 0;
}
bool Stack::push(int a)
{
	if(size == sizeof(array)) return false;
	array[size++] = a;
	return true;
}
int Stack::pop()
{
	if(size == 0) 
	{
		std::cout << "ARRAY_IS_EMPTY\n";	
		return 0;	//naprimer
	}
	return array[--size];	
}
void Stack::print()
{
	std::cout << "( ";
	for(int i=0; i<size; i++)
		std::cout << array[i] << " ";
	std::cout << ")" << std::endl;
}
int main()
{
	std::cout << "____Exercise #1____\n";	
	Power pw_1;
	pw_1.calculate();
	Power pw_2(-4.4, -5.3);
	pw_2.calculate();
	pw_2.set(4, 3);
	pw_2.calculate();
	
	std::cout << "____Exercise #2____\n";
	RGBA color_1;
	color_1.print();
	RGBA color_2(26, 55, 14, 186);
	color_2.print();
	
	std::cout << "____Exercise #3____\n";
	Stack stack;
    stack.reset();
    stack.print();    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();    
    stack.pop();
    stack.print();    
    stack.pop();
	stack.pop();
    stack.print();
	return 0;
}