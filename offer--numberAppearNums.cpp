#include<iostream>
#include<vector>
using namespace std;

int GetEndK(vector<int> data, int k){
	int start = 0;
	int end = data.size() - 1;
	int mid;
	while (start <= end){
		mid = (start + end) / 2;
		if (data[mid] == k){
			if (mid == data.size() - 1){
				return mid;
			}
			if (data[mid + 1] != k){
				return mid;
			}
			else{
				start = mid + 1;
			}
		}
		else if (data[mid] > k){
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	return -1;
}

int GetFirstK(vector<int> data, int k){
	int start = 0;
	int end = data.size() - 1;
	int mid;
	while (start <= end){
		mid = (start + end) / 2;
		if (data[mid] == k){
			if (mid == 0){
				return mid;
			}
			if (data[mid - 1] != k){
				return mid;
			}
			else{
				end = mid - 1;
			}
		}
		else if (data[mid] > k){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return -1;
}

int GetNumberOfK(vector<int> data, int k) {
	//�ö��ֲ��ң��ֱ��ҳ���һ��k�����һ��k
	int firstK = GetFirstK(data, k);
	int endK = GetEndK(data, k);
	if (firstK == -1 || endK == -1){
		return 0;
	}
	return endK - firstK + 1;
}

int main(){
	int n, k, temp;
	vector<int> data;
	cout << "�������������ܵĸ�����";
	cin >> n;
	cout << "������Ҫ���ҵ������ǣ�";
	cin >> k;
	cout << "���������������е�����";
	for (int i = 0; i < n; i++){
		cin >> temp;
		data.push_back(temp);
	}
	GetNumberOfK(data, k);
	return 0;
}