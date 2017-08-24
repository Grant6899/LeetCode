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
	vector<int> findMode(TreeNode* root) {
		vector<int> result;
		unordered_map<int, int> table;

		int maxCount = -1;
		DFS(root, table, maxCount);

		for (auto element : table) {
			if (element.second == maxCount) {
				result.push_back(element.first);
			}
		}

		return result;
	}

	void DFS(TreeNode* root, unordered_map<int, int>& table, int& maxCount) {
		if (root == NULL)
			return;
		if (table.find(root->val) == table.end()) {
			table.insert({ root->val, 1 });
		}
		else
			table[root->val]++;

		if (table[root->val] > maxCount)
			maxCount = table[root->val];

		DFS(root->left, table, maxCount);
		DFS(root->right, table, maxCount);

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



	vector<int> src{ 1,2, 3,4,5,6 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.findMode(root);

	return 0;
}