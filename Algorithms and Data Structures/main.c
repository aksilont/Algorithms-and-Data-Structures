//
//  main.c
//  Algorithms and Data Structures
//
//  Created by Aksilont on 15.09.2021.
//

#include <stdio.h>
#include <math.h>

void menu(void);
void solution1(void);
void solution2(void);
void solution3(void);
void solution4(void);

int main(int argc, const char * argv[]) {
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
            case 4:
                printf("--------------------\n");
                solution4();
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
    return 0;
}

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void swapLite(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapSort(int *a, int *b, int ascending) {
    if (ascending) {
        if (*a > *b) {
            swap(a, b);
        }
    } else {
        if (*a < *b) {
            swap(a, b);
        }
    }
    
}

void menu() {
    printf("1 - Задание №1\n");
    printf("2 - Задание №2\n");
    printf("3 - Задание №3\n");
    printf("4 - Задание №4\n");
    printf("0 - Выход\n");
}

void solution1() {
    double height, weight;
    
    printf("Введите рост человек в см: \n");
    scanf("%lf", &height);
    
    printf("Введите вес человека в кг: \n");
    scanf("%lf", &weight);
    
    double imt = 10000 * weight / (height * height);
    
    printf("Индекс массы тела = %lf\n", imt);
}

void solution2() {
    int x1, x2, x3, x4;
    int typeSort = 1;
    
    printf("Введите первое целое число:\n");
    scanf("%i", &x1);
    
    printf("Введите второе целое число:\n");
    scanf("%i", &x2);
    
    printf("Введите третье целое число:\n");
    scanf("%i", &x3);
    
    printf("Введите четвертое целое число:\n");
    scanf("%i", &x4);
    
    printf("Укажите направление сортировки (0 - по убыванию, 1 - по возрастанию):\n");
    scanf("%i", &typeSort);
    char *sorting = typeSort ? "по возрастанию" : "по убыванию";
    
    // Сравнение первой переменной с остальными
    swapSort(&x1, &x2, typeSort);
    swapSort(&x1, &x3, typeSort);
    swapSort(&x1, &x4, typeSort);
    
    // Сравнение второй с оставшимися
    swapSort(&x2, &x3, typeSort);
    swapSort(&x2, &x4, typeSort);
    
    // Сравнение последних перменных
    swapSort(&x3, &x4, typeSort);
    
    printf("Ваши числа %s: %i, %i, %i, %i\n", sorting, x1, x2, x3, x4);
}

void solution3() {
    int a, b;
    
    printf("Введите первое целое число:\n");
    scanf("%i", &a);
    
    printf("Введите второе целое число:\n");
    scanf("%i", &b);
    
    swap(&a, &b);
    
    printf("Ваши числа после обмена значений: %i, %i\n", a, b);
}

void solution4() {
    int a, b, c;
    double d;
    double x1, x2;
    
    // Одно решение: 1,12,36
    // 2 решения: 1,-2,-31
    
    printf("Квадратное уравнени вида: ax2 + bx + c = 0\n");
    printf("Введите коэффициенты через запятую (a,b,c):\n");
    scanf("%i, %i, %i", &a, &b, &c);
    
    d = b * b - 4 * a * c;
    
    if (d < 0) {
        printf("Уравнение не имеет решений!\n");
    } else if (d == 0) {
        x1 = -b / (2 * a);
        printf("Уровнение имеет один корень = %lf\n", x1);
    } else {
        x1 = (-b - sqrt(d)) / (2 * a);
        x2 = (-b + sqrt(d)) / (2 * a);
        printf("Уровнение имеет 2 корня: %lf и %lf\n", x1, x2);
    }
}
