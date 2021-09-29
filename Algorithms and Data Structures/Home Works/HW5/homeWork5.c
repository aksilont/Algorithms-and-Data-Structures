//
//  homeWork5.c
//  Algorithms and Data Structures
//
//  Created by Aksilont on 28.09.2021.
//

#include <string.h>

#include "homeWork5.h"
#include "Stack.h"

// ----------------------------------------------------------------------------------

void menu(void);
void solution1(void);
void solution2(void);
void solution3(void);
void solution4(void);

// ----------------------------------------------------------------------------------

void homeWork5(void) {
    
    printf("Практическое задание №5\n");
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
}

// ----------------------------------------------------------------------------------

void menu() {
    
    char ask1[500] = "Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.";
    char ask2[500] = "Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. Если память не выделяется, то выводится соответствующее сообщение.";
    char ask3[500] = "Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{. Например: (2+(2*2)) или [2/{5*(4+7)}]";
    char ask4[500] = "*Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, не удаляя первый список)";
    
    printf("1 - %s\n", ask1);
    printf("2 - %s\n", ask2);
    printf("3 - %s\n", ask3);
    printf("4 - %s\n", ask4);
    printf("0 - Выход\n");
}

// ----------------------------------------------------------------------------------
// 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

int numberOfDigits(int in) {
    return (in != 0) ? (numberOfDigits(in >> 1) + 1) : (0);
}

void fillStack(Stack *stack, int in, int counter) {
    if (in > 0) {
        push(stack, (in % 2) ? '1' : '0');
        fillStack(stack, in / 2, --counter);
    }
}

void decToBin(int in, Stack *out) {
    // Вычислим сколько всего разрядов в нашем числе
    int i = numberOfDigits(in);
    fillStack(out, in, --i);
}

void solution1() {
    int number = 0;
    printf("Введите целое число для конвертации в двоичный вид\n");
    scanf("%d", &number);
    
    Stack *myStack = newStack();
    decToBin(number, myStack);
    printStack(myStack);
    clearStack(myStack);
}

// ----------------------------------------------------------------------------------
// 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.

void solution2(void) {
    // Создадим новый стэк и поместим в него 4 буквы a, b, c, d
    Stack *alphabet = newStack();
    push(alphabet, 'a');
    push(alphabet, 'b');
    push(alphabet, 'c');
    push(alphabet, 'd');
    printf("Вывод стека на основе односвязного списка после добавлений 'a,b,c,d': ");
    printStack(alphabet);
    // Извлечем из стэка последние 2 буквы и добавим букву f
    pop(alphabet);
    pop(alphabet);
    push(alphabet, 'f');
    // Распечатаем стэк, результат должен быть "fba"
    printf("Вывод стэка после изъятия 2-х последних элементов и добавления 'f': ");
    printStack(alphabet);
    clearStack(alphabet);
}

// ----------------------------------------------------------------------------------
// 3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
// Примеры
// правильных скобочных выражений: (), ([])(), {}(), ([{}])
// неправильных — )(, ())({), (, ])}), ([(])
// для скобок [,(,{.
// Например: (2+(2*2)) или [2/{5*(4+7)}]

void solution3(void) {
    checkSyntax("[2/{5*(4+7)}]~");
    checkSyntax("[3/){9*](4(1+{13)}]~");
    checkSyntax("(200 / [10 * 2]) * {2 * (15 + 23)}~");
    printf("\n");
}

// ----------------------------------------------------------------------------------
// 4. *Создать функцию, копирующую односвязный список
// (то есть создает в памяти копию односвязного списка, не удаляя первый список).

void solution4(void) {
    // Создадим новый стэк и поместим в него 4 буквы a, b, c, d
    Stack *alphabet = newStack();
    push(alphabet, 'a');
    push(alphabet, 'b');
    push(alphabet, 'c');
    push(alphabet, 'd');
    printf("Вывод первого стэка после добавлений 'a,b,c,d': ");
    printStack(alphabet);
    // Скопируем стэк в новый
    Stack *anotherAlphabetStack = copyStack(alphabet);
    printf("Вывод копии стэка: ");
    printStack(anotherAlphabetStack);
    // Извлечем из первого стэка последние 2 буквы и добавим букву f
    pop(alphabet);
    pop(alphabet);
    push(alphabet, 'f');
    // Распечатаем первый стэк, результат должен быть "fba"
    printf("Вывод первого стэка после изъятия 2-х последних элементов и добавления 'f': ");
    printStack(alphabet);
    // Очистим память первого стэка
    clearStack(alphabet);
    // Поместим во второй стэк букву z, распечатаем его (результат: zdcba) и освободим память
    push(anotherAlphabetStack, 'z');
    printf("Вывод копии стэка после добавления 'z': ");
    printStack(anotherAlphabetStack);
    clearStack(anotherAlphabetStack);
}
