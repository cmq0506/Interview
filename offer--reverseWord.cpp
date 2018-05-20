#include<iostream>
#include<string>
using namespace std;

void reverse(string& str, int startIndex, int endIndex){
	while (startIndex<endIndex){
		swap(str[startIndex], str[endIndex]);
		startIndex++;
		endIndex--;
	}
}

/*
翻转单词顺序列
*/
string ReverseSentence(string str) {
	int startIndex = 0;
	int endIndex = str.size() - 1;
	reverse(str, startIndex, endIndex);
	//如何找出句子中的单词：因为单词与单词之间是用空格隔开的
	startIndex = endIndex = 0;
	//如果endIndex没有到字符串的末尾
	while (str[startIndex] != '\0'){
		while (str[endIndex] != '\0' && str[endIndex] != ' '){
			endIndex++;
		}
		reverse(str, startIndex, endIndex - 1);
		if (str[endIndex] != '\0'){
			endIndex++;
		}
		startIndex = endIndex;
	}
	return str;
}

/*
左旋转字符串
*/
string LeftRotateString(string str, int n) {
	if (str.size()<1){
		return str;
	}
	int startIndex = 0;
	int endIndex = str.size() - 1;
	reverse(str, startIndex, endIndex);
	if (n>str.size()){
		return str;
	}
	startIndex = 0;
	endIndex = str.size() - 1 - n;
	reverse(str, startIndex, endIndex);
	startIndex = endIndex + 1;
	endIndex = str.size() - 1;
	reverse(str, startIndex, endIndex);
	return str;
}

int main(){
	string str="I am a student.";
	string outputStr1 = ReverseSentence(str);
	string outputStr2 = LeftRotateString(str,3);
	cout << outputStr1 << endl;
	cout << outputStr1 << endl;
	return 0;
	system("pause");
}