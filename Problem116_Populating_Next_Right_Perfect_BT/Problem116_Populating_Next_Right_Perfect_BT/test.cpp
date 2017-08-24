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


// Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root)
			return;

		if (root->left) {
			root->left->next = root->right;
			if (root->next) {
				root->right->next = root->next->left;
			}
		}
		connect(root->left);
		connect(root->right);
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

TreeLinkNode* createLinkTree(const vector<int>& src, int i) {
	if (src[i] == -1)
		return NULL;

	TreeLinkNode* current = new TreeLinkNode(src[i]);
	if (i * 2 + 1 < src.size())
		current->left = createLinkTree(src, i * 2 + 1);
	else
		current->left = NULL;

	if (i * 2 + 2 < src.size())
		current->right = createLinkTree(src, i * 2 + 2);
	else
		current->right = NULL;
	return current;
}


int main() {
	Solution s;



	vector<int> src{ 1,2,3,4,5,6,7 };

	TreeLinkNode* root = createLinkTree(src, 0);

	s.connect(root);

	return 0;
}