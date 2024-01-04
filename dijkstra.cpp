#include"AExam.h"
#define INF 0x3f
#define P pair<int, int>
using namespace std;

static int d[10000], vis[10000], g[100][100];  //vis用于记录已经被走过的点
static int n, m, s, cnt = 0;
priority_queue<P, vector<P>, greater<P> >a;  //堆优化

void dij() {
	memset(d, INF, sizeof d);
	d[s] = 0;  //表示除了自身之外都是不可到达的
	a.push({0,s});  //把点逐个加入优先队列，按照从小到大的顺序更新周围的点
	while (!a.empty()) {
		int p = a.top().second;
		a.pop();
		if (!vis[p]) {  //已经被采纳的点不用加入两次
			vis[p] = 1;
			for (int i = 1; i <= n; i++) { 
				if (d[i] > d[p] + g[p][i]) {
					d[i] = d[p] + g[p][i];
					a.push({d[i], i});
				}
			}
		}
	}
}

void dijkstra() {
	cin >> n >> m >> s;  //n个点，m条边，起点为s
	memset(g, INF, sizeof g);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
	}
	dij();
	for (int i = 0; i < n; i++)
		cout << d[i + 1] << " ";
}
/*
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
*/
