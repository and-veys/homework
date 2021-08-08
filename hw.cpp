#include <iostream>
#include <string.h>
#define X_MAX 10
#define Y_MAX 10
bool getInteger(int & nValue)
{
	nValue = 0;
	std::string buffer;
	std::cout << "Enter a number: ";		
	std::getline(std::cin, buffer);	
	if(buffer.size() == 0) return false;
	int nSign = 1;
	int i=0;
	if(buffer.size() != 1 && buffer[0] == '-')
	{
		++i;
		nSign = -1;
	}
	for(i; i<buffer.size(); ++i)
	{
		if(buffer[i] >= '0' && buffer[i] <= '9')
			nValue = nValue*10 + buffer[i] - '0';
		else return false;		
	}
	nValue*=nSign;
	return true;	
}
//-----------------------------------------------------------
template <class T1, class T2> double div(T1 a, T2 b)
{
	double res = a;
	if(b == 0) throw "DivideByZero";
	return res/b;
}
class Ex
{
private:
	double x;
public:
	Ex(double a) : x(a){}
	std::string what(){return std::to_string(x);}
};
class Bar
{
private:
	double y;
public:
	Bar() : y(0){}
	double get(){return y;}
	void set(double a)
	{
		if(y+a > 100) throw Ex(y*a);
		y=a;
	}
};
class Robot
{
private:
	int x;
	int y;
public:
	Robot():x(0), y(0){};
	void move(int dx, int dy);
	
};
class RobotError
{
protected:
	int x;
	int y;
	int dx;
	int dy;
public:
	RobotError(int _x, int _y, int _dx, int _dy):x(_x), y(_y), dx(_dx), dy(_dy){}
	std::string what(){return "X=" + std::to_string(x) + "; Y=" + std::to_string(y) + "; DX=" + std::to_string(dx) + "; DY=" + std::to_string(dy);}	
};
class IllegalCommand : public RobotError
{
public:
	IllegalCommand(int _x, int _y, int _dx, int _dy):RobotError::RobotError(_x, _y, _dx, _dy){}
};
class OffTheField : public RobotError
{
public:
	OffTheField(int _x, int _y, int _dx, int _dy):RobotError::RobotError(_x, _y, _dx, _dy){}	
};
void Robot::move(int dx, int dy)
{
	if(abs(dx) > 1 || abs(dy) > 1) throw IllegalCommand(x, y, dx, dy);
	if(dx+x < 0 || dx+x >= X_MAX || dy+y < 0 || dy+y >= Y_MAX) throw OffTheField(x, y, dx, dy);
	x += dx;
	y += dy;
}
int main()
{
	std::cout << "_____Exercise #1_____" << std::endl;
	try
	{
		std::cout << "Result: " << div(23.6, 5) << " !!!" << std::endl;
		std::cout << "Result: " << div(23.6, 0) << " !!!" << std::endl;
	}
	catch(const char * ex)
	{
		std::cerr << "Error: " << ex << std::endl;
	}
	
	std::cout << "_____Exercise #2_____" << std::endl;
	Bar bar;
	int n;
	try
	{
		while(true)
		{
			if(getInteger(n))
			{
				if(n==0) break;
				bar.set(n);
				std::cout << "Bar.y = " << bar.get() << ". ";
			}
		}		
	}
	catch(Ex & ex)
	{
		std::cerr << "Error: " << ex.what() << std::endl;		
	}
	
	std::cout << "_____Exercise #3_____" << std::endl;
	Robot robot;
	try
	{
		robot.move(1, 1);
		robot.move(2, -1);
		robot.move(0, -1);
		robot.move(0, -1);
		std::cout << "Robot moved !!" << std::endl;
	}
	catch(IllegalCommand ex)
	{
		std::cout << "Error. Illegal command: " << ex.what() << std::endl;
	}
	catch(OffTheField ex)
	{
		std::cout << "Error. Off the field: " << ex.what() << std::endl;
	}	
	return 0;
}
