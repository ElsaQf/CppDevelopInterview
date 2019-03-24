//面试题28：对称的二叉树
//题目：若二叉树和它的镜像一样，那么它是对称的

#include <iostream>
using namespace std;

struct BiTreeNode{
	int val;
	BiTreeNode *left;
	BiTreeNode *right;
}; 

//输入：
//T: 8,6,5,-1,-1,7,-1,-1,6,7,-1,-1,5,-1,-1 
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

BiTreeNode *mirrorTree(BiTreeNode *T1){
	BiTreeNode *T = T1;
	if(T == NULL){
		return T;
	}
	if(T->left == NULL && T->right == NULL){
		return T;
	}
	BiTreeNode *temp = T->left;
	T->left = T->right;
	T->right = temp;
	
	if(T->left){
		mirrorTree(T->left);
	}
	if(T->right){
		mirrorTree(T->right);
	}
	
	return T;
}


bool Compare(BiTreeNode *left, BiTreeNode *right){
	if(left == NULL && right == NULL){
		cout << "1" << endl;
		return true;
	}
	if(left == NULL || right == NULL){
		cout << "2" << endl;
		return false;
	}
	if(left->val != right->val){
		cout << "3" << endl;
		return false;
	}
	return Compare(left->left, left->right) && Compare(right->left, right->right);
}

bool isSymmetrical(BiTreeNode *pRoot){
	if(pRoot == NULL){
		cout << "0" << endl;
		return true;
	}
	return Compare(pRoot->left, pRoot->right);
}

void preOrderTraverse(BiTreeNode *T){
	if(T != NULL){
		cout << T->val << " ";
		preOrderTraverse(T->left);
		preOrderTraverse(T->right);
	}
}



int main(){
	BiTreeNode *T;
	createBiTree(T);
	preOrderTraverse(T);
	cout << endl;
	if(isSymmetrical(T)){
		cout << "Yes";
	}else{
		cout << "No";
	}
	
	return 0;
}
