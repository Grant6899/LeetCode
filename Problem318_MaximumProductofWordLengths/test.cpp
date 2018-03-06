/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:55:14 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<bool>> counts;

		for(string w : words){
			vector<bool> temp(256, false);
			for(char ch : w)
				temp[ch] = true;
			counts.push_back(temp);
		}

		int res = 0;
		for(int i = 0; i < words.size();++i)
			for(int j = i + 1; j < words.size();++j){
				bool overlap = false;
				for(int k = 97; k < 123; ++k)
					if(counts[i][k] == true && counts[j][k] == true){
						overlap = true;
						break;
					}
				if(overlap) continue;
				res = max(res, (int)(words[i].size() * words[j].size()));

			}
		return res;
    }
};

int main(){
    vector<string> words{ "a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    Solution s;
    cout << s.maxProduct(words) << endl;
    return 0;
}
