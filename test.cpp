/*
��Ŀ����������÷���
	  1�����ö������n��������ȡ��top-k����������
	  2����Ҫʹ����С�ѣ�ά��k�߶ȵĶ�
*/
#include<iostream>
#include<vector>
using namespace std;

void headAdjust(vector<int> &arr, int start, int end){
	int temp = arr[start];
	//i����ָ�����������
	int i = start * 2 + 1;
	while (i <= end){
		//����������������С��
		if (i + 1 <= end&&arr[i] > arr[i + 1]){
			//�����������������������iָ��������
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
	//�������Ǵӵ�һ����Ҷ�ڵ㿪ʼ�������ϸ��£�ֱ�����µ����ڵ�Ϊֹ
	for (int i = end / 2 - 1; i >= 0; i--){
		headAdjust(arr,i,end);
	}
	//������ж�����
	for (int i = end; i-1 >= 0; i--){
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		headAdjust(arr, 0, i-1);
	}
}

int main(){
	//������ά��k����С����С��
	int k;
	int n;
	cin >> n;
	cout << "top-k��ֵΪ��";
	cin >> k;
	cout << "�����������飬Ȼ���ҳ�top-" << k << "��ֵ" << endl;
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
	//�Զѽ�����С������
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