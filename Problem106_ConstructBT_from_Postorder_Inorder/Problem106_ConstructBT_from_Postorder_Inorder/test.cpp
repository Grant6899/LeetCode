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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0)
			return NULL;

		int mid = std::find(inorder.begin(), inorder.end(), postorder[postorder.size()-1]) - inorder.begin();

		TreeNode* current = new TreeNode(inorder[mid]);

		vector<int> leftin = vector<int>(inorder.begin(), inorder.begin() + mid);
		vector<int> leftpost = vector<int>(postorder.begin(), postorder.begin() + mid);
		vector<int> rightin = vector<int>(inorder.begin() + mid + 1, inorder.end());
		vector<int> rightpost = vector<int>(postorder.begin() + mid, postorder.end()-1);
		current->left = buildTree(leftin, leftpost);
		current->right = buildTree(rightin, rightpost);
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



	vector<int> post = { 10,8,4,9,5,2,6,7,3,1 }, in = { 8,10,4,2,5,9,1,6,3,7 };

	//TreeNode* root = createTree(src, 0);

	auto ans = s.buildTree(in, post);

	return 0;
}