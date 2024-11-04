// lab2proga.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <ctime>
void vvodkolodi(int arr[]) {
    int p;
    p = 1;
    
    for (int i = 0; i < 11; i++) {
        arr[i] = p;
        p += 1;
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


void rukastart(int* score, int rand) {
    *score = *score + rand;
}

int main()
{
    int arr[12], ri, n, opsc, mysc;
    char ch;
    opsc = 0;
    mysc = 0;
    n = 11;
    vvodkolodi(arr);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]); 
    ri = viborkarti(arr, &n);
    rukastart(&opsc, ri);
    ri = viborkarti(arr, &n);
    rukastart(&opsc, ri);
    printf("\n%d\n",opsc);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    ri = viborkarti(arr, &n);
    rukastart(&mysc, ri);
    ri = viborkarti(arr, &n);
    rukastart(&mysc, ri);
    printf("\n%d\n", mysc);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
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
