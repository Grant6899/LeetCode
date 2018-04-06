/*************************************************************************
	> File Name: test_iterative.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Apr  5 20:44:39 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		
        stack<TreeNode*> s;
        TreeNode *p=root;
        
        while(p != NULL || !s.empty()){
            while(p!=NULL){
                res.push_back(p->val);
                s.push(p);
                p=p->left;
            }
            
            if(!s.empty()){
                p=s.top();
                s.pop();
                p=p->right;
            }
        }
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
	vector<int> src{ 1, -1, 2, 3};

	TreeNode* root = createTree(src, 0);

	auto ans = s.preorderTraversal(root);

	return 0;
}