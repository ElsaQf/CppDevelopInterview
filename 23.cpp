//面试题23：链表中环的入口节点
//题目：若一个链表中包含环，找出环的入口节点
//
//方法：
//1->2->3->4->5->6
//      ^        |
//	  |--------|
//1.判断是否有环
//	设置slow,fast两个指针，slow每次一步，fast每次两步
//	若都不为NULL，且slow==fast，找到相遇点，有环
//2.计算环的长度
//	从相遇点开始计数，到再回到相遇点，count++
//3.设置两个指针，一个从头先走count步，另一个开始从头走
//	直到相遇，相遇点是环的入口 

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
};

ListNode *MeetingNode(ListNode *pHead){
	if(pHead == NULL){
		return NULL;
	}
	ListNode *pSlow = pHead;
	ListNode *pFast = pSlow->next;
	if(pFast == NULL){
		return NULL;
	}
	while(pSlow != NULL && pFast != NULL){
		if(pFast == pSlow){
			return pFast;
		}
		pSlow = pSlow->next;
		pFast = pFast->next;
		if(pFast != NULL){
			pFast = pFast->next;
		}
	}
	return NULL;
}

ListNode *EntryNodeOfLoop(ListNode *pHead){
	if(pHead == NULL){
		return NULL;
	}
	ListNode *meetingNode = MeetingNode(pHead);
	if(meetingNode == NULL){
		return NULL;
	}
	int countNode = 1;
	ListNode *pNode1 = meetingNode;
	while(pNode1->next != meetingNode){
		countNode++;
		pNode1 = pNode1->next;
	}
	pNode1 = pHead;
	for(int i = 0; i < countNode; i++){
		pNode1 = pNode1->next;
	}
	ListNode *pNode2 = pHead;
	while(pNode1 != pNode2){
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return pNode1;
}

ListNode *createList(int a[], int n){
	ListNode *head;
	ListNode *end;
	head = new ListNode;
	head->next = NULL;
	end = head;
	for(int i = 0; i < n; i++){
		ListNode *node = new ListNode;
		node->val = a[i];
		node->next = NULL;
		end->next = node;
		end = node;
	}
	ListNode *p = head->next;
	delete head;
	return p;
}

void Print(ListNode *head){
	ListNode *p = head;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main(){
	int a[] = {1,2,3,4,5,6};
	int n = 6;
	ListNode *List = createList(a, n);
	Print(List);
	
	ListNode *p = List;
	for(int i = 0; i < 2; i++){
		p = p->next;
	}
	ListNode *q = p;
	while(q->next){
		q = q->next;
	}
	q->next = p;
	
	cout << "入口节点：";
	ListNode *entry = EntryNodeOfLoop(List);
	cout << entry->val; 
	
	return 0;
}
