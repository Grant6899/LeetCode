/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:46:27 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> counts;
		vector<int> res;
		int num = words.size(), len = words[0].size();

		for(string word : words)
			counts[word]++;

		for(int i = 0; i < s.size() - num * len + 1; ++i){
			unordered_map<string, int> observed;

			int j = 0;

			for(; j < num; ++j){
				string word = s.substr(i + j * len, len);
                //cout << word << endl;
				if(counts.find(word) != counts.end()){
					observed[word]++;
					if(observed[word] > counts[word])
						break;
				}
				else
					break;
			}

			if(j == num) res.push_back(i);

		}
		return res;
	}
};

int main(){
    vector<string> words{"foo", "bar"};
    Solution s;
    auto ans = s.findSubstring("barfoothefoobarman", words);
    for(int a : ans)
        cout << a << endl;
    return 0;
}
