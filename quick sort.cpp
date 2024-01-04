#include"AExam.h"
using namespace std;

void swap(int nums[], int a, int b) {
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

int getMid(int nums[], int n, int low, int high) {
	int flag = low;
	while (low < high) {
		while (low < high && nums[high] >= nums[flag]) high--;
		swap(nums, flag, high);
		flag = high;
		while (low < high && nums[low] <= nums[flag]) low++;
		swap(nums, low, flag);
		flag = low;
	}
	return flag;
}

void quickSort(int nums[], int n, int low, int high) {
	if (low >= high)
		return;
	int mid = getMid(nums, n, low, high);
	quickSort(nums, n, low, mid - 1);
	quickSort(nums, n, mid + 1, high);
}

void output1d(int nums[], int n) {
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
}

void qsort() {
	int numbers[10], n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	quickSort(numbers, n, 0, n - 1);
	output1d(numbers, n);
}
/*
9
9 5 1 3 6 7 8 4 2
*/