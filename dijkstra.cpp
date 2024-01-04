#include"AExam.h"
#define INF 0x3f
#define P pair<int, int>
using namespace std;

static int d[10000], vis[10000], g[100][100];  //vis���ڼ�¼�Ѿ����߹��ĵ�
static int n, m, s, cnt = 0;
priority_queue<P, vector<P>, greater<P> >a;  //���Ż�

void dij() {
	memset(d, INF, sizeof d);
	d[s] = 0;  //��ʾ��������֮�ⶼ�ǲ��ɵ����
	a.push({0,s});  //�ѵ�����������ȶ��У����մ�С�����˳�������Χ�ĵ�
	while (!a.empty()) {
		int p = a.top().second;
		a.pop();
		if (!vis[p]) {  //�Ѿ������ɵĵ㲻�ü�������
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
	cin >> n >> m >> s;  //n���㣬m���ߣ����Ϊs
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
