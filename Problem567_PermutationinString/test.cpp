/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 25 23:01:16 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        vector<int> target(26, 0), dic(26, 0);

        for(int i = 0; i < s1.size(); ++i){
            dic[s2[i] - 'a']++;
            target[s1[i] - 'a']++;
        }

        for(int i = s1.size(); i < s2.size(); ++i){
            if(dic == target)
                return true;

            dic[s2[i] - 'a']++;
            dic[s2[i-s1.size()] - 'a']--;

        }

        if(dic == target)
            return true;
        return false;
    }
};

int main(){
    string s1 = "ab", s2 = "eidbaooo";
    Solution s;
    cout << s.checkInclusion(s1, s2) << endl;

    return 0;
}
