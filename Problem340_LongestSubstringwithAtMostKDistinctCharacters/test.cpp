/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar 14 18:59:02 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> cnt;
		int st = 0, res = 0;
		for(int i = 0; i < s.size(); ++i){
			cnt[s[i]]++;
			while(cnt.size() > k){
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
    cout << s. lengthOfLongestSubstringKDistinct("abdcab", 4) << endl;
    return 0;
}

