#include "Cell.h"

Cell::Cell() :x(0), y(0)
{
}

Cell::Cell(int x, int y) :x(x), y(y){}

Cell::Cell(int x, int y, int realNum)
{
	this->x = x;
	this->y = y;
	this->realNum = realNum;
	for (int i = 0; i < 9; i++) {
		if (i != realNum - 1) {
			numList[i] = 0;
		}
	}
}

int Cell::isFinish()
{
	int index = -1;
	int count = 0;
	for (int i = 0; i < 9; i++) {
		if (numList[i] == 1) {
			if (count == 0) {
				count++;
				index = i;
			}
			else {
				return -1;
			}
		}
	}
	return index + 1;
}

int Cell::check(int num)
{
	if (!this->finishFlag) {
		numList[num - 1] = 0;
		int finishIndex = isFinish();
		if (finishIndex != -1) {
			realNum = finishIndex;
			return realNum;
		}
	}
	return -1;
}

void Cell::showCell()
{
	cout<<"-------"<<endl;
	for (int i = 0; i < 3; i++) {
		cout << "|";
		for (int j = 0; j < 3; j++) {
			int index = i * 3 + j;
			int num = numList[index];
			string tem = num == 1 ? to_string(num) : " ";
			if (j != 2) tem += " ";
			cout << tem;
		}
		cout << "|";
	}
	cout << "-------" << endl;
}

string Cell::showRow(int i) {
	string res = "|";
	string mid = "";
	for (int j = 0; j < 3; j++) {
		int index = i * 3 + j;
		int num = numList[index];
		string tem = num == 1 ? to_string(index+1) : " ";
		if (j != 2) tem += " ";
		res += tem;
	}
	res += "|";
	return res;
}

void Cell::setFinish()
{
	finishFlag = true;
}
