/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 20 22:15:56 2018
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* newroot = new TreeNode(v);
            newroot->left = root;
            return newroot;
        }
        
        addRow(root, v, d, 1);
		return root;
    }
	
	void addRow(TreeNode* root, int v, int d, int level){
        if(level > d - 1 || level <= d-1 && !root)
			return;
		
		addRow(root->left, v, d, level + 1);
		addRow(root->right, v, d, level + 1);
		
		if(level == d - 1){
			TreeNode* new_left = new TreeNode(v);
			TreeNode* new_right = new TreeNode(v);
			
			if(root) new_left->left = root->left;
			if(root) new_right->right = root->right;
			
			root->left = new_left;
			root->right = new_right;
		}
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

	auto ans = s.addOneRow(root, 2, 2);

	return 0;
}