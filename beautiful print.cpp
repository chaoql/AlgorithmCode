#include"AExam.h"
#define INF 1000
using namespace std;

int wordsLen(int wordsL[], int i, int j) {
	//�����i��j�ĵ����ܳ���
	int sum = 0;
	for (int k = i; k <= j; k++) {
		sum += wordsL[k];
	}
	return sum;
}

void beautifulPrint() {
	int n, M, extra[100][100], lc[100][100], c[100], l[100], position[100];
	string words[100];
	c[0] = 0;
	cin >> n >> M;//n�����ʣ�ÿ�����M���ַ�
	for (int i = 1; i <= n; i++) {
		cin >> words[i];
		l[i] = words[i].size();
		c[i] = INF;
	}
	for (int i = 1; i <= n; i++) {  //���дӵ�i����ʼ��
		for (int j = i; j <= n; j++) {  //�ŵ���j��
			extra[i][j] = M - j + i - wordsLen(l, i, j);  //���i��j�ŵ�һ�У���ô���ж��ж��ٸ�ʣ��ո�
			if (extra[i][j] < 0)  //���зŲ�����ô�൥��
				lc[i][j] = INF;
			else if (j == n && extra[i][j] >= 0)  //����һ��
				lc[i][j] = 0;
			else  //�������
				lc[i][j] = pow(extra[i][j], 3);
			if (c[i - 1] + lc[i][j] < c[j]) {  //��i�������Ƿ�ո����
				c[j] = min(c[i - 1] + lc[i][j], c[j]);  //��ƪ���´�1��j��ŵ��ʵĿո�����֮��
				//position����ܶ�ֵ����������ģ���Ϊ��̬�滮�Ǵ�ǰ������ģ�����ֻ��������ֵ����ȫ�ֵ����ţ����ʱ�ɹ����򣬼��Ӻ���ǰ����
				position[j] = i;  //������jΪ��β��һ����˵�����������ʼλ��Ϊi
			}
		}
	}
	stack<int> st;
	int i = n;
	while (i > 0) {
		st.push(position[i]);
		i = position[i] - 1;
	}
	st.pop();
	for (int i = 1; i <= n; i++) {
		if (!st.empty() && i == st.top())
		{
			cout << endl;
			st.pop();
		}
		cout << words[i] << ' ';
	}
	cout << "\n��ʣ��ո�����" << c[n];
}
/*
10 8
abc de h polq cs opaqe gh t asd th
*/