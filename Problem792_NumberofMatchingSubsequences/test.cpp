/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:31:49 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> ch_location(26);

		for(int i = 0; i < S.size(); ++i)
			ch_location[S[i]-'a'].push_back(i);

		int res = 0;
		for(string word : words){
			int last = -1;
			bool find = true;
			for(char ch : word){
				auto it = upper_bound(ch_location[ch-'a'].begin(), ch_location[ch-'a'].end(), last);
                if(it == ch_location[ch-'a'].end()){
					find = false;
					break;
				}
				last = *it;
			}
			if(find) res++;
		}
		return res;
    }
};

int main(){
    vector<string> words{"a", "bb", "acd", "ace"};
    Solution s;
    cout << s.numMatchingSubseq("abcde", words) << endl;
    return 0;
}
