#include"AExam.h"
using namespace std;
static int n, sum = 0, x[1000], y[1000], zl[1000], zr[1000];  //横轴、纵轴、左对角线、右对角线

void print() {
	for (int i = 1; i <= n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void dfs(int i) {//每一行
	if (i > n) {
		sum++;
		print();
		return;
	}
	for (int j = 1; j <= n; j++) {//每一列
		if (!x[i] && !y[j] && !zl[i - j + n] && !zr[i + j]) {
			x[i] = j;  //在第i行第j个位置放置皇后
			y[j] = 1;
			zl[i - j + n] = 1;
			zr[i + j] = 1;
			dfs(i + 1);
			x[i] = 0;
			y[j] = 0;
			zl[i - j + n] = 0;
			zr[i + j] = 0;
		}
	}
}

void nqueens() {
	cin >> n;
	dfs(1);
	cout << sum;
}