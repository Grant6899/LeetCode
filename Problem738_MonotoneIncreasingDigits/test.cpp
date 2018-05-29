/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 17:51:46 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int len = to_string(N).size();
        string N_str = to_string(N);
        string ans = "";

        for(int i = 0; i < len; ++i){
            bool find = false;
            for(char ch = '0'; ch <= '9'; ++ch){
                if(ans + string(len - i, ch) > N_str){
                    ans += char(ch - 1);
                    find = true;
                    break;
                }
            }
            if(!find)
                ans += '9';
        }
        return stoi(ans);
    }

};

int main(){
    Solution s;
    cout << s. monotoneIncreasingDigits(1234) << endl;
    return 0;
}
