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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q)
			return root;
		
		TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
		TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
		
		if (leftNode && rightNode)
			return root;

		if (!leftNode)
			return rightNode;
		if (!rightNode)
			return leftNode;
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



	vector<int> src{ 37,-34,-48,-1,-100,-100,48 };

	TreeNode* root = createTree(src, 0);

	TreeNode* pp = root->left->right, *qq = root->right->left;


	auto ans = s.lowestCommonAncestor(root, pp, qq);

	return 0;
}