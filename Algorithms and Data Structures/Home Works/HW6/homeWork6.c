//
//  homeWork6.c
//  Algorithms and Data Structures
//
//  Created by Aksilont on 30.09.2021.
//

#include "homeWork6.h"
#include <string.h>
#include <time.h>

// ----------------------------------------------------------------------------------

void menu(void);
void solution1(void);
void solution2(void);

// ----------------------------------------------------------------------------------

void homeWork6(void) {
    
    printf("Практическое задание №6\n");
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
    char *ask;
    
    ask = "Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов";
    printf("1 - %s\n", ask);
    
    ask = "Переписать программу, реализующую двоичное дерево поиска. а) Добавить в него обход дерева различными способами; б) Реализовать поиск в двоичном дереве поиска";
    printf("2 - %s\n", ask);
    
//    ask = "*Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер», в которой использовать все знания, полученные на уроках. Считайте данные в двоичное дерево поиска. Реализуйте поиск по какому-нибудь полю базы данных (возраст, вес).";
//    printf("3 - %s\n", ask3);
    printf("0 - Выход\n");
}

// ----------------------------------------------------------------------------------
// 1. Реализовать простейшую хеш-функцию.
// На вход функции подается строка, на выходе сумма кодов символов.

char *concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 нужен для нуль-терминатора строки.
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

static const unsigned char sTable[256] =
{
  0xa3,0xd7,0x09,0x83,0xf8,0x48,0xf6,0xf4,0xb3,0x21,0x15,0x78,0x99,0xb1,0xaf,0xf9,
  0xe7,0x2d,0x4d,0x8a,0xce,0x4c,0xca,0x2e,0x52,0x95,0xd9,0x1e,0x4e,0x38,0x44,0x28,
  0x0a,0xdf,0x02,0xa0,0x17,0xf1,0x60,0x68,0x12,0xb7,0x7a,0xc3,0xe9,0xfa,0x3d,0x53,
  0x96,0x84,0x6b,0xba,0xf2,0x63,0x9a,0x19,0x7c,0xae,0xe5,0xf5,0xf7,0x16,0x6a,0xa2,
  0x39,0xb6,0x7b,0x0f,0xc1,0x93,0x81,0x1b,0xee,0xb4,0x1a,0xea,0xd0,0x91,0x2f,0xb8,
  0x55,0xb9,0xda,0x85,0x3f,0x41,0xbf,0xe0,0x5a,0x58,0x80,0x5f,0x66,0x0b,0xd8,0x90,
  0x35,0xd5,0xc0,0xa7,0x33,0x06,0x65,0x69,0x45,0x00,0x94,0x56,0x6d,0x98,0x9b,0x76,
  0x97,0xfc,0xb2,0xc2,0xb0,0xfe,0xdb,0x20,0xe1,0xeb,0xd6,0xe4,0xdd,0x47,0x4a,0x1d,
  0x42,0xed,0x9e,0x6e,0x49,0x3c,0xcd,0x43,0x27,0xd2,0x07,0xd4,0xde,0xc7,0x67,0x18,
  0x89,0xcb,0x30,0x1f,0x8d,0xc6,0x8f,0xaa,0xc8,0x74,0xdc,0xc9,0x5d,0x5c,0x31,0xa4,
  0x70,0x88,0x61,0x2c,0x9f,0x0d,0x2b,0x87,0x50,0x82,0x54,0x64,0x26,0x7d,0x03,0x40,
  0x34,0x4b,0x1c,0x73,0xd1,0xc4,0xfd,0x3b,0xcc,0xfb,0x7f,0xab,0xe6,0x3e,0x5b,0xa5,
  0xad,0x04,0x23,0x9c,0x14,0x51,0x22,0xf0,0x29,0x79,0x71,0x7e,0xff,0x8c,0x0e,0xe2,
  0x0c,0xef,0xbc,0x72,0x75,0x6f,0x37,0xa1,0xec,0xd3,0x8e,0x62,0x8b,0x86,0x10,0xe8,
  0x08,0x77,0x11,0xbe,0x92,0x4f,0x24,0xc5,0x32,0x36,0x9d,0xcf,0xf3,0xa6,0xbb,0xac,
  0x5e,0x6c,0xa9,0x13,0x57,0x25,0xb5,0xe3,0xbd,0xa8,0x3a,0x01,0x05,0x59,0x2a,0x46
};

void hash(char *str) {
    int lenghtOfCode = 16;
    char result[lenghtOfCode];

    char *table = "1234567890abcdef";
    unsigned long lenghtOfTable = strlen(table);
    
    unsigned long hash = 0;
    int rotate = 2;
    
    int i;
    for (i = 0; i < lenghtOfCode + 1; i++) {
        hash += sTable[(*str + i) & 255];
        hash = (hash << (32 - rotate)) | (hash >> rotate);
        result[i] = table[hash % lenghtOfTable];
    }
    printf("Хэш-код строки %s: ", str);
    for (i = 0; i < lenghtOfCode; i++) {
        printf("%c", result[i]);
    }
    printf("\n");
}

// Решение задания 1
void solution1() {
    hash("32jfl d;ajfk l; fjklj k2l ;j32kj5k23l; j2l;");
    hash("473289478329 4723 472389");
    hash("Test");
    hash("456");
    hash("Setr");
    hash("Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов");
}

// ----------------------------------------------------------------------------------
// 2. Переписать программу, реализующую двоичное дерево поиска.
//   а) Добавить в него обход дерева различными способами;
//   б) Реализовать поиск в двоичном дереве поиска;

void fillFile(char *filename, int counter, int range) {
    srand(time(NULL));
    FILE *file;
    file = fopen(filename, "w");
    
    int i, number;
    fprintf(file, "%d", counter);
    for (i = 0; i < counter; i++) {
        fprintf(file, "\n");
        number = rand() % range - range / 2;
        fprintf(file, "%d %d", number, i);
    }
    
    fclose(file);
}

typedef int T;

typedef struct Node {
    T data;
    int index;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// Создание нового узла
Node *getFreeNode(T value, int index, Node *parent) {
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->index = index;
    tmp->parent = parent;
    return tmp;
}

// Вставка узла
void insert(Node **head, int value, int index) {
    Node *tmp = NULL;
    if (*head == NULL) {
        *head = getFreeNode(value, index, NULL);
        return;
    }
    tmp = *head;
    while (tmp) {
        if (value >= tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(value, index, tmp);
                return;
            }
        } else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeNode(value, index, tmp);
                return;
            }
        } else {
            exit(2); // дерево построено неправильно
        }
    }
}


// Создание бинарного дерева из данных файла
Node *createTreeFrom(char *filename) {
    // Построение дерева
    Node *Tree = NULL;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        puts("Не удалось открыть файл");
        exit(1);
    }
    int count;
    fscanf(file, "%d", &count); // Считываем количество записей
    int i;
    for (i = 0; i < count; i++) {
        int value, index;
        fscanf(file, "%d %d", &value, &index);
        insert(&Tree, value, index);
    }
    fclose(file);
    return Tree;
}

// Распечатка бинарного дерева в виде скобочной записи
void printTree(Node *root) {
    if (root) {
        printf("%d[%d]",root->data, root->index);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

// Обход дерева 3 способами
void directOrderTravers(Node *root) {
    if (root) {
        printf("%d[%d];", root->data, root->index);
        directOrderTravers(root->left);
        directOrderTravers(root->right);
    }
}

void symmetricOrderTravers(Node *root) {
    if (root) {
        symmetricOrderTravers(root->left);
        printf("%d[%d];", root->data, root->index);
        symmetricOrderTravers(root->right);
    }
}

void reverseOrderTravers(Node *root) {
    if (root) {
        reverseOrderTravers(root->left);
        reverseOrderTravers(root->right);
        printf("%d[%d];", root->data, root->index);
    }
}

void orderTravers(Node *root) {
    int type;
    printf("Введите тип обхода дерева (1 - прямой, 2 - симметричный, 3 - обратный): ");
    scanf("%d", &type);
    switch (type) {
        case 1:
            printf("Прямой обход дерева: ");
            directOrderTravers(root);
            break;
        case 2:
            printf("Симметричный обход дерева: ");
            symmetricOrderTravers(root);
            break;
        case 3:
            printf("Обратный обход дерева: ");
            reverseOrderTravers(root);
            break;
        default:
            break;
    }
    printf("\n");
}

// Поиск значения в бинарном дереве
void searchValueInTree(Node *root) {
    T value;
    printf("Введите значение для поиска: ");
    scanf("%d", &value);
    if (root) {
        Node *tmp = root;
        while (tmp) {
            if (value > tmp->data) {
                tmp = tmp->right;
            } else if (value < tmp->data) {
                tmp = tmp->left;
            } else {
                printf("Искомое значение %d найдено под индексом %d\n", tmp->data, tmp->index);
                return;
            }
        }
        printf("Значение %d не найдено!\n", value);
    } else {
        printf("Дерево не определено!\n");
    }
}

// Решение задания 2
void solution2(void) {
    char *filename = "data.txt";
    int countOfRecords = 100;
    int rndRange = 1000; // -500 ... 500
    
    // Заполнить файл случайными числами
    fillFile(filename, countOfRecords, rndRange);
    
    // Создание бинарного дерева из данных файла
    Node *Tree = createTreeFrom(filename);
    
    // Распечатка бинарного дерева в виде скобочной записи
    printTree(Tree);
    printf("\n");
    
    // Обход бинароного дерева
    orderTravers(Tree);
    
    // Поиск значения в бинарном дереве
    searchValueInTree(Tree);
    
    free(Tree);
}

// ----------------------------------------------------------------------------------
// 3. *Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер», в которой использовать все знания, полученные на уроках.
// Считайте данные в двоичное дерево поиска. Реализуйте поиск по какому-нибудь полю базы данных (возраст, вес).

void solution3(void) {}
