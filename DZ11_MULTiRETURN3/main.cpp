#include <iostream>
#include <stdlib.h>
#include <string.h>
#define LEN 100
using namespace std;
class Q    //Объявление клаcса Q
{
private:    //Объявление член-данных
    int mas[LEN];        //массив целых чисел
    int kol;    //текущий размер массива
public:    //Объявление член-функций (методов)
    Q();    //объявление конструктора без параметров
    Q(int, int[]); // //объявление конструктора с 2-мя параметрами
    void Output(); //объявление член-функция вывода данных
    int Funk(int *);   /* объявление член-функции подсчета количества четных чисел и их суммы */
    int Hardsolve(int*);
};
int main(int argc, char *argv[])
{
    cout<<"\nZadanie 24:Дан массив A размера N. Найти максимальный элемент M из его элементов с нечетными номерами: A1, A3, A5, … . Вывести M и его индекс.\n";
    cout<<"\nZadanie 49:  Дан целочисленный массив размера N. Найти количество противоположных элементов в данном массиве и их произведение или выведите (0,1), если таких элементов нет.\n";
    // обработка первого объекта
    cout<< "\nObrabotka pervogo obekta";
    Q obj; /* инициализация объекта с помощью конструктора без параметров */
    obj.Output();     //вывод данных
    int chet=0;
    int summ=obj.Funk(&chet);   /* вычисление кол-ва четных чисел и их суммы */
    cout<<"\nZadanie 24\n";
    cout<<"\nindex  = "<<summ<<endl;
    cout<<"max with nechet index="<<chet;
    cout <<endl;
    cout<<endl;
    cout<<"\nZadanie 49\n";
    int counter;
    int rec = obj.Hardsolve(&counter);
    if (!counter)
        cout<<"(0,1)\n";
    else
        cout<<"kol-vo protivop elem = "<<counter<<endl<<"Proizved etih elementov = "<<rec<<endl;
    // обработка второго объекта
    cout<<"\nObrabotka vtorogo obekta";
    // ввод данных для передачи во второй объект
    int masiv[10]; // определение массива
    int n;        // размер массива
    cout<<"\nVvedite razmer massiva kol ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Wvedite masiv["<<(i+1)<<"]= ";
        cin>>masiv[i];
    }
    
    Q obj1(n,masiv);//инициализация объекта с помощью //конструктора с параметрами - передача введенного массива
    obj1.Output();    //вывод данных по второму объекту
     cout<<"\nZadanie 24\n";
    summ=obj1.Funk(&chet);   //вычисление кол-ва четных
    // чисел и их суммы
    cout<<"\n index =  "<<summ <<"\nmax with nechet index "<<chet;
    cout<<endl;
    cout<<endl;
    cout<<"\nZadanie 49\n";
    rec = obj1.Hardsolve(&counter);
    if (!counter)
        cout<<"(0,1)\n";
    else
        cout<<"kol-vo protivop elem = "<<counter<<endl<<"Proizved etih elementov = "<<rec<<endl;
    return 0;
}

Q::Q()    //Конструктор  без параметров
{
    cout <<"\nVvedite razmer massiva kol= ";
    cin>>kol;
    for(int i=0;i<kol;i++)
    {
        cout<<"Wvedite mas["<<(i+1)<<"]= "; cin>>mas[i];
    } }
// отложенное определение конструктора с параметрами
Q::Q(int m,int x[])
{ kol=m;
    for(int i=0;i<kol;i++)
    { mas[i]=x[i];
    }
}   // конец конструктора
//отложенное определение функции вывода массива объекта
void Q::Output()
{
    cout <<"\n\t Massive:"<<"\n\n";
    for(int i=0;i<kol;i++)
        cout<<mas[i]<<"   ";
}
/*отложенное определение функции подсчета кол-ва четных
 чисел и их суммы */
int Q::Funk(int *max)
{
    int index=1;
    *max=mas[1];
    for(int i=3;i<kol; i+=2)
        if(mas[i]>*max) {
            *max = mas[i];
            index = i;
        }
    return (index) ; //Возврат в вызвавшую функцию суммы четных чисел
}

int Q::Hardsolve(int *count)
{
    bool maser[kol];
    bool flag;
    int sum = 1;
    *count = 0;
    for (int i = 0; i < kol; i++)
        maser[i] = false;
    for (int i = 0; i < kol; i++)
    {
        flag = false;
        for (int j = i+1; j<kol; j++)
        {
            if ((mas[i]+mas[j]) == 0)
            {
                flag = true;
                maser[j] = true;
            }
        }
        if(flag)
        {
            maser[i] = true;
        }
    }
    for (int i = 0; i < kol; i++) {
        if (maser[i]){
            sum *= mas[i];
           *count = *count + 1;
        }
        cout<<maser[i]<<" ";
    }
    cout<<endl;
    return(sum);
}
