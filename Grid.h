#pragma once
#include "Cell.h"
#include<queue>
#include<iostream>
using namespace std;
class Grid
{
	Cell cellGrid[9][9];
	int finishCount = 0;
	queue<Cell*> finishedLine;
public:
	Grid();
	void checkGrid();
	void startPrimaryAlgorithm();
	void showGrid();
	void handleCell(int x, int y, int realNum);
	~Grid();
};

