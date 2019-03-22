//面试题17：打印从1到最大的n位数
//
//方法：
//不能循环输出1~99...9，大数
//1.使用字符串输出 
//2.全排列 

#include <iostream>
#include <cstring>
using namespace std;

//1.使用字符串输出 
bool selfIncrement(char *number){
	bool isOverflow = false;
	int carry = 0;
	int length = strlen(number);
	
	for(int i = length - 1; i >= 0; i--){
		int iSum;
		iSum = number[i] - '0' + carry;
		if(i == length - 1){
			iSum++;
		}
		if(iSum >= 10){
			if(i == 0){
				isOverflow = true;
			}else{
				iSum -= 10;
				carry = 1;
				number[i] = '0' + iSum;
			}
		}else{
			number[i] = '0' + iSum;
			break;
		}
	}
	return isOverflow;
}

void printNumber(char *number){
	bool isBeginningEqual0 = true;
	int length = strlen(number);
	
	for(int i = 0; i < length; i++){
		if(isBeginningEqual0 && number[i] != '0'){
			isBeginningEqual0 = false;
		}
		if(!isBeginningEqual0){
			cout << number[i];
		}
	}
	cout << endl;
}


void printToMax(int n){
	if(n <= 0){
		return;
	}
	char *number = new char[n+1];
	memset(number, '0', n);
	while(!selfIncrement(number)){
		printNumber(number);
	}
	
	delete[] number;
} 

//2.全排列 
bool print1ToMaxN(const int n);
bool print1ToMaxNRecursion(char *a, int size, int index);
bool printNum(char *a, int size);

bool print1ToMaxN(const int size){
	if(size <= 0){
		return false;
	}
	char *a = new char[size];
	for(int i = 0; i <= 9; i++){
		a[0] = i + '0';
		print1ToMaxNRecursion(a, size, 1);
	}
	return true;
}

bool print1ToMaxNRecursion(char *a, int size, int index){
	if(size <= 0 || index < 0){
		return false;
	}
	if(index == size){
		printNum(a, size);
		return true;
	}
	for(int i = 0; i <= 9; i++){
		a[index] = i + '0';
		print1ToMaxNRecursion(a, size, index+1);
	}
}

bool printNum(char *a, int size){
	if(size <= 0){
		return false;
	}
	bool IsPre0 = true;
	for(int i = 0; i < size; i++){
		if(IsPre0 && a[i] != '0'){
			IsPre0 = false;
		}
		if(!IsPre0){
			cout << a[i];
		}
	}
	cout << "\t";
}



int main(){
	int n = 3;
//	printToMax(n);
	print1ToMaxN(n);
	
	return 0;
}
