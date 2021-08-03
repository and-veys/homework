#include <iostream>
std::ostream& endll(std::ostream &out)
{
	out << "\n" << std::endl;
	return out;
}
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
int main()
{
	std::cout << "_____Exercise #1_____" << std::endl;
	int nValue;
	while(!getInteger(nValue)) 
		std::cout << "Error!! ";
	std::cout << "Number is " << nValue << std::endl;
	
	std::cout << "_____Exercise #2_____" << std::endl;	
	std::cout << "Hello world" << endll << "!!!" << std::endl;
    return 0;
}


