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
	//task_two();
	task_three();
	//task_four();

	return 0;
}

void task_one()
{
	double angle = 0;
	double result = 0;

	for (; ;)
	{
		angle += 5;
		if (360 < angle)
		{
			angle -= 360;
		}
		result = sin(angle * 3.14 / 180.0) * 50;

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
	// hhd는 char형, hd는 short형
	// hhu는 unsigned char형, hu는 unsigned short형
	// 서식문자 전부 정리 해놓기

	for ( ; ; )
	{
		printf("숫자를 입력하세요(0 ~ 255) : ");
		unsigned char input = 0;
		scanf_s("%hhu", &input);
		printf("2진수 : ");

		for (int i = 0; i < 8; ++i)
		{
			//printf("%hhu", (input & (char)pow(2, 7 - i)) >> (7 - i));
			printf("%hhu", (input & (1 << (7 - i))) >> (7 - i));
			if (3 == i)
			{
				printf(" ");
			}
		}
		printf("\n\n");
	}
}

void task_three()
{
	unsigned short flag = 0;
	unsigned char input = 0;
	unsigned short onoff = 0;
	for( ; ; )
	{
		printf("비트 위치를 입력하세요(1 ~ 16) : ");
		scanf_s("%hhu", &input);
		printf("Off/On 값을 입력하세요[0, 1] : ");
		scanf_s("%hu", &onoff);

		if (0 == onoff)
		{
			//0xFFFF - (1 << (input - 1));
			flag &= ~(1 << (input - 1));			// 값을 뺀다. 빼려는 위치만 0을 넣고 AND로 0 만듦.
		}
		else
		{
			flag |= 1 << (input - 1);				// 값을 넣는다. 넣으려는 위치만 1을 넣고 OR로 1 만듦.
		}

		for (int i = 0; i < 16; ++i)
		{
			printf("%d번 비트 : ", 16 - i);
			if (0 == (flag & (1 << (15 - i))) >> (15 - i))
			{
				printf("OFF\n");
			}
			else
			{
				printf("on\n");
			}
		}
		printf("\n");
	}
}

void task_four()
{
	unsigned int flag = 0;
	unsigned char input = 0;
	unsigned int value = 0;
	for (; ; )
	{
		printf("바이트 위치(1 ~ 4) : ");
		scanf_s("%hhu", &input);
		printf("값(0 ~ 255) : ");
		scanf_s("%d", &value);

		flag &= ~(0xFF << ((4 - input) * 8));	// 해당 byte 위치의 값 0 초기화
		flag |= value << ((4 - input) * 8);

		for (int i = 0; i < 4; ++i)
		{
			printf("%d번째 바이트 값 : ", i + 1);
			printf("%u\n", (flag & 0xFF << ((3 - i) * 8)) >> ((3 - i) * 8) );
		}

		printf("전체 4바이트 값 : %#010x\n\n", flag);
	}
}