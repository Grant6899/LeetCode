

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
	TreeNode* convertBST(TreeNode* root) {
		int sum = 0;
		addGreaterUtil(root, &sum);
		return root;
	}

	void addGreaterUtil(TreeNode *root, int *sum_ptr){
		if (root == NULL)
			return;

		addGreaterUtil(root->right, sum_ptr);

		*sum_ptr = *sum_ptr + root->val;

		root->val = *sum_ptr;

		addGreaterUtil(root->left, sum_ptr);
	}


};




int main() {

	std::vector<int> vec{ 4, 3, 10, 15 };

	Solution s;


}