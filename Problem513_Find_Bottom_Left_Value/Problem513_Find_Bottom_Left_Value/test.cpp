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
	int findBottomLeftValue(TreeNode* root) {
		int result, maxlevel = -1;
		findLeftBottom(root, 0, result, maxlevel);
		return result;
	}

	void findLeftBottom(TreeNode* root, int level, int& result, int& maxlevel) {
		if (!root)
			return;

		findLeftBottom(root->left, level + 1, result, maxlevel);
		if (level > maxlevel) {
			maxlevel = level;
			result = root->val;
		}
		findLeftBottom(root->right, level + 1, result, maxlevel);
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



	vector<int> src = { 0, -1, 1 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.findBottomLeftValue(root);

	return 0;
}