// study.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

#define ADD(a, b) (a) + (b)
#define MUL(a, b) (a) * (b)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int Add_Inline(int a, int b) { return a + b; }
inline int MUL_Inline(int a, int b) { return a * b; }
inline int MAX_Inline(int a, int b) { return (a > b) ? a : b; }

int main()
{
	int add, mul, max;

	add = Add_Inline(10, 20);
	mul = MUL_Inline(5 + 5, 10 + 10);
	max = MAX_Inline(10, 20);

    cout << "ADD_Inline : " << add << endl;
	cout << "MUL_Inline : " << mul << endl;
	cout << "MAX_Inline : " << max << endl;

	add = ADD(10, 20);
	mul = MUL(5 + 5, 10 + 10);
	max = MAX(10, 20);

	cout << "ADD : " << add << endl;
	cout << "MUL : " << mul << endl;
	cout << "MAX : " << max << endl;

	return 0;
}