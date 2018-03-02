/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 21:30:04 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> matches;

        for(int i = 0; i < n; ++i)
            matches.push_back(to_string(i + 1));

        while(n > 1){
            for(int i = 0; i < n; ++i){
                matches[i] = "(" + matches[i] + "," + matches[n - 1 - i] + ")";
            }
            n = n / 2;
        }
        return matches[0];
    }
};

int main(){
    int n;
    Solution s;
    cout << s.findContestMatch(8) << endl;
    return 0;
}
