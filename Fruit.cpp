﻿#include "pch.h"
#include "Fruit.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

Fruit::Fruit()
{

}


Fruit::~Fruit()
{

}

wstring Fruit::GetRow(int row_num)
{
	int num = row_num - top;

	switch (num) {
	case 0: return L"\x1B[32m ┌ \033[0m";
	case 1: return L"\x1B[31m███\033[0m";
	case 2: return L"\x1B[31m ▀ \033[0m";
	}

	return L"";
}

int Fruit::GetWidth()
{
	return 3;
}

int Fruit::GetHeight()
{
	return 3;
}
