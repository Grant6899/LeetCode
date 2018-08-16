#include<iostream>
#include<vector>
#include<algorithm>

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(root, 0, sum, cur, res);
        return res;
    }
    
    void dfs(TreeNode* root, int cur_sum, int sum, vector<int>& cur, vector<vector<int>>& res){
        cur.push_back(root->val);
        cur_sum += root->val;
        
        for(int c : cur)
            cout << c << " ";
        cout << endl;
        
        if( cur_sum == sum && !root->left && !root->right){
            res.push_back(cur);
            return;
        }
            
        if(root->left) dfs(root->left, cur_sum, sum, cur, res);
        if(root->right) dfs(root->right, cur_sum, sum, cur, res);
        
        cout << "poping " << cur.back() << endl;
        cur.pop_back();
        
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



	vector<int> src{ 5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,5,1 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.pathSum(root, 22);

	return 0;
}
