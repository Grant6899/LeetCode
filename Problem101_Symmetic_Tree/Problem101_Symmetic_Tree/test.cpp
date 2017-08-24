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
	bool isSymmetric(TreeNode* root) {
		TreeNode* l = root, *r = root;
		return isSym(l, r);
	}

	bool isSym(TreeNode* l, TreeNode* r) {
		if (!l && !r)
			return true;
		else if ((!l && r) || (l && !r))
			return false;
		bool b1 = isSym(l->left, r->right);
		bool b2 = (l->val == r->val);
		bool b3 = isSym(l->right, r->left);
		return (b1 && b2 && b3);
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



	vector<int> src{ 1,2,2,-1, 3,-1,3 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.isSymmetric(root);

	return 0;
}