#include<iostream>
#include<vector>
#include<algorithm>

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
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL)
			return 0;
		
		if (root->left == NULL)
			return sumOfLeftLeaves(root->right);

		if (root->left->left == NULL && root->left->right == NULL)
			return root->left->val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
		else
			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
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



	vector<int> src{ -9,-3,2,-1,4,4,0,-1,-1,-6,-1,-5 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.sumOfLeftLeaves(root);

	return 0;
}