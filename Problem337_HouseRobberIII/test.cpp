/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 21 20:05:00 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

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
    int rob(TreeNode* root) {
        
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }

    pair<int,int> dfs(TreeNode* root){
        if(!root)
            return(make_pair(0, 0));

        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        pair<int, int> res;
        res.first = root->val + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);
        return res;
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

	vector<int> src{ 3,4,5,3,3,-1,1 };

	TreeNode* root = createTree(src, 0);

	cout << s.rob(root) << endl;

	return 0;
}
