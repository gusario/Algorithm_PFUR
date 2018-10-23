#include <iostream>
#include <stdlib.h>
#include <string.h>

#define LEN 100

using namespace std;
//Объявление класса Q
class Q
{
    //Объявление член-данных
    int mas[100];    //массив целых чисел
    int kol;    //текущий размер массива
    //Объявление член-функций (методов)
public:
    Q(int, int *); /* объявление конструктора с параметрами */
    void output(); //объявление член-функции вывода
    int funk(int, int);   /*объявление член-функции нахождения максимального элемента массива */
    int SameMax();
};    //конец объявления класс Q
int main(int argc, char *argv[])
{
    cout<<"\nZadanie 23: Дан массив размера N и целые числа K и L (1<=K<=L<=N). Найти сумму всех элементов массива, кроме элементов с номерами от K до L включительно\n";
    cout<<"\nZadanie 48: Дан целочисленный массив размера N. Найти максимальное количество его одинаковых элементов.\n";
    int   n, K, L; // n- текущий размер массива mas
    int m;
    int mas[100];       // массив целых чисел
    /* ввод массива целых чисел для передачи через конструктор в объект  */
    cout<<"\nPlease input array size n=";
    cin>>n;
    cout <<"\nVvod massiva chisel :\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\nVvedite mas["<<(i+1)<<"]=     \b";
        cin>>mas[i];
        cout<<endl;
    }
    Q obj(n, mas);
    obj.output();      //вывод данных
    cout<<"\nZadanie 23:\n";
    do{
        cout<<"Vvedite K = ";
        cin>>K;
    }while(K>n || K<1);
    do{
        cout<<"Vvedite L = ";
        cin>>L;
    }while(L>n-1 || L<K);
    m=obj.funk(K, L);
    cout<<"\n\n Rezuhat:"<<"\n Summa =  " <<m<<"\n\n";
    cout<<"Zadanie 47:\n";
    cout<<" MAx Kol-vo Same elements = "<<obj.SameMax();
    return 0;
}

Q::Q(int size, int *tmp_mas) /* конструктор с параметрами: размер массива и указатель массива   */
{
    kol=size;  // передaча формального массива в массив объекта
    for(int i=0; i<kol; i++)
        mas[i]=tmp_mas[i];
}
void Q::output()    //функция вывода данных
{
    cout <<"\n\t Massive:"
    <<"\n\t    \n";
    for(int i=0; i<kol; i++)
        cout <<mas[i]<<"   ";
}
// отложенное определение функции нахождения max
int Q::funk(int K, int L)
{
    int Sum = 0;
    for(int i=0;i<kol; i++)
        if (i<K || i>L)
            Sum += mas[i];
    return (Sum);    //возврат максимального значения
}

int Q::SameMax(){
    int count = 1;
    int tmp;
    for (int i = 1; i< kol; i++) {
        tmp = 1;
        for (int j = 0; j<i; j++)
            if (mas[j] == mas[i])
                tmp++;
        if(tmp>count)
            count = tmp;
    }
    return count;
}
