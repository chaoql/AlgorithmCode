#include "AExam.h"
#define pN 1000
using namespace std;

struct Node
{
	double x, y;
};
int pointNumber = pN;
Node P[pN];

bool cmp(Node& a, Node& b) {
	return a.x < b.x;
}

void Merge(int l, int r) {//�鲢����Ĺ鲢��������y����
	int mid = (l + r) / 2, i = l, j = mid + 1;
	vector<Node> temp;
	while (i <= mid && j <= r) {
		if (P[i].y < P[j].y) 
			temp.push_back(P[i++]);
		else 
			temp.push_back(P[j++]);
	}
	while (i <= mid)
		temp.push_back(P[i++]);
	while (j <= r)
		temp.push_back(P[j++]);
	for (int i = l; i < temp.size(); i++)
		P[i] = temp[i];
}
void CreatePoints(Node Points[], int pointNumber) {//������ɵ�����
	srand(time(NULL));
	for (int i = 0; i < pointNumber; i++) {
		Points[i].x = rand();
		Points[i].y = rand();
		//ÿ1000�����ݳ���һ���ض������������ݾ�����ɢ�������ظ�
		Points[i].x *= ((i / 1000.0) + 1);
		Points[i].y *= ((i / 1000.0) + 1);
		for (int j = 0; j < i; j++) {//�����Ѿ����ɵ����е㣬һ�������غ����������ɸõ�
			if (Points[j].x == Points[i].x && Points[j].y == Points[i].y) {
				i--;
				break;
			}
		}
	}
}
double dis(Node p1, Node p2) {//�����Ծ���
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double mergeMethod(Node P[], int l, int r, Node &p1, Node &p2) {//����˼·��������������
	if (r - l <= 1)
		return INT_MAX;
	else if (r - l == 2) {
		//Merge(l, r);
		p1 = P[l];
		p2 = P[r];
		return dis(p1, p2);
	}
	else {
		Node l1, l2, r1, r2;
		int mid = (l + r) / 2;
		double mindis=INT_MAX;
		double middleX = P[mid].x; //����
		double mindis1 = mergeMethod(P, l, mid, l1, l2); //���������
		double mindis2 = mergeMethod(P, mid + 1, r, r1, r2); //�Ҳ�������
		if (mindis1 < mindis2) {
			mindis = mindis1;
			p1 = l1;
			p2 = l2;
		}
		else{
			mindis = mindis2;
			p1 = r1;
			p2 = r2;
		}
		vector<Node> temp;
		Merge(l, r);//����y����
		for (int i = l; i <= r; i++) {  //�ҵ����м�����ĵ�
			if (fabs(P[i].x - middleX) <= mindis) {
				temp.push_back(P[i]);
			}
		}
		double tempDis = INT_MAX;
		for (int i = 0; i < temp.size(); i++) {  //�����м����飬ÿ����������������6�Σ���¼��̾���͵��
			for (int j = i + 1; j < i + 1 + 6 && j < temp.size(); j++) {
				tempDis = dis(temp[i], temp[j]);
				if (tempDis < mindis) {
					mindis = tempDis;
					p1 = temp[i];
					p2 = temp[j];
				}
			}
		}
		temp.clear();
		return mindis;
	}
}

void NPOP() {
	CreatePoints(P, pointNumber);  //������ɲ�������
	cout << "���е�ԣ�" << endl;
	for (int i = 0; i < pointNumber; i++)
		cout << "��" << P[i].x << ", " << P[i].y << "��" << endl;
	cout << "------------------"<<endl;
	Node minPoint1, minPoint2;
	sort(P, P + pointNumber, cmp);  //��x���п���
	double dis = mergeMethod(P, 0, pointNumber - 1, minPoint1, minPoint2);  //�����㷨���������
	cout << "�����Ծ��룺"<< dis << endl;
	cout << "�����ԣ���" << minPoint1.x << "," << minPoint1.y << "��-��" << minPoint2.x << "," << minPoint2.y << ")" << endl;
}