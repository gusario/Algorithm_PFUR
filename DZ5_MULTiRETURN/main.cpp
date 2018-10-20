//Nurdinov David NI-202
#include <iostream>
using namespace std;

/*Zadanie 13: Дан массив размера N. Найти минимальный из его локальных максимумов. Вывести ноль или сумму элементов до этого максимума соответственно.*/

/*Zadanie 38: Дан массив размера N. Найти два соседних элемента, сумма которых максимальна, и вывести эти элементы в порядке возрастания их индексов*/

class Q //Объявление класcа Q
{
    //Объявление член-данных
private:
    int mas[100]; //массив целых чисел
    int kol; //текущий размер массива
    //Объявление член-функций (методов)
public:
    void Еnter();//объявление член-функция ввода данных
    void Output(); //объявление член-функция вывода данных
    int Funk(int *, bool *);
    void MaxNeigh(int*, int *, bool *);
}; //конец объявления класса

//основная программа
int main()
{
    cout<<"Zadanie 13:\n Дан массив размера N. Найти минимальный из его локальных максимумов. Вывести ноль или сумму элементов до этого максимума соответственно.\n";
    cout<<"Zadanie 38:\n Дан массив размера N. Найти два соседних элемента, сумма которых максимальна, и вывести эти элементы в порядке возрастания их индексов.\n";

    
    int loc_max = -32568;// результат - кол-во четных чисел
    bool flag = false;
    int first, second;
    Q obj;    //создание объекта
    obj.Еnter();//ввод данных в объект
    obj.Output();// вывод данных объекта
    cout<<"\nZadanie 13:\n";
    int summ=obj.Funk(&loc_max, &flag);/*вычисление кол-ва четных чисел и их суммы*/
    cout <<"Summs do local max = "<<summ;
    if (flag)
        cout<<"\nbiggest local max = "<<loc_max<<endl;
    else
    cout<<"\nLocal max = Not exist!\n";
    cout<<"\nZadanie 38:\n";
    flag = true;
    obj.MaxNeigh(&first, &second, &flag);
    if(flag)
        cout<<"Max sum pri: "<<first<<" and "<<second<<endl;
    return 0;
    }
    void Q::Еnter() // отложенное описание функции ввода
    {//ввод размера массива
        do{
        cout <<"\nVvedite razmer massive kol=\b";
            cin>>kol;
        }while(kol <= 0 || kol > 100);
        
        for(int i=0;i<kol;i++)
        {
            cout<<"Vvedite mas["<<(i+1)<<"]    \b\b\b";
            cin>>mas[i];
        }
    }
    
    void Q::Output() /*отложениое описание функции вывода
                      данных объекта */
    {
        cout <<"\n\t Massive:" <<"\n\t    \n";
        for(int i=0;i<kol;i++)
            cout <<mas[i]<<"   ";
    }
    
    int Q::Funk(int *loc_max, bool *flag)
    {
        int sum=0;
        int c = 0;
        for(int i = 1; i <kol - 1;i++)
            if(mas[i] > mas[i - 1] && mas[i] > mas[i + 1] && mas[i] > *loc_max){
                *loc_max = mas[i];
                *flag = true;
                c = i;
            }
        for(int i = 0; i < c; i++)
            sum+=mas[i];
        return (sum);
    }
    void Q::MaxNeigh(int *first, int *second, bool *flag)
    {
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
