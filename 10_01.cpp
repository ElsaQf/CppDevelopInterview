//面试题10：斐波那契数列
//题目一：求斐波那契数列的第n项

//方法一：递归，时间复杂度高
//方法二：非递归 

#include <iostream>
using namespace std;

//递归 
int fibo(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	return fibo(n-1)+fibo(n-2);
} 

// 非递归
int fibo2(int n){
	int a = 0, b = 1;
	if(n == 0){
		return a;
	}
	if(n == 1){
		return b;
	}
	for(int i = 2; i <= n; i++){
		int c = a + b;
		a = b;
		b = c;
	}
	return b;
} 

int main(){
	int n;
	cout << "输入n: ";
	cin >> n;
	cout << "斐波那契数列第n项： " << fibo2(n);
	
	return 0; 
}
