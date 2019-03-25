//面试题32：从上到下打印二叉树
//
//题目一：不分行从上到下打印二叉树
//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印 
//方法：层次遍历（队列） 
//
//题目二：分行从上到下打印二叉树 
//方法：在题目一的基础上增加两个变量m,n
//m是当前层要打印的数目，pop后m--
//当m==0时，换行，m=n, n=0 


#include <iostream>
#include <queue>
using namespace std;

struct BiTreeNode{
	int val;
	BiTreeNode *left;
	BiTreeNode *right;
};

void createBiTree(BiTreeNode *&T){
	int c;
	cin >> c;
	if(c == -1){
		T = NULL;
	}else{
		T = new BiTreeNode;
		T->val = c;
		createBiTree(T->left);
		createBiTree(T->right);
	}
}
void preOrderTraverse(BiTreeNode *T){
	if(T){
		cout << T->val << " ";
		preOrderTraverse(T->left);
		preOrderTraverse(T->right);
	}
}
void levelOrderTraverse(BiTreeNode *T){
	if(T == NULL){
		return;
	}
	queue<BiTreeNode *> q;
	q.push(T);
	while(!q.empty()){
		BiTreeNode *temp = q.front();
		cout << temp->val << " ";
		q.pop();
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
	}
}

void levelOrderTraverse2(BiTreeNode *T){
	if(T == NULL){
		return;
	}
	queue<BiTreeNode *> q;
	int m = 0, n = 0;
	q.push(T);
	m++;
	while(!q.empty()){
		if(m == 0){
			cout << endl;
			m = n;
			n = 0;
		}
		BiTreeNode *temp = q.front();
		cout << temp->val << " ";
		q.pop();
		m--;
		if(temp->left){
			q.push(temp->left);
			n++;
		}
		if(temp->right){
			q.push(temp->right);
			n++;
		}
	}
} 

int main(){
	BiTreeNode *T;
	createBiTree(T);
//	preOrderTraverse(T);
	levelOrderTraverse2(T);
	
	return 0;
}
