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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;

		if (nums.size() == 1)
			return new TreeNode(nums[0]);

		int mid = nums.size() / 2;

		TreeNode* current = new TreeNode(nums[mid]);

		vector<int> leftVec(nums.begin(), nums.begin() + mid);
		vector<int> rightVec(nums.begin() + mid + 1, nums.end());

		current->left = sortedArrayToBST(leftVec);
		current->right = sortedArrayToBST(rightVec);
		
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



	vector<int> src{ 1,2, 3,4,5,6 };

	//TreeNode* root = createTree(src, 0);

	auto ans = s.sortedArrayToBST(src);

	return 0;
}