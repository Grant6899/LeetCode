/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 17:54:18 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
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
    int findClosestLeaf(TreeNode* root, int k) {
        vector<vector<int>> graph(1001);    
        treeToGraph(root, graph);
        
        int res = BFS(graph, k, root->val);
        
        return res;
    }
    
private:
    int BFS(vector<vector<int>>& graph, int root, int tree_root){
        if(graph[root].empty() || graph[root].size() == 1 && root != tree_root)
            return root;
        
        vector<bool> visited(1001, false);
        queue<pair<int, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            pair<int, int> st = q.front();
            for(int next : graph[st.first]){
                if(!visited[next]){
                    visited[next] = true;
                    if(graph[next].size() == 1 && next != tree_root)
                        return next;
                    q.push({next, st.second + 1});
                }
            }
            q.pop();
        }
    }
    
    void treeToGraph(TreeNode* root, vector<vector<int>>& graph){
        if(!root)
            return;
        
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            treeToGraph(root->left, graph);
        }
        
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            treeToGraph(root->right, graph);
        }        
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

	vector<int> src{ 1,2,4,-1, 3,-1,9 };

	TreeNode* root = createTree(src, 0);

	cout << s.findClosestLeaf(root, 3) << endl;

	return 0;
}
