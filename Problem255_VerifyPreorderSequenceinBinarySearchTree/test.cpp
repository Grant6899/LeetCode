/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 22:08:07 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return check(preorder, 0, preorder.size());
    }
    
    bool check(vector<int>& preorder, int left, int right){
        if(right <= left)
            return true;
        
        int benchmark = preorder[left], mid = preorder.size();
        //cout << left << " " << right << endl;
        for(int i = left + 1; i < right; ++i)
            if(preorder[i] > benchmark){
                mid = i;
                break;
            }
        
        for(int i = mid; i < right; ++i)
            if(preorder[i] < benchmark)
                return false;
                   
        return check(preorder, left + 1, mid) && check(preorder, mid, right);
    }    
};

int main(){
    vector<int> preorder{3, 1, 2, 4, 5};
    Solution s;
    s.check(preorder, 4, 6);
    //cout << s.verifyPreorder(preorder) << endl;
    return 0;
}
