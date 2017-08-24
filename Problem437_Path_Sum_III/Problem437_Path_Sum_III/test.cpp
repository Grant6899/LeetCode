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
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;

		return DFS(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}

	int DFS(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;
		if (root->val == sum)
			return 1 + DFS(root->left, sum - root->val) + DFS(root->right, sum - root->val);

		else 
			return DFS(root->left, sum - root->val) + DFS(root->right, sum - root->val);
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



	vector<int> src{ 10,5,-3,3,2,-1,11,3,-2,-1,1 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.pathSum(root, 8);

	return 0;
}