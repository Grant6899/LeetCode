/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb  1 18:34:08 2018
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
    TreeNode* deleteNode(TreeNode* root, int key) {
		if(!root)
			return nullptr;
		
		if(root->val == key){
			if(!root->right){
				delete root;
				return root->left;
			}
			else{
				TreeNode* right = root->right;
				while(right->left)
					right = right->left;
				swap(root->val, right->val);
				
			}
		}	
			
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		
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



	vector<int> src{ 1,2,2,-1, 3,-1,3 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.deleteNode(root, 2);

	return 0;
}
