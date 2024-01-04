#include"AExam.h"
using namespace std;


bool judge(int g[]) {
	if (g[0] + g[1] + g[2] == 15 &&
		g[3] + g[4] + g[5] == 15 &&
		g[6] + g[7] + g[8] == 15 &&
		g[0] + g[3] + g[6] == 15 &&
		g[1] + g[4] + g[7] == 15 &&
		g[2] + g[5] + g[8] == 15 &&
		g[0] + g[4] + g[8] == 15 &&
		g[2] + g[4] + g[6] == 15)
		return true;
	return false;
}

void output(int g[]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << g[i * 3 + j];
		cout << endl;
	}
	cout << "---------" << endl;
}

void dfs(int g[], int vis[], int m) {
	if (m == 9)
		if (judge(g)) {
			output(g);
			return;
		}
		else
			return;
	for (int i = 1; i <= 9; i++) {
		if (vis[i])
			continue;
		vis[i] = 1;
		g[m] = i;
		dfs(g, vis, m + 1);
		vis[i] = 0;
	}
}



void huanfang() {
	int g[9], vis[10]; //g[i]表示所有
	memset(vis, 0, sizeof vis);
	dfs(g, vis, 0);
}