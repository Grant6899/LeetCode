/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Apr  5 20:28:23 2018
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

struct PTreeNode : TreeNode{
    bool isFirstVisited;
    PTreeNode(TreeNode* x, bool visit) : TreeNode(x->val){ left = x->left; right = x->right; isFirstVisited = visit;}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<PTreeNode*> s;
        vector<int> res;
        TreeNode* p = root;
        PTreeNode* temp;
        
        while(p || !s.empty()){
            
            while(p){
                PTreeNode* ptn = new PTreeNode(p, true);
                s.push(ptn);
                p = p->left;
            }
            
            if(!s.empty()){
                temp = s.top();
                s.pop();
                if(temp->isFirstVisited == true){     //表示是第一次出现在栈顶 
                    temp->isFirstVisited = false;
                    s.push(temp);
                    p = temp->right;    
                }
                else{                     //第二次出现在栈顶 
                    res.push_back(temp->val);
                    p = NULL;
                }
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

	auto ans = s.postorderTraversal(root);

	return 0;
}