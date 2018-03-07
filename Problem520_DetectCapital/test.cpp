/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar  7 14:40:15 2018
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(isupper(word[0])){
            int cnt = 0;
            for(char ch : word)
                if(isupper(ch))
                    cnt++;

            if(cnt == 1 || cnt == word.size())
                return true;
            else return false;
        }
        else{
            for(char ch : word)
                if(isupper(ch))
                    return false;
            return true;
        }
    }
};

int main(){
    Solution s;
    cout << s.detectCapitalUse("FlAg") << endl;
    return 0;
}
