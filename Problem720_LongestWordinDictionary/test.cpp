/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:07:23 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> word_set;

		for(string word : words)
			word_set.insert(word);

		sort(words.begin(), words.end(), [](string& s1, string& s2){return s1.size() == s2.size()? s1 < s2 : s1.size() > s2.size();});

		for(string word : words){
			bool found = true;
			for(int i = word.size() - 1; i >= 1; --i)
				if(!word_set.count(word.substr(0, i))){
					found = false;
					break;
				}
			if(found)
				return word;
		}

		return "";
    }
};

int main(){
    Solution s;
    vector<string> words{"w","wo","wor","worl", "world"};
    cout << s.longestWord(words) << endl;
    return 0;
}
