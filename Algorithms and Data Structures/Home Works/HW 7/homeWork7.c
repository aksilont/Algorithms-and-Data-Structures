//
//  homeWork7.c
//  Algorithms and Data Structures
//
//  Created by Aksilont on 05.10.2021.
//

#include "homeWork7.h"
#include "Queue.h"

#define MAX 7
#define infinity 9999

// ----------------------------------------------------------------------------------

void menu(void);
void solution1(void);
void solution2(void);
void solution3(void);

// ----------------------------------------------------------------------------------

void homeWork7(void) {
    
    printf("Практическое задание №7\n");
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
    
    ask = "Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран";
    printf("1 - %s\n", ask);
    
    ask = "Написать рекурсивную функцию обхода графа в глубину";
    printf("2 - %s\n", ask);
    
    ask = "Написать функцию обхода графа в ширину";
    printf("3 - %s\n", ask);
    
    printf("0 - Выход\n");
}

// ----------------------------------------------------------------------------------
// 1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран

int i, j;
int matrix[MAX][MAX];

void printMatrix(int size, int matrix[size][size]) {
    printf("Матрица смежности: \n");
    printf("%s", "      ");
    for (i = 0; i < size; i++) {
        printf("%c(%d) ", 65 + i, i);
    }
    printf("\n");
    for (i = 0; i < size; i++) {
        printf("%c(%d)", 65 + i, i);
        for (j = 0; j < size; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrixFrom(char *fileName, int size) {
    
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Не удалось открыть файл");
        exit(1);
    }
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    
}

void solution1(void) {
    fillMatrixFrom("matrix.txt", 5);
    printMatrix(5, matrix);
}

// ----------------------------------------------------------------------------------
// 2. Написать рекурсивную функцию обхода графа в глубину

void prepareMatrix(int size, int matrix[size][size]) {
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = infinity;
            }
        }
    }
}

void dfs(int matrix[MAX][MAX], int visited[MAX], int currentPeack) {
    int adjIndex;
    visited[currentPeack] = 2;
    
    for (adjIndex = 0; adjIndex < MAX; adjIndex++) {
        if (matrix[currentPeack][adjIndex] != infinity && visited[adjIndex] == 1) {
            printf("Переход %c(%d) -> %c(%d)\n", 65 + currentPeack, currentPeack, 65 + adjIndex, adjIndex);
            dfs(matrix, visited, adjIndex);
        }
    }
}

void solution2(void) {
    
    fillMatrixFrom("matrix2.txt", 7);
    printMatrix(7, matrix);
    prepareMatrix(7, matrix);
     
    // Массив вершин для контроля посещяемости (значения: 1 - не посещена, 2 - цель для посещения, 3 - обработана)
    int visited[MAX];
    
    // Все вершины изначально не посещены
    for (i = 0; i < MAX; i++) {
        visited[i] = 1;
    }
    
    int startPeak = 4;
    printf("Старт из %c(%d)\n", 65 + startPeak, startPeak);
    dfs(matrix, visited, startPeak);
}

// ----------------------------------------------------------------------------------
// 3. Написать функцию обхода графа в ширину

void bfs(int matrix[MAX][MAX], int visited[MAX], int startIndex) {
    
    Queue* peaks = createQueue();
    
    printf("Точка старта: %c(%d)\n", 65 + startIndex, startIndex);
    enQueue(peaks, startIndex);
    visited[startIndex] = 2;
    
    while (!queueIsEmpty(peaks)) {
        int currentPeack = deQueue(peaks);
        printf("-----\n");
        printf("Текущая вершина %c(%d)\n", 65 + currentPeack, currentPeack);
        
        if (visited[currentPeack] == 2) {
            for (i = 0; i < MAX; i++) {
                if (matrix[currentPeack][i] != infinity && visited[i] == 1) {
                    enQueue(peaks, i);
                    visited[i] = 2;
                    printf("Обнаружена смежная вершина для посещения - %c(%d)\n", 65 + i, i);
                }
            }
            visited[currentPeack] = 3;
            printf("Вершина %c(%d) обработана\n", 65 + currentPeack, currentPeack);
        }
    }
}



void solution3(void) {
    fillMatrixFrom("matrix2.txt", 7);
    printMatrix(7, matrix);
    prepareMatrix(7, matrix);
    
    // Массив вершин для контроля посещяемости (значения: 1 - не посещена, 2 - цель для посещения, 3 - обработана)
    int visited[MAX];
    
    // Все вершины изначально не посещены
    for (i = 0; i < MAX; i++) {
        visited[i] = 1;
    }
    
    bfs(matrix, visited, 3);
}
