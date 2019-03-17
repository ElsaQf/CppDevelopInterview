//面试题9：用两个栈实现队列
//题目：用两个栈实现一个队列，实现appendTail和deleteHead两个功能

//方法：
//stack1用来尾插，stack2用来头删
//删除：stack2为空时，stack2.push(stack1.top()),stack1的栈顶元素依次全部压入stack2，弹出stack2.pop()
//插入：stack1.push(i) 

#include <iostream>
#include <stack>
using namespace std;

template<typename T> class CQueue{
	public:
		CQueue(void);
		~CQueue(void);
		
		void appendTail(const T &node);
		T deleteHead();
	private:
		stack<T> stack1;
		stack<T> stack2;
};

template <typename T> void CQueue<T>::appendTail(const T &node){
	stack1.push(node);
}

template <typename T> T CQueue<T>::deleteHead(){
	if(stack2.empty()){
		if(stack1.size() > 0){
			while(!stack1.empty()){
				T elem = stack1.top();
				stack1.pop();
				stack2.push(elem);
			}
		}
	}
	
	T elem = stack2.top();
	stack2.pop();
	
	return elem;
}

template<typename T> CQueue<T>::CQueue(void){}
template<typename T> CQueue<T>::~CQueue(void){}

void Test(){
	CQueue<int> que;
	
	cout << "Push 1,2,3 successively into CQueue." << endl;
	que.appendTail(1);
	que.appendTail(2);
	que.appendTail(3);
	cout << "Pop the head of the queue: " << que.deleteHead() << endl;
	cout << "Pop the head of the queue: " << que.deleteHead() << endl;
	
	cout << "Push 4,5,6 successively into CQueue." << endl;
	que.appendTail(4);
	que.appendTail(5);
	que.appendTail(6);
	
	for(int i = 0; i < 4; i++){
		cout << "Pop the head of the queue: " << que.deleteHead() << endl;
	}
}

int main(){
	Test();
	
	return 0;
}
