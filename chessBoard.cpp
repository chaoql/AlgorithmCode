#include"AExam.h"
using namespace std;
static int n, g[100][100], num = 1;

void chessBoard(int x, int y, int sx, int sy, int size) {
	if (size == 1)
		return;
	int s = size / 2, t = ++num;
	if (sx < x + s && sy < y + s)  chessBoard(x, y, sx, sy, s);//特殊方格在左上角
	else {//特殊方格不在左上角
		g[x + s - 1][y + s - 1] = t;//左上角棋盘的右下角
		chessBoard(x, y, x + s - 1, y + s - 1, s);
	}
	if (sx < x + s && sy >= y + s)  chessBoard(x, y + s, sx, sy, s);//特殊方格在右上角
	else {  //特殊方格不在右上角
		g[x + s - 1][y + s] = t;//右上角棋盘的左下角
		chessBoard(x, y + s, x + s - 1, y + s, s);
	}
	if (sx >= x + s && sy >= y + s)  chessBoard(x + s, y + s, sx, sy, s);//特殊方格在右下角
	else {  //特殊方格不在右下角
		g[x + s][y + s] = t;//右下角棋盘的左上角
		chessBoard(x + s, y + s, x + s, y + s, s);
	}
	if (sx >= x + s && sy < y + s)  chessBoard(x + s, y, sx, sy, s);//特殊方格在左下角
	else {  //特殊方格不在左下角
		g[x + s][y + s - 1] = t;//左下角棋盘的右上角
		chessBoard(x + s, y, x + s, y + s - 1, s);
	}
}

void chessBoard() {
	int x, y;//特殊方格坐标
	cin >> n;
	cin >> x >> y;
	g[x][y] = num;
	chessBoard(0, 0, x, y, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << g[i][j] << "\t";
		cout << endl;
	}
}
/*
16
1 0
*/