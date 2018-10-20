#include <iostream>
using namespace std;
class Q //Объявление класcа Q
{    //Объявление член-данных
private:
    int mas[100];    //массив целых чисел
    int kol;    //текущий размер массива
    //Объявление член-функций (методов)
public:
    void Enter(); //Объявление член-функции ввода данных
    void output(); //Обьявление член-функции вывода данных
    int *funk(int*); //объявление член-функции упорядочивания всех четных элементов массива   */
    int *ModCheck(int, int *);
    
};    //конец объявления класс Q
    
    int main()
    {
        cout<< "Zadanie 15: Дан массив A ненулевых целых чисел размера N. Переместить в начало массива значения тех его элементов AK, которые удовлетворяют неравенству AK < AN. \n";
        cout<< "Zadanie 40: Дан массив. Образовать новый массив, состоящий из элементов исходного, заканчивающихся на заданную цифру k. \n";
        Q obj; // Объявление объекта
        int *p_k;
        int i; // указатель на массив объекта для вывода результата
        int n; // размер распечатаемого массива в объекте
        obj.Enter(); // ввод данных в объект
        obj.output();    //Вывод данных   obj
        p_k=obj.funk(&n); //сортировка четных элементов массива
        cout<<"Zadanie 15:\n";
        cout<<"\n\nYporaydocheny massiv obj\n";
        for (i=0; i<n; i++)
            cout<<p_k[i]<<"   ";// печать массива;
        cout<<endl;
        cout<<"\nZadanie 40:\n";
        int k;
        cout<<"Vvedite K = ";
        cin>>k;
        cout<<endl;
        p_k = obj.ModCheck(k, &n);
        cout<<"\nNew massiv obj\n";
        for (i=0; i<n; i++)
            cout<<p_k[i]<<"   ";// печать массива;
        return 0;
    }
    
    void Q::Enter() // отложенное опр-ние функции ввода данных
    {
        
        do{
            cout <<"\nVvedite pazmer massiva kol=       \b\b\b\b";
            cin >>kol;
            
        } while(kol <= 0);
        cout <<"\nVvedite massive:\n";
        for(int i=0;i<kol;i++){
            cout <<"Vvedite mas["<<(i+1)<<"]=    \b\b\b\b";
            cin >>mas[i];
            cout <<endl;
            
        }
    }
    
    void Q::output()
    {
        cout <<"\n\t Massive:" <<"\n\t    \n";
        for(int i=0; i<kol; i++)
            cout <<mas[i] <<"   ";
        cout <<endl;
    }

int *Q::funk(int* n1)
{
    *n1 = kol;
    int i = 0;
    int j = 0;
    int tmp;
    for (i = 1;i < kol - 1; i++)
        if (mas[i] < mas[kol - 1]) {
            tmp = mas[i];
            for (j = i; j >0; j--)
                mas[j] = mas[j - 1];
            mas[0] = tmp;
        }
    return(mas);
}

int *Q::ModCheck(int k, int *n)
{
    int count = 0;
    int i = 0;
    int j = 0;
    int numcol = 0;
    int *newMas;
    int k1 = k;
    
    while(k1)
    {
        k1 /=10;
        numcol++;
    }
    newMas = (int*)malloc(sizeof(int) * kol);
    for (i = 0; i < kol; i++)
        if (mas[i] % (10*numcol) == k)
        {
            newMas[j] = mas[i];
            j++;
            count++;
        }
    *n = count;
    return (newMas);
}
