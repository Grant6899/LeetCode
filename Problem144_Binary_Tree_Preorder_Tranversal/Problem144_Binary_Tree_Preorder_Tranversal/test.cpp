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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		preorder(root, result);
		return result;
	}

	void preorder(TreeNode* root, vector<int>& result) {
		if (!root)
			return;
		result.push_back(root->val);
		preorder(root->left, result);
		preorder(root->right, result);
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



	vector<int> src = { 1,2,3,4,5,6,7,8,-1,-1,9 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.preorderTraversal(root);

	return 0;
}