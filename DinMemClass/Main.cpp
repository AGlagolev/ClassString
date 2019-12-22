#include <iostream>
#include "Myfunc.h"
#include "Auxiliary.h"



class String
{
	unsigned int size; // Разме строки в Байтах
	char* str;         // указатель на строку в динамической памяти
	////////////////////////////////////////////////////////////////
public:
	///////////////////////// *********GETS
	int get_size() const
	{
		return size;
	}
	///////////////////////////////////////
	const char* get_str() const
	{
		return str;
	}
	///////////////////////////////////////
	char* get_str() // Метод для неконст обектов (дает возможность изменять объект)
	{
		return str;
	}
	///////////////////////// ***********OPERATORS
	///////////////////////// Operator +=
	//String operator+=(String& obj)
	//{
	//	String A = *this;
	//	//A = A + obj;
	//	return A;
	//}
	//////////////////////////////////////////////// Operator []
	const char& operator[](int index) const
	{
		return str[index];
	}
	/////////////////////////////////////////////// Operator []
	char& operator[](int index)
	{
		return str[index];
	}
	/////////////////////////////////////////// Operator MoveAssignment
	String& operator=(String&& other)
	{
		delete[] str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		//for (int i = 0; other.str[i]; i++) this->str[i] = other.str[i];
		std::cout << "MoveAssignmentOperator" << this << std::endl;
		return *this;
	}		
/////////////////////////////////////////////// AssigmentOperator
		String& operator=(const String& other)
		{			
			this->size = other.size;
			this->str = new char[size] {};
			for (int i = 0; other.str[i]; i++) this->str[i] = other.str[i];
			std::cout << "AssigmentOperator" << this << std::endl;
			return *this;
		}
	///////////////////////// ******* METHODS
		//////////////////// print
		void print() const
		{
			std::cout << "size:\t" << size << std::endl;
			std::cout << "str:\t" << str << std::endl;     // Оператор << перегружен с char таким образом, что вместо адреса при выводе указателя выводит значение
		}
		///////////////////////////////////////// Strlen
		int Strlen(const char* str)
		{
			int i = 0;
			for (; str[i]; i++)
			return i;
		}

	/////////////////////////   ***** CONSTRUCTORS
		
		//String(String&& other)  // MoveConstructor
		//{
		//	this->size = other.size;
		//	this->str = other.str;
		//	other.str = nullptr/*(или поставить 0 вместо nullptr)*/; // применяется к указателям 
		//	std::cout << "MoveConstructor" << this << std::endl;
 	//	}
	///////////////////////////////// CopyConstructor
		String(const String& other)                                    // При коппировании будет выделятся другая область памяти
		{
			this->size = other.size;
			this->str = new char[size] {};
			for (int i = 0; other.str[i]; i++) this->str[i] = other.str[i];
			std::cout << "CopyConstructor" << this << std::endl;
		}
		////////////////////////////////// DefultConstructor
		String(unsigned int size = 80)
		{
			this->size = size;
			this->str = new char[size] {};
			std::cout << "DefultConstructor" << this << std::endl;
		}
		///////////////////////////////// Constructor whith one parameter 
		String(const char* str)
		{
			this->size = strlen(str)+1;
			this->str = new char[size] {};
			for (int i = 0; str[i]; i++) this->str[i] = str[i]; //*(this->str[i]) = *(str[i])
			std::cout << "Constructor" << this << std::endl;
		}

		~String() ///////////////////////////////// Defstructor
		{
			delete[] this->str;
			std::cout << "Defstructor" << this << std::endl;
		}
		
};
//
//std::ostream& operator<<(std::ostream& os, const char* str)
//{
//	for (int i = 0; str[i]; i++)os << str + i;
//	return os;
//}
//
//std::ostream& operator<<(std::ostream& os, char* str)
//{
//	for (int i = 0; str[i]; i++)os << str + i;
//	return os;
//}
///////////////////////////FUNCTIONS///////////////////////

String operator+(const String& left, const String& right);
void operator+=(String& left, const String& right);
std::ostream& operator<<(std::ostream& os, String& str);

void main()
{
	setlocale(LC_ALL, "Russian");
	std::system("color 0A");
	Font(25);
	SetConsoleCP(1251);        // Для вывода кирилицы из массива + шрифт Lucida console, Console 
	SetConsoleOutputCP(1251);
	char* S = new char[5]{'1','2','3','4','5'};
	//std::cout << *S << std::endl << reinterpret_cast<const char*>(S + 1);
	//std::cout << typeid(reinterpret_cast<const char*>(S)).name() << std::endl;
	//std::cout << typeid(&S+1).name() << std::endl;
	//std::cout << *(&S) << std::endl;// << *(&S + 1);
	//std::cout << reinterpret_cast<const char *>(S + 1) << std::endl;
	/*String str1;
	str1.print();
	String str2 = "Hello";
	str2.print();*/
	//str3.print();
	//str3.print();
	//str4.print();

	String str3;// = str2;
	str3 = "WH";
	String str4;
	str4 = "FK";

	String str5;
	str5 = str3 + str4;
	//str5.print();
	str5 += str3;
	str5.print();
	//std::cout << str5 << std::endl;

	//std::cout << str5.get_str();
}



///////////////////////////FUNCTIONS///////////////////////
String operator+(const String& left, const String& right)
{
	String result = left.get_size() + right.get_size() -1;
	/*for (int i = 0; i < left.get_size();i++) result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size();i++) result.get_str()[i+left.get_size()-1] = right.get_str()[i];
	*/
	for (int i = 0; i < left.get_size(); i++) result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++) result[i + left.get_size() - 1] = right[i];

	return result;
}
////////////////////////////////////////////////////////////////////
void operator+=(String& left, const String& right)
{	
	left = left + right;		
}
////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, String& str)
{
	os << str.get_str();
	return os;
}