#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Заполнение массива случайными числами в диапазоне (бегин, енд)
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	arr[i] = rand() % (end - begin) + begin;
}

//Вывод массива в консоль
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

//Создаем функцию для Задачи 1 
template <typename T>
void add_el(T *&arr, const int length, int num) {
	if (num <= 0)
		return;
	T* tmp = new T[length + num]{}; //создаем новый указатель на нов.массив, заполненный нулями {}
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[]arr; //удалили исходный массив - мы его почистили
	arr = tmp; //перенаправили исходный указатель на область tmp
}

//Создаем функцию для Задачи 2 
template <typename T>
void substruct_el(T*& arr, const int length, int num) {
	if (num <= 0)
		return;
	if (num > length) {
		delete[]arr;
		arr = new int[0];
		return;
	}
	
	T* tmp = new T[length - num]; 
	for (int i = 0; i < (length-num); i++)
		tmp[i] = arr[i];
	delete[]arr; 
	arr = tmp;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//Динамические переменные
	/*int* point = new int;// выделение участка динамической памяти размером в 4 байта с помощью оператора new

	*point = 10;
	cout << "point = " << point << '\n';
	cout << "*point = " << *point << '\n';

	delete point; // очищение области памяти, на которую направлен указатель
	point = nullptr;
	
	if (point != nullptr)
		cout << *point << '\n';
	else
		cout << "Указатель нейтрален.\n";

	point = new int;// выделение нового участка памяти
	*point = 15;
	cout << "point = " << point << '\n';
	cout << "*point = " << *point << '\n';

	delete point;
	*/

	//Динамические массивы
	/*cout << "Введите длину массива: ";
	cin >> n;
	if (n < 0)
		cout << "Ошибка! Длина не может быть отрицательной.\n";
	else {
		int* mass = new int[n]; //выделение динамической памяти для хранения массива
		srand(time(NULL));
		cout << "Динамический массив: \n";
		for (int i = 0; i < n; i++) {
			mass[i] = rand() % 10 + 1;
			cout << mass[i] << ", ";
		}
		cout << "\b\b.\n";
		delete[] mass;
	}
	 */

	//Задача 1 Увеличение массива

	/*cout << "Задача 1 .\nВведите длину массива: \n";
	int size1;
	cin >> size1;
	int* arr1 = new int[size1];
	cout << "Изначальный массив: \n";
	fill_arr(arr1, size1, 1, 11);//диапазон не включительно (11 не входит в диапазон), от 1 до 10 - сами выбрали такой диапазон
	show_arr(arr1, size1);

	cout << "Введите количество новых элементов:\n";
	cin >> n;

	add_el(arr1, size1, n);
	size1 += n;
	cout << "Итоговый массив:\n";
	show_arr(arr1, size1);
	*/

	//Задача 2 Уменьшение массива
	cout << "Задача 2 .\nВведите длину массива: \n";
	int size2;
	cin >> size2;
	int* arr2 = new int[size2];
	cout << "Изначальный массив: \n";
	fill_arr(arr2, size2, 1, 11);
	show_arr(arr2, size2);
	cout << "Введите количество элементов, которое необходимо убрать:\n";
	cin >> n;

	substruct_el(arr2, size2, n);
	size2 -= n;
	cout << "Итоговый массив:\n";
	show_arr(arr2, size2);


	return 0;
}