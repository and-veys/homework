#include <iostream>
#include <math.h>
class Figure
{
private:
	std::string name;		//imya figury
	double x, y;			//tochka vstavki figury
public:
	double pi;
	Figure(std::string n) : x(0), y(0), name(n), pi(atan(1)*4.0) {}
	double degToRad(double a){return a;}
	virtual double area()=0;
	void printArea(){std::cout << name << ": area = " << area() << std::endl;};
};
class Circle : public Figure
{
private:
	double radius;
public:
	Circle(double r, std::string n = "circle") : Figure(n), radius(r){};
	double area() {return pi*radius*radius;}
};
class Parallelogram : public Figure
{
private:
	double side_1, side_2, angle;
public:
	Parallelogram(double s1, double s2, double a, std::string n = "parallelogram") : Figure(n), side_1(s1), side_2(s2), angle(pi*a/180.0) {};
	double area() {return side_1*side_2*sin(angle);}
};
class Rectangle : public Parallelogram
{
public:
	Rectangle(double s1, double s2) : Parallelogram(s1, s2, 90, "rectangle"){}
};
class Square : public Parallelogram
{
public:
	Square(double s) : Parallelogram(s, s, 90, "square"){}
};
class Rhombus : public Parallelogram
{
public:
	Rhombus(double s, double a) : Parallelogram(s, s, a, "rhombus"){}
};
class Car
{
private:
	std::string company;
	std::string model;
public:
	Car(std::string c, std::string m) : company(c), model(m) {std::cout << "Car::Car" << std::endl;}
	void print(){std::cout << "__" << company << "__" << model << "__" << std::endl;}
};
class PassengerCar : virtual public Car
{
public:
	PassengerCar(std::string c, std::string m) : Car(c, m) {std::cout << "PassengerCar::PassengerCar" << std::endl;}
};
class Bus : virtual public Car
{
public:
	Bus(std::string c, std::string m) : Car(c, m) {std::cout << "Bus::Bus" << std::endl;}
};
class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string c, std::string m) : PassengerCar(c, m), Bus(c, m), Car(c, m) {std::cout << "Minivan::Minivan" << std::endl;}
};
class Fraction
{
private:
	int numerator;
	int denominator;
	void reduction();
public:
	Fraction(): numerator(0), denominator(1){}
	Fraction(int n, int d);
	bool set(int n, int d);
	std::string print();
	Fraction operator+(Fraction& fr) {return Fraction(numerator * fr.denominator + fr.numerator*denominator, fr.denominator*denominator);}
	Fraction operator-(Fraction& fr) {return Fraction(numerator * fr.denominator - fr.numerator*denominator, fr.denominator*denominator);}
	Fraction operator*(Fraction& fr) {return Fraction(numerator * fr.numerator, fr.denominator*denominator);}
	Fraction operator/(Fraction& fr) {return Fraction(numerator * fr.denominator, fr.numerator*denominator);}
	Fraction operator-() {return Fraction(numerator * -1, denominator);}
	bool operator==(Fraction& fr) {return (numerator == fr.numerator && fr.denominator == denominator);}
	bool operator!=(Fraction& fr) {return (numerator != fr.numerator || fr.denominator != denominator);}
	bool operator>(Fraction& fr) {return (numerator * fr.denominator > fr.numerator*denominator);}
	bool operator<=(Fraction& fr) {return !(*this > fr);}
	bool operator<(Fraction& fr) {return (numerator * fr.denominator < fr.numerator*denominator);}
	bool operator>=(Fraction& fr) {return !(*this < fr);}
};
Fraction::Fraction(int n, int d)
{
	if(!set(n, d))
	{
		std::cout << "ERROR" << std::endl;
		numerator = 0;
		denominator = 1;
	}
}
bool Fraction::set(int n, int d)
{
	if(d == 0) return false;
	numerator = (d < 0) ? n * (-1) : n;
	denominator = abs(d);
	reduction();
	return true;
}
void Fraction::reduction()
{
	int temp = denominator;
	while(temp != 0)
	{
		if(denominator%temp == 0 && numerator%temp == 0)
		{
			denominator /= temp;
			numerator /= temp;
			break;
		}
		temp--;
	}		
}
std::string Fraction::print()
{
	std::string res;
	int num = numerator/denominator;
	int n = numerator%denominator;
	if(n == 0)
		res = std::to_string(num);
	else if(num == 0)
		res = std::to_string(numerator) + "/" + std::to_string(denominator);
	else
		res = std::to_string(num) + " " + std::to_string(abs(n)) + "/" + std::to_string(denominator);
	return res;
}
int main()
{
	std::cout << "____ Exercise #1 ____" << std::endl;
	Circle c(12.4);
	c.printArea();
	Parallelogram p(3.5, 6.7, 34);
	p.printArea();
	Rectangle r (6.6, 8.4);
	r.printArea();
	Square sq (5.4);
	sq.printArea();
	Rhombus rh (4.8, 56);
	rh.printArea();
	
	std::cout << std::endl << "____ Exercise #2 ____" << std::endl;
	Car car("Car", "A");
	car.print();
	PassengerCar pas("PassengerCar", "B");
	pas.print();
	Bus bus("Bus", "C");
	bus.print();
	Minivan mnv("Minivan", "D");
	mnv.print();
	
	std::cout << std::endl << "____ Exercise #3 ____" << std::endl;
	Fraction f1, f2;
	f1.set(9, 26);
	f2.set(13, 16);
	std::cout << "f1 = " << f1.print() << std::endl;
	std::cout << "f2 = " << f2.print() << std::endl;
	std::cout << "f1+f2  = " << (f1 + f2).print() << std::endl;
	std::cout << "f1-f2  = " << (f1 - f2).print() << std::endl;
	std::cout << "f1*f2  = " << (f1 * f2).print() << std::endl;
	std::cout << "f1/f2  = " << (f1 / f2).print() << std::endl;
	std::cout << "-f1    = " << (-f1).print() << std::endl;
	std::cout << "f1==f2 = " << ((f1 == f2)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1==f1 = " << ((f1 == f1)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1!=f2 = " << ((f1 != f2)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1!=f1 = " << ((f1 != f1)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1>f2  = " << ((f1 > f2)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1>f1  = " << ((f1 > f1)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1<f2  = " << ((f1 < f2)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1<f1  = " << ((f1 < f1)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1<=f2  = " << ((f1 <= f2)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1<=f1  = " << ((f1 <= f1)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1>=f2  = " << ((f1 >= f2)?"TRUE":"FALSE") << std::endl;
	std::cout << "f1>=f1  = " << ((f1 >= f1)?"TRUE":"FALSE") << std::endl;
	
	return 0;
}