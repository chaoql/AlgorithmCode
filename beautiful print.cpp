#include"AExam.h"
#define INF 1000
using namespace std;

int wordsLen(int wordsL[], int i, int j) {
	//计算从i到j的单词总长度
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
	cin >> n >> M;//n个单词，每行最多M个字符
	for (int i = 1; i <= n; i++) {
		cin >> words[i];
		l[i] = words[i].size();
		c[i] = INF;
	}
	for (int i = 1; i <= n; i++) {  //此行从第i个开始放
		for (int j = i; j <= n; j++) {  //放到第j个
			extra[i][j] = M - j + i - wordsLen(l, i, j);  //如果i到j放到一行，那么这行对有多少个剩余空格
			if (extra[i][j] < 0)  //这行放不下这么多单词
				lc[i][j] = INF;
			else if (j == n && extra[i][j] >= 0)  //最有一行
				lc[i][j] = 0;
			else  //正常情况
				lc[i][j] = pow(extra[i][j], 3);
			if (c[i - 1] + lc[i][j] < c[j]) {  //从i处分行是否空格更少
				c[j] = min(c[i - 1] + lc[i][j], c[j]);  //整篇文章从1到j存放单词的空格立方之和
				//position数组很多值都是无意义的，因为动态规划是从前往后算的，但是只有最后的数值才是全局的最优，输出时由果导因，即从后往前看。
				position[j] = i;  //对于以j为结尾的一行来说，本行最佳起始位置为i
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
	cout << "\n总剩余空格数：" << c[n];
}
/*
10 8
abc de h polq cs opaqe gh t asd th
*/