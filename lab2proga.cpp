// lab2proga.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <ctime>
int t1=0, t2=0;
void vvodkolodi(int arr[]) {
    for (int i = 0; i < 11; i++) {
        arr[i] = i+1;
    }
}
int viborkarti(int arr[], int *size){
    int ri, randc, i, j;
    ri = rand() % *size;
    randc = arr[ri];
    for (int i = ri; i < *size - 1; i++) arr[i] = arr[i + 1];
            (*size)--;   
    return randc;
}


void rukamy(int score[], int arr[], int *size) {
    int ri;
    score[t1] = viborkarti(arr, size);
    t1++;
    
}
void rukabota(int score[], int arr[], int *size) {
    int ri;
    ri = viborkarti(arr, size);
    score[t2] = ri;
    t2++;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int arr[11], ri1, ri2, ri3, ri4, n, opsc[10], mysc[10], i=0;
    char ch;
    srand(time(NULL));
    n = 11;
    vvodkolodi(arr);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    rukamy(mysc, arr,&n);
    rukamy(mysc, arr, &n);
    rukabota(opsc, arr, &n);
    rukabota(opsc, arr, &n);
    for (i = 0; i < t1; i++)
        printf("%d ", mysc[i]);
    printf("\n");
    for (i = 0; i < t2; i++)
        printf("%d ", opsc[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("%d", n);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
