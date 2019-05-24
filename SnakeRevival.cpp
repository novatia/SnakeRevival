#pragma once
#include "pch.h"

#include "SnakeRevival.h"
#include "GameMode.h"

using namespace std;

SnakeRevival::SnakeRevival()
{
	gm = GameMode::GetInstance();
}


SnakeRevival::~SnakeRevival()
{
}

void SnakeRevival::Start()
{
	string buffer =  gm->menu.GetView();
	cout << buffer;
}
