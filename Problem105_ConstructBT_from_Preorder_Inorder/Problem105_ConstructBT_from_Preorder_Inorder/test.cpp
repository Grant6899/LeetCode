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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)
			return NULL;

		int mid = std::find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
		
		TreeNode* current = new TreeNode(preorder[0]);

		vector<int> leftin = vector<int>(inorder.begin(), inorder.begin() + mid);
		vector<int> leftpre = vector<int>(preorder.begin() + 1, preorder.begin() + mid + 1);
		vector<int> rightin = vector<int>(inorder.begin() + mid + 1, inorder.end());
		vector<int> rightpre = vector<int>(preorder.begin() + mid + 1, preorder.end());
		current->left = buildTree(leftpre, leftin);
		current->right = buildTree(rightpre, rightin);
		return current;
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



	vector<int> pre = { 1,2,4,8,10,5,9,3,6,7 }, in = { 8,10,4,2,5,9,1,6,3,7 };

	//TreeNode* root = createTree(src, 0);

	auto ans = s.buildTree(pre, in);

	return 0;
}