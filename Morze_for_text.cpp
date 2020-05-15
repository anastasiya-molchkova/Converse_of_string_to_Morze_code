/* Напишите программу-телеграф, которая принимает от пользователя сообщение и выводит его на экран в виде последовательности
точек и тире.*/

#include <iostream>
#include <string>    // для std::string
#include <vector>    // для std::vector
#include <Windows.h> // для кириллицы

using std::cout; using std::cin; using std::endl;
using std::string; using std::vector;

struct mappingAlphabetToMorze
{
	char letter;
	string Morzecode;
};

namespace MorzeCoding
{
	const vector<mappingAlphabetToMorze> lettersCode{ { // я решила делать вектор, а не массив, т.к. в условии пропущена буква ё, а делать массив непонятной длины не хочется
		{'а',"·-"},{'А',"·-"},
		{'б',"-···"},{'Б',"-···"},
		{'в',"·--"},{'В',"·--"},
		{'г',"--·"},{'Г',"--·"},
		{'д',"-··"},{'Д',"-··"},
		{'е',"·"},{'Е',"·"},
		{'ж',"···-"},{'Ж',"···-"},
		{'з',"--··"},{'З',"--··"},
		{'и',"··"},{'И',"··"},
		{'й',"·---"},{'Й',"·---"},
		{'к',"-·-"},{'К',"-·-"},
		{'л',"·-··"},{'Л',"·-··"},
		{'м',"--"},{'М',"--"},
		{'н',"-·"},{'Н',"-·"},
		{'о',"---"},{'О',"---"},
		{'п',"·--·"},{'П',"·--·"},
		{'р',"·-·"},{'Р',"·-·"},
		{'с',"···"},{'С',"···"},
		{'т',"-"},{'Т',"-"},
		{'у',"··-"},{'У',"··-"},
		{'ф',"··-·"},{'Ф',"··-·"},
		{'х',"····"},{'Х',"····"},
		{'ц',"-·-·"},{'Ц',"-·-·"},
		{'ч',"---·"},{'Ч',"---·"},
		{'ш',"----"},{'Ш',"----"},
		{'щ',"--·-"},{'Щ',"--·-"},
		{'ъ',"·--·-·"},{'Ъ',"·--·-·"},
		{'ы',"-·--"},{'Ы',"-·--"},
		{'ь',"-··-"},{'Ь',"-··-"},
		{'э',"··-··"},{'Э',"··-··"},
		{'ю',"··--"},{'Ю',"··--"},
		{'я',"·-·-"},{'Я',"·-·-"},  } };
}

string letterToMorze(const char letter)
{
	for (const auto& element : MorzeCoding::lettersCode)
		if (element.letter == letter) return element.Morzecode;
	return "unknown_symbol";
}

void stringToMorze(string& text)
{
	cout << endl << "Вот как это примерно выглядит на азбуке Морзе:" << endl;
	for (const auto& symbol : text)
	{
		if (symbol == ' ') cout << "   ";
		else cout << letterToMorze(symbol) << " ";
	}
	cout << endl;
}

int main()
{
	// подключаем возможность ввода-вывода на кириллице:
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string some_string{ "" };

	while (true)
	{
		cout << endl << "Введите, пожалуйста, строку: " << endl;
		std::getline(cin, some_string);

		stringToMorze(some_string);
	}

	return 0;
}