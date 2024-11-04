// lab2proga.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <ctime>
void vvodkolodi(int arr[]) {
    int p, c;
    p = 6;
    c = 0;
    for (int i = 0; i < 24; i++) {
        arr[i] = p;
        c += 1;
        if (c == 4) { c = 0; p += 1; }
    }
    p = 1;
    c = 0;
    for (int i = 24; i < 36; i++) {
        arr[i] = p;
        c += 1;
        if (c == 4) { c = 0; p += 1; }
    }
}
int viborkarti(int arr[], int *size){
    int ri, randc, i, j;
    srand(time(NULL));
    ri = rand() % *size;
    randc = arr[ri];
    for (i = 0; i < *size; i++) {
        if (arr[i] == randc) {
            for (j = i; j < *size - 1; j++) arr[j] = arr[j + 1];
            (*size)--;
            break;
        }
    }
    return randc;
}

int main()
{
    int arr[36], ri, n;
    char ch;
    n = 36;
    vvodkolodi(arr);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]); 
    do {
    ri = viborkarti(arr,&n);
    printf("\n%d\n", ri);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    } while ((ch = _getch()) != 'q');
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
