/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 21:05:15 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<sstream>
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> pool;
		vector<TreeNode*> res;
		tranversal(root, pool, res);

		return res;
    }
	
	void tranversal(TreeNode* root, unordered_map<string, int>& pool, vector<TreeNode*>& res){
		if(!root)
			return;
		
		string str = serialize(root);
		if(pool.find(str) != pool.end() && pool[str] == 1){ 
			res.push_back(root);
		}
		pool[str]++;
		
		tranversal(root->left, pool, res);
		tranversal(root->right, pool, res);	
	}
	
	
	string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
	
	void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
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



	vector<int> src{ 1,2,2,-1, 3,-1,3 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.findDuplicateSubtrees(root);

	return 0;
}
