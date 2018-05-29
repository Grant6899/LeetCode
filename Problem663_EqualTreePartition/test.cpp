/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:16:52 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
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
      bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> map;
        int sum = getsum(root, map);
        if(sum == 0)return map[sum] > 1;
        return sum%2 == 0 && map.count(sum/2);
    }
    
    int getsum(TreeNode* root,  unordered_map<int, int>& map){
        if(root == NULL)return 0;
        int cur = root->val + getsum(root->left, map) + getsum(root->right, map);
        map[cur]++;
        return cur;
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

	auto ans = s.checkEqualTree(root);
	cout << ans << endl;
	return 0;
}
