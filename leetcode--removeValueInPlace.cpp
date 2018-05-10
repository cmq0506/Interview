/*
leetcode��Ŀ��Given an array and a value, remove all instances of that value 
              in place and return the new length.The order of elements can be
			  changed. It doesn't matter what you leave beyond the new length.
���Ľ��ͣ���Ҫ��ɾ�������е�ָ����ֵvalue�����֣����ҷ����µ����鳤�ȣ��ص���in place���������½����飩
˼·������2���α�i,j
*/
#include<iostream>
#include<vector>
using namespace std;

void removeAndGetLen(vector<int> number, int removeNumber){
	int j = 0;
	for (int i = 0; i < number.size(); i++){
		if (number[i] != removeNumber){
			swap(number[i], number[j]);
			j++;
		}
	}
	number.erase(number.begin() + j, number.end());
	for (int i = 0; i < number.size(); i++){
		cout << number[i] << " ";
	}
	cout << "��������ĳ���Ϊ" << j << endl;
}

int main(){
	int temp, removeNumber;
	//removeNumber��ʾҪɾ����ֵ
	cin >> removeNumber;
	vector<int> number;
	do{
		cin >> temp;
		number.push_back(temp);
	} while (cin.get() != '\n');
	removeAndGetLen(number, removeNumber);
	system("pause");
	return 0;
}