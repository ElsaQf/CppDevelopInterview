//面试题27：二叉树的镜像
//
//方法：递归 
//从根节点开始遍历，若有子树，则交换左右子树 

#include <iostream>
using namespace std;

struct BiTreeNode{
	int val;
	BiTreeNode *left;
	BiTreeNode *right;
}; 

//输入：
//T: 8,6,5,-1,-1,7,-1,-1,10,9,-1,-1,11,-1,-1 
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

void mirrorTree(BiTreeNode *T){
	if(T == NULL){
		return;
	}
	if(T->left == NULL && T->right == NULL){
		return;
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
}

int main(){
	BiTreeNode *T;
	createBiTree(T);
	preOrderTraverse(T);
	cout << endl;
	mirrorTree(T);
	preOrderTraverse(T);
	cout << endl;
	
	return 0;
}
