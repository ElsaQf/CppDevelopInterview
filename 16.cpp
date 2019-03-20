//面试题16：数值的整数次方
//题目：实现函数double Power(double base, int exponent),求base的exponent次方
//不得使用库函数，同时不需要考虑大数问题

//方法：
//1.底数为0，不合法，返回0
//2.指数为0，返回1
//3.指数为负，先求指数为正时的值，再取倒数 

#include <iostream>
using namespace std;

double Power(double base, int exponent){
	if(int(base) == 0){
		return 0;
	}
	if(exponent == 0){
		return 1;
	}
	int exp = abs(exponent);
	double result = 1.0;
	for(int i = 0; i < exp; i++){
		result *= base;
	}
	if(exponent < 0){
		result = 1.0 / result;
	}
	return result;
}

int main(){
	int base = 2, exponent = -5;
	cout << Power(base, exponent);
	
	return 0;
}
