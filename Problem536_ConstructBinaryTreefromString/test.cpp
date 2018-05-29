/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:38:42 2018
 ************************************************************************/

#include<iostream>
#include<vector>
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
    TreeNode* str2tree(string s) {
        if(s.find("(") == string::npos){
            if(s.empty())
                return nullptr;
            return new TreeNode(stoi(s));
        }
        int i = s.find("(");
        
        int left_b = i;
        
        TreeNode* root = new TreeNode(stoi(s.substr(0, i + 1)));
        
        int counter = 0;
        for(; i < s.size(); ++i){
            
            if(s[i] == '(')
                counter++;
            if(s[i] == ')')
                counter--;
            if(counter == 0)
                break;
        }
        
        //cout << "left: " << s.substr(left_b + 1, i - left_b - 1) << endl;
        
        root->left = str2tree(s.substr(left_b + 1, i - left_b - 1));
        
        
        if(s.find('(', i) == string::npos)
            root->right = nullptr;
        else{
            //cout << "right: " << s.substr(i + 2, s.size() - i - 3) << endl;
            root->right = str2tree(s.substr(i + 2, s.size() - i - 3));
        }
        return root;    
    }
};



int main() {
	Solution s;


	auto ans = s.str2tree("4(2(3)(1))(6(5))");

	return 0;
}

