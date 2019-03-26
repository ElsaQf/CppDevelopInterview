//面试题33：二叉搜索树的后序遍历序列
//题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
//
//方法：
//后序遍历，最后一个元素是根节点，前面连续小的是左子树，连续大的是右子树，这样就分成两部分
//对每一部分递归 

#include <iostream>
#include <vector>
using namespace std;

bool bst(vector<int> seq, int begin, int end){
	if(seq.empty() || begin > end){
		return false;
	}
	
	int i = begin;
	for(; i < end; i++){
		if(seq[i] > seq[end]){
			break;
		}
	}
	int j = i;
	for(; j < end; j++){
		if(seq[j] < seq[end]){
			return false;
		}
	}
	
	bool left = true;
	if(i > begin){
		left = bst(seq, begin, i-1);
	}
	
	bool right = true;
	if(i < end-1){
		right = bst(seq, i, end-1);
	}
	
	return left && right;
}

bool VerifySequenceOfBST(vector<int> sequence){
	if(sequence.empty()){
		return false;
	}
	return bst(sequence, 0, sequence.size()-1);
} 


int main(){
	vector<int> a = {5,7,6,9,11,10,8};
	vector<int> b = {7,4,6,5};
	
	if(VerifySequenceOfBST(a)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	
	if(VerifySequenceOfBST(b)){
		cout << "Yes2" << endl;
	}else{
		cout << "No2" << endl;
	}
	
	return 0;
}
