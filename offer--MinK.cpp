/*
实现：最小的k个数
*/
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& number, int start, int end){
	int index = end;
	int j = start - 1;
	for (int i = start; i < end; i++){
		if (number[i] < number[index]){
			swap(number[i], number[j+1]);
			j++;
		}
	}
	swap(number[j+1], number[index]);
	return j + 1;
}

void quickSort(vector<int>& number, int start, int end){
	if (start < end){
		int position = partition(number, start, end);
		quickSort(number, start, position-1);
		quickSort(number, position+1, end);
	}
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
	int start = 0;
	int end = input.size() - 1;
	int position = partition(input, start, end);
	while (position != k && position != (k + 1)){
		if (position < k){
			start = position+1;
		}
		else{
			end = position-1;
		}
		position = partition(input, start, end);
	}
	vector<int> kMinNumber;
	kMinNumber.assign(input.begin(), input.begin() + k);
	quickSort(kMinNumber, 0, kMinNumber.size() - 1);
	return kMinNumber;
}

int main(){
	vector<int> number;
	//输入n个数，找出前k个小的数
	int n,k;
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		number.push_back(temp);
	}
	vector<int> kMinNumber = GetLeastNumbers_Solution(number, k);
	for (int i = 0; i < kMinNumber.size(); i++){
		cout << kMinNumber[i] << " ";
	}
	system("pause");
	return 0;
}