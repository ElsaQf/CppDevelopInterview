//面试题8：二叉树的下一个节点
//题目：给定一棵二叉树和其中一个节点，如何找出中序遍历序列的下一个节点？
//树中的节点除了有两个分别指向左右子节点的指针，还有一个指向父节点的指针
//中序遍历序列{d,b,h,e,i,a,f,c,g} 

//方法： 
//若p是右子树且有右子树，则下一个是右子树的最左子树
//若p是左子树，则下一个是父节点
//若p是右子树且没有右子树，则下一个是最根节点root 

#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

TreeNode *getNext(TreeNode *pNode){
	if(pNode = nullptr){
		return nullptr;
	}
	
	TreeNode *pNext = nullptr;
	
	// 若p是右子树且有右子树，则下一个是右子树的最左子树
	// 若p是左子树，则下一个是父节点
	// 若p是右子树且没有右子树，则下一个是最根节点root 
	 
	if(pNode->right != nullptr){
		TreeNode *pRight = pNode->right;
		while(pRight->left != nullptr){
			pRight = pRight->left;
		}
		pNext = pRight;
	}else if(pNode->parent != nullptr){
		TreeNode *pCur = pNode;
		TreeNode *pPar = pNode->parent;
		while(pPar->parent != nullptr && pCur == pPar->right){
			pCur = pPar;
			pPar = pPar->parent;
		}
		pNext = pPar;
	}
	
	return pNext;
}
