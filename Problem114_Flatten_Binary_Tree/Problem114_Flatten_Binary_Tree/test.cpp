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
	void flatten(TreeNode *root) {
		dfs(root);
	}

	TreeNode *dfs(TreeNode *root) {
		if (!root) return root;

		TreeNode *cur = root;
		TreeNode *left = dfs(root->left);
		TreeNode *right = dfs(root->right);

		if (left) {
			cur->left = NULL;
			cur->right = left; // set right pointer of the root node
			while (cur->right) cur = cur->right; // get the last node of the left side
		}

		cur->right = right; // right pointer of the last node of the left side
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



	vector<int> src{ 1,2,5,3,4,-1,6 };
	TreeNode* root = createTree(src, 0);

	s.flatten(root);

	return 0;
}