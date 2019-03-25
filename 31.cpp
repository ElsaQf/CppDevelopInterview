//面试题31：栈的压入、弹出序列
//题目：输入两个整数序列，第一个表示栈的压入序列，判断第二个是否是栈的弹出序列
//
//方法：
//两个序列a,b,设置一个辅助栈st,
//st.empty() -> st.push(a[j])
//st.top() == b[i] -> pop
//st.top() != b[i] -> push(a[j])
//跳出循环后，若st.empty(),则返回true 

#include <iostream>
#include <stack>
using namespace std;

bool isOrder(int a[], int b[], int n){
	stack<int> st;
	int i = 0, j = 0;
	while(i < n){
		if(j > n){
			break;
		}
		if(st.empty()){
			st.push(a[j]);
			j++;
		}else{
			if(st.top() == b[i]){
				st.pop();
				i++;
			}else{
				if(j < n){
					st.push(a[j]);
					j++;
				}else{
					break;
				}
			}
		}
	}
	return st.empty();
}


int main(){
	int a[] = {1,2,3,4,5};
	int b[] = {4,5,3,2,1};
	
	if(isOrder(a, b, 5)){
		cout << "Yes";
	}else{
		cout << "No";
	}
	
	return 0;
} 
