//面试题11：旋转数组的最小数字
//题目：把一个数组最开始的若干个元素搬到数组的末尾，称为数组的旋转
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素
//{3,4,5,1,2}是{1,2,3,4,5}的一个旋转，该数组的最小元素是1 

//方法一：遍历，时间复杂度O(n)，不采用
//方法二：根据旋转数组的特性，数组可分为两部分有序，二分查找，找到最小值
//low = 0, high = n - 1, mid = (low + high) / 2
//low < mid -> low = mid + 1, idx1 = low
//mid < high -> idx2 = mid, high = mid - 1
//取idx小者 

#include <iostream>
using namespace std;

int min_xuanzhuan(int nums[], int n){
	int low = 0, high = n - 1;
	int idx1 = 0, idx2 = 0;
	while(low < high){
		int mid = (low + high) / 2;
		if(nums[low] < nums[mid]){
			low = mid + 1;
			idx1 = low;
		}else if(nums[mid] < nums[high]){
			idx2 = mid;
			high = mid - 1;
		}
	}
	return (nums[idx1] <= nums[idx2]) ? nums[idx1] : nums[idx2];
}


int main(){
	int nums[] = {3,4,5,1,2};
	int n = 5;
	
	cout << min_xuanzhuan(nums, n);
	
	return 0;
}
