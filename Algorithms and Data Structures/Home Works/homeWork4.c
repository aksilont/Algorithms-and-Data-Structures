//
//  homeWork4.c
//  Algorithms and Data Structures
//
//  Created by Aksilont on 22.09.2021.
//

#include <string.h>

#include "homeWork4.h"
#define ROW 8
#define COL 8
// ----------------------------------------------------------------------------------

void menu(void);
void solution1(void);
void solution2(void);

// ----------------------------------------------------------------------------------

void homeWork4(void) {
    
    printf("Практическое задание №4\n");
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
    printf("0 - Выход\n");
}

// ----------------------------------------------------------------------------------

// Карта массива 8x8:
//   | 1  2  3  4  5  6  7  8
// --------------------------
// 1 | 1  1  1  1  1  1  1  1
// 2 | 1  1  1  0  1  1  1  1
// 3 | 1  0  1  1  0  1  1  1
// 4 | 1  1  0  1  1  1  1  1
// 5 | 1  1  1  1  0  1  0  1
// 6 | 1  1  1  1  1  1  1  0
// 7 | 1  1  1  0  1  0  1  1
// 8 | 1  0  1  1  1  1  1  1

void fillArrMap(int row, int col, int a[][col]) {
    int i;
    int j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            a[i][j] = 1;
        }
    }
    
    // Препятствия
    a[2 - 1][4 - 1] = 0;
    
    a[3 - 1][2 - 1] = 0;
    a[3 - 1][5 - 1] = 0;
    
    a[4 - 1][3 - 1] = 0;
    
    a[5 - 1][5 - 1] = 0;
    a[5 - 1][7 - 1] = 0;
    
    a[6 - 1][8 - 1] = 0;
    
    a[7 - 1][4 - 1] = 0;
    a[7 - 1][6 - 1] = 0;
    
    a[8 - 1][2 - 1] = 0;
}

void print(int row, int col, int a[][col]) {
    int i;
    int j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%5i", a[i][j]);
        }
        printf("\n");
    }
}

// ----------------------------------------------------------------------------------
// 1. Количество маршрутов с препятствиями.
// Реализовать чтение массива с препятствием и нахождение количество маршрутов.

void solution1() {
    
    int arrMap[ROW][COL];
    fillArrMap(ROW, COL, arrMap);
    printf("Карта массива:\n");
    print(ROW, COL, arrMap);
    printf("----------------------------------\n");
    
    int i;
    int j;
    int arr[ROW][COL];
    for (j = 0; j < COL; j++) {
        arr[0][j] = 1;
    }
    
    for (i = 1; i < ROW; i++) {
        arr[i][0] = 1;
        for (j = 1; j < COL; j++) {
            int leftVal = 0;
            int upVal = 0;
            if (arrMap[i][j]) {
                leftVal = arrMap[i][j - 1] ? arr[i][j - 1] : 0;
                upVal   = arrMap[i - 1][j] ? arr[i - 1][j] : 0;
            }
            arr[i][j] = leftVal + upVal;
        }
    }
    printf("Массив ходов:\n");
    print(ROW, COL, arr);
}

// ----------------------------------------------------------------------------------
// 2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.

int i, j, c[20][20];
long lenghtFirst, lenghtSecond;
char firstSeq[20], secondSeq[20];
char mapDirections[20][20];

void printSubsequence(long i, long j) {
    if (i == 0 || j == 0)
        return;
    
    if (mapDirections[i][j] == 'c') {
        printSubsequence(i - 1, j - 1);
        printf("%c", firstSeq[i - 1]);
    }
    else if (mapDirections[i][j] == 'u')
        printSubsequence(i - 1, j);
    else
        printSubsequence(i, j - 1);
}

void lcs(void) {
    lenghtFirst = strlen(firstSeq);
    lenghtSecond = strlen(secondSeq);
    for (i = 0; i <= lenghtFirst; i++) c[i][0] = 0;
    for (i = 0; i <= lenghtSecond; i++) c[0][i] = 0;

    // c, u и l - обозначают поперечное, восходящее и нисходящее направления соответственно(cross upper left)
    // lenghtFirst - длина первой строки
    // lenghtSecond - длина второй строки
    for (i = 1; i <= lenghtFirst; i++)
        for (j = 1; j <= lenghtSecond; j++) {
            if (firstSeq[i - 1] == secondSeq[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                mapDirections[i][j] = 'c';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                mapDirections[i][j] = 'u';
            } else {
                c[i][j] = c[i][j - 1];
                mapDirections[i][j] = 'l';
            }
        }
}

void solution2() {
    printf("Введите первую последовательность: ");
    scanf("%s", firstSeq);
    printf("Введите вторую последовательность: ");
    scanf("%s", secondSeq);
    printf("Самая длинная общая подпоследовательность: ");
    lcs();
    printSubsequence(lenghtFirst, lenghtSecond);
}
