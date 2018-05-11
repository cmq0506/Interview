/*
leetcode题目：Given an array and a value, remove all instances of that value 
              in place and return the new length.The order of elements can be
			  changed. It doesn't matter what you leave beyond the new length.
中文解释：主要是删除数组中的指定数值value的数字，并且返回新的数组长度，重点在in place（即不能新建数组）
思路：设置2个游标i,j
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
	cout << "最终数组的长度为" << j << endl;
}

int main(){
	int temp, removeNumber;
	//removeNumber表示要删除的值
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