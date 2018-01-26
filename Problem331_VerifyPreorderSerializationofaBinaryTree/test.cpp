/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 25 21:37:39 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> tree;
            
        
        preorder += ",";        
        while(preorder != ""){
            
            string temp = preorder.substr(0, preorder.find(','));
            preorder = preorder.substr(preorder.find(',')+1);
            tree.push_back(temp);

            while(tree.size() >= 2 && tree.back() == "#" && tree[tree.size() - 2] == "#"){
                tree.pop_back();
                tree.pop_back();
                tree.pop_back();
                tree.push_back("#");
            }

            if( tree.size() == 1 && tree[0] == "#" && preorder != "")
                return false;

            for(auto ch : tree)
                cout << ch << ' ';
            cout << endl;
        }
        
        if(tree.size() == 1 && tree[0] == "#")
            return true;
        else 
            return false;
    }
};

int main(){

    Solution s;
    cout << s.isValidSerialization("1,#,#,#,#") << endl;

    return 0;
}
