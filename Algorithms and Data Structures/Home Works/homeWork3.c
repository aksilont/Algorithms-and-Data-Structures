//
//  homeWork3.c
//  Algorithms and Data Structures
//
//  Created by Aksilont on 18.09.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "homeWork3.h"
#define ARRAY_SIZE 80

// ----------------------------------------------------------------------------------

void menu(void);
void solution1(void);
void solution2(void);
void solution3(void);

// ----------------------------------------------------------------------------------

void homeWork3(void) {
    srand(time(NULL));
    
    printf("Практическое задание №3\n");
    int sel = 0;
    do {
        printf("Выберите задание\n");
        menu();
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                printf("--------------------\n");
                solution1();
                printf("--------------------\n");
                break;
            case 2:
                printf("--------------------\n");
                solution2();
                printf("--------------------\n");
                break;
            case 3:
                printf("--------------------\n");
                solution3();
                printf("--------------------\n");
                break;
            case 0:
                printf("--------------------\n");
                printf("Завершение работы!\n");
                break;
            default:
                break;
        }
    } while (sel != 0);
}

// ----------------------------------------------------------------------------------

void menu() {
    printf("1 - Задание 1\n");
    printf("2 - Задание 2\n");
    printf("3 - Задание 3\n");
    printf("0 - Выход\n");
}

void print(int *a, int arrSize) {
    int i;
    for (i = 0; i < arrSize; i++) {
        printf("%6i", a[i]);
    }
    printf("\n");
}

void fillRandomArray(int *arr, int arrSize) {
    int i;
    for (i = 0; i < arrSize; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

int *makeRandomArray(int arrSize) {
    int *arr = (int*)malloc(arrSize * sizeof(int));
    int i;
    for (i = 0; i < arrSize; i++) {
        arr[i] = rand() % 100 + 1;
    }
    return arr;
}

int *makeSortedArray(int arrSize, int startValue) {
    int *arr = (int*)malloc(arrSize * sizeof(int));
    int i;
    for (i = 0; i < arrSize; i++) {
        arr[i] = startValue++;
    }
    return arr;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int isArraySorted(int *arr, int arrSize) {
    int i;
    for (i = 0; i < arrSize - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// ----------------------------------------------------------------------------------

// 1. Попробовать оптимизировать пузырьковую сортировку.
// Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
// Написать функции сортировки, которые возвращают количество операций.

int bubleSort(int *arr, int arrSize) {
    int count = 0;
    int i, j;
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < arrSize - 1; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return count;
}

int bubleSortOptimized(int *arr, int arrSize) {
    if (isArraySorted(arr, arrSize)) {
        return 0;
    }
    
    int count = 0;
    int i, j;
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < arrSize - 1 - i; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return count;
}

void solution1() {
    int *arr;
    int count = 0;
    
    //arr = makeSortedArray(ARRAY_SIZE, 40);
    arr = makeRandomArray(ARRAY_SIZE);
    printf("----------      ПУЗЫРЬКОВАЯ СОРТИРОВКА (НЕ ОПТИМИЗИРОВАНА)      ----------\n");
    printf("До сортировки: \n");
    print(arr, ARRAY_SIZE);
    count = bubleSort(arr, ARRAY_SIZE);
    printf("После сортировки: \n");
    print(arr, ARRAY_SIZE);
    printf("Количество проходов = %6d\n", count);
    printf("--------------------------------------------------------------------------\n");
    
    //arr = makeSortedArray(ARRAY_SIZE, 40);
    arr = makeRandomArray(ARRAY_SIZE);
    printf("----------      ПУЗЫРЬКОВАЯ СОРТИРОВКА (ОПТИМИЗИРОВАННАЯ)      -----------\n");
    printf("До сортировки: \n");
    print(arr, ARRAY_SIZE);
    count = bubleSortOptimized(arr, ARRAY_SIZE);
    printf("После сортировки: \n");
    print(arr, ARRAY_SIZE);
    printf("Количество проходов = %6d\n", count);
    printf("---------------------------------------------------------------------------\n");
    
    free(arr);
}

// ----------------------------------------------------------------------------------

//2. *Реализовать шейкерную сортировку.

int shakerSort(int *arr, int arrSize) {
    if (isArraySorted(arr, arrSize)) {
        return 0;
    }
    
    int count = 0;
    int i, j;
    int startIndex = 0;
    int endIndex = arrSize - 1;
    for (i = 0; i < arrSize; i++) {
        if (i % 2) {
            for (j = startIndex; j < endIndex; j++) {
                count++;
                if (arr[j] > arr[j + 1]) {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
            endIndex--;
        } else {
            for (j = endIndex; j > startIndex; j--) {
                count++;
                if (arr[j] < arr[j - 1]) {
                    swap(&arr[j], &arr[j - 1]);
                }
            }
            startIndex++;
        }
    }
    return count;
}

void solution2() {
    int *arr = makeRandomArray(ARRAY_SIZE);
    int count = 0;
    
    printf("До сортировки: \n");
    print(arr, ARRAY_SIZE);
    count = shakerSort(arr, ARRAY_SIZE);
    printf("После сортировки: \n");
    print(arr, ARRAY_SIZE);
    printf("Количество проходов = %6d\n", count);
    if (isArraySorted(arr, ARRAY_SIZE)) {
        printf("Массив успешно отсортирован\n");
    }
    free(arr);
}

// ----------------------------------------------------------------------------------

// 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
// Функция возвращает индекс найденного элемента или -1, если элемент не найден.

int findValueByBinaryMethod(int *arr, int arrSize, int value) {
    int L = 0, R = arrSize - 1;
    int m = L + (R - L) / 2;
    
    while(L <= R && arr[m] != value)
    {
        if (arr[m] < value) {
            L = m + 1;
        } else {
            R = m - 1;
        }
        m = L + (R - L) / 2;
    }
    
    if (arr[m] == value) {
        return m;
    } else {
        return -1;
    }
}

void solution3() {
    int *arr = makeSortedArray(ARRAY_SIZE, 16);
    print(arr, ARRAY_SIZE);
    
    int value;
    printf("Введите целое число для поиска в массиве:");
    scanf("%i", &value);
    
    int findingIndex = findValueByBinaryMethod(arr, ARRAY_SIZE, value);
    if (findingIndex != -1) {
        printf("Значение %d находится в массиве под индексом %d\n", value, findingIndex);
    } else {
        printf("Значение %d не содержится в массиве\n", value);
    }
    free(arr);
}

// ----------------------------------------------------------------------------------

