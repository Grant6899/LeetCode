/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar  4 13:38:24 2018
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
    int findSecondMinimumValue(TreeNode* root) {
        pair<int, int> mins = make_pair(INT_MAX, INT_MAX);
        transversal(root, mins);
        
        return mins.second == INT_MAX? -1 : mins.second;
    }
    
    void transversal(TreeNode* root, pair<int, int>& mins){
        if(!root)
            return;
        
        transversal(root->left, mins);
        
        if(root->val != mins.first && root->val != mins.second){
            if(root->val < mins.first){
                mins.second = mins.first;
                mins.first = root->val;
            }
            else if(root->val < mins.second)
                mins.second = root->val;
        }
        
        transversal(root->right, mins);
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
	auto ans = s.findSecondMinimumValue(root);
	cout << ans << endl;
	return 0;
}

