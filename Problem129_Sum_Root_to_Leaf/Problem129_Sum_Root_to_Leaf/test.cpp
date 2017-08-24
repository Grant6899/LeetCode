#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>

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
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		if (!root)
			return 0;
		DFS(root, 0, sum);
		return sum;
	}

	void DFS(TreeNode* root, int current, int&sum) {
		current = current * 10 + root->val;
		if (!root->left && !root->right) {
			sum += current;
			return;
		}
		else if (!root->right) {
			DFS(root->left, current, sum);
		}
		else if (!root->left) {
			DFS(root->right, current, sum);
		}
		else {
			DFS(root->left, current, sum);
			DFS(root->right, current, sum);
		}
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



	vector<int> src{ 1,2, 3, 4};

	TreeNode* root = createTree(src, 0);

	auto ans = s.sumNumbers(root);

	return 0;
}