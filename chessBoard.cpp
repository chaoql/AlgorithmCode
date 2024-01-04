#include"AExam.h"
using namespace std;
static int n, g[100][100], num = 1;

void chessBoard(int x, int y, int sx, int sy, int size) {
	if (size == 1)
		return;
	int s = size / 2, t = ++num;
	if (sx < x + s && sy < y + s)  chessBoard(x, y, sx, sy, s);//���ⷽ�������Ͻ�
	else {//���ⷽ�������Ͻ�
		g[x + s - 1][y + s - 1] = t;//���Ͻ����̵����½�
		chessBoard(x, y, x + s - 1, y + s - 1, s);
	}
	if (sx < x + s && sy >= y + s)  chessBoard(x, y + s, sx, sy, s);//���ⷽ�������Ͻ�
	else {  //���ⷽ�������Ͻ�
		g[x + s - 1][y + s] = t;//���Ͻ����̵����½�
		chessBoard(x, y + s, x + s - 1, y + s, s);
	}
	if (sx >= x + s && sy >= y + s)  chessBoard(x + s, y + s, sx, sy, s);//���ⷽ�������½�
	else {  //���ⷽ�������½�
		g[x + s][y + s] = t;//���½����̵����Ͻ�
		chessBoard(x + s, y + s, x + s, y + s, s);
	}
	if (sx >= x + s && sy < y + s)  chessBoard(x + s, y, sx, sy, s);//���ⷽ�������½�
	else {  //���ⷽ�������½�
		g[x + s][y + s - 1] = t;//���½����̵����Ͻ�
		chessBoard(x + s, y, x + s, y + s - 1, s);
	}
}

void chessBoard() {
	int x, y;//���ⷽ������
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