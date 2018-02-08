/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Feb  6 23:17:35 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int res = 0;
        vector<vector<bool>> dp(p.size(), vector<bool>(p.size(), false));
        vector<vector<bool>> found(26, vector<bool>(p.size(), false));

        for(int i = 0; i < p.size(); ++i){
                dp[i][i] = true;
                if(!found[p[i] - 'a'][1])
                    res++;
                found[p[i] - 'a'][1] = true;
            }

        for(int i = 2; i <= p.size(); i++)
        for(int j = 0; j + i - 1 < p.size(); j++){
            if(dp[j][j+i-2] && isValid(p[j+i-2], p[j+i-1])){
                dp[j][j+i-1] = true;
                if(!found[p[j] - 'a'][i])
                    res++;
                found[p[j] - 'a'][i] = true;
            }
        }
        return res;
    }

    bool isValid(char ch1, char ch2){
        return ch1 == 'z'? ch2 == 'a' : ch2 - ch1 == 1;
    }
};



int main(){
    Solution s;

    cout << s.findSubstringInWraproundString("zab") << endl;
    return 0;
}
