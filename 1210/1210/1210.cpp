// 1210.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

int func(int a, int b)
{
	int c;

	c = a + b;

	return c;
}

int main()
{
	int result = 0;
	result = func(10, 20);
    std::cout << result << std::endl;

	system("pause");
}
