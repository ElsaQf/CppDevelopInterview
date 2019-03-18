//面试题13：机器人的运动范围
//题目：地上有一个m行n列的方格，
//机器人从(0,0)开始移动，每次可以上下左右移动一格
//但不能进入行列坐标的数位之和大于k的格子
//例如，k=18时，机器人能够进入(35,37),因为3+5+3+7=18
//不能进入(35,38),因为3+5+3+8=19
//问机器人能到达多少个格子？


#include <iostream>
#include <cstring>
using namespace std;

int getWeight(int num1, int num2);
int movingCount(int k, int rows, int cols);
int movingCountCore(int k, int rows, int cols, int row, int col, bool *visited, int &count);

void test(char *testName, int k, int rows, int cols, int expected);
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();


int main(){
	test1();
	
	return 0;
}

void test(char *testName, int k, int rows, int cols, int expected){
	if(testName != nullptr){
		cout << testName << " begin:" << endl;
	}
	cout << "k = " << k << " , rows = " << rows << ", cols = " << cols << endl;
	int count = movingCount(k, rows, cols);
	cout << "expected = " << expected << ", count = " << count << endl;
	if(expected == count){
		cout << expected << " is passed !" << endl;
	}else{
		cout << "Not passed !" << endl;
	}
}

void test1(){
	test("Test1", 5, 10, 10, 21);
}

int movingCount(int k, int rows, int cols){
	if(k < 0 || rows <= 0 || cols <= 0){
		return 0;
	}
	
	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	
	int count = 0;
	count = movingCountCore(k, rows, cols, 0, 0, visited, count);
	
	delete []visited;
	
	return count;
}

int movingCountCore(int k, int rows, int cols, int row, int col, bool *visited, int &count){
	// 机器人不能进入的情况：
	
	// 1.初值不合理 
	if(k < 0 || rows <= 0 || cols <= 0){
		return 0;
	}
	// 2.超出棋盘范围 
	if(row < 0 || row >= rows || col < 0 || col >= cols){
		return 0;
	}
	// 3.数位和超出阈值 
	if(getWeight(row, col) > k){
		return 0;
	}
	// 4.格子已经走过了 
	if(visited[row*cols+col] == true){
		return 0;
	}
	
	if(getWeight(row, col) <= k && visited[row*cols+col] == false){
		visited[row*cols+col] = true;
		count = 1 + movingCountCore(k, rows, cols, row, col-1, visited, count)
				+ movingCountCore(k, rows, cols, row, col+1, visited, count)
				+ movingCountCore(k, rows, cols, row-1, col, visited, count)
				+ movingCountCore(k, rows, cols, row+1, col, visited, count);
	}
	return count;
}

int getWeight(int num1, int num2){
	int sum = 0;
	while(num1){
		sum += num1%10;
		num1 /= 10;
	}
	while(num2){
		sum += num2%10;
		num2 /= 10;
	}
	return sum;
}
