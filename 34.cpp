//面试题34：二叉树中和为某一值的路径
//题目：输入一棵二叉树和一个整数，打印输出二叉树节点值的和为输入整数的所有路径
//路径为根节点到叶子节点
//
//方法：
//访问根节点，path.push_back(root->val), currentSum += root->val
//递归访问左右子树
//判断currentSum == expectNumber || isLeaf
//True allpath.push_back(path)
//False path.pop_back()

#include <iostream>
#include <vector>
using namespace std;

struct BiTreeNode{
	int val;
	BiTreeNode *left;
	BiTreeNode *right;
}; 

class Solution{
	public:
		void findAllPath(BiTreeNode *root, int expectNumber, int currentSum, vector<vector<int>> &allpath, vector<int> &path){
			//记录当前访问的节点
			path.push_back(root->val);
			//记录访问到当前节点，所有节点的和
			currentSum += root->val;
			
			//判断是否为叶子节点
			bool isLeaf = (root->left == NULL) && (root->right == NULL);
			//如果为叶子节点，判断路径的和是否满足要求，满足，保存该路径
			if(isLeaf && currentSum == expectNumber){
				allpath.push_back(path);
			}			
			if(root->left){
				findAllPath(root->left, expectNumber, currentSum, allpath, path);
			}
			if(root->right){
				findAllPath(root->right, expectNumber, currentSum, allpath, path);
			}
			
			//如果是叶子节点又不满足有求，退回到父节点，删除当前节点
			path.pop_back(); 
		}
		
		vector<vector<int>> FindPath(BiTreeNode *root, int expectNumber){
			vector<vector<int>> allpath;
			vector<int> path;
			//边界条件
			if(root == NULL){
				return allpath;
			} 
			int currentSum = 0;
			findAllPath(root, expectNumber, currentSum, allpath, path);
			return allpath;
		}
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

int main(){
	BiTreeNode *T;
	createBiTree(T);
	Solution sol;
	vector<vector<int>> AllPath = sol.FindPath(T, 22);
	for(int i = 0; i < AllPath.size(); i++){
		vector<int> p = AllPath[i];
		for(int j = 0; j < AllPath[i].size(); j++){
			cout << AllPath[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
