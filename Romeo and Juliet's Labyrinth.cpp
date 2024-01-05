#include"AExam.h"
#define INF 0x3f3f3f3f
using namespace std;

static int Map[100][100], m, n, k, p, q, r, s, minz = INF, roadnums = 0, minMap[100][100];
static int diry[8] = { 0, 0, -1, 1, -1, -1, 1, 1 }, dirx[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
//����(dirx[i], diry[i])
static int judge(int x, int y) {  //�жϵ��Ƿ���Ч
	if (x > 0 && x <= m && y > 0 && y <= n && Map[x][y] != -1)
		return 1;
	else
		return 0;
}
//�����־dir��0�� 1�� 2�� 3�� 4��5��6��7��8->(��ʼ���ϣ��£����ң� ���ϣ����ϣ����£�����)
static void dfs(int x, int y, int znums, int roads, int dir, int pace) {//��x, y����ǰ��λ��znumsת�������roads���ʷ�������pace��ǰ�ǵڼ���
	if (x == r && y == s) {  //��������Ҷ
		if (roads == (m * n - k)) {  //���������зǷ�շ�����ת���������
			if (znums < minz) {
				roadnums = 1;//����ת���·������
				minz = min(minz, znums);
				for (int i = 1; i <= m; i++)
					for (int j = 1; j <= n; j++)
						minMap[i][j] = Map[i][j];
			}
			else if (znums == minz)//��ͬ������ת���·��
				roadnums++;
		}
		return;
	}
	for (int i = 0; i < 8; i++) {
		int nx = x + dirx[i], ny = y + diry[i];
		int j = judge(nx, ny);
		if (Map[nx][ny] || !j)//���߻�ͷ·��ֻ�߷Ƿ�շ���
			continue;
		Map[nx][ny] = ++pace;
		int curdir = i + 1;//�ж��Ƿ����
		if (dir && dir != curdir)
			znums++;
		int tempdir = dir;//�ݴ���ֵ��Ϊ�˻���ʱ��ԭ
		dir = curdir;
		dfs(nx, ny, znums, roads + 1, dir, pace);
		Map[nx][ny] = 0;
		if (dir != tempdir)
			znums--;
		dir = tempdir;
		pace--;
	}
}

void RandJ()
{
	memset(Map, 0, sizeof(Map));
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		Map[temp1][temp2] = -1;  //��շ���
	}
	cin >> p >> q >> r >> s;
	Map[p][q] = 1;
	dfs(p, q, 0, 1, 0, 1);
	cout << minz << "\n" << roadnums << endl;;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			cout << minMap[i][j] << "\t";
		cout << endl;
	}
}
/*
3 4 2
1 2
3 4
1 1
2 2
*/