/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar  4 13:29:19 2018
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
    int findTilt(TreeNode* root) {
        int res = 0;
        sum(root, res);
        return res;
    }
    
    int sum(TreeNode* root, int& res){
        if(!root)
            return 0;
        
        int leftsum = sum(root->left, res);
        int rightsum = sum(root->right, res);        
        
        res += abs(leftsum - rightsum);
        return leftsum + rightsum + root->val;
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
	auto ans = s.findTilt(root);
	cout << ans << endl;
	return 0;
}


