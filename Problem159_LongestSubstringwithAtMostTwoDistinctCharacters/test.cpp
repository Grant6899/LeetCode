/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar 14 19:00:30 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> cnt;
		int st = 0, res = 0;
		for(int i = 0; i < s.size(); ++i){
			cnt[s[i]]++;
			while(cnt.size() > 2){
				if(--cnt[s[st]] == 0)
					cnt.erase(s[st]);
				st++;
			}
			res = max(res, i - st + 1);
		}
		return res;
    }
};

int main(){
    Solution s;
    cout << s. lengthOfLongestSubstringTwoDistinct("abdcab") << endl;
    return 0;
}


