#include <iostream>
#include <stdlib.h>
#include <string.h>
#define LENROW 100
#define LENCOL 100
using namespace std;

class Q //Объявление класса Q
{
public:
    int N;
    int M;
    int mas[LENROW][ LENCOL]; //массив слов
public: //Объявление член-функций (методов)
    void Enter(); //Объявление член-функции ввода данных
    void Output(); //Объявление член-функции вывода данных
    int MinElem(int);
    bool MinorNot(int, int);
    void MaxandMin();
    
};    //конец объявления класс Q

int main()
{
    cout<<"\nZadanie 13 : Дана матрица размера M x N. В K-ой строке матрицы найти минимальный элемент. Вывести эту строку и минимальный элемент.\n";
    cout<<"Zadanie 38 : Дана целочисленная матрица размера . Найти элемент, являющийся максимальным в своей строке и минимальным в своем столбце (по условию такие элементы есть в матрице). Вывести этот элемент и столбец, в котором этот элемент расположен.\n";

    Q obj;    //Объявление объекта
    obj.Enter(); //Ввод данных
    obj.Output(); //Вывод данных
    
    cout<<"\n Zadanie 13:\n";
    int K;
    do{
        cout<<"\nВведите К = ";
        cin>>K;
        if (K < 0 || K >= obj.N)
            cout<<"Неверное значение К\n";
    }while(K < 0 || K >= obj.N);
    
    cout<<"В строке ";
    for(int j = 0; j < obj.M; j++)
        cout<<obj.mas[K][j]<<" ";
    cout<<endl<<obj.MinElem(K)<<" - Минимальный элемент\n";
    cout<<"\n Zadanie 38:\n";
    obj.MaxandMin();
    return 0;
}
void Q::Enter() /* отложенное определение член-функции ввода данных*/
{
    do{
    cout<<"\n\nVvedite N = \b";
    cin>>N;
    }while(N<=0);
    do{
        cout<<"\n\nVvedite M = \b";
        cin>>M;
    }while(M<=0);
    
    for(int i=0; i<N; i++)
    {
        for(int j = 0; j < M; j++){
            cout<<"\nVvedile mas["<<(i)<<"]"<<"["<<(j)<<"] = ";
            cin>>mas[i][j];
        }
    }
}

void Q::Output()    /* отложенное определение член-функиия вывода данных */
{
    cout<<"\n\n Vivod massiva :\n";
    for(int i=0;i<N;i++){
        
        for(int j=0;j<M;j++)
            cout<<mas[i][j]<<" ";
        
        putchar('\n');
        
    }
}

int Q:: MinElem(int K)
{
        int min = mas[K][0];
    for (int j = 1; j < M; j++) {
        if (mas[K][j] < min)
            min = mas[K][j];
    }
    return min;
}

bool Q:: MinorNot(int j, int min){
    for (int i = 0; i < N; i++)
        if (mas[i][j] < min)
            return (false);
    return (true);
}

void Q:: MaxandMin(){
    int max;
    int index;
    for (int i = 0; i < N; i++) {
        max = mas[i][0];
        index = 0;
        for (int j = 1; j < M; j++)
            if(mas[i][j] > max){
                max = mas[i][j];
                index = j;
            }
        if(MinorNot(index, max)){
            cout<<"В столбце ";
            for (int i = 0; i < N; i++)
                cout<<mas[i][index]<<" ";
            cout<<"\n число "<<max<<" - искомое число\n";
            return;
        }
    }
}
