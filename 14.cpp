//面试题14：剪绳子
//题目：一段长为n的绳子，剪成m段(n>1, m>1)，使得每段长度乘积最大
//
//方法一：动态规划
//方法二：贪心 


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 动态规划 
int cutRope(int length){
	if(length <= 1){
		return 0;
	}
	if(length == 2){
		return 1;
	}
	if(length == 3){
		return 2;
	}
	
	vector<int> backup{0,1,2,3};
	
	for(int i = 4; i <= length+1; i++){
		int max = 0;
		
		for(int j = 1; j <= (i/2); j++){
			int temp = backup[j] * backup[i-j];
			if(temp > max){
				max = temp;
			}
		}
		backup.push_back(max);
	}
	
	return backup[length];
}

// 贪心 
//长度大于等于5时，尽量分为长度为3的段
//剩下4时，分为2*2最好
int cutRope2(int length){
	if(length <= 1){
		return 0;
	}
	if(length == 2){
		return 1;
	}
	if(length == 3){
		return 2;
	}
	if(length == 4){
		return 3;
	}
	
	int timeOf3 = length / 3;
	int product = 0;
	int result = length - timeOf3 * 3;
	
//	处理不同余数的情况：
//	余数为0: pow(3, timeOf3)
//	余数为1：timeof3--, 剩下4(分为2*2最好),pow(3, timeOf3)*4
//	余数为2：pow(3, timeOf3)*2 
	
	if(result == 0){
		product = pow(3, timeOf3);
	}else if(result == 2){
		product = pow(3, timeOf3) * 2;
	}else if(result == 1){
		timeOf3--;
		product = pow(3, timeOf3) * 4;
	}
	return product;
}

int main(){
	cout << "Enter the rope length: ";
	int n;
	while(cin >> n){
		cout << cutRope2(n) << endl;
	}
	return 0;
}
