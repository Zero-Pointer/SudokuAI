#include "Grid.h"



Grid::Grid()
{
	int x;
	int y;
	int realNum;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cellGrid[i][j] = Cell(i, j);
		}
	}
	while (true) {
		cin >> x >> y >> realNum;
		if (x == -1) break;
		cellGrid[x][y] = Cell(x, y, realNum);
	}
}

void Grid::checkGrid()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			Cell* temCell = &cellGrid[i][j];
			if (temCell->isFinish() != -1) {
				finishedLine.push(temCell);
			}
		}
	}
}

void Grid::startPrimaryAlgorithm()
{
	while (!finishedLine.empty()) {
		Cell* frontCell = finishedLine.front();
		frontCell->setFinish();
		finishedLine.pop();
		handleCell(frontCell->x, frontCell->y, frontCell->realNum);
	}
}

void Grid::showGrid()
{
	string allStr[9];
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 3; k++) {
			string rowStr;
			for (int j = 0; j < 9; j++) {
				rowStr += cellGrid[i][j].showRow(k);
				if (j != 8) rowStr += "  ";
			}
			cout << rowStr << endl;
		}
		cout << endl;
	}
}

void Grid::handleCell(int x, int y, int realNum)
{
	// row
	for (int j = 0; j < 9; j++) {
		if (j == y) continue;
		int res = cellGrid[x][j].check(realNum);
		if (res != -1) {
			finishedLine.push(&cellGrid[x][j]);
		}
	}
	// column
	for (int i = 0; i < 9; i++) {
		if (i == x) continue;
		int res = cellGrid[i][y].check(realNum);
		if (res != -1) {
			finishedLine.push(&cellGrid[i][y]);
		}
	}
	// grid
	int left = y - (y % 3);
	int top = x - (x % 3);
	for (int i = top; i < top + 3; i++) {
		for (int j = left; j < left + 3; j++) {
			if (i == x || j == y) continue;
			int res = cellGrid[i][j].check(realNum);
			if (res != -1) finishedLine.push(&cellGrid[i][j]);
		}
	}
}

Grid::~Grid()
{
	//for (int i = 0; i < 9; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		delete& cellGrid[i][j];
	//	}
	//}
}
