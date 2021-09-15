//
//  main.c
//  Algorithms and Data Structures
//
//  Created by Aksilont on 15.09.2021.
//

#include <stdio.h>
#include <string.h>

// ----------------------------------------------------------------------------------

void menu(void);
void solution1(void);
void solution2(void);

// ----------------------------------------------------------------------------------

int main(int argc, const char * argv[]) {
    printf("Практическое задание №2\n");
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
    return 0;
}

// ----------------------------------------------------------------------------------

void menu() {
    printf("1 - Задание 1 (Конвертация DEC -> BIN)\n");
    printf("2 - Задание 2 (Возведение в степень)\n");
    printf("0 - Выход\n");
}

// ----------------------------------------------------------------------------------

//1. Перевод из десятичной системы в двоичную, используя рекурсию

int numberOfDigits(int in) {
    return (in != 0) ? (numberOfDigits(in >> 1) + 1) : (0);
}

void fillArray(int in, char *out, int counter) {
    if (in > 0) {
        out[counter] = (in % 2) ? '1' : '0';
        fillArray(in / 2, out, --counter);
    }
}
void decToBin(int in, char *result) {
    char out[64];
    // Вычислим сколько всего разрядов в нашем числе
    int i = numberOfDigits(in);
    // Обнулим массив
    out[i] = '\0';
    // Запись в массив
    fillArray(in, out, --i);
    // Запишем массив в "строку"
    strcat(result, out);
}

void solution1() {
    int number = 0;
    printf("Введите целое число для конвертации в двоичный вид\n");
    scanf("%d", &number);
    
    char bin[64] = "";
    decToBin(number, bin);
    printf("Ваше число %d в двоичном виде = %s\n", number, bin);
}

// ----------------------------------------------------------------------------------

// 2. a. Возведение в степень
long powLite(int a, int b)//Первое число основание степени, второе показатель.
{
    long p = 1;
    while (b)
    {
        p = p * a;//Умножаем число а само на себя b раз
        b--;
    }
    return p;
}

//2. b. Возведение в степень рекурсивно
long powRecursion(int a, int b) {
    if (b != 0) {
        return a * powRecursion(a, --b);
    } else {
        return 1;
    }
}

// Ускоренное возведение в степень
long quickPow(int a, int b) //Первое число основание степени, второе показатель.
{
    long n = 1;
    while (b)
    {
        //Если число делится без остатка на два то получается 0, а это значит что оно чётное и здесь будет false
        if (b % 2)
        {
            b--;
            n *= a;
        }
        else
        {
            //Если степень n чётная, то переходим к степени вдвое меньшей, иначе заменяем по имеющимся правилам нечётную степень на чётную.
            a *= a;
            b /= 2;
        }
    }
    return n;
}

// 2. c. Ускоренное возведение в степень рекурсивно
long quickPowRecursion(int a, int b) {
    if (b != 0) {
        if (b % 2) {
            return a * quickPowRecursion(a, --b);
        } else {
            return quickPowRecursion(a * a, b / 2);
        }
    } else {
        return 1;
    }
}

void solution2() {
    int number = 0;
    int grade = 0;
    printf("Введите основание = ");
    scanf("%d", &number);
    printf("Введите показатель = ");
    scanf("%d", &grade);
    
    long result = quickPowRecursion(number, grade);
    printf("Результат: %d ^ %d = %ld\n", number, grade, result);
}
