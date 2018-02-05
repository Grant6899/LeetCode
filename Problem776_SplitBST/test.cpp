/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Feb  4 19:14:42 2018
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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        TreeNode* t1 = nullptr, *t2 = nullptr;
        vector<TreeNode*> res { t1, t2 };
        transverse(root, V, res);
        return res;
    }

    void transverse(TreeNode* root, int V, vector<TreeNode*>& res){
        if(!root)
            return;

        if(root->val <= V)
            res[0] = addValue(res[0], root->val);
        else
            res[1] = addValue(res[1], root->val);
        transverse(root->left, V, res);
        transverse(root->right, V, res);
    }

    TreeNode* addValue(TreeNode* root, int new_val){
        if(!root){
            TreeNode* temp = new TreeNode(new_val);
            return temp;
        }

        if(new_val > root->val)
            root->right = addValue(root->right, new_val);
        else
            root->left = addValue(root->left, new_val);
        return root;
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



	vector<int> src{ 4,2,6,1,3,5,7 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.splitBST(root, 4);

	return 0;
}
