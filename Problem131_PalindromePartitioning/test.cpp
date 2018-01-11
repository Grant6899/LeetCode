/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 10 21:36:11 2018
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        find(s, 0);
        return result;
    }

private:
    vector<vector<string>> result;
    vector<string> current;
    
    void find(string s, int st){
        if(st == s.size()){
            result.push_back(current);
        }
        
        for(int i = st; i < s.size(); ++i){
            
            if(isPalindrome(s, st, i)){
                current.push_back(s.substr(st, i - st + 1));
                find(s, i + 1);
                current.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int l, int r){
        bool res = true;
        while(l<r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return res;
    }

};

int main(){
    
    Solution s;
    
    auto ans = s.partition("aaab");

    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j)
            cout<<ans[i][j]<<" ";
        cout << endl;
    }

    return 0;
}
