//面试题4：二维数组中的查找
//题目：在一个二维数组中，每一行从左到右递增，每一列从上到下递增
//请完成一个函数，数据一个二维数组和一个整数，判断数组中是否含有该整数 

// 方法：从右上角开始，
//target<a[i][j] -> 向左走 j-- 
//target>a[i][j] -> 向下走 i++ 

#include <iostream>
using namespace std;

bool Find(int *matrix, int rows, int cols, int n){
	int row = 0, col = cols - 1;
	while(row < rows && col >= 0){
		if(n == matrix[row*cols+col]){
			return true;
		}else if(n < matrix[row*cols+col]){
			col--;
		}else{
			row++;
		}
	}
	return false;
}

int main(){
	int matrix[][4] = {{1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15}};
	int i = 10;
	bool found = Find((int *)matrix, 4, 4, i);
	if(found){
		cout << "Found";
	}else{
		cout << "Not Found";
	}
	return 0;
}
