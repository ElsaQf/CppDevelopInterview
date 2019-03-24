//面试题22：链表中倒数第k个节点
//题目：输入一个链表，输出该链表中倒数第k个节点
//
//方法：
//倒数第k个，就是正数第n-k+1个
//定义两个指针：
//第一个从头开始，移到第k-1个时，第二个指针从头开始一起移动
//直到第一个指针移动到最后（二者保持k-1的距离） 
//此时第二个指针正好移动到第n-k+1个，即倒数第k个 

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
}; 

ListNode *createList(int a[], int n){//尾插法 
	ListNode *head;
	ListNode *end = NULL;
	head = new ListNode;
	head->next = NULL;
	end = head;
	int count = 0;
	for(int i = 0; i < n; i++){
		ListNode *node = new ListNode;
		node->val = a[i];
		node->next = NULL;
		end->next = node;
		end = node;
	}
	return head;
}
void Print(ListNode *head){
	ListNode *p;
	p = head->next;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

ListNode *findK(ListNode *L, int k){
	ListNode *p;
	ListNode *q;
	p = L->next;
	q = L->next;
	for(int i = 1; p; i++){
		if(i > k){
			q = q->next;
		}
		p = p->next;
		
	}
	return q;
}

int main(){
	int a[] = {1,2,3,4,5,6};
	int n = 6;
	ListNode *List = createList(a, n);
	Print(List);
	int k = 3;
	cout << "倒数第k个节点：";
	ListNode *node_k = findK(List, k);
	cout << node_k->val;
	 
	
	return 0;
}
