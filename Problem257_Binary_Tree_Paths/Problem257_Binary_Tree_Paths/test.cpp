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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;

		if (root == NULL)
			return result;
		
		string current_path = to_string(root->val);
		if (root->left == NULL && root->right == NULL) {
			result.push_back(current_path);
			return result;
		}

		
		DFS(root->left, current_path, result);

		current_path = to_string(root->val);
		DFS(root->right, current_path, result);

		return result;
	}

	void DFS(TreeNode* root, string& current, vector<string>& result) {
		if (root == NULL)
			return;
		auto temp = current;
		current = current + "->" + to_string(root->val);
		
		if (root->left == NULL && root->right == NULL) {
			result.push_back(current);
			current = temp;
			return;
		}
		DFS(root->left, current, result);
		DFS(root->right, current, result);
		current = temp;
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



	vector<int> src{ 1,2, 3,4,5 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.binaryTreePaths(root);

	return 0;
}