/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:10:57 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int A_counter = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'A')
                A_counter++;

            if(A_counter > 1)
                return false;
            if(i > 1 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L')
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.checkRecord("PPALLP") << endl;
    return 0;
}
