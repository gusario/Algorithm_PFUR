//Nurdinov David NI-202
#include <iostream>
#include <math.h>
using namespace std;

/*Zadanie 14: Дан целочисленный массив A размера N. Вывести порядковый номер последнего из тех его элементов AK, которые удовлетворяют двойному неравенству A1 < AK < AN. Если таких элементов нет, то вывести 0. Вывести произведение чисел от первого элемента до числа  AK  или ноль соответственно.*/

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
    void MinDiffer(int, int*, int *, bool *);
}; //конец объявления класса

//основная программа
int main()
{
    cout<<"Zadanie 14:\n Дан целочисленный массив A размера N. Вывести порядковый номер последнего из тех его элементов AK, которые удовлетворяют двойному неравенству A1 < AK < AN. Если таких элементов нет, то вывести 0. Вывести произведение чисел от первого элемента до числа  AK  или ноль соответственно. \n";
     cout<<"Zadanie 39:\n Дано число R и массив размера N. Найти два соседних элемента массива, сумма которых наиболее близка к числу R, и вывести эти элементы в порядке возрастания их индексов (то есть такой элемент AK, для которого величина |AK – R| является минимальной). \n";
    
    int correct_ans;
    
    bool flag = false;
    Q obj;    //создание объекта
    obj.Еnter();//ввод данных в объект
    obj.Output();// вывод данных объекта
    cout<<"\nZadanie 14:\n";
    int summ=obj.Funk(&correct_ans, &flag);
    if(!flag)
        summ = 0;
    cout <<"Proizved = "<<summ;
    if (flag)
        cout<<"\nlast right index = "<<correct_ans<<endl;
    else
        cout<<"\nright index = Not exist!\n";
    
    cout<<"\nZadanie 39:\n";
    flag = true;
    int R;
    int first;
    int second;
    cout<<"Vvedite R ";
    cin>>R;
    obj.MinDiffer(R, &first, &second, &flag);
    if(flag)
        cout<<"Closest sum to R with "<<first<<" and "<<second<<endl;
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
/*ZAdanie 14*/
int Q::Funk(int *right_ans, bool *flag)
{
    int sum=1;
    for(int i = 1; i <kol;i++)
        if(mas[i] > mas[0] && mas[i] < mas[kol - 1]){
            *right_ans = i;
            *flag = true;
        }
    for(int i = 0; i < *right_ans; i++)
        sum*=mas[i];
    return (sum);
}
/*Zadanie 39*/
void Q::MinDiffer(int R,int *first, int *second, bool *flag)
{
    if (kol < 2)
    {
        cout<<"Некорректные данные: невозможно найти результат\n";
        *flag = false;
        return ;
    }
    int  sum = mas[0] + mas[1];
    *first = mas[0];
    *second = mas[1];
   for (int i = 1; i < kol - 1; i++) {
        if(abs(R - (mas[i] + mas[i+1])) < abs(R - sum))
        {
            sum = mas[i] + mas[i+1];
            *first = mas[i];
            *second = mas[i + 1];
        }
    }
}
