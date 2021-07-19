#include <iostream>
#include <string.h>
#define LEN_NAME 64
class Person
{
private:
	char m_name[LEN_NAME];
	char m_age;
	char m_gender;
	float m_weight;
public:
	Person(const char * n, char a, char g, float w) : m_age(a), m_gender(g), m_weight(w) {strcpy(m_name, n);}
	void setName(const char * n) {strcpy(m_name, n);}
	void setAge(char a) {m_age = a;}
	void setWeight(float w) {m_weight = w;}		
	void printInfo() const;
	bool isName(const char * nm) const {return strcmp(nm, m_name)==0;}
};
class Student : public Person
{
private:
	short m_year;
public:
	int static count;
	Student(const char * n, char a, char g, float w, short y) : Person(n, a, g, w), m_year(y){count++;}
	~Student(){count--;}
	void setYear(short y){m_year = y;}
	void addYear(){m_year++;}
	void printInfo() const;
};
void Person::printInfo() const
{
	std::cout << "NAME: " << m_name << std::endl;
	std::cout << "AGE: " << (int)m_age << std::endl;
	std::cout << "GENDER: " << m_gender << std::endl;
	std::cout << "WEIGHT: " << m_weight << " kg" << std::endl;
}
void Student::printInfo() const
{
	Person::printInfo();
	std::cout << "YEAR: " << m_year << std::endl;	
}
int Student::count;
void printStudent(Student ** st, const char * nm)
{
	int i;
	for(i=0; i<Student::count; i++)
	{
		if(st[i]->isName(nm))	
			break;
	}
	if(i==Student::count)
		std::cout << "Student \'" << nm << "\'" << " is not found." << std::endl;
	else
		st[i]->printInfo();
}
class Fruit
{
private:
	char name[LEN_NAME];
	char color[LEN_NAME];
public:
	Fruit(const char * n, const char * c) {strcpy(name, n); strcpy(color, c);}
	char * getName() {return name;}
	char * getColor() {return color;}
};
class Apple : public Fruit
{
public:
	Apple(const char * n, const char * c):Fruit(n, c){};
	Apple(const char * c):Fruit("apple", c){}
};
class Banana : public Fruit
{
public:
	Banana():Fruit("banana", "yellow") {}
};
class GrannySmith : public Apple
{
public:
	GrannySmith():Apple("Granny Smith apple", "green"){}
};
int main()
{
	std::cout << "____Exercise #1____" << std::endl;
	Student::count = 0;
	Student* students[10];	
	students[0] = new Student("Andrey", 20, 'M', 68.5, 2021);
	students[1] = new Student("Ivan", 30, 'M', 78.4, 2020);
	students[2] = new Student("Alex", 25, 'M', 98.1, 2019);
	students[3] = new Student("Nina", 33, 'W', 56.7, 2021);
	std::cout << "Enter name of student: ";
	char buffer[LEN_NAME];
	std::cin >> buffer; 
	printStudent(students, buffer);
	
	std::cout << "____Exercise #2____" << std::endl;
	Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}