#include "AExam.h"
#define VLength 100 
#define LMAX 256
#define HEADER 11
using namespace std;

int length(int x) {  //计算数据存储位数
	int num = 0;
	while (x / 2.0>=1) {
		x = x / 2.0;
		num++;
	}
	if (x > 0)
		num++;
	return num;
}
void compress(int n, int S[], int l[], int b[], int P[]) {//更新S[i]为前i个段最优合并的存储位数
	S[0] = 0;
	for (int i = 1; i <= n; i++) {//遍历每一个像素点
		//每个新的像素点单独成段
		b[i] = length(P[i]);//更新第i位的像素位数
		int bmax = b[i];
		S[i] = S[i - 1] + bmax;
		l[i] = 1;
		for (int j = 2; j <= i && j <= LMAX; j++) {//倒序遍历分段长度，j=2表示后俩点为一组
			bmax = bmax > b[i - j + 1] ? bmax : b[i - j + 1];//前i个像素的后j个像素的最大像素位数
			if (S[i] > S[i - j] + j * bmax) {//后j个像素一组的分组方法更优
				S[i] = S[i - j] + j * bmax;
				l[i] = j; //前i个像素的后j个像素为一组
			}

		}
		S[i] += HEADER;//新分了组那就要加上附加信息11位
	}
}
void IC() {
	int n;//像素点数目
	int P[VLength];//像素点
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> P[i];
	int S[VLength], l[VLength], b[VLength];//S[i]为前i个段最优合并的存储位数，l[i]表示第i点的前l[i]个像素点为一组，b[i]为第i个像素的存储长度
	compress(n, S, l, b, P);
	int temp = n;
	stack<int> Length, beginP;//记录分段长度和分段起始位置
	while (temp) {
		//最优分段的最后一段的段长度和像素位数分别存储于l[n], b[n]中,前一段的段长度和像素位数存储于l[n - l[n]]和 b[n - l[n]]中.
//		S[m++] = temp - l[temp];//S数组只记录中间过程，得到l和b数组后已经不需要S数组，因此用来记录划分位置
		Length.push(l[temp]);
		beginP.push(temp - l[temp] + 1);
		temp -= l[temp];
	}
	cout << "共分：" << Length.size() << "段" << endl;
	while (Length.size()) {
		cout << "段起始位置：" << beginP.top() << " ";
		cout << "段长度：" << Length.top() << " ";
		int bmax = INT_MIN;
		for (int i = 0; i < Length.top(); i++) //确定每个分段中最大的存储位数
			bmax = bmax > b[beginP.top() + Length.top() - 1] ? bmax : b[beginP.top() + Length.top() - 1];
		cout << "存储位数：" << bmax << endl;
		Length.pop();
		beginP.pop();
	}
}
/*
测试数据：
6
10 12 15 255 1 2
16
10 9 12 40 50 35 15 12 8 10 9 15 11 130 160 240
*/