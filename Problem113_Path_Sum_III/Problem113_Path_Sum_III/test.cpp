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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		if (!root)
			return result;
		DFS(root, sum, result, { });
		return result;
	}

	void DFS(TreeNode* root, int sum, vector<vector<int>>& result, vector<int> current) {
		if (!root)
			return;
		current.push_back(root->val);
		DFS(root->left, sum - root->val, result, current);
		if (root->val == sum && !root->left && !root->right) {
			result.push_back(current);
		}
		DFS(root->right, sum - root->val, result, current);
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



	vector<int> src{ 5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,5,1 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.pathSum(root, 22);

	return 0;
}