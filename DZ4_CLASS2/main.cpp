//Nurdinov David NI-202
#include <iostream>
using namespace std;
#define MaxLEN 100
#define LEN 10

class Q       //Объявление класса Q
{
    //Объявление член-данных
    int mas[MaxLEN];    //массив целых чисел
    int kol;    //текущий размер массива
    //Объявление член-функций (методов)
public:
    void Enter(int, int *); //член-функции ввода данных
    void Output();  //Объявление член-функции вывода данных
    int Funk(); //член-функция нахождения максимального элемента массива
    int DifVal();
    int check_sort();
};
    
    int main()
    {
        Q obj[LEN];    //Создание массива объектов
        int n;    // действительное количество объектов
        int kol;  //текущий размер массива mas объекта
        int otv_mas[LEN];    //массив ответов
        int otv_mas1[LEN];
        int mas[MaxLEN]; // рабочий массив элементов
        
        cout<<"Zadanie 18:\n Дан массив A ненулевых целых чисел размера N. Вывести значение первого из тех его элементов AK, которые удовлетворяют неравенству AK < AN. Если таких элементов нет, то вывести 0\n";
        cout<<"Zadanie 43:\n Дан целочисленный массив размера N, все элементы которого упорядочены (по возрастанию или по убыванию). Найти количество различных элементов в данном массиве\n";
        
        do
        {
            cout<<"\nVvedite kolichestvo objectov ";
            cin>>n;
            
        }while(n <= 0 || n > 10);
        for(int i=0; i<n; i++)  // цикл по объектам
        {
            //ввод рабочего массива чисел для i-гo объекта
            cout<<"\n Vvod ["<<(i+1)<<"] massiva:" <<"\n  ";
            do{
            cout<<"\n\nVvedite pazmer massiva kol= \b\b\b";
            cin>>kol;
            }while(kol <= 0 || kol > 100);
            for(int j=0; j<kol; j++)
            {
                cout<<"\nVvedite mas["<<(j+1) <<"]= \b\b\b";
                cin>>mas[j];
            }
            obj[i].Enter(kol,mas); //передача введенного массива чисел в объект
            obj[i].Output(); // вывод массива текущего объекта
            otv_mas[i]=obj[i].Funk();
            otv_mas1[i] = obj[i].DifVal();
        }
        // цикл вывода максимальных величин по объектам
        cout<<"Zadanie 18";
        for(int j=0;j<n;j++)
            cout<<"\n Rezultat: "<<"\n  first suitable element ["<<(j+1)<<"] massiva paven " <<otv_mas[j];
        cout<<"\nZadanie 43";
        for(int j=0;j<n;j++)
            if(otv_mas1[j] != -1)
            cout<<"\n Rezultat: "<<"\n  Amount of different values ["<<(j+1)<<"] massiva equal " <<otv_mas1[j];
            else
                cout<<"\n Rezultat: "<<"\n  Amount of different values ["<<(j+1)<<"] massiva equal " <<"WRONG DATA!\n";
        return 0;
    }
    // отложенное определение функции ввода данных
    // передача двух параметров: количества и адрес массе им
    void Q::Enter(int kol1, int *p_mas )
    {
        kol=kol1;
        for(int i=0;i<kol;i++)
            mas[i]=p_mas[i];
    }
    // отложенное определение функции вывода данных
    void Q::Output()   //функция вывода данных
    {
        cout <<"\n\t Massive :"<<"\n\t--    \n";
        for(int i=0; i<kol; i++)
            cout<<mas[i]<<"   ";
        cout <<endl;
    }
        // отложенное определение функции вычисления максимума
        int Q::Funk() //функция вычисления max
        {
            for(int i=0; i<kol - 1; i++)
                if (mas[i] < mas[kol - 1])
                    return mas[i];
            return(0);
        }
int Q::DifVal()
{
    if (!check_sort()) {
       // cout<<"Неправильные данные: Массив не отсортирован"<<endl;
        return -1;
    }
    
    int i = 0;
    int count = 0;
    int check;
    bool flag = true;
    for (i = 0; i < kol; i++) {
        check = mas[i];
        for (int j = 0; j < i; j++)
            if (check == mas[j]) {
                flag = false;
                break;
            }
        if (flag) {
            count++;
        }
        flag = true;
    }
    return count;
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


