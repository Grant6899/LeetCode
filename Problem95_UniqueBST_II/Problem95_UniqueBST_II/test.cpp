#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* q;
	vector < vector<TreeNode*>> g{ {NULL}, { q = new TreeNode(1)} };
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n < 2)
			return g[n];
		else {
			for (int i = 2; i <= n; i++) {
				vector<TreeNode*> result;
				for (int j = 1; j <= i; j++) {
					
					for (auto left_it = g[j-1].begin(); left_it < g[j-1].end(); left_it++)
						for (auto right_it = g[i - j].begin(); right_it < g[i - j].end(); right_it++) {
							TreeNode* current_root = new TreeNode(j);
							current_root->left = *left_it;
							TreeNode* current_right = new TreeNode(*right_it);
							current_root->left = *left_it;

						}

				}
			}


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



	vector<int> src = { 1,2,3,4,5,6,7,8,-1,-1,9 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.numTrees(4);

	return 0;
}