/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar  4 13:14:20 2018
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool find = false;  
        check(s, t, find);
        return find;
    }
    
    void check(TreeNode* s, TreeNode* t, bool& find){
        if(!s || find)
            return;
        
        check(s->left, t, find);
        if(s->val == t->val)
            find = find || isSameTree(s, t);
        check(s->right, t, find);
    }
    
    bool isSameTree(TreeNode* r1, TreeNode* r2){
        if(!r1 && !r2)
            return true;
        
        if(!r1 && r2 || r1 && !r2)
            return false;
        
        return r1->val == r2->val && isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right);
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
	std::vector<int> src{1,2,3,4,5}, p{1,2,3};
	TreeNode* root = createTree(src, 0), * pa = createTree(p, 0);
	Solution s;
	auto ans = s.isSubtree(root, pa);
	cout << ans << endl;
	return 0;
}
