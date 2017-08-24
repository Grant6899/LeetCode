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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;

		pushNode(root, 0, result);

		std::reverse(result.begin(), result.end());
		return result;
	}

	void pushNode(TreeNode* root, int level, vector<vector<int>>& result) {
		if (root == NULL)
			return;

		if (level >= result.size())
			result.push_back({ root->val });
		else
			result[level].push_back(root->val);

		pushNode(root->left, level + 1, result);
		pushNode(root->right, level + 1, result);
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



	vector<int> src{ 3,9,20,-1,-1,15,7 };
	
	TreeNode* root = createTree(src, 0);

	auto ans = s.levelOrderBottom(root);

	return 0;
}