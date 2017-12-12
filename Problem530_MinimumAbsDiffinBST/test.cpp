/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 10 19:53:02 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>
#include<climits>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

class Solution {
private:
    int previous = -1, min_diff = INT_MAX;

public:
    int getMinimumDifference(TreeNode* root) {
        if (root->left != NULL)
            getMinimumDifference(root->left);
        
        if (previous >= 0)
            min_diff = min(min_diff, root->val - previous);
        previous = root->val;

        if (root->right != NULL)
            getMinimumDifference(root->right);

        return min_diff; 
        
    }
};



int main() {
	Solution s;

	vector<int> src = { 236,104,701,-1,227,-1,911 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.getMinimumDifference(root);

    cout << ans << endl;
	return 0;
}
