#pragma once
#include<iostream>
#include<string>
using namespace std;
class Cell
{
	bool finishFlag = false;
	int numList[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };

public:
	int x, y;
	int realNum = -1;
	Cell();
	Cell(int x, int y);
	Cell(int x, int y, int realNum);
	/// <summary>
	/// It will tell you this cell isFinished or not.
	/// </summary>
	/// <returns>If finished, it will return realNum, else return -1.</returns>
	int isFinish();
	/// <summary>
	/// When another linked cell finished,
	/// check this cell and remove the same num.
	/// if this cell after check have finished too,
	/// return the finish num,
	/// or return -1.
	/// </summary>
	/// <param name="num"></param>
	/// <returns>After check, if will return realNum(if finished) or -1.</returns>
	int check(int num);


	void showCell();

	string showRow(int index);
	void setFinish();
};

