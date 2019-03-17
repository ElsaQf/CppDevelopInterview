//面试题7：重建二叉树
//题目：输入二叉树的前序中序遍历结果，重建二叉树
//前序遍历序列{1,2,4,7,3,5,6,8}
//中序遍历序列{4,7,2,1,5,3,8,6}
//
//方法：
//遍历pre，pre[0]是根节点root，在in中找到root，左边是左子树，右边是右子树
//在分别对左右子树，找pre[i+1]为root，再分割，递归 



#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
}; 

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> in){
	int len = in.size();
	if(len == 0){
		return NULL;
	}
	vector<int> left_pre, right_pre;
	vector<int> left_in, right_in;
	
	TreeNode *head = new TreeNode(pre[0]);
	int index = 0;
	for(int i = 0; i < len; i++){
		if(in[i] == pre[0]){
			index = i;
			break;
		}
	}
	
	for(int i = 0; i < index; i++){
		left_pre.push_back(pre[i+1]);
		left_in.push_back(in[i]);
	}
	for(int i = index + 1; i < len; i++){
		right_pre.push_back(pre[i]);
		right_in.push_back(in[i]);
	}
	
	head->left = reConstructBinaryTree(left_pre, left_in);
	head->right = reConstructBinaryTree(right_pre, right_in);
	
	return head;
}


void postTraverse(TreeNode *T){
	if(T){
		postTraverse(T->left);
		postTraverse(T->right);
		cout << T->val << " ";
	}
}

int main(){
	vector<int> pre = {1,2,4,7,3,5,6,8};
	vector<int> in = {4,7,2,1,5,3,8,6};
	
	TreeNode *T = reConstructBinaryTree(pre, in);
	
	postTraverse(T);//后序遍历验证 
	
	return 0;
}
