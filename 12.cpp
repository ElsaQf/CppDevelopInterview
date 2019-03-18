//面试题12：矩阵中的路径
//题目：设计一个函数，判断矩阵中是否存在一条包含字符串所有字符的路径

// 方法：回溯
 

#include <iostream>
#include <cstring>
using namespace std;

void show(char *matrix, int rows, int cols);
bool havePath(char *matrix, const char *str, int rows, int cols);
bool findPath(char *matrix, const char *str, int rows, int cols, int row, int col, bool *visited, int &stepLen);

void Test1();
void Test2();
void Test3();
void Test4();



int main(){
	char matrix[] = "abtgcfcsjdeh";
	const char *str = "bfce";
	
	cout << "矩阵如下：" << endl;
	show(matrix, 3, 4);
	cout << endl; 
	
	bool hasPath = havePath(matrix, str, 3, 4);
	cout << str << " ";
	if(hasPath) {
		cout << "找到路线" << endl;
	}else{
		cout << "没有找到路线" << endl;
	}
	
	return 0;
}

bool havePath(char *matrix, const char *str, int rows, int cols){
	if(matrix == nullptr || rows < 0 || cols < 0){
		return false;
	}
	
	bool *visited = new bool[rows*cols];
	memset(visited, 0, sizeof(visited));
	
	bool hasPath = false;
	int stepLen = 0;
	
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			hasPath = findPath(matrix, str, rows, cols, row, col, visited, stepLen);
			if(hasPath == true){
				return true;
			}
		}
	}
	delete []visited;
	
	return false;
}

bool findPath(char *matrix, const char *str, int rows, int cols, int row, int col, bool *visited, int &stepLen){
	if(matrix == nullptr || str == nullptr){
		return false;
	}
	if(rows < 1 || cols < 1 || row < 0 || row >= rows || col < 0 || col >= cols){
		return false;
	} 
	
	if(str[stepLen] == '\0'){
		return true;
	}
	
	bool isFind = false;
	
	if((str[stepLen] == matrix[row*cols+col]) && (visited[row*cols+col] == false)){
		visited[row*cols+col] = true;
		stepLen++;
		isFind = findPath(matrix, str, rows, cols, row, col-1, visited, stepLen)
				|| findPath(matrix, str, rows, cols, row, col+1, visited, stepLen)
				|| findPath(matrix, str, rows, cols, row-1, col, visited, stepLen)
				|| findPath(matrix, str, rows, cols, row+1, col, visited, stepLen);
				
		if(isFind == false){
			stepLen--;
			visited[row*cols+col] = false;
		}
	}
	
	return isFind;
}


void show(char *matrix, int rows, int cols){
	if(matrix == nullptr){
		return;
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout << matrix[i*cols+j] << " ";
		}
		cout << endl;
	}
}

void Test1(){
	char matrix1[] = "ABCESFCSADEE";
	const char *str1 = "SEE";
	cout << "矩阵路径如下：" << endl;
	show(matrix1, 3, 4);
	cout << endl;
	
	bool hasPath = havePath(matrix1, str1, 3, 4);
	cout << str1 << " ";
	if(hasPath){
		cout << "找到路线" << endl;
	}else{
		cout << "没找到路线" << endl;
	}
}
