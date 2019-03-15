//面试题6：从尾到头打印链表
//方法一：链表转置
//方法二：栈 

#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
};

class LinkList{
	private:
		ListNode *head;
	public:
		LinkList();
		void CreateLinkList(int a[], int len);
		void Print();
		
		void PrintReverse();
		void LinkListReverse();
};

LinkList::LinkList(){
	head = new ListNode;
	head->next = NULL;
}

void LinkList::CreateLinkList(int a[], int len){
	ListNode *p, *s;
	p = head;
	for(int i = 0; i < len; i++){
		s = new ListNode;
		s->val = a[i];
		s->next = p->next;
		p->next = s;
	}
}

void LinkList::Print(){
	ListNode *p;
	p = head->next;
	cout << "Print LinkList: ";
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

void LinkList::PrintReverse(){
	stack<int> s;
	ListNode *p;
	p = head->next;
	while(p){
		s.push(p->val);
		p = p->next;
	}
	cout << "PrintReverse: ";
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void LinkList::LinkListReverse(){//链表反转我好菜啊！！ 
	ListNode *pre, *cur;
	pre = head->next;
	
	while(pre->next){
		cur = pre->next;
		cout << "currrent: " << cur->val << endl;
		pre->next = cur->next;
		cur->next = head->next;
		head->next = cur;
	}
}

int main(){
	int a[] = {1,2,3,4};
	int len = sizeof(a) / sizeof(int);
	LinkList list;
	list.CreateLinkList(a, len);
	list.Print();
//	list.PrintReverse();
	list.LinkListReverse();
	list.Print();
	
	
	return 0;
}
