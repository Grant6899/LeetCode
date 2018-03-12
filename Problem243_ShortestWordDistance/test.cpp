/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  8 18:58:23 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int lastseen1 = -1, lastseen2 = -1;
        int res = INT_MAX;
        for(int i = 0; i < words.size(); ++i){
            if(words[i] == word1){
                if(lastseen2 != -1 && i - lastseen2 < res)
                    res = i - lastseen2;
                lastseen1 = i;
            }

            if(words[i] == word2){
                if(lastseen1 != -1 && i - lastseen1 < res)
                    res = i - lastseen1;
                lastseen2 = i;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words{"a", "b"};
    cout << s.shortestDistance(words, "a", "b") << endl;
    return 0;
}
