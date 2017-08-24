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
	//Always remember to use header when it comes to collecting linked list;
	//AC - recursive method - 40ms;
	void connect(TreeLinkNode *root)
	{
		if (!root) return;
		TreeLinkNode t(0), *cur;
		cur = &t;
		while (root)
		{
			if (root->left)
			{
				cur->next = root->left;
				cur = cur->next;
			}
			if (root->right)
			{
				cur->next = root->right;
				cur = cur->next;
			}
			root = root->next;
		}
		connect(t.next);
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



	vector<int> src{ 1,2,3,4,5,-1,6,7,-1,-1,-1,-1,-1,-1,8 };

	TreeLinkNode* root = createLinkTree(src, 0);

	s.connect(root);

	return 0;
}