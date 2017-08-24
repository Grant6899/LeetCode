#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>

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
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL)
			return 1 + minDepth(root->right);
		if (root->right == NULL)
			return 1 + minDepth(root->left);
		return 1 + std::min(minDepth(root->left), minDepth(root->right));
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



	vector<int> src{ 1,2, 3,4,5 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.minDepth(root);

	return 0;
}