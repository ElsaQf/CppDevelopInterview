//面试题39：数组中出现次数超过一半的数字
//题目：数组中有一个数字出现次数超过数组长度的一半，找出这个数字
//
//方法一：排序，中位数
//方法二：快排中的partition
//方法三：出现次数超过数组长度的一半，说明这个数字的个数比其他数字个数之和还要多
//用计数的方法 

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void printMost(int a[], int n){
	sort(a, a+n);
	cout << a[n/2];
	
}

int MoreThanHalfNum(int a[], int len){
	int result = a[0];
	int count = 1;
	
	for(int i = 1; i < len; i++){
		if(a[i] == result){
			count++;
		}else if(count == 0){
			result = a[i];
			count = 1;
		}else{
			count--;
		}
	}
	
	return result;
}



int Partition2(int *data, int start, int end){
	if(start == end){
		return start;
	}
	int index = start;
	int i = start + 1;
	int j = end;
	while(i <= j){
		while(data[i] <= data[index]){
			i++;
		}
		while(data[j] >= data[index]){
			j--;
		}
		if(i < j){
			swap(data[i], data[j]);
		}else{
			i++;
		}
	}
	swap(data[j], data[index]);
	return j;
}

int MidOfArray(int *data, int length, int start, int end){
	int mid = Partition2(data, start, end);
	if(mid == length/2){
		return data[mid];
	}else if(mid > length/2){
		return MidOfArray(data, length, start, mid-1);
	}else{
		return MidOfArray(data, length, mid+1, end);
	}
}


int main(){
	int a[] = {1,2,3,2,2,2,5,4,2};
	int n = sizeof(a) / sizeof(int);
//	printMost(a, n);
//	cout << MoreThanHalfNum(a, n);
	cout << MidOfArray(a, n, 0, n-1);
	
	return 0;
}
