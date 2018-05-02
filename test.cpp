/*
题目：堆排序的用法：
	  1、利用堆排序从n个数字中取出top-k个最大的数字
	  2、主要使用最小堆，维护k尺度的堆
*/
#include<iostream>
#include<vector>
using namespace std;

void headAdjust(vector<int> &arr, int start, int end){
	int temp = arr[start];
	//i这里指向的是左子树
	int i = start * 2 + 1;
	while (i <= end){
		//先找左右子树中最小的
		if (i + 1 <= end&&arr[i] > arr[i + 1]){
			//如果左子树大于右子树，则i指向右子树
			i++;
		}
		if (temp > arr[i]){
			arr[start] = arr[i];
			start = i;
			i = 2 * start + 1;
		}
		else{
			break;
		}
	}
	arr[start] = temp;
}

void heapSort(vector<int> &arr, int start, int end){
	//堆排序是从第一个非叶节点开始从下往上更新，直到更新到根节点为止
	for (int i = end / 2 - 1; i >= 0; i--){
		headAdjust(arr,i,end);
	}
	//下面进行堆排序
	for (int i = end; i-1 >= 0; i--){
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		headAdjust(arr, 0, i-1);
	}
}

int main(){
	//堆排序维护k个大小的最小堆
	int k;
	int n;
	cin >> n;
	cout << "top-k的值为：";
	cin >> k;
	cout << "依次输入数组，然后找出top-" << k << "个值" << endl;
	vector<int> arr(k,0);
	for (int i = 0; i < n; i++){
		if (i > k - 1){
			int temp;
			cin >> temp;
			if (temp > arr[0]){
				arr[0] = temp;
				headAdjust(arr, 0, k - 1);
			}
		}
		else{
			int temp;
			cin >> temp;
			arr[i] = temp;
			if (i == k - 1){
				headAdjust(arr, 0, k - 1);
			}
		}
	}
	//对堆进行最小堆排序
	heapSort(arr, 0, k - 1);
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i];
		if (i < arr.size()-1){
			cout << " ";
		}
	}
	system("pause");
	return 0;
}