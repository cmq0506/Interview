/*
��Ŀ����¼1~n��1���ֵĴ���������1���Ըĳ���������
*/
#include<iostream>
using namespace std;

//����numAppear��ʾĳ�����ֳ��ֵĴ���
#define numAppear 1

int findOneNumber(int n){
	int num = 0;
	int nTemp = n;
	int bit = 1;
	while (nTemp > 0){
		if (nTemp % 10 > numAppear){
			num += bit * (nTemp / 10 + 1); //���ĳһλ����numAppear�Ļ�
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