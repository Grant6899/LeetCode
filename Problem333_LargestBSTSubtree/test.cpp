/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar  4 18:52:46 2018
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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        isValidBST(root, nullptr, nullptr, res);
        return res;
    }
    
    
    pair<bool, int> isValidBST(TreeNode* root, TreeNode* low, TreeNode* high, int& res){
        if(!root)
            return make_pair(true, 0);
    
        pair<bool, int> root_Res;
        auto ltree = isValidBST(root->left, low, root, res);
        auto rtree = isValidBST(root->right, root, high, res);
   
        bool isValid =  ltree.first && rtree.first;
       
        if(isValid)
            root_Res = make_pair(isValid, ltree.second + rtree.second + 1);
        else
            root_Res = make_pair(false, 1);
        
        if(low && root->val <= low->val)
            root_Res.first = false;
            
        if(high && root->val >= high->val)
            root_Res.first = false;
        
        
        res = max(res, root_Res.second);
        
        cout << "Node: " << root->val << " num: " << root_Res.second << endl;
        return root_Res;
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
	std::vector<int> src{1,2, -1, -1, 4};
	TreeNode* root = createTree(src, 0);
	Solution s;
	auto ans = s.largestBSTSubtree(root);
	return 0;
}

