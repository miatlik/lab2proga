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
    int ri, randc;
    ri = rand() % *size;
    randc = arr[ri];
    for (int i = ri; i < *size - 1; i++) arr[i] = arr[i + 1];
            (*size)--;   
    return randc;
}
void rukamy(int score[], int arr[], int *size) {
    score[t1] = viborkarti(arr, size);
    t1++;
    
}
void rukabota(int score[], int arr[], int *size) {
    int ri;
    ri = viborkarti(arr, size);
    score[t2] = ri;
    t2++;
}
void vivodrukamy(int mysc[],int sum) {
    printf("\nМои карты: ");
    for (int i = 0; i < t1; i++)
        printf("%d, ", mysc[i]);
    for (int i = 0; i < t1; i++)
        sum += mysc[i];
    printf("%d/21", sum);
    sum = 0;
}
void vivodrukabota(int opsc[], int sum) {
    printf("\nКарты противника: ?,  ");
    for (int i = 1; i < t2; i++)
        printf("%d, ", opsc[i]);
    for (int i = 1; i < t2; i++)
        sum += opsc[i];
    printf("?+%d/21", sum);
    sum = 0;
}
void vivodreza(int mysc[], int opsc[]) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < t1; i++)
        sum1 += mysc[i];
    for (int i = 0; i < t2; i++)
        sum2 += opsc[i];
    if (sum1 > 21 && sum2 < 22) printf("У вас перебор. Вы проиграли\n");
    if (sum2 > 21 && sum1 < 22) printf("У противника перебор. Вы выиграли\n");
    if (sum1 > 21 && sum2 > 21 && sum1 < sum2) printf("У вас и противника перебор.Вы выиграли, так как имеете меньше очков\n");
    if (sum1 > 21 && sum2 > 21 && sum1 > sum2) printf("У вас и противника перебор.Вы проиграли, так как имеете больше очков\n");
    if (sum1 < 22 && sum2 < 22 && sum1 < sum2) printf("Вы проиграли. Противник ближе к 21 очку\n");
    if (sum1 < 22 && sum2 < 22 && sum1 > sum2) printf("Вы выиграли. Вы ближе к 21 очку\n");
    if (sum1 == sum2) printf("Ничья\n");
}
int reshenie_ai(int opsc[]) {
    int sum = 0, randbot = 1;
    for (int i = 0; i < t2; i++)
        sum += opsc[i];
    if (sum < 17) randbot = 0;
    return randbot;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    char ch;
    do{
    int arr[11], n, opsc[10], mysc[10], sum, f1 = 1, f2 = 1, take, per = 0;
    t1 = 0;
    t2 = 0;
    srand(time(NULL));
    sum = 0;
    n = 11;
    vvodkolodi(arr);
    printf("\n");
    rukamy(mysc, arr, &n);
    rukamy(mysc, arr, &n);
    rukabota(opsc, arr, &n);
    rukabota(opsc, arr, &n);
    vivodrukamy(mysc, sum);
    vivodrukabota(opsc, sum);
    while (f1 == 1 || f2 == 1) {
        if (f1 == 1) {
            printf("\nНажмите 1, чтобы тянуть карту\n");
            printf("Нажмите 2, чтобы спасовать\n");
            while (scanf("%d", &take) != 1 || take < 1 || take >2) {
                while (getchar() != '\n'); printf("Ошибка. Выберите 1 или 2: ");
            }
            while (getchar() != '\n');
            for (int i = 0; i < t1; i++)
                sum += mysc[i];
            if (sum > 21) per = 1;
            sum = 0;
            if (take == 1) {
                if (per == 0) rukamy(mysc, arr, &n);
                else printf("Нельзя брать карту при переборе\n");
            }
            else {
                printf("Вы спасовали");
                f1 = 0;
            }
        }
        reshenie_ai(opsc);
        if (reshenie_ai(opsc) == 0 && f2 == 1) rukabota(opsc, arr, &n);
        if (reshenie_ai(opsc) == 1 && f2 == 1) {
            printf("\nПротивник спасовал");
            f2 = 0;
        }
        vivodrukamy(mysc, sum);
        if (f1 == 1) {
            vivodrukabota(opsc, sum);
        }
        else {
            printf("\nКарты противника: ");
            for (int i = 0; i < t2; i++)
                printf("%d, ", opsc[i]);
            for (int i = 0; i < t2; i++)
                sum += opsc[i];
            printf("%d/21", sum);
            sum = 0;
            printf("\n");
        }
        if (f1 == 0 && f2 == 0) vivodreza(mysc, opsc);
    }
    puts("\nНажмите q, чтобы выйти или любую другую клавишу, чтобы сыграть заново\n\n");
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
