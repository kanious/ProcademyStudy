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
	{' ', ' ', '0', '0', '0', '0', ' ', ' ', ' ', ' ', '0', ' ', ' ', ' ', ' '},
	{' ', '0', '0', '0', '0', '0', ' ', '0', ' ', ' ', '0', '0', ' ', ' ', ' '},
	{' ', '0', '0', '0', ' ', '0', '0', '0', '0', ' ', '0', '0', '0', '0', '0'},
	{' ', '0', '0', ' ', ' ', '0', '0', '0', '0', '0', '0', ' ', '0', '0', ' '},
	{' ', '0', '0', ' ', ' ', ' ', '0', '0', '0', '0', '0', ' ', ' ', ' ', '0'},
	{'0', '0', ' ', '0', '0', ' ', '0', '0', '0', '0', '0', ' ', ' ', '0', '0'},
	{'0', '0', ' ', ' ', '0', ' ', '0', '0', '0', '0', '0', '0', '0', ' ', ' '},
	{'0', '0', '0', ' ', '0', ' ', '0', '0', '0', ' ', '0', '0', '0', '0', ' '},
	{'0', ' ', ' ', ' ', ' ', ' ', '0', '0', ' ', ' ', '0', '0', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', '0', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
};

void print(char(*arr)[MAX_COL]);
void paint(char(*arr)[MAX_COL]);
void recursive(char(*arr)[MAX_COL], int row, int col);

int main()
{
	int a = rand();


	char change[MAX_ROW][MAX_COL];

	for ( ; ; )
	{
		memcpy_s(change, sizeof(change), base, sizeof(base));
		print(change);
		Sleep(1000);

		paint(change);
		Sleep(3000);
	}

	return 0;
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

	// 반복적인 코드는 지양해야 한다.
	// 다만 이렇게 하는 게 성능면에서는 효율적이다. 조건에 따라 함수를 스택에 올리지 않아도 되므로.

	// 하지만 성능에 그리 민감하지 않다면 재귀 위쪽에 예외 처리를 몰아주는 것이
	// 가독성이나 유지보수 측면에서 훨씬 낫다.
	// 회사에서 성능이 많이 필요하지 않은 컨텐츠 같은 부분이라면 쌤 코드처럼 짜는 것이 좋다.
	// 하지만 성능이 필요한 경우에는 아래처럼 한다.

	// 다음 과제 : 재귀 없이 스택을 활용하여 일반 루프문으로 바꾼다.

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

void print(char(*arr)[MAX_COL])
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