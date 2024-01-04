#include"AExam.h"
#define INF 0x3f3f3f3f
using namespace std;

void max_min() {
	priority_queue<int, vector<int>, greater<int>> minq;
	vector<int> maxv;
	int n, min, max;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		minq.push(temp);
		maxv.push_back(temp);
	}
	sort(maxv.begin(), maxv.end());//默认从小到大
	while (minq.size() > 1) {
		int a = minq.top();
		minq.pop();
		int b = minq.top();
		minq.pop();
		minq.push(a * b + 1);
	}
	max = minq.top();
	//找最小值不用再排序，因为每次都取最大值乘积加一，绝对比所有数都大，直接放最后就行
	for (int i = 0; i < n - 1; i++) {
		maxv[n - i - 2] = maxv[n - i - 1] * maxv[n - i - 2] + 1;
	}
	min = maxv[0];
	cout << "max=" << max << "\nmin=" << min << endl;
	cout << max - min;
}
/*
3
3 5 7
*/