#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

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
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		int ld = getDepth(root->left), rd = getDepth(root->right);
		return (abs(ld - rd) <= 1 && isBalanced(root->left) && isBalanced(root->right) );
	}

	int getDepth(TreeNode* root) {
		if (!root)
			return 0;
		else
			return 1 + max(getDepth(root->left), getDepth(root->right));
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



	vector<int> src{1,-1,3,-1,-1,2 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.isBalanced(root);

	return 0;
}