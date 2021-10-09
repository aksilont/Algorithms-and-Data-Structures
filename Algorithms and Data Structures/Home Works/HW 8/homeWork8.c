//
//  homeWork8.c
//  Algorithms and Data Structures
//
//  Created by Aksilont on 08.10.2021.
//

#include <time.h>
#include "homeWork8.h"

// ----------------------------------------------------------------------------------

void menu(void);
void solution1(void);
void solution2(void);
void solution3(void);

// ----------------------------------------------------------------------------------

void homeWork8(void) {
    srand(time(NULL));
    
    printf("Практическое задание №8\n");
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
    char *ask;
    
    ask = "Реализовать сортировку подсчетом";
    printf("1 - %s\n", ask);
    
    ask = "Реализовать быструю сортировку";
    printf("2 - %s\n", ask);
    
    ask = "Реализовать сортировку слиянием";
    printf("3 - %s\n", ask);
    
    printf("0 - Выход\n");
}

// ----------------------------------------------------------------------------------

int *makeRandomArray(int arrSize, int min, int max) {
    int *arr = (int*)malloc(arrSize * sizeof(int));
    int i;
    for (i = 0; i < arrSize; i++) {
        arr[i] = rand() % (max - min) + min;
    }
    return arr;
}

void printArr(int *arr, int arrSize) {
    for (int i = 0; i < arrSize; i++)
    {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}

// ----------------------------------------------------------------------------------
// 1. Реализовать сортировку подсчетом

void countingSort(int arrSize, int arr[arrSize], int maxValue) {
    int i, j;
    int *countingArr = (int *)malloc(maxValue * sizeof(int));
    
    for (i = 0; i < maxValue; i++)
        countingArr[i] = 0;
    
    int currentValue = 0;
    for (i = 0; i < arrSize; i++) {
        currentValue = arr[i];
        countingArr[currentValue]++;
    }
    
    printf("Частотный массив значений:\n");
    printArr(countingArr, maxValue);
    
    int position = 0;
    for (j = 0; j < maxValue; j++)
        for (i = 0; i < countingArr[j]; i++) {
            arr[position] = j;
            position++;
        }
    
    free(countingArr);
}

void solution1(void) {
    int arrSize = 15;
    int minValue = 0;
    int maxValue = 30;
    int *arr = makeRandomArray(arrSize, minValue, maxValue);
    
    printf("Сортировка подсчетом\n");
    
    printf("До сортировки:\n");
    printArr(arr, arrSize);
    
    countingSort(arrSize, arr, maxValue);
    
    printf("После сортировки:\n");
    printArr(arr, arrSize);
    
    free(arr);
}

// ----------------------------------------------------------------------------------
// 2. Реализовать быструю сортировку

void quickSort(int *numbers, int left, int right) {
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];

    while (left < right) {
        while ((numbers[right] >= pivot) && (left < right)) {
            right--;
        }
            
        if (left != right) {
            numbers[left] = numbers[right];
            left++;
        }

        while ((numbers[left] <= pivot) && (left < right)) {
            left++;
        }
            
        if (left != right) {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) {
        quickSort(numbers, left, pivot - 1);
    }
        
    if (right > pivot) {
        quickSort(numbers, pivot + 1, right);
    }
}

void solution2(void) {
    int arrSize = 100;
    int minValue = -500;
    int maxValue = 500;
    int *arr = makeRandomArray(arrSize, minValue, maxValue);
    
    printf("Быстрая сортировка\n");
    
    printf("До сортировки:\n");
    printArr(arr, arrSize);
    
    quickSort(arr, 0, arrSize - 1);
    
    printf("После сортировки:\n");
    printArr(arr, arrSize);
    
    free(arr);
}

// ----------------------------------------------------------------------------------
// 3. Реализовать сортировку слиянием

void mergeSort(int *arr, int startIndex, int endIndex) {
    // границы сомкнулись, т.е. в группе остался 1 элемент -> выходим
    if (startIndex == endIndex) return;
    
    // определяем середину последовательности
    int mid = (startIndex + endIndex) / 2;
    
    // и рекурсивно вызываем функцию сортировки для каждой половины
    mergeSort(arr, startIndex, mid);
    mergeSort(arr, mid + 1, endIndex);
    
    // начало первого пути
    int firstWay = startIndex;
    // начало второго пути
    int secondWay = mid + 1;
    
    // дополнительный массив
    int *tmpArr = (int*)malloc(endIndex * sizeof(int));
    
    int i;
    // для всех элементов дополнительного массива
    for (i = 0; i < endIndex - startIndex + 1; i++) {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути, если secondWay > endIndex
        if ((secondWay > endIndex) || ((firstWay <= mid) && (arr[firstWay] < arr[secondWay]))) {
            tmpArr[i] = arr[firstWay];
            firstWay++;
        } else {
            tmpArr[i] = arr[secondWay];
            secondWay++;
        }
    }
    
    // переписываем сформированную последовательность в исходный массив
    for (int i = 0; i < endIndex - startIndex + 1; i++)
        arr[startIndex + i] = tmpArr[i];
    
    free(tmpArr);
}

void solution3(void) {
    int arrSize = 30;
    int minValue = -50;
    int maxValue = 50;
    int *arr = makeRandomArray(arrSize, minValue, maxValue);
    
    printf("Сортировка слиянием\n");
    
    printf("До сортировки:\n");
    printArr(arr, arrSize);
    
    mergeSort(arr, 0, arrSize);
    
    printf("После сортировки:\n");
    printArr(arr, arrSize);
    
    free(arr);
}
