#include <iostream>
template <class T> class Smart_pointer
{
private:
	T* m_ptr;
public:
	Smart_pointer(T* p = nullptr):m_ptr(p){}
	Smart_pointer(Smart_pointer & sp):m_ptr(sp.m_ptr){sp.m_ptr = nullptr;}
	~Smart_pointer(){delete m_ptr;}
	Smart_pointer & operator = (Smart_pointer & sp);
	T& operator *() const {return *m_ptr;}
	T* operator ->()const {return m_ptr;}
	bool isNull()const {return m_ptr == nullptr;}
	template <class V> friend std::ostream & operator << (std::ostream & out, Smart_pointer<V> & sp);
};
template <class T> Smart_pointer<T> & Smart_pointer<T>::operator = (Smart_pointer<T> & sp)
{
	if(this != &sp)
	{	
		delete m_ptr;
		m_ptr = sp.m_ptr;
		sp.m_ptr = nullptr;
	}
	return *this;
}
template <class V> std::ostream & operator << (std::ostream & out, Smart_pointer<V> & sp)
{
	if(sp.isNull()) out << "NULL";
	else out << *sp;	
	return out;
}
class Date
{
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(): m_day(1), m_month(1), m_year(2000){}
	Date(int d, int m, int y):m_day(d), m_month(m), m_year(y){}
	int getDay() const {return m_day;}
	int getMonth() const {return m_month;}
	int getYear() const {return m_year;}
	void setDay(int d){m_day = d;}
	void setMonth(int m){m_month = m;}
	void setYear(int y){m_year = y;}
	int compareDate(Date & d);
	friend std::ostream& operator << (std::ostream & out, Date & d);
};
int Date::compareDate(Date & d)
{
	Date * temp = this;
	int a[2];
	for(int i=0; i<2; i++)
	{
		a[i]= temp->getYear() * 10000 + temp->getMonth()*100 + temp->getDay();
		temp=&d;
	}
	if(a[0]==a[1]) return 0;
	return (a[0] > a[1])?1:-1;
}
std::ostream& operator << (std::ostream & out, Date & d)
{	
	out << (d.m_day < 10?"0":"") << d.m_day << "." << (d.m_month < 10?"0":"") << d.m_month << "." << d.m_year;
	return out;
}
Smart_pointer<Date> & compareDate (Smart_pointer<Date> & d1, Smart_pointer<Date> & d2)
{
	if(d1->compareDate(*d2) > 0) return d1;
	return d2;
}
template <class T> void swap (Smart_pointer<T> & d1, Smart_pointer<T> & d2)
{
	Smart_pointer<T> temp = d1;
	d1=d2;
	d2=temp;
}
int main()
{
	std::cout << "_____Exercise #1_____" << std::endl;
	Smart_pointer<Date>today(new Date);
	Smart_pointer<Date>date;
	today->setDay(5);
	today->setMonth(8);
	today->setYear(2021);	
	std::cout << "today is " << *today << std::endl;
	date = today;
	std::cout << "today is " << today  << std::endl;
	std::cout << "date is " << date << std::endl;
	
	std::cout << "_____Exercise #2_____" << std::endl;
	Smart_pointer<Date>date1(new Date(30,06,1956));
	Smart_pointer<Date>date2(new Date(28,04,1971));
	std::cout << "After compare..." << std::endl;
	Smart_pointer<Date>date3 = compareDate(date1, date2);
	std::cout << "date1 is " << date1 << std::endl;
	std::cout << "date2 is " << date2 << std::endl;
	std::cout << "date3 is " << date3 << std::endl;
	std::cout << "After swap..." << std::endl;
	swap(date1, date3);	
	std::cout << "date1 is " << date1 << std::endl;
	std::cout << "date2 is " << date2 << std::endl;
	std::cout << "date3 is " << date3 << std::endl;	
	return 0;
}