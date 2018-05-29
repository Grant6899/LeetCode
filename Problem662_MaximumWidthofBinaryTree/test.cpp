/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:00:11 2018
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


struct MapNode {
    int val;
    vector<MapNode*> neighbors;
    MapNode(int x) : val(x), neighbors(vector<MapNode*>()) {}
 };
 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<vector<int>> b;
        
        dfs(root, 0, 0, b);
        
        int res = 0;
        for(int i = 0; i < b.size(); ++i)
            res = max(res, b[i][1] - b[i][0] + 1);
        return res;
    }
    
    void dfs(TreeNode* root, int cur, int level, vector<vector<int>>& b){
        if(!root)
            return;
        
        if(level == b.size())
            b.push_back({cur, cur});
        else{
            b[level][0] = min(b[level][0], cur);
            b[level][1] = max(b[level][1], cur);
        }
        
        dfs(root->left, cur * 2, level + 1, b);
        dfs(root->right, cur * 2 + 1, level + 1, b);
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
	vector<int> src{ 1,2,3};

	TreeNode* root = createTree(src, 0);

	auto ans = s.widthOfBinaryTree(root);
	cout << ans << endl;
	return 0;
}
