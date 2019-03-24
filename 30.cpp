//面试题30：包含min函数的栈
//题目：定义栈的数据结构，实现一个能够找到栈的最小元素的min函数
//在该栈中，调用min,push,pop的时间复杂度都是O(1)
//
//方法：
//构造辅助栈minSt,每次压入st时，比较val和minSt.top()，压入小者进minSt
//这样，minSt.top()就是min
//pop时，st和minSt都要弹出 

#include <iostream>
#include <stack>
using namespace std;

stack<int> st, minSt;

class Solution{
	public:
		stack<int> st, minSt;
		void push(int val){
			st.push(val);
			if(minSt.empty()){
				minSt.push(val);
			}else{
				minSt.push((val < minSt.top()) ? val : minSt.top()); 
			}
		}
		
		void pop(){
			if(!st.empty()){
				st.pop();
				minSt.pop();
			}
		}
		
		int top(){
			if(!st.empty()){
				return st.top();
			}
			return 0;
		}
		
		int min(){
			if(!minSt.empty()){
				return minSt.top();
			}
			return 0;
		}
};

int main(){
	Solution s;
	s.push(3);
	s.push(4);
	s.push(2);
	s.push(1);
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	
	return 0;
}
