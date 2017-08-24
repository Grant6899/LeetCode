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
	bool isValidBST(TreeNode* root) {
		return isValid(root, NULL, NULL);
	}

	bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
		if (!root)
			return true;
		
		if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
			return false;
		}
		
		return (isValid(root->left, minNode, root) && isValid(root->right, root, maxNode));
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



	vector<int> src = { 10,5,15,-1,-1,6,20 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.isValidBST(root);

	return 0;
}