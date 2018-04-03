/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  2 22:41:13 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for(string word : words)
            if(isMatch(S, word)){
                cout << word << endl;
                res++;
            }

        //cout << isMatch("nnnnnnzzzznnnnnnpppppfffff", "nzznpf") << endl;

        return res;
    }

    bool isMatch(string a, string b){
        //cout << a << " " << b << endl;
        if(a.empty() && b.empty())
            return true;

        if(a[0] != b[0])
            return false;

        char ch = a[0];
        int same_a = 0, same_b = 0;

        for(int i = 0; i < a.size(); ++i){
            if(a[i] != ch)
                break;
            same_a++;
        }
        //cout << same_a << " ";
        for(int i = 0; i < b.size(); ++i){
            if(b[i] != ch)
                break;
            same_b++;
        }
        //cout << same_b << endl;

        if(same_a < same_b || same_a != same_b && same_a < 3)
            return false;
        else
            return isMatch(a.substr(same_a), b.substr(same_b));
    }
};

int main(){
    Solution s;
    vector<string> words{"hello", "hi", "helo"};
    cout << s. expressiveWords("heeellllooo", words) << endl;
    return 0;
}

