/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:43:05 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
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
    MapNode* buildMap(TreeNode* root, MapNode* father, vector<MapNode*>& nodes) {
        if(!root)
            return nullptr;
        MapNode *startNode = new MapNode(root->val);
        nodes.push_back(startNode);
        if (father) {
            startNode->neighbors.push_back(father);
        }
        if (root->left) {
            startNode->neighbors.push_back(buildMap(root->left, startNode, nodes));
        }
        if (root->right) {
            startNode->neighbors.push_back(buildMap(root->right, startNode, nodes));
        }
        return startNode;
    }	

    int longestConsecutive(TreeNode* root) {
        
		vector<MapNode*> nodes;
		buildMap(root, nullptr, nodes);
		
		int res = 0;
        for(auto start : nodes){
			unordered_set<MapNode*> visited;
			dfs(start, visited, 1, res);
		}
		
		return res;
    }
	
	void dfs(MapNode* cur, unordered_set<MapNode*>& visited, int cur_len, int& res){
		if(!cur)
			return;
		
		res = max(res, cur_len);
		visited.insert(cur);
		
		for(MapNode* next : cur->neighbors)
			if(next->val == cur->val + 1){
				dfs(next, visited, cur_len + 1, res);
			}
		
		visited.erase(cur);
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

	auto ans = s.longestConsecutive(root);

	return 0;
}
