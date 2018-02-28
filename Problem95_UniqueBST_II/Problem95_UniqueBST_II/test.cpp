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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> res;
        
        if(n == 0)
            return vector<TreeNode*>();
        
        res.push_back({nullptr});
        res.push_back({new TreeNode(1)});
        
        for(int i = 2; i <= n; ++i){
            vector<TreeNode*> cur;
            
            for(int mid = 1; mid <= i; ++mid){

                for(TreeNode* left : res[mid - 1])
                for(TreeNode* right : res[i - mid]){
                    TreeNode* new_root = new TreeNode(mid);
                    
                    new_root->left = left;
                    
                    new_root->right = copyTree(right, mid);
                    
                    cur.push_back(new_root);
                }
            }
            res.push_back(cur);
        }
            
        return res[n];        
    }
    
    TreeNode* copyTree(TreeNode* root, int diff){
        if(!root)
            return nullptr;
        
        TreeNode* new_root = new TreeNode(root->val + diff);
        new_root->left = copyTree(root->left, diff);
        new_root->right = copyTree(root->right, diff);
        return new_root;
    }

};

int main() {
	Solution s;
	auto ans = s.generateTrees(3);

	return 0;
}
