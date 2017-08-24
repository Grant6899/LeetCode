

#include <vector>
#include <unordered_map>
#include <iostream>

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
	int max(int a, int b) {
		return ((a > b) ? a : b);
	}


	int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL)
			return 0;

		int lh = getHeight(root->left);
		int rh = getHeight(root->right);

		int ld = diameterOfBinaryTree(root->left);
		int rd = diameterOfBinaryTree(root->right);

		return max(lh + rh + 1, max(ld, rd)) - 1;
	}

	int getHeight(TreeNode* root) {
		if (root == NULL)
			return 0;

		int lh = getHeight(root->left);
		int rh = getHeight(root->right);

		return 1 + max(lh, rh);
	}


};




int main() {

	std::vector<int> vec{ 4, 3, 10, 15 };

	Solution s;


}