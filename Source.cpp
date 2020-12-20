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

int count_operators(string chunk_of_code) {
	int counter = 0;
	for (int i = 0; i < chunk_of_code.length(); i++) 
		if (chunk_of_code[i] == '+') counter++;
	return counter;
}

int count_operands(string chunk_of_code) {
	int counter = 0;
	bool flag = false;
	for (int i = 0; i < chunk_of_code.length(); i++)
	{
		if (chunk_of_code[i] != '+' && chunk_of_code[i] != ' ' && !flag)
		{
			counter++; 
			flag = true;
		}
		if (chunk_of_code[i] == '+' || chunk_of_code[i] == ' ')
		{
			flag = false;
		}


	}
	return counter;
}

bool operands_quantity_correct(string chunk_of_code) { 
	int operands_quantity = count_operands(chunk_of_code);
	int operators_quantity = count_operators(chunk_of_code);
	// cout << operands_quantity << endl; количество плюсов
	// cout << operators_quantity << endl; количество операндов
	return operands_quantity == operators_quantity + 1; }

string del_all_spaces(string chunk_of_code) {
	string new_chunk = chunk_of_code;
	remove_if(new_chunk.begin(), new_chunk.end(), isspace); // функция удаления пробелов
	return new_chunk;
}

bool operands_position_correct(string chunk_of_code) { 
	bool is_correct = true;
	string chunk_of_code_without_spaces = del_all_spaces(chunk_of_code); // убираем пробелы 
	for (int i = 0; i < chunk_of_code_without_spaces.length() - 1; i++)
	{
		if (chunk_of_code_without_spaces[i] == '+' && i == 0) return false;
		if (chunk_of_code_without_spaces[i + 1] == '+' && i + 1 == chunk_of_code.length() - 1) return false;
		if (chunk_of_code_without_spaces[i] == '+' && chunk_of_code_without_spaces[i+1] == '+') return false;
	}

	return is_correct; }

bool plus_is_there(string chunk_of_code) {
	for (int i = 0; i < chunk_of_code.length(); i++) if (chunk_of_code[i] == '+') return true;
	return false;
}


bool plus_used_correctly(string chunk_of_code) {
	if (plus_is_there(chunk_of_code) && operands_quantity_correct(chunk_of_code) && operands_position_correct(chunk_of_code)) return true;
	else return false;
}


void main() {
	string chunk_of_code;
	chunk_of_code = input();
	if (plus_used_correctly(chunk_of_code)) cout << "Operator plus was used correctly\n";
	else cout << "Operator plus was'nt used correctly or not even found!";
}