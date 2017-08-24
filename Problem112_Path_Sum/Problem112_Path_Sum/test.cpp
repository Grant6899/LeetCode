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
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;

		if (root->val == sum && !root->left && !root->right)
			return true;

		if (root->left == NULL)
			return hasPathSum(root->right, sum - root->val);
		
		else if (root->right == NULL)
			return hasPathSum(root->left, sum - root->val);

		else
			return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
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



	vector<int> src{ 5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,-1,1 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.hasPathSum(root, 22);

	return 0;
}