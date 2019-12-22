#include <iostream>
#include "Myfunc.h"
#include "Auxiliary.h"

class String
{
	unsigned int size; // Разме строки в Байтах
	char* str;         // указатель на строку в динамической памяти
};




void main()
{
	setlocale(LC_ALL, "Russian");
	std::system("color 70");
	Font(25);
	SetConsoleCP(1251); // Для вывода кирилицы из массива + шрифт Lucida console, Console 
	SetConsoleOutputCP(1251);


}