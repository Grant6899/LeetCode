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
	int kthSmallest(TreeNode* root, int k) {
		int count = 0;
		int result;
		findkth(root, count, k, result);
		return result;
	}

	void findkth(TreeNode* root, int& count, int k, int& result) {
		if (!root)
			return;
		findkth(root->left, count, k, result);
		count++;
		if (count == k)
			result = root->val;
		findkth(root->right, count, k, result);
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



	vector<int> src{6,2,8,0,4,7,9,-1,-1,3,5 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.kthSmallest(root, 7);

	return 0;
}