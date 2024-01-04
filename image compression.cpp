#include "AExam.h"
#define VLength 100 
#define LMAX 256
#define HEADER 11
using namespace std;

int length(int x) {  //�������ݴ洢λ��
	int num = 0;
	while (x / 2.0>=1) {
		x = x / 2.0;
		num++;
	}
	if (x > 0)
		num++;
	return num;
}
void compress(int n, int S[], int l[], int b[], int P[]) {//����S[i]Ϊǰi�������źϲ��Ĵ洢λ��
	S[0] = 0;
	for (int i = 1; i <= n; i++) {//����ÿһ�����ص�
		//ÿ���µ����ص㵥���ɶ�
		b[i] = length(P[i]);//���µ�iλ������λ��
		int bmax = b[i];
		S[i] = S[i - 1] + bmax;
		l[i] = 1;
		for (int j = 2; j <= i && j <= LMAX; j++) {//��������ֶγ��ȣ�j=2��ʾ������Ϊһ��
			bmax = bmax > b[i - j + 1] ? bmax : b[i - j + 1];//ǰi�����صĺ�j�����ص��������λ��
			if (S[i] > S[i - j] + j * bmax) {//��j������һ��ķ��鷽������
				S[i] = S[i - j] + j * bmax;
				l[i] = j; //ǰi�����صĺ�j������Ϊһ��
			}

		}
		S[i] += HEADER;//�·������Ǿ�Ҫ���ϸ�����Ϣ11λ
	}
}
void IC() {
	int n;//���ص���Ŀ
	int P[VLength];//���ص�
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> P[i];
	int S[VLength], l[VLength], b[VLength];//S[i]Ϊǰi�������źϲ��Ĵ洢λ����l[i]��ʾ��i���ǰl[i]�����ص�Ϊһ�飬b[i]Ϊ��i�����صĴ洢����
	compress(n, S, l, b, P);
	int temp = n;
	stack<int> Length, beginP;//��¼�ֶγ��Ⱥͷֶ���ʼλ��
	while (temp) {
		//���ŷֶε����һ�εĶγ��Ⱥ�����λ���ֱ�洢��l[n], b[n]��,ǰһ�εĶγ��Ⱥ�����λ���洢��l[n - l[n]]�� b[n - l[n]]��.
//		S[m++] = temp - l[temp];//S����ֻ��¼�м���̣��õ�l��b������Ѿ�����ҪS���飬���������¼����λ��
		Length.push(l[temp]);
		beginP.push(temp - l[temp] + 1);
		temp -= l[temp];
	}
	cout << "���֣�" << Length.size() << "��" << endl;
	while (Length.size()) {
		cout << "����ʼλ�ã�" << beginP.top() << " ";
		cout << "�γ��ȣ�" << Length.top() << " ";
		int bmax = INT_MIN;
		for (int i = 0; i < Length.top(); i++) //ȷ��ÿ���ֶ������Ĵ洢λ��
			bmax = bmax > b[beginP.top() + Length.top() - 1] ? bmax : b[beginP.top() + Length.top() - 1];
		cout << "�洢λ����" << bmax << endl;
		Length.pop();
		beginP.pop();
	}
}
/*
�������ݣ�
6
10 12 15 255 1 2
16
10 9 12 40 50 35 15 12 8 10 9 15 11 130 160 240
*/