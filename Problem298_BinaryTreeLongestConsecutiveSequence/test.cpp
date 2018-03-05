/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar  4 13:00:58 2018
 ************************************************************************/

#include<iostream>
#include<vector>

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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        find(root, 0, res);
        return res;
    }
    
    void find(TreeNode* root, int len, int& res){
        
        if(!root)
            return;
        len = max(len, 1);
        //cout << "Node: " << root->val << " len: " << len << endl;
        res = max(res, len);
    
        if(root->left && root->left->val == root->val + 1)
            find(root->left, len + 1, res);
        else
            find(root->left, 0, res);
        
        
        if(root->right && root->right->val == root->val + 1)
            find(root->right, len + 1, res);
        else
            find(root->right, 0, res);
        
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

int main(){
	std::vector<int> src{1,2,3,4,5};
	TreeNode* root = createTree(src, 0);
	Solution s;
	auto ans = s.longestConsecutive(root);
	cout << ans << endl;
	return 0;
}
