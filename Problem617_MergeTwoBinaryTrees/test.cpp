/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 17 22:31:49 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2)
            return NULL;
        
        
        if(!t1 && t2)
            return t2;
        
        if(t1 && !t2){
            return t1;
        }
        
        if(t1 && t2){
            TreeNode* head = new TreeNode(t1->val + t2->val);
            head->left = mergeTrees(t1->left, t2->left);
            head->right = mergeTrees(t1->right, t2->right);
            return head;
        }
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
    Solution s;

	vector<int> src{ 1,3,2,5 }, s2 {2,1,3,-1,4,-1,7};

	TreeNode* root = createTree(src, 0);
    TreeNode* root2 = createTree(s2, 0);

	auto ans = s.mergeTrees(root, root2);

	return 0;
}
