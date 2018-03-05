/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar  4 11:19:37 2018
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* prev = nullptr, *res = nullptr;
        inorder(root, p, prev, res);
        return res;
    }
    
    void inorder(TreeNode* root, TreeNode* p, TreeNode*& prev, TreeNode*& res){
        if(!root)
            return;
        
        inorder(root->left, p, prev, res);
        if(p == prev)
            res = root;
        prev = root;
        inorder(root->right, p, prev, res);
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
	auto ans = s.inorderSuccessor(root, root->left);
	cout << ans->val << endl;
	return 0;
}
