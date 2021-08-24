#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <locale.h>
#include <string.h>
#include "header.h"

/* Нужно сделать контекстное меню.
1 Добавить абонента
2 Удалить абонента
3 Вывести список абонентов
4 Поиск абонента
Данные об абонентах имя и телефон*/


int main()
{
	int H = 1, z;
	char call[10];
	setlocale(LC_ALL, "Rus");

	while (H) {
		printf("Введите команду: (вызов справки кнопкой 9)  ");
		scanf("%d", &z);
		switch (z)
		{
		case 1:
			In();
			break;
		case 2:
			Out();
			break;
		case 3:
			Delete();
			break;
		case 4:
			Clear();
			break;
		case 5:
			printf("Введите имя абонента:");
			scanf("%s", &call);
			FindCall(call);
			break;
		case 6:
			Edit();
			break;
		case 7:
			Bardak();
			break;
		case 0:
			H = 0;
			break;
		case 9:
			printf("0 - выйти из терминала\n1 - добавить абонента\n2 - посмотреть данные абонента\n3 - удалить выбранного пользователя\n4 - удалить все номера\n5 - найти абонента по имени\n6 - изменить определенного пользователя\n7 - очистить консоль\n");
			break;
		}
	}

	system("pause");
	return 0;
}