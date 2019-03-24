//面试题24：反转链表
 
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
};

ListNode *createList(int a[], int n){
	ListNode *head = new ListNode;
	head->next = NULL;
	ListNode *p = head;
	for(int i = 0; i < n; i++){
		ListNode *node = new ListNode;
		node->val = a[i];
		node->next = p->next;
		p->next = node;
	}
	return head;
}

void Print(ListNode *head){
	ListNode *p = head->next;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

void reverse(ListNode *head){
	ListNode *pre;
	ListNode *cur;
	pre = head->next;
	while(pre->next){
		cur = pre->next;
		pre->next = cur->next;
		cur->next = head->next;
		head->next = cur;
	}
}

int main(){
	int a[] = {1,2,3,4,5,6};
	int n = 6;
	ListNode *List = createList(a, n);
	Print(List);
	reverse(List);
	Print(List);
	cout << "反转后的链表头结点：" << List->next->val;
	
	return 0;
}
