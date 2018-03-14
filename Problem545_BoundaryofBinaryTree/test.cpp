/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar 14 18:56:32 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res, res_left, res_leaves, res_right;
		
		if(!root) return res;
		res.push_back(root->val);
		leftBoundary(root->left, res_left);
		bottomBoundary(root->left, res_leaves);
		bottomBoundary(root->right, res_leaves);
		rightBoundary(root->right, res_right);
		reverse(res_right.begin(), res_right.end());
		
		for(int i : res_left)
			res.push_back(i);
		for(int i : res_leaves)
			res.push_back(i);
		for(int i : res_right)
			res.push_back(i);
		
		return res;
    }
	
	void leftBoundary(TreeNode* root, vector<int>& res){
		if(!root || !root->left && !root->right)
			return;
		res.push_back(root->val);
		if(root->left)
			leftBoundary(root->left, res);
		else
			leftBoundary(root->right, res);
	}
	
	
	void bottomBoundary(TreeNode* root, vector<int>& res){
		if(!root) return;
		if(!root->left && !root->right)	res.push_back(root->val);
		
		bottomBoundary(root->left, res);
		bottomBoundary(root->right, res);
	}
	
	void rightBoundary(TreeNode* root, vector<int>& res){
		if(!root || !root->left && !root->right)
			return;
		res.push_back(root->val);			
		if(root->right)
			rightBoundary(root->right, res);
		else
			rightBoundary(root->left, res);
	}
};


TreeNode* createTree(const vector<int>& src, int i) {
	if (src[i] == -1)
		return NULL;

	TreeNode* current = new TreeNode(src[i]);
	if (i * 2 + 1 < src.size())
		current->left = createTree(src, i * 2 + 1);
	else
		current->left = NULL;

	if (i * 2 + 2 < src.size())
		current->right = createTree(src, i * 2 + 2);
	else
		current->right = NULL;
	return current;
}


int main() {
	Solution s;



	vector<int> src{ 1,2,2,-1, 3,-1,3 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.boundaryOfBinaryTree(root);

	return 0;
}