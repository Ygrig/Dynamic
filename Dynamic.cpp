#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//���������� ������� ���������� ������� � ��������� (�����, ���)
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	arr[i] = rand() % (end - begin) + begin;
}

//����� ������� � �������
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

//������� ������� ��� ������ 1 
template <typename T>
void add_el(T *&arr, const int length, int num) {
	if (num <= 0)
		return;
	T* tmp = new T[length + num]{}; //������� ����� ��������� �� ���.������, ����������� ������ {}
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[]arr; //������� �������� ������ - �� ��� ���������
	arr = tmp; //������������� �������� ��������� �� ������� tmp
}

//������� ������� ��� ������ 2 
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

	//������������ ����������
	/*int* point = new int;// ��������� ������� ������������ ������ �������� � 4 ����� � ������� ��������� new

	*point = 10;
	cout << "point = " << point << '\n';
	cout << "*point = " << *point << '\n';

	delete point; // �������� ������� ������, �� ������� ��������� ���������
	point = nullptr;
	
	if (point != nullptr)
		cout << *point << '\n';
	else
		cout << "��������� ���������.\n";

	point = new int;// ��������� ������ ������� ������
	*point = 15;
	cout << "point = " << point << '\n';
	cout << "*point = " << *point << '\n';

	delete point;
	*/

	//������������ �������
	/*cout << "������� ����� �������: ";
	cin >> n;
	if (n < 0)
		cout << "������! ����� �� ����� ���� �������������.\n";
	else {
		int* mass = new int[n]; //��������� ������������ ������ ��� �������� �������
		srand(time(NULL));
		cout << "������������ ������: \n";
		for (int i = 0; i < n; i++) {
			mass[i] = rand() % 10 + 1;
			cout << mass[i] << ", ";
		}
		cout << "\b\b.\n";
		delete[] mass;
	}
	 */

	//������ 1 ���������� �������

	/*cout << "������ 1 .\n������� ����� �������: \n";
	int size1;
	cin >> size1;
	int* arr1 = new int[size1];
	cout << "����������� ������: \n";
	fill_arr(arr1, size1, 1, 11);//�������� �� ������������ (11 �� ������ � ��������), �� 1 �� 10 - ���� ������� ����� ��������
	show_arr(arr1, size1);

	cout << "������� ���������� ����� ���������:\n";
	cin >> n;

	add_el(arr1, size1, n);
	size1 += n;
	cout << "�������� ������:\n";
	show_arr(arr1, size1);
	*/

	//������ 2 ���������� �������
	cout << "������ 2 .\n������� ����� �������: \n";
	int size2;
	cin >> size2;
	int* arr2 = new int[size2];
	cout << "����������� ������: \n";
	fill_arr(arr2, size2, 1, 11);
	show_arr(arr2, size2);
	cout << "������� ���������� ���������, ������� ���������� ������:\n";
	cin >> n;

	substruct_el(arr2, size2, n);
	size2 -= n;
	cout << "�������� ������:\n";
	show_arr(arr2, size2);


	return 0;
}