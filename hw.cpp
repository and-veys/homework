#include <iostream>
#include <fstream>
char * read_file(std::string);
void write_file(std::ofstream &, char *);
int main(int argN, char ** argV)
{
//Exercise #1
	std::ofstream file ("one.txt");
	if(file.is_open())
	{	
		file << "Father Duck goes for a swim.\n"; 
		file << "Mother Duck comes out with him\n";
		file << "And behind them, nice and clean,\n";
		file << "Seven yellow ducklings swim.\n";
		file.close();
	}
	file.open ("two.txt");
	if(file.is_open()) 
	{
		file << "Seven little yellow balls." << std::endl;
		file << "\"Quack, quack, quack\" the mother calls." << std::endl;
		file << "What a pretty sight they make" << std::endl;
		file << "Swimming on the lake." << std::endl;
		file.close();
	}
//Exercise #2	
	file.open("three.txt");
	if(file.is_open())
	{
		write_file(file, read_file("one.txt"));
		write_file(file, read_file("two.txt"));
		file.close();		
	}	
//Exercise #3
	if(argN == 3)
	{
		std::ifstream fl(argV[1]);
		std::string str(argV[2]);
		bool bl = false;
		if(fl.is_open())
		{
			std::string word;
			while(!fl.eof())
			{
				fl >> word;
				if(word == str) 
				{
					bl=true;					
					break;
				}				
			}
			std::cout << "\"" << str << "\" is" << (bl?" ":" not ") << "in \"" << argV[1] << "\"" << std::endl;
		}
		else std::cout << "Unknown name of file." << std::endl;		
	}
	else std::cout << "It needs two parameters." << std::endl;
	return 0;
}
char * read_file(std::string s)
{
	std::ifstream file(s, std::ios::ate);
	if(!file.is_open()) return nullptr;
	int n = file.tellg();
	char * a = (char *) calloc(n, sizeof(char));
	if(a != nullptr)
	{
		file.seekg(0);
		file.read(a, n);
	}
	file.close();
	return a;
}
void write_file(std::ofstream & f, char * a)
{
	if(a != nullptr) 
	{
		f << a;
		free(a);
	}
}