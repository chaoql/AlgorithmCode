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

void Merge(int l, int r) {//归并排序的归并操作（对y排序）
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
void CreatePoints(Node Points[], int pointNumber) {//随机生成点数据
	srand(time(NULL));
	for (int i = 0; i < pointNumber; i++) {
		Points[i].x = rand();
		Points[i].y = rand();
		//每1000个数据乘以一个特定的数，将数据尽量分散，减少重复
		Points[i].x *= ((i / 1000.0) + 1);
		Points[i].y *= ((i / 1000.0) + 1);
		for (int j = 0; j < i; j++) {//遍历已经生成的所有点，一旦发现重合则重新生成该点
			if (Points[j].x == Points[i].x && Points[j].y == Points[i].y) {
				i--;
				break;
			}
		}
	}
}
double dis(Node p1, Node p2) {//计算点对距离
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double mergeMethod(Node P[], int l, int r, Node &p1, Node &p2) {//分治思路处理最近点对问题
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
		double middleX = P[mid].x; //中线
		double mindis1 = mergeMethod(P, l, mid, l1, l2); //左侧最近点对
		double mindis2 = mergeMethod(P, mid + 1, r, r1, r2); //右侧最近点对
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
		Merge(l, r);//按照y排序
		for (int i = l; i <= r; i++) {  //找到在中间区域的点
			if (fabs(P[i].x - middleX) <= mindis) {
				temp.push_back(P[i]);
			}
		}
		double tempDis = INT_MAX;
		for (int i = 0; i < temp.size(); i++) {  //遍历中间数组，每个点最多遍历其他点6次，记录最短距离和点对
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
	CreatePoints(P, pointNumber);  //随机生成测试数据
	cout << "所有点对：" << endl;
	for (int i = 0; i < pointNumber; i++)
		cout << "（" << P[i].x << ", " << P[i].y << "）" << endl;
	cout << "------------------"<<endl;
	Node minPoint1, minPoint2;
	sort(P, P + pointNumber, cmp);  //对x进行快排
	double dis = mergeMethod(P, 0, pointNumber - 1, minPoint1, minPoint2);  //分治算法求解最近点对
	cout << "最近点对距离："<< dis << endl;
	cout << "最近点对：（" << minPoint1.x << "," << minPoint1.y << "）-（" << minPoint2.x << "," << minPoint2.y << ")" << endl;
}