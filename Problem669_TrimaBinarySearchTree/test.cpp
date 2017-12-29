#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return root;

        if(root->val < L){
            root = trimBST(root->right, L, R);
        }
        else if(root->val > R){
            root = trimBST(root->left, L, R);
        }
        else{
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
        }

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

	vector<int> src = { 3,0,4,-1,2,-1,-1,-1,-1,1};

	TreeNode* root = createTree(src, 0);

	auto ans = s.trimBST(root, 1, 3);

	return 0;
}
