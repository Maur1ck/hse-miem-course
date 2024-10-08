#include <stdio.h>
#include <math.h>
#define lmax 200

int main() {
    int n,i,minIndex,offset,k,np;
    float x,h,a,sr,r[lmax];

    printf("Лабораторная работа №1 Мишин Михаил БИТ241\n");
    
    // задание 1----------------------------------------------------------------------------------
    printf("Задание 1, вариант 4\n");
    do {
        printf("Введите длину массива R от 1 до %d: ",lmax);
        scanf("%d",&n);
    } while (n <= 0 || n > lmax);

    printf("Введите x, h, a: ");
    scanf("%f",&x);
    scanf("%f",&h);
    scanf("%f",&a);

    for (i = 1; i <= n; i++) {
        r[i] = 0.3 * cos(2.0*a*x-i*i*h);
    }

    printf("Массив из %d элементов:\n",n);
    for (i = 1; i <= n; i++) {
        printf("%8.3f ",r[i]);
    }
    printf("\n");

    // задание 2------------------------------------------------------------------------------------
    printf("Задание 2, вариант 9\n");

    minIndex = 1;
    for (i = 2; i <= n; i++) {
        if (r[i] < r[minIndex]) {
            minIndex = i;
        }
    }

    printf("Первый минимальный элемент: r[%d] = %8.3f\n", minIndex, r[minIndex]);

    offset = 0;
    for (i = minIndex + 1; i <= n; i++) {
        if (r[i] > 0) {
            offset++;  
        } else {
            r[i-offset] = r[i];  
        }
    }
    k = n - offset;  

    if (k == n) {
        printf("После первого минимального элемента нет положительных элементов\n");
    } else {
        printf("Массив после удаления положительных элементов:\n");
        for (i = 1; i <= k; i++) {
            printf("%8.3f ",r[i]);
        }
        printf("\n");
    }

    // задание 3 ------------------------------------------------------------------------------------------
    printf("Задание 3, вариант 8\n");

    np = 0;
    for (i = 1; i <= k; i++) {
        if (r[i] > 0 && r[i] >= r[np]) np = i;
    }

    if (np == 0) printf("Нет положительного элемента\n");
    else if (np == k) printf("Последний максимальный положительный элемент — последний в массиве, невозможно подсчитать среднее арифметическое\n");
    else {
        sr = 0;
        for(i = np + 1; i <= k; i++) {
            sr+=r[i];
        }
        printf("sr=%8.3f\n",sr/(k-np));
    }
    return 0;
}
