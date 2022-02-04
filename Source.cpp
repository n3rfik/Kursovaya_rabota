#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "conio.h"
#include "stdlib.h"
#include "time.h"
#include "locale.h"
#include <queue>



std::queue <int> Q;       
int* num;				


void bfs(int v, int**matrix,int size)
{
	FILE* file = fopen("results.txt", "a");            
	Q.push(v);					
	num[v] = 1;					
	

	while (Q.empty() != true)               
	{
		v = Q.front();				
		Q.pop();						
		fprintf(file,"%d ", v);

		for (int i = 1; i < size; i++)
		{
			if ((matrix[v][i] == 1) && (num[i] == 0))   
			{
				Q.push(i);
				num[i] = 1;
			}
		}
	}
	fclose(file);
}


int main()
{
	FILE* file = fopen("results.txt", "w");
	int s;
	int size = 0;
	int** matrix;
	setlocale(LC_ALL, "Russian");
	while (true) {
		printf("Введите тип ввода:\n1-Автоматическая генерация\n2-Считывать из файла\n");
		int answer;
		printf("Выбрать: ");
		scanf_s("%d", &answer);
		if (answer == 1) {
			printf("Введите размер матрицы: ");
			scanf_s("%d", &size);
			num = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; i++)
			{
				num[i] = 0;
			}
			printf("\n");
			matrix = (int**)malloc(size * sizeof(int*));
			srand(time(NULL));
			for (int i = 0; i < size; i++)
			{
				matrix[i] = (int*)malloc(size * sizeof(int));

			}
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					matrix[i][j] = rand() % 2;
					matrix[j][i] = matrix[i][j];


					if (matrix[i] == matrix[j])
						matrix[i][j] = 0;



				}
			}
			break;
		}
		else if (answer == 2) {
			FILE* input = fopen("test.txt", "r");
			char a[10];
			fgets(a,10,input);
			for (int i = 0; i < 10; i++)
			{
				if (a[i] >= '0' && a[i] <= '9') {
					size = size * 10 + (a[i] - '0');
				}
			}
			num = (int*)malloc(size * sizeof(int));
				for (int i = 0; i < size; i++)
				{
					num[i] = 0;
				}
			printf("\n");
			matrix = (int**)malloc(size * sizeof(int*));
			srand(time(NULL));
				for (int i = 0; i < size; i++)
				{
					matrix[i] = (int*)malloc(size * sizeof(int));

				}
				char* buffer = (char*)malloc(sizeof(char) * 2 * size+1);
				for (int i = 0; i < size; i++)
				{
					fgets(buffer, size * 2+1, input);
					for (int j = 0; j < size * 2; j = j + 2)
					{
						matrix[i][j / 2] = (int)buffer[j] - '0';
					}
				}
				fclose(input);
			break;
		}
		else {
			printf("Введенно неверное значение, повторите попытку!\n");
			printf("\n");
		}
	}	
	printf("Матрица:\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%3d", matrix[i][j]);
		}
		printf("\n");

	}
	printf("Введите стартовую вершину: ");
	scanf_s("%d", &s);
	printf("\n");
	fprintf(file, "Обход закончен с результатом: ");
	fclose(file);
	bfs(s,matrix,size);
	system("PAUSE");
	return 0;
}
