#include <iostream>
#include <string>
#include <vector>
#include <functional>
/*
* Шестая лабораторная работа
* Автор: Супран Федор Константинович
* Группа: ПИ2-2
*/

/*
* Напишите функцию, которая возвращает наибольший из трех целочисленных аргументов.
*/
int findMaxOfThree(int a, int b, int c)
{
	return std::max(a, std::max(b, c));
}
void func1()
{
	system("cls");
	int a, b, c;
	std::cout << "Введите первое число: ";
	std::cin >> a;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	std::cout << "Введите третье число: ";
	std::cin >> c;
	std::cout << "Максимальное число: " << findMaxOfThree(a, b, c) << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Напишите функцию, которая имеет два аргумента int: нижний предел и верхний 
* предел. Функция должна читать целое число из входных данных. Если это
* число выходит за указанные пределы, функция должна снова вывести меню
* (используя функцию из части а)), чтобы повторно предложить пользователю
* ввести новое значение. Если введенное целое значение попадает в рамки пределов,
* функция должна возвратить его в вызывающую функцию. Ввод нецелочисленного значения
* должен приводить к возвращению функцией значения, соответствующего выходу из программы
* (часть а. Напишите функцию, которая выводит на экран меню из четырех пронумерованных
* вариантов и предлагает выбрать один из них. Ввод верхнего и нижнего предела, возможность
* изменить входящее целое число повторным вводом с клавиатуры и выход из меню и программы)
*/
bool ok = true;
int func2_1(int start, int end)
{
	system("cls");
	double x;
	std::cout << "Введите целое число: ";
	std::cin >> x;
	if (x != int(x)) // Ввод нецелочисленного значения
		exit(1);
	else if (int(x) < start || int(x) > end)// Число выходит за указанные пределы
	{
		ok = false;
		return x;
	}
	else if (x >= start && x <= end)// Целое значение попадает в рамки пределов
	{
		ok = true;
		return x;
	}
		
}
void func2()
{
	int start = 0, end = 0, x = 0;
	while (true)
	{
		system("cls");
		int choice = 0;
		std::cout << "============================\n";
		std::cout << "=====Меню второй задачи=====\n";
		std::cout << "============================\n";
		std::cout << "start = " << start << "; end = " << end << "; x = " << x << std::endl;
		std::cout << "1) Ввод верхнего и нижнего предела\n";
		std::cout << "2) Изменить входящее целое число повторным вводом с клавиатуры\n";
		std::cout << "3) Выход из меню\n";
		std::cout << "4) Выход из программы\n";
		std::cout << "Введите номер пункта: ";
		std::cin >> choice;
		if (choice == 1)
		{
			system("cls");
			std::cout << "Введите нижний предел: ";
			std::cin >> start;
			std::cout << "Введите верхний предел: ";
			std::cin >> end;
		}
		else if (choice == 2)
		{
			int temp = func2_1(start, end);
			if (ok) x = temp;
		}
		else if (choice == 3)
		{
			break;
		}
		else if (choice == 4)
		{
			exit(1);
		}
	}

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Реализуйте сортировку массива вставками (массив из целых чисел)
*/
void insertionSort(int* arr, int size) // сортировка вставками
{
	int temp, prev;
	for (size_t i = 1; i < size; i++)
	{
		temp = arr[i];
		prev = i - 1;
		while (prev >= 0 && arr[prev] > temp)
		{
			arr[prev + 1] = arr[prev];
			arr[prev] = temp;
			prev--;
		}
	}
}
void func3()
{
	system("cls");
	int size;
	std::cout << "Введите размер массива: ";
	std::cin >> size;
	int* arr = new int[size];
	std::cout << "Заполните массив: ";
	for (size_t i = 0; i < size; i++)
		std::cin >> arr[i];
	insertionSort(arr, size);
	std::cout << "Отсортированный массив: ";
	for (size_t i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Меню для выбора функций
*/
void showMenu(std::vector<std::string> titleVector, std::vector<std::function<void()>> fVector)
{
	while (true)
	{
		system("cls");
		int choice = 0;
		std::cout << "============================\n";
		std::cout << "============Меню============\n";
		std::cout << "============================\n";
		for (size_t i = 0; i < titleVector.size(); i++)
			std::cout << i + 1 << ") " << titleVector[i] << std::endl;
		std::cout << "Введите номер выбранной задачи: ";
		std::cin >> choice;
		if (choice - 1 < 0 || choice - 1 >= titleVector.size())
			break;
		else
			fVector[choice - 1]();
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<std::string> titleVector =
	{
		"Наибольший из трех целочисленных аргументов.",
		"Задание 2.",
		"Cортировка массива вставками (массив из целых чисел)."
	};
	std::vector<std::function<void()>> fVector = { func1, func2, func3 };
	showMenu(titleVector, fVector);
	return 0;
}