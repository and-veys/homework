#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
class ArrayInt
{
private:
    int m_length;
    int *m_data;

public:
    ArrayInt(): m_length(0), m_data(nullptr){}
    ArrayInt(int length);
    ~ArrayInt(){delete[] m_data;}
	void erase() {delete[] m_data; m_data = nullptr; m_length = 0;}
	int getLength() {return m_length;}
	int& operator[](int index);
	void resize(int newLength);
	void insertBefore(int value, int index);
	void push_back(int value) {insertBefore(value, m_length);}
	int deleteBefore(int index);
	int pop_back(){return deleteBefore(m_length-1);}
	int pop_front(){return deleteBefore(0);}
	void sort();
	void print();
};
ArrayInt::ArrayInt(int length) : m_length(length)
{
	assert(length >= 0);
	if (length > 0)
		m_data = new int[length];
    else
		m_data = nullptr;
}
int& ArrayInt::operator[](int index)
{
	assert(index >= 0 && index < m_length);
	return m_data[index];
}
void ArrayInt::resize(int newLength)
{
	if (newLength == m_length) return;
    if (newLength <= 0)
    {
		erase();
        return;
    }
	int *data = new int[newLength];
    if (m_length > 0)
    {
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
        for (int index=0; index < elementsToCopy ; ++index)
			data[index] = m_data[index];
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
}
void ArrayInt::insertBefore(int value, int index)
{
	assert(index >= 0 && index <= m_length);
	int *data = new int[m_length+1];
    for (int before=0; before < index; ++before)
		data[before] = m_data[before];
    data [index] = value;
    for (int after=index; after < m_length; ++after)
		data[after+1] = m_data[after];
    delete[] m_data;
    m_data = data;
    ++m_length;
}
int ArrayInt::deleteBefore(int index)
{
	assert(index >= 0 && index < m_length);
	int temp = m_data[index];
	int *data = new int[m_length-1];
    for (int before=0; before < index; ++before)
		data[before] = m_data[before];
    for (int after=index+1; after < m_length; ++after)
		data[after-1] = m_data[after];
    delete[] m_data;
    m_data = data;
    --m_length;
	return temp;
}
void ArrayInt::sort()
{
	int temp;
	for(int i=0; i<m_length; i++)
	{
		for(int j=0; j<m_length-1-i; j++)
		{
			if(m_data[j] > m_data[j+1])
			{
				temp = m_data[j];
				m_data[j] = m_data[j+1];
				m_data[j+1] = temp;
			}			
		}
	}
}
void ArrayInt::print()
{
	for(int i=0; i< m_length; i++)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}
void printVector(std::vector<int> & v)
{
	for(int i=0; i<v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}
int main()
{
	std::cout << "_____Exercise_#1_____" << std::endl;
	int ar[] = {18, 3, 1286, -2, 542, 66, -17, 467, 1199};
	ArrayInt ai;
	for(int i=0; i<sizeof(ar)/sizeof(int); i++)
		ai.push_back(ar[i]);
	ai.print();
	ai.sort();
	ai.print();
	std::cout << "Del_Back: " << ai.pop_back() << std::endl;
	std::cout << "Del_Front: " << ai.pop_front() << std::endl;
	ai.print();
	
	std::cout << "_____Exercise_#2_____" << std::endl;
	std::vector<int> vec = {5, 8, 1, 4, 0, 5, 1, 6, 6, 3, 8};
	printVector(vec);
	std::sort(vec.begin(), vec.end(), std::less<int>());
	int n=1;
	for(int i=1; i<vec.size(); i++)
	{
		if(vec[i] != vec[i-1]) n++;		
	}
	std::cout << "Number of different elements is " << n << "." << std::endl;
	return 0;
}