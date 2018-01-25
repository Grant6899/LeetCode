/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 24 11:26:08 2018
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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


class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        _root = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        
    }

    /** @return the next smallest number */
    int next() {

    }

    int next(TreeNode* root){
        if(!root){
            

        }
    }



private:
    TreeNode* _root;
};


int main() {
	Solution s;

	vector<int> src{ 1,2,2,-1, 3,-1,3 };

	TreeNode* root = createTree(src, 0);

	auto ans = s.isSymmetric(root);

	return 0;
}
