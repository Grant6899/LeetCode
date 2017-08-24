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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		push(root, 0, result);
		return result;
	}

	void push(TreeNode* root, int level, vector<vector<int>>& result) {
		if (!root)
			return;

		if (level >= result.size()) {
			result.push_back({ root->val });
		}
		else if (level % 2 == 0) {
			result[level].push_back(root->val);
		}
		else
			result[level].insert(result[level].begin(), root->val);

		push(root->left, level + 1, result);
		push(root->right, level + 1, result);
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



	vector<int> src{ 6,2,8,0,4,7,9,-1,-1,3,5 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.zigzagLevelOrder(root);

	return 0;
}