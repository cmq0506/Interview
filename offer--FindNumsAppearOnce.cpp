#include<iostream>
#include<vector>
using namespace std;

unsigned int findBinaryFirstOne(int number){
	int indexBit = 0;
	//(number & 1)这里一定要括号，如果不打括号的话，会出现问题
	while (((number & 1) == 0) && indexBit < (8 * sizeof(int))){
		number = number >> 1;
		indexBit++;
	}
	return indexBit;
}

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	int sum = 0;
	for (int i = 0; i<data.size(); i++){
		sum ^= data[i];
	}
	unsigned int index = findBinaryFirstOne(sum);
	*num1 = *num2 = 0;
	for (int i = 0; i<data.size(); i++){
		int temp = data[i];
		temp = temp >> index;
		if (temp & 1){
			*num1 ^= data[i];
		}
		else{
			*num2 ^= data[i];
		}
	}
}

int main(){
	vector<int> data = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int num1, num2;
	FindNumsAppearOnce(data, &num1, &num2);
	cout << num1 << endl;
	cout << num2 << endl;
	system("pause");
}