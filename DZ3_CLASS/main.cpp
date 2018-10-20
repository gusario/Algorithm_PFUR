//Nurdinov David NI-202
#include <iostream>
#include <stdlib.h>
using namespace std;
#define LEN 100

class Q{ //Объявление класса Q //Объявление член-данных private:
	int mas[LEN];	//массив целых чисел;
	int kol;	//текущий размер массива
	int *mes;
	
	
	//Объявление член-функций (методов)
public:
	void Enter(); //Объявление член-функции ввода
	void Output();//Объявление член-функции вывода
	int check_sort();// Объявление член-функции проверки на отсортировки
	void including();// Задание 16
	void MaxNeigh(int *first, int *second, bool *flag);
	
};	//конец объявления класс Q

int main()
{
	cout<<"Zadanie 16 : Включить заданное число D в массив A( N ) , упорядоченный по возрастанию, с сохранением упорядоченности."<<endl;
	cout<<"Zadanie 41 : Дан массив размера N. Найти два соседних элемента, сумма которых максимальна, и вывести эти элементы в порядке возрастания их индексов."<<endl;
	Q obj;	//Создание объекта
	int first = 0;
	int second = 0;
	bool flag  = true;
	obj.Enter();	//Ввод данных
	obj.Output();	//Вывод данных
		cout <<"\n\n Rezultat:\n";
	cout<<"New masive with D\n";
	obj.including();
	obj.MaxNeigh(&first, &second, &flag);
	if (flag) {
		cout<<"Elems with max sum: "<<first<<" and "<<second<<endl;
	}
	
	
	return 0;
}

void Q::Enter() //функция ввода данных
{
	cout <<"\nVvedite pazmer massiva kol=      \b\b\b";
	/* ввод размера массива */
	cin>>kol;
	cout <<"\nVvedite massive chisel:\n";
	for(int i=0;i<kol;i++) // цикл ввода массива
	{
		cout<<"Vvedite mas["<<(i+1)<<"]=   \b\b\b";
		cin>>mas[i];
		cout <<endl;
	}
}

void Q::Output() /* отложенное определение функции вывода массива о6ъекта   */
{
	cout<<"\n\t Massive:"
	<<"\n\t--------------\n";
	for(int i=0;i<kol;i++)//вывод массива
		cout<<mas[i]<<" ";
	cout<<endl;
}

int Q::check_sort() /* отложенное определение функции проверки на отсортированность*/
{
	for (int i = 0; i < kol - 1; i++) {
		if (mas[i] > mas[i + 1]) {
			return false;
		}
	}
	return true;
}

void Q::including()/* отложенное определение функции добавления D в массив*/
{
	cout<<"Zadanie 16:\n";
	if (!check_sort()) {
		cout<<"Неправильные данные: Массив не отсортирован"<<endl;
		return ;
	}
	if (kol < 0)
	{
		cout<<"Неправильные данные: Массив имеет отрицательное кол-во элементов\n";
		return ;
	}
	int D;
	int i = 0;
	int mem;
	cout<<"Vvedite D = ";
	cin>>D;
	cout<<endl;
	while(mas[i] < D && i < kol)
		i++;
	mem = i;
	kol += 1;
	for (i = kol; i > mem; i--) {
		mas[i] = mas[i - 1];
	}
	mas[mem] = D;
	Output();
}

void Q::MaxNeigh(int *first, int *second, bool *flag)
{
	cout<<"Zadanie 41:\n";
	if (kol < 2)
	{
		cout<<"Некорректные данные: невозможно найти сумму\n";
		*flag = false;
		return ;
	}
	int  sum = mas[0] + mas[1];
	*first = mas[0];
	*second = mas[1];
	for (int i = 1; i < kol - 1; i++) {
		if(mas[i] + mas[i+1] > sum)
		{
			sum = mas[i] + mas[i+1];
			*first = mas[i];
			*second = mas[i + 1];
		}
	}
}
