/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 31 10:08:48 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> v_location;
        string v_str = "";

        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
            || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                v_location.push_back(i);
                v_str += s[i];
            }
        }

        reverse(v_str.begin(), v_str.end());
        for(int i = 0; i < v_location.size(); i++)
            s[v_location[i]] = v_str[i];
        
        return s;
    }
};

int main(){
    Solution s;
    cout << s.reverseVowels("hello") << endl;
    return 0;
}
