//面试题25：合并两个递增链表
 
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
};

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

ListNode *merge(ListNode *head1, ListNode *head2){
	if(head1 == NULL){
		return head2;
	}
	if(head2 == NULL){
		return head1;
	}
	ListNode *mergeHead = NULL;
	ListNode *end = mergeHead;
	if(head1->val < head2->val){
		mergeHead = head1;
		mergeHead->next = merge(head1->next, head2); 
	}else{
		mergeHead = head2;
		mergeHead->next = merge(head1, head2->next);
	}
	return mergeHead;
}

int main(){
	int a[] = {1,3,5,7};
	int b[] = {2,4,6,8,9};
	ListNode *List1 = createList(a, 4);
	ListNode *List2 = createList(b, 5);
	Print(List1);
	Print(List2);
	cout << "Merge: " << endl;
	ListNode *mergeList = merge(List1->next, List2->next);
	ListNode *p = mergeList;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	
	return 0;
	
} 
