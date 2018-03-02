/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 22:44:54 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        TreeNode* prev = nullptr, *res = nullptr;
        double min_diff = std::numeric_limits<double>::max();
        
        closestValue(root, target, prev, min_diff, res);
        //cout << found << endl;
        return res->val;
    }
    
    void closestValue(TreeNode* root, double target, TreeNode*& prev, double& min_diff, TreeNode*& res){
        if(!root || prev && prev->val > target)
            return;
        
        closestValue(root->left, target, prev, min_diff, res);
        
        if(fabs(root->val - target) < min_diff){
            res = root;
            min_diff = fabs(root->val - target);
        }
        
        prev = root;
        closestValue(root->right, target, prev, min_diff, res);
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
	vector<int> src{ 3, 1, 7, -1, 2, 4};
	TreeNode* root = createTree(src, 0);
	cout << s.closestValue(root, 5) << endl;
	return 0;
}
