/*
题目：记录1~n中1出现的次数，这里1可以改成任意数字
*/
#include<iostream>
using namespace std;

//设置numAppear表示某个数字出现的次数
#define numAppear 1

int findOneNumber(int n){
	int num = 0;
	int nTemp = n;
	int bit = 1;
	while (nTemp > 0){
		if (nTemp % 10 > numAppear){
			num += bit * (nTemp / 10 + 1); //如果某一位大于numAppear的话
		}
		else if (nTemp % 10 == numAppear){
			num += bit * (nTemp / 10);
			num += (n % bit + 1);
		}
		else{
			num += bit * (nTemp / 10);
		}
		nTemp = nTemp / 10;
		bit = bit * 10;
	}
	return num;
}

int main(){
	int n;
	cin >> n;
	int oneNum = findOneNumber(n);
	cout << oneNum;
	system("pause");
	return 0;
}