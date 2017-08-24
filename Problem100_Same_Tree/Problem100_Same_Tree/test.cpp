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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q)
			return true;
		else if ((!p && q) || (p && !q))
			return false;
		bool b1 = isSameTree(p->left, q->left);
		bool b2 = (p->val == q->val);
		bool b3 = isSameTree(p->right, q->right);
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