/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  9 19:22:32 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return nullptr;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if(root->val == 0 && !root->left && !root->right){
            delete root;
            return nullptr;
        }
        else
            return root;
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
	vector<int> src{ 1, -1, 0, 1};

	TreeNode* root = createTree(src, 0);

	auto ans = s.pruneTree(root);

	return 0;
}