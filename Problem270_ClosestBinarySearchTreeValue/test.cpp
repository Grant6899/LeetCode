/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:37:49 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
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
    int closestValue(TreeNode* root, double target) {
        int a = root->val;
        auto kid = target < a ? root->left : root->right;
        if (!kid) return a;
        int b = closestValue(kid, target);
        return abs(a - target) < abs(b - target) ? a : b;
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
	vector<int> src{ 4,2,5,1,3};

	TreeNode* root = createTree(src, 0);

	auto ans = s.closestValue(root,3.7);

	return 0;
}