/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 24 11:26:08 2018
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
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
        findLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_data.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp = _data.top();
        _data.pop();
        if(temp->right)
            findLeft(temp->right);
        return temp->val;
    }

private:
    stack<TreeNode*> _data;

    void findLeft(TreeNode* root){
        while(root){
            _data.push(root);
            root = root->left;
        }
    }
};


int main() {

	vector<int> src{ 1,2,2,-1, 3,-1,3 };

	TreeNode* root = createTree(src, 0);
    
    BSTIterator bst_it = BSTIterator(root);

    while(bst_it.hasNext()){
        cout << bst_it.next() << ' ';
    }
	return 0;
}
