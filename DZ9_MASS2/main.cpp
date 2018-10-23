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
    double funk(int, int);   /*объявление член-функции нахождения максимального элемента массива */
    int diff();
};    //конец объявления класс Q
int main(int argc, char *argv[])
{
    cout<<"\nZadanie 22: Дан массив размера N и целые числа K и L (1<=K<=L<=N). Найти среднее арифметическое элементов массива с номерами от K до L включительно.\n";
    cout<<"\nZadanie 47: Дан целочисленный массив размера N. Найти количество различных элементов в данном массиве.\n";
    int   n, K, L; // n- текущий размер массива mas
    double m;
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
    cout<<"Zadanie 22:\n";
    do{
        cout<<"Vvedite K = ";
        cin>>K;
    }while(K>n || K<1);
    do{
        cout<<"Vvedite L = ";
        cin>>L;
    }while(L>n-1 || L<K);
    m=obj.funk(K, L);    //нахождение max элемента массива
    cout<<"\n\n Rezuhat:"<<"\n Srednee Arifmet =  " <<m<<"\n\n";
    cout<<"Zadanie 47:\n";
    cout<<"Kol-vo different elements = "<<obj.diff();
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
double Q::funk(int K, int L)
{
    double Sum = 0;
    for(int i=K;i<=L; i++)
        Sum += mas[i];
    cout<<Sum<<endl;
    return (Sum/(L - K + 1));    //возврат максимального значения
}

int Q::diff(){
    int count = 1;
    bool flag;
    for (int i = 1; i< kol; i++) {
        flag = true;
        for (int j = 0; j<i; j++)
            if (mas[j] == mas[i])
                flag = false;
        if(flag)
            count++;
    }
    return count;
}
