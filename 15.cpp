//面试题15：二进制中1的个数
//题目：实现一个函数，输入一个整数，输出该数的二进制表示中1的个数
//输入9，1001（二进制），输出2 

//方法：我没有用位运算，直接十进制转二进制 

#include <iostream>
#include <vector>
using namespace std;

int countBinary(int num){
	int count = 0;
	vector<int> binary_num;
	while(num){
		binary_num.push_back(num%2);
		num /= 2;
	}
	int len = binary_num.size();
	for(int i = 0; i < len; i++){
		if(binary_num[i] == 1){
			count++;
		}
	}
	return count;
}

int main(){
	int num;
	
	cout << "输入整数：";
	cin >> num;
	cout << "输出二进制中1的个数：" << countBinary(num);
	
	return 0;
}
