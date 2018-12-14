// 1214.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std;

#define MAX_COL 15
#define MAX_ROW 10

char base[MAX_ROW][MAX_COL] =
{
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', '0', '0', '0', '0', '0', ' ', '0', ' ', ' ', '0', ' ', ' ', ' ', ' '},
	{' ', '0', '0', '0', ' ', '0', '0', '0', '0', ' ', '0', '0', '0', '0', ' '},
	{' ', '0', '0', ' ', ' ', '0', '0', '0', '0', '0', '0', ' ', '0', '0', ' '},
	{' ', '0', '0', ' ', ' ', ' ', '0', '0', '0', '0', '0', ' ', ' ', ' ', ' '},
	{' ', '0', ' ', '0', '0', ' ', '0', '0', '0', '0', '0', ' ', ' ', '0', ' '},
	{' ', '0', ' ', ' ', '0', ' ', '0', '0', '0', '0', '0', '0', '0', ' ', ' '},
	{' ', '0', '0', ' ', '0', ' ', '0', '0', '0', ' ', '0', '0', '0', '0', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', '0', '0', ' ', ' ', '0', '0', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
};

void print(char(*arr)[MAX_COL]);
void paint(char(*arr)[MAX_COL]);
void recursive(char(*arr)[MAX_COL], int row, int col);

int main()
{
	char change[MAX_ROW][MAX_COL];

	while (true)
	{
		memcpy_s(change, sizeof(change), base, sizeof(base));
		print(change);
		Sleep(1000);

		paint(change);
		Sleep(3000);
	}

	return 0;
}

void print(char (*arr)[MAX_COL])
{
	system("cls");
	for (int i = 0; i < MAX_ROW; ++i)
	{
		for (int j = 0; j < MAX_COL; ++j)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

void paint(char(*arr)[MAX_COL])
{
	recursive(arr, 5, 7);
}

void recursive(char(*arr)[MAX_COL], int row, int col)
{
	arr[row][col] = '*';
	print(arr);
	Sleep(50);

	// 왼쪽
	if (0 < col)
	{
		if ('0' == arr[row][col - 1])
		{
			recursive(arr, row, col - 1);
		}
	}
	// 위쪽
	if (0 < row)
	{
		if ('0' == arr[row - 1][col])
		{
			recursive(arr, row - 1, col);
		}
	}
	// 오른쪽
	if (MAX_COL > col)
	{
		if ('0' == arr[row][col + 1])
		{
			recursive(arr, row, col + 1);
		}
	}
	// 아래쪽
	if (MAX_ROW > row)
	{
		if ('0' == arr[row + 1][col])
		{
			recursive(arr, row + 1, col);
		}
	}
}