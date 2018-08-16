/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jul  1 21:43:16 2018
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<MapNode*> nodes;
        MapNode* targetNode = nullptr;
        buildMap(root, nullptr, nodes, target, targetNode);
        
        vector<int> res;
        unordered_set<MapNode*> visited;
        dfs(targetNode, 0, K, res, visited);
        return res;
    }
    
    void dfs(MapNode* cur, int i, int K, vector<int>& res, unordered_set<MapNode*>& visited){
        if(i == K){
            res.push_back(cur->val);
            return;
        }
        
        visited.insert(cur);
        for(MapNode* next : cur->neighbors)
            if(!visited.count(next))
                dfs(next, i + 1, K, res, visited);
    }
    
    MapNode* buildMap(TreeNode* root, MapNode* father, vector<MapNode*>& nodes, TreeNode* target, MapNode*& targetNode) {
        if(!root)
            return nullptr;
        MapNode *startNode = new MapNode(root->val);
        nodes.push_back(startNode);
        if (father) {
            startNode->neighbors.push_back(father);
        }
        if (root->left) {
            startNode->neighbors.push_back(buildMap(root->left, startNode, nodes, target, targetNode));
        }
        if (root->right) {
            startNode->neighbors.push_back(buildMap(root->right, startNode, nodes, target, targetNode));
        }
        
        if(root == target)
            targetNode = startNode;
        
        return startNode;
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
	vector<int> src{ 3,5,1,6,2,0,8,-1,-1,7,4};

	TreeNode* root = createTree(src, 0);

	auto ans = s.distanceK(root, root->left, 2);

	return 0;
}
