/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 27 21:19:01 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        istringstream iss(s);
        vector<string> parsed = split(s, ' ');

        string res = "";
        for(string str : parsed)
            res += str + " ";
        res.pop_back();
        return res;
    }

    vector<string> split(const string& s, char delimiter){
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)){
            reverse(token.begin(), token.end());
            tokens.push_back(token);
        }
        return tokens;
    }


};


int main(){
    
    Solution s;
    cout << s.reverseWords("Let's take LeetCode contest") << endl;

    return 0;
}
