#include <iostream>
#include "Myfunc.h"
#include "Auxiliary.h"
#include <cstdio>


class String
{
	unsigned int size; // Разме строки в Байтах
	char* str;         // указатель на строку в динамической памяти
	////////////////////////////////////////////////////////////////
public:
	///////////////////////// **********FRIENDS
	friend void operator>>(std::istream& is, String& str);
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
		//std::cout << "MoveAssignmentOperator" << this << std::endl;
		return *this;
	}		
/////////////////////////////////////////////// AssigmentOperator
		String& operator=(const String& other)
		{			
			this->size = other.size;
			this->str = new char[size] {};
			for (int i = 0; other.str[i]; i++) this->str[i] = other.str[i];
			//std::cout << "AssigmentOperator" << this << std::endl;
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
		
		String(String&& other)  // MoveConstructor
		{
			this->size = other.size;
			this->str = other.str;
			other.str = nullptr/*(или поставить 0 вместо nullptr)*/; // применяется к указателям 
			//std::cout << "MoveConstructor" << this << std::endl;
 		}
	///////////////////////////////// CopyConstructor
		String(const String& other)                                    // При коппировании будет выделятся другая область памяти
		{
			this->size = other.size;
			this->str = new char[size] {};
			for (int i = 0; other.str[i]; i++) this->str[i] = other.str[i];
			//std::cout << "CopyConstructor" << this << std::endl;
		}
		////////////////////////////////// DefultConstructor
		String(unsigned int size = 80)
		{
			this->size = size;
			this->str = new char[size] {};
			//std::cout << "DefultConstructor" << this << std::endl;
		}
		///////////////////////////////// Constructor whith one parameter 
		String(const char* str)
		{
			this->size = strlen(str)+1;
			this->str = new char[size] {};
			for (int i = 0; str[i]; i++) this->str[i] = str[i]; //*(this->str[i]) = *(str[i])
			//std::cout << "Constructor" << this << std::endl;
		}

		~String() ///////////////////////////////// Defstructor
		{
			delete[] this->str;
			//std::cout << "Defstructor" << this << std::endl;
		}
		
};

///////////////////////////FUNCTIONS///////////////////////

String operator+(const String& left, const String& right);
void operator+=(String& left, const String& right);
std::ostream& operator<<(std::ostream& os, String& str);
int comparison(const String& A, const String& B);
void SwitchStandart();
bool operator<(const String& A, const String& B);
bool operator>(const String& A, const String& B);
bool operator==(const String& A, const String& B);
int fin_d(const String& A, const String& B);


#define STRINGS
//#define OTHERS

void main()
{
	setlocale(LC_ALL, "Russian");
	std::system("color 0A");
	Font(20);
	SetConsoleCP(1251);        // Для вывода кирилицы из массива + шрифт Lucida console, Console 
	SetConsoleOutputCP(1251);



#ifdef STRINGS
	String As, Bs, Cs;

BeginST:
	

	std::cout << "Введите строку 1: ";
	std::cin >> As;	
	W_line(); //As.print();
	
	std::cout << "Введите строку 2: ";
	std::cin >> Bs;
	W_line();
	
vvod_S:
	std::system("cls");

	std::cout << "\nПервая строка:  " << As << "( " << As.get_size() + 1 << " Байт)" << std::endl;
	W_line();
	std::cout << "\nВтораяая строка:  " << Bs << "( " << Bs.get_size() + 1 << " Байт)" << std::endl;
	W_line();
	std::cout << std::endl << "\t\t\nВыбирете действие, которое необходимо сделать со строками:  \n\n";
	std::cout << "1 - сравнение \n2 - поиск в строках \n3 - оператор + \n4 - оператор += ";
	std::cout << "\nr - Перезаписать строки\nESC - выход\n\n";
	
	
	//std::cout << _getch()-48;
	switch (_getch() - 48)
	{
	case 1://  Comparison
	{
		switch (comparison(As, Bs))
		{
		case 0: {std::cout << "Строки одинаковы "; break; };
		case 1: {std::cout << "строка 1 > строки 2"; break; };
		case 2: {std::cout << "строка 1 < строки 2"; break; };
		}
		SwitchStandart();
		goto vvod_S;
	};
	case 2:// Search
	{

		std::cout << "Что ищем?: ";
		switch (fin_d(As, Bs))
		{
		case 0: {std::cout << "Совпадений не найдено "; break; };
		case 1: {std::cout << "Найдено совпадение в строке 1"; break; };
		case 2: {std::cout << "Найдено совпадение в строке 2"; break; };
		}
		SwitchStandart();
		goto vvod_S;
	};
		case 3: // +
		{
			Cs = As + Bs;
			std::cout << Cs;
	
			SwitchStandart();
			goto vvod_S;
		};
		case 4: // +=
		{
			As += Bs;
			std::cout << As;
	
			SwitchStandart();
			goto vvod_S;
		};	
	case 34:
	{
		std::system("cls");
		goto BeginST;
	};
	case 66:
	{
		std::system("cls");
		goto BeginST;
	};
	case 154:
	{
		std::system("cls");
		goto BeginST;
	};
	case 186:
	{
		std::system("cls");
		goto BeginST;
	};
	case -21:
	{
		break;
	};
	default:
	{
		std::cout << "Неверный ввод_\n";
		std::system("pause");
		std::system("cls");
		goto vvod_S;

	};
	}

#endif // STRINGS

#ifdef OTHER
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
#endif // OTHER


}



///////////////////////////FUNCTIONS Defenition///////////////////////
////////////////////////////////////////////// Operator +
String operator+(const String& left, const String& right)
{
	String result = left.get_size() + right.get_size() -1;
	int a = left.get_size();
	int b = right.get_size();
	/*for (int i = 0; i < left.get_size();i++) result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size();i++) result.get_str()[i+left.get_size()-1] = right.get_str()[i];
	*/
	for (int i = 0; i < a; i++) result[i] = left[i];
	for (int i = 0; i < b; i++) result[i + a - 1] = right[i];	

	return result;
}
////////////////////////////////////////////// Operator +=
void operator+=(String& left, const String& right)
{	
	left = left + right;		
}
////////////////////////////////////////////// Operator <<
std::ostream& operator<<(std::ostream& os, String& str)
{
	os << str.get_str();
	return os;
}
////////////////////////////////////////////// Operator <
bool operator<(const String& A, const String& B)
{
	int z = 0;
	(A.get_size() > B.get_size()) ? z = B.get_size() - 1 : z = A.get_size() - 1;
	
	for (int i = 0; i < z; i++) if (A[i] < B[i]) return true;	
	
	return false;
}
////////////////////////////////////////////// Operator >
bool operator>(const String& A, const String& B)
{
	int z = 0;
	(A.get_size() > B.get_size()) ? z = B.get_size() - 1 : z = A.get_size() - 1;

	for (int i = 0; i < z; i++)	if (A[i] > B[i]) return true;
	return false;
}
////////////////////////////////////////////// Operator ==
bool operator==(const String& A, const String& B)
{
	int z = 0;
	if (A.get_size() != B.get_size()) return 0;
	z = A.get_size() - 1;

	for (int i = 0; i < z; i++) if (A[i] < B[i]) return 0;	
	return true;
}
////////////////////////////////////////////////////////////////////
void operator>>(std::istream& is, String& str)
{
	is.getline(str.str, 80);
	int i = 0;
	for (; str[i]; i++);
	str.size = i + 1;
}
////////////////////////////////////////////////////////////////////
int comparison(const String& A, const String& B)
{
	int z = 0;
	(A.get_size() > B.get_size()) ? z = B.get_size() -1 : z = A.get_size() -1;
	
	for (int i = 0; i < z; i++)
	{
		if (A > B)	return 1;
		if (A < B)	return 2;
		if (A == B) return 0;
	}
}
////////////////////////////////////////////////////////////////////
void SwitchStandart()
{
	std::cout << std::endl;
	std::system("pause");
	std::system("cls");
}
////////////////////////////////////////////////////////////////////
int fin_d(const String& A, const String& B)
{ 
	
	String Ds;
	std::cin >> Ds;
	int sA = A.get_size();
	int sB = B.get_size();
	int sD = Ds.get_size();

	
	for (int i = 0; i < sA; i++)
	{
		if (Ds[0] == A[i])
		{
			for (int g = 0; g < sD -1; g++)
			{
				if (Ds[g] != A[i + g]) goto b;
			}
			return 1;
		}
	}

b:

	for (int i = 0; i < sB; i++)
	{
		if (Ds[0] == B[i])
		{
			for (int g = 0; g < sD -1; g++)
			{
				if (Ds[g] != B[i + g]) goto End;
			}
			return 2;
		}
	}
End:
	return 0;
}