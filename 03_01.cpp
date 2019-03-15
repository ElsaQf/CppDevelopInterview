//面试题3：数组中的重复数字

//题目一：找出数组中的重复数字 
//在一个长度为n的数组里的所有数字都在0~n-1范围内。
//数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复几次。
//请找出数组中任意一个重复数字
//例如： 
//如果输入长度为7的数组{2,3,1,0,2,5,3},
//那么对应输出重复数字2或者3 

//方法一：sort 时间复杂度O(nlogn) 
//方法二：hash 时间复杂度O(n) 
//	改变数组顺序，空间复杂度O(1)
//	新建数组，将原来的数组逐个放到新数组中，空间复杂度O(n) 


#include <iostream>
#include <algorithm>
using namespace std;

//验证是否在0~n-1
bool isValid(int nums[], int n){
	for(int i = 0; i < n; i++){
		if(nums[i] < 0 || nums[i] > n-1){
			return false;
		}
	}
	return true;
}

//方法一：排序，时间复杂度O(nlogn)
vector<int> duplication_sort(int nums[], int n){
	sort(nums, nums+n);
	vector<int> dups;
	for(int i = 1; i < n; i++){
		if(nums[i] == nums[i-1]){
			dups.push_back(nums[i]);
		}
	}
	return dups;
}
// 只输出一次重复数字 
void Test1(){
	int nums[8] = {2,3,1,0,2,5,3,3};
	if(isValid(nums, 8)){
		vector<int> dup = duplication_sort(nums, 8);
		dup.erase(unique(dup.begin(), dup.end()), dup.end());//去除dup中的重复数字，只输出一次 
		for(int i = 0; i < dup.size(); i++){
			cout << dup[i] << " ";
		}
	}
}

// 方法二：哈希表，时间复杂度O(n)
// 空间复杂度O(1)：改变数组顺序 
vector<int> duplication_hash(int nums[], int n){
	vector<int> dups;
	for(int i = 0; i < n; i++){
		if(nums[i] != i){
			if(nums[i] != nums[nums[i]]){
				while(nums[i] != nums[nums[i]]){
					int temp = nums[i];
					nums[i] = nums[temp];
					nums[temp] = temp;
				}
			}else{
				dups.push_back(nums[i]);
			}
		}
	}
	return dups;
}
// 空间复杂度O(n)：需要额外的数组空间 
vector<int> duplication_hash2(int nums[], int n){
	int nums2[n];
	vector<int> dups;
	for(int i = 0; i < n; i++){
		nums2[i] = -1;
	}
	for(int i = 0; i < n; i++){
		int j = nums[i];
		if(nums2[j] == -1){
			nums2[j] = j;
		}else{
			dups.push_back(j);
		}
	}
	return dups;
} 


void Test2(){
	int nums[8] = {2,3,1,0,2,5,3,3};
	if(isValid(nums, 8)){
		vector<int> dup = duplication_hash2(nums, 8);
//		dup.erase(unique(dup.begin(), dup.end()), dup.end());//去除dup中的重复数字，只输出一次 
		for(int i = 0; i < dup.size(); i++){
			cout << dup[i] << " ";
		}
	}
}
 


int main(){
	Test2();
	
	return 0;
}
