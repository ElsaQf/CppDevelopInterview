//面试题26：树的子结构
//题目：输入两棵二叉树A,B，判断B是不是A的子结构 

//方法：
//1.找到相同的根节点
//2.递归 

#include <iostream>
using namespace std;

struct BiTreeNode{
	int val;
	BiTreeNode *left;
	BiTreeNode *right;
}; 

//输入：
//T1: 8,8,9,-1,-1,2,4,-1,-1,7,-1,-1,7,-1,-1 
//T2: 8,9,-1,-1,2,-1,-1
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
	if(T != NULL){
		cout << T->val << " ";
		preOrderTraverse(T->left);
		preOrderTraverse(T->right);
	}
}

bool dfs(BiTreeNode *r1, BiTreeNode *r2){
	if(!r2){
		return true;
	}
	if(!r1){
		return false;
	}
	if(r1->val != r2->val){
		return false;
	}else{
		return dfs(r1->left, r2->left) && dfs(r1->right, r2->right); 
	}
}

bool hasSubtree(BiTreeNode *T1, BiTreeNode *T2){
	if(T1 == NULL || T2 == NULL){
		return false;
	}
	return (dfs(T1, T2)) || hasSubtree(T1->left, T2) || hasSubtree(T1->right, T2);
}

int main(){
	BiTreeNode *T1;
	BiTreeNode *T2;
	createBiTree(T1);
	createBiTree(T2);
//	preOrderTraverse(T);
//	cout << endl;
	if(hasSubtree(T1, T2)){
		cout << "Yes";
	}else{
		cout << "No";
	}
	
	
	return 0;
}
