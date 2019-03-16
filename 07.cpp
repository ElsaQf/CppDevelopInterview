//面试题7：重建二叉树
//题目：给出前序遍历和中序遍历结果，重建该二叉树
//前序遍历{1,2,4,7,3,5,6,8}，中序遍历{4,7,2,1,5,3,8,6} 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
}; 

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin);
void postTraverse(TreeNode *T){
	if(T){
		postTraverse(T->left);
		postTraverse(T->right);
		cout << T->val << " ";
	}
}
int main(){
	vector<int> pre = {1,2,4,7,3,5,6,8};
	vector<int> vin = {4,7,2,1,5,3,8,6};
	
	TreeNode *newRoot = reConstructBinaryTree(pre, vin);
	
	postTraverse(newRoot);
	
	return 0;
}

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin){
	if(pre.size() == 0 || pre.size() != vin.size()){
		return nullptr;
	}
	int root = pre[0];
	TreeNode *newNode = new TreeNode(root);
	
	if(pre.size() == 1){
		return newNode;
	}
	
	auto posi = find(vin.begin(), vin.end(), root);
	
	if(posi == vin.end()){
		return nullptr;
	}
	int leftSize = posi - vin.begin();
	int rightSize = vin.end() - posi - 1;
	
	newNode->left = reConstructBinaryTree(vector<int>(pre.begin()+1, pre.begin()+1+leftSize), vector<int>(vin.begin()+leftSize+1, vin.end()));
	
	return newNode;
}
