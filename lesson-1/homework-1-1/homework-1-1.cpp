// homework-3-1-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

int* get_array_from_file(std::ifstream& fin); //чтение массива из файла
int* shift_right(int* array); //сдвиг элементов вправо (кроме нулевого)
int* shift_left(int* array); //сдвиг элементов влево (кроме нулевого)
void put_array_to_file(std::ofstream& fout, int* array); //записать массив в файл

int main()
{

	setlocale(LC_ALL, "Russian");
	std::ifstream fin("in.txt");


	if (!fin.is_open())
	{
		std::cout << "нет файла \n";
		return -1;
	}

	//чтение из файла первого массива
	int* array_1 = get_array_from_file(fin);
	if (array_1 == nullptr)
	{
		std::cout << "Не удалось считать первый массив из файла \n";
		return -1;
	}

	int size_1 = array_1[0]; //размер первого массива хранится в его первом элементе

	for (int i = 0; i <= size_1; ++i)
	{
		std::cout << array_1[i] << " ";
	}
	std::cout << "\n";

	shift_right(array_1);
	for (int i = 0; i <= size_1; ++i)
	{
		std::cout << array_1[i] << " ";
	}
	std::cout << "\n";

	//чтение из файла второго массива
	int* array_2 = get_array_from_file(fin);
	if (array_2 == nullptr)
	{
		std::cout << "Не удалось считать второй массив из файла \n";
		return -1;
	}

	int size_2 = array_2[0]; //размер второго массива хранится в его первом элементе

	for (int i = 0; i <= size_2; ++i)
	{
		std::cout << array_2[i] << " ";

	}
	std::cout << "\n";

	shift_left(array_2);
	for (int i = 0; i <= size_2; ++i)
	{
		std::cout << array_2[i] << " ";
	}
	std::cout << "\n";

	std::ofstream fout("out.txt");

	put_array_to_file(fout, array_1); //записать первый массив в файл
	put_array_to_file(fout, array_2); //записать второй массив в файл


	fin.close();
	fout.close();
	delete[] array_1;
	delete[] array_2;
}

int* get_array_from_file(std::ifstream& fin)
{
	if (fin.eof()) //файл закончился и читать нечего
	{
		std::cout << "нет данных для чтения \n";
		return nullptr; //вернуть пустой указатель
	}

	std::string temp_str = "0";
	fin >> temp_str;
	int array_size = 0;
	array_size = std::stoi(temp_str); //сюда нужно добавить обработку исключений

	if (array_size <= 0)
	{
		std::cout << "Неверный размер массива \n";
		return nullptr; //вернуть пустой указатель
	}

	int* new_array = new int[array_size + 1](); //дополнительный элемент массива будет содержать информацию о его размере, чтобы не вводить лишнюю переменную
	new_array[0] = array_size;

	//считать элементы массива из файла
	for (int i = 1; i <= array_size; ++i)
	{
		if (!fin.eof())
		{
			fin >> temp_str;
			new_array[i] = std::stoi(temp_str); //сюда нужно добавить обработку исключений
		}
		else
		{
			std::cout << "Не хватает элементов массива \n";
			return nullptr; //вернуть пустой указатель
		}
	}

	return new_array;
}

int* shift_right(int* array) //сдвиг элементов вправо (кроме нулевого)
{
	int array_size = array[0]; //размер массива

	if (array_size <= 0)
		return array; //выход, если размер массива <= 0

	int temp_value = array[array_size]; //сохранить значение последнего элемента
	for (int i = array_size; i > 1; --i)
	{
		array[i] = array[i - 1];
	}

	array[1] = temp_value;
	return array;
}
int* shift_left(int* array) //сдвиг элементов влево (кроме нулевого)
{
	int array_size = array[0]; //размер массива

	if (array_size <= 0)
		return array; //выход, если размер массива <= 0

	int temp_value = array[1]; //сохранить значение первого элемента
	for (int i = 1; i < array_size; ++i)
	{
		array[i] = array[i + 1];
	}

	array[array_size] = temp_value;

	return array;
}

void put_array_to_file(std::ofstream& fout, int* array) //записать массив в файл
{
	int array_size = array[0];

	if (array_size <= 0)
		return; //выход, если размер массива <= 0

	for (int i = 0; i <= array_size; ++i)
	{
		fout << array[i] << " ";
	}
	fout << "\n";

	return;
}