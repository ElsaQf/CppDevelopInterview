//面试题29：顺时针打印矩阵 
//
//方法：
//从(i,i)开始，
//从左到右答应一行
//从上到下打印一列
//从右到左打印一行
//从下到上打印一列 

#include <iostream>
using namespace std;

void PrintMatrixInCircle(int numbers[][4], int rows, int cols, int start){
	int endX = cols - start - 1;
	int endY = rows - start - 1;
	
//	从左到右打印一行
	for(int i = start; i <= endX; i++){
		cout << numbers[start][i] << " ";
	} 
//	从上到下打印一列
	if(start < endY){
		for(int i = start + 1; i <= endY; i++){
			cout << numbers[i][endY] << " ";
		}
	} 
//	从右到左打印一列
	if(start < endX && start < endY){
		for(int i = endX - 1; i >= start; i--){
			cout << numbers[endY][i] << " ";
		}
	} 
//	从下到上打印一列
	if(start < endX && start < endY - 1){
		for(int i = endY - 1; i >= start + 1; i--){
			cout << numbers[i][start] << " ";
		}
	} 
} 


int main(){
	int a[4][4];
	int num = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			num++;
			a[i][j] = num;
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for(int i = 0; i < 4; i++){
		PrintMatrixInCircle(a, 4, 4, i);
	}
	
	return 0;
}
