//面试题18：删除链表的节点
//题目一：在O(1)时间内删除链表节点 

//方法：
//1.已知删除节点非尾节点，则将删除节点的值置为下一个节点的值index->next->val，无需遍历
//2.已知删除节点是尾节点，需要遍历，找到前一个节点 

#include <iostream> 
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
};



void createLinkList(ListNode *head, int n){
	ListNode *p;
	ListNode *temp;
	p = head;
	for(int i = 0; i < n; i++){
		temp = new ListNode;
		temp->val = i;
		temp->next = p->next;
		p->next = temp;
	}
}

void Print(ListNode *head){
	ListNode *p;
	p = head->next;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
}

ListNode *FindPtr(ListNode *head, int num){
	ListNode *p;
	p = head->next;
	while(p){
		if(p->val == num){
			ListNode *q;
			q = p;
			return q;
		}else{
			p = p->next;
		}
	}
	return nullptr;
}

void DeletePtr(ListNode *head, ListNode *index){
	if(index->next == NULL){
		ListNode *p;
		p = head;
		while(p->next->next){
			p = p->next;
		}
		p->next = NULL;
		delete index;
	}else{
		ListNode *p;
		p = index->next;
		index->val = p->val;
		index->next = p->next;
		delete p;
	}
}



int main(){
	ListNode *head;
	head = new ListNode;
	head->val = -1;
	head->next = NULL;
	createLinkList(head, 10);
//	Print(head);
	ListNode *f = FindPtr(head, 0);
	DeletePtr(head, f);
	Print(head);
	return 0;
}
