// 1212.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "math.h"
#include "windows.h"
using namespace std;

void task_one();
void task_two();
void task_three();
void task_four();

int main()
{
	//task_one();
	task_two();
	//task_three();
	//task_four();

	return 0;
}

void task_one()
{
	double d = 0;
	double result = 0;

	for (; ;)
	{
		d += 5;
		if (360 < d)
		{
			d -= 360;
		}
		result = sin(d * 3.14 / 180.0) * 50;

		if (0 <= result)
		{
			printf("                                                            ");
			for (int j = 0; j < result; ++j)
				printf("*");
		}
		else
		{
			for (int i = 0; i < 60 + result; ++i)
				printf(" ");
			for (int j = 0; j < -result; ++j)
				printf("*");
		}

		printf("\n");
		Sleep(20);
	}
}

void task_two()
{
	while (true)
	{
		printf("\n숫자를 입력하세요(0 ~ 255) : ");
		unsigned char input = 0;
		scanf_s("%hhd", &input);		// hhd는 char형, hd는 short형
		printf("\n2진수 : ");

		for (int i = 0; i < 8; ++i)
		{
			printf("%d", (input & (int)pow(2, 7 - i)) >> (7 - i));
			if (3 == i)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void task_three()
{

}

void task_four()
{

}