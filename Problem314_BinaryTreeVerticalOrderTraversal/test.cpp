/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar  7 13:16:44 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<map>

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> map;
        queue<pair<int, TreeNode*>> q;
        vector<vector<int>> res;

        if(root) 
            q.push(make_pair(0, root));
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            //cout << cur.first << " " << cur.second->val << endl;
            
            map[cur.first].push_back(cur.second->val);

            if(cur.second->left) q.push(make_pair(cur.first - 1, cur.second->left));
            if(cur.second->right) q.push(make_pair(cur.first + 1, cur.second->right));
        }
        
        
        
        for(auto e : map)
            res.push_back(e.second);
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

int main(){
	std::vector<int> src{1,2, 3, 5, 4};
	TreeNode* root = createTree(src, 0);
	Solution s;
	auto ans = s.verticalOrder(root);
	return 0;
}



