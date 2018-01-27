/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 26 19:14:08 2018
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> sta;

        for(int i = 0; i < num.size(); ++i){
            
            while(!sta.empty() && sta.back() > num[i] && k){
                sta.pop_back();
                --k;
            }
            
            if(!(sta.empty() && num[i] == '0'))
                sta.push_back(num[i]);
        }
        
        while(!sta.empty() && k > 0){
            sta.pop_back();
            --k;
        }
        
        string res = "";
        for(char ch : sta)
            res += ch;

        return res == "" ? "0" : res;
    }
};

int main(){
    Solution s; 
    cout << s.removeKdigits("100200", 1) << endl;

    return 0;
}
