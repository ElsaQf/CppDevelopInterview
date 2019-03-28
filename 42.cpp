//面试题42：连续子数组的最大和
//题目：输入一个整型数组，数组中有整数也有负数，求所有子数组的和的最大值
//时间复杂度是O(n) 

#include <iostream>
#include <vector>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array){
	if(array.empty()){
		return 0;
	}
	
	int cur_sum = array[0];
	int max_sum = array[0];
	
	for(int i = 1; i < array.size(); i++){
		if(cur_sum <= 0){
			cur_sum = array[i];
		}else{
			cur_sum += array[i];
		}
		if(cur_sum > max_sum){
			max_sum = cur_sum;
		}
	}
	return max_sum;
} 

int main(){
	vector<int> a = {1,-2,3,10,-4,7,2,-5};
	
	cout << FindGreatestSumOfSubArray(a);
	
	return 0;
}
