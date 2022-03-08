﻿#include <iostream>
#include <conio.h>
#include <windows.h>
int main()
{
	setlocale(LC_CTYPE, "rus");

	int mas[10][10] = {{1,2,1,1,1,1,1,1,1,1,}, // инициализация двумерного массива
					   {1,2,0,0,1,2,2,2,2,1,},//1-cтенки
					   {1,2,1,0,0,2,1,1,2,1,},//2-настоящий путь
					   {1,2,0,1,1,2,2,1,2,1,},//3-персонаж
					   {1,2,2,2,1,1,2,1,2,1,},
					   {1,0,1,2,2,2,2,1,2,1,},
					   {1,0,1,2,1,0,1,0,2,3,},//начало 6 9
					   {1,0,1,2,1,0,0,1,0,1,},
					   {1,0,0,0,1,0,1,1,0,1,},
					   {1,1,1,1,1,1,1,1,1,1,} };
	int f = 1, key = 0, a = 6, b = 9;

	printf_s("Нажми на любую клавишу стрелок");
	_getch();

	while (f != 0) {
		key = _getch();
		system("cls");
		int sta = a, stb = b;
		if (key == 80) {//вниз
			a++; if (mas[a][b] == 1) a--;//берем новые координаты, если можно встать на ячейку, 
		}								//иначе оставляем старые
		if (key == 72) {//вверх
			a--; if (mas[a][b] == 1) a++;
		}
		if (key == 77) {//вправо
			b++; if (mas[a][b] == 1) b--;
		}
		if (key == 75) {//влево
			b--; if (mas[a][b] == 1) b++;
		}
		mas[a][b] = 3;//код-две решетки-персонаж

		if (a == 0 && b == 1)//если ты нашел выход
		{
			system("cls");
			printf_s("The end");
			break;
		}
		if (a == 2 && b == 3)
		{
			system("cls");
			printf_s("ахахахах ловушка");
			break;
		}
		else {  //иначе - ищи выход
			// два цикла - внутренний и внешний, осуществляющие обращение к каждому элементу массива
			for (int i = 0; i < 10; i++) //переключение по строкам
			{
				for (int j = 0; j < 10; j++) {// переключение по столбцам
					if (mas[i][j] == 1)
					{
						printf_s("%c",64);// вывести символ @ в консоль
					}
					if (mas[i][j] == 3)
					{
						printf_s("%c", 2);// вывести символ смайлика в консоль

					}
					else if (mas[i][j] == 0 || mas[i][j] == 2)
					{
						printf_s(" ");  // вывести пробел

					}
					if (sta != a || stb != b) mas[sta][stb] = 0;//замазываю предыдущее положение пробелами

				}
				printf_s("\n");
			}

		}
	}/*
	int i;//с помощью этого кода я выводил символы ASCII в консоль
	i = 0;
	do
	{
		printf("%d %c \n", i, i);
		i++;
	} while (i <= 255);
	return 0;*/
}