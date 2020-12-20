#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 18. Написать программу, определяющую корректность применения в данном коде оператора +


string input() {
	string my_string;
	string line;
	ifstream file("input.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			my_string += line;
		}
	}
	line.erase();
	file.close();
	return my_string;
}
