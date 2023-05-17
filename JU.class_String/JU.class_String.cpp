#include <iostream>
#include <windows.h>
#include"myString.h"


myString create_string()
{
	myString q;
	std::cout << "Введите строку: ";
	std::cin >> q;
	return q;
}

//-------------------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	myString f("Ivan Kolbin");
	std::cout << "Строка, полученная от пользователя f: " << f << std::endl << std::endl;

	myString f0(3);
	std::cout << "Строка по умолчанию f0: " << f0 << "\n";
	std::cout << "Длина строки заданного размера: " << f0.length() << std::endl << std::endl;

	// работа конструктора копирования
	myString f1{ f };
	std::cout << "Конструктор копирования:\n";
	std::cout << "Строка f1 (из f): " << f1 << std::endl << std::endl;
	

	// работа конструктора перемещения
	myString f2{create_string()};
	std::cout << "Конструктор перемещения:\n";
	std::cout << "Строка f2: " << f2 << std::endl << std::endl;

	// работа оператора копирующего присаивания
	std::cout << "Оператор копирующего присаивания:\n";
	f1 = f2;
	std::cout << "Строка f1 (из f2): " << f1 << std::endl << std::endl;

	// работа оператора перемещающего присаивания
	std::cout << "Оператор перемещающего присаивания:\n";
	f2 = create_string();
	std::cout << "Строка f2: " << f2 << std::endl << std::endl;

	// вывод значений строки по индексу
	std::cout << "Нулевой символ строки f: " << f[0]
		<< "\nВосьмой символ строки f: " << f[8]
		<< "\nЧетвертый символ строки f: " << f[4] << std::endl << std::endl;

	// примеры поиска и вывода искомых символов
	std::cout << "Индекс символа 'n' в строке f: " << f('n')
		<< "\nИндекс символа 'i' в строке f: " << f('i')
		<< "\nИндекс несуществующего символа в строке f: " << f('6') << std::endl << std::endl;

	// преобразование строки в целые числа
	myString f3{ "2345,5"};
	std::cout << "Преобразование строки в целое число:\n" << "Строка f3: " << f3 << "\n";
	int num = myStol(f3);
	std::cout << "Число полученное из строки f3: " << num << std::endl << std::endl;

	return 0;
}