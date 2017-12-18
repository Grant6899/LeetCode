/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 17 21:36:56 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cmath>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<vector<string>> result;
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = deep(root);
        int width = pow(2, deep(root)) - 1;
        result = vector<vector<string>>(depth, vector<string>(width, ""));
        fill(root, 0, 0, width);
        return result;
    }
    
    int deep(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(deep(root->left), deep(root->right)) + 1;
    }
    
    void fill(TreeNode* root, int level, int l, int r){
        if(root == NULL)
            return;
        int mid = l + (r - l) / 2;
        result[level][mid] = to_string(root->val);
        fill(root->left, level + 1, l, mid - 1);
        fill(root->right, level + 1, mid + 1, r);
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

	vector<int> src{ 1,2,3,-1,4,-1,-1};

	TreeNode* root = createTree(src, 0);

	auto ans = s.printTree(root);
    
    for(auto it = ans.begin(); it < ans.end(); ++it){
        for(auto jt = (*it).begin(); jt < (*it).end(); ++jt){
            cout << *jt << '|';
        }
        cout << endl;
    }


	return 0;
}
