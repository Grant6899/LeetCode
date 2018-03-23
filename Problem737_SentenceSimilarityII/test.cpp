/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 22 19:36:00 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {

		if(words1.size() != words2.size())
			return false;

		unordered_map<string, int> idx;

		int cnt = 0;
		for(auto& p : pairs)
			if(idx.find(p.first) == idx.end())
				idx[p.first] = cnt++;


		for(auto& p : pairs){
			if(idx[p.first] != idx[p.second]){
				int temp = idx[p.second];
				for(auto& it : idx)
					if(it.second == temp)
						it.second = idx[p.first];
			}
		}

		for(int i = 0; i < words1.size(); ++i)
			if(idx[words1[i]] != idx[words2[i]])
				return false;

		return true;
    }
};

int main(){
    vector<string> words1{"great", "acting", "skills"}, words2{"fine", "drama", "talent"};
    vector<pair<string, string>> rule{{"great", "good"}, {"fine", "good"}, {"acting","drama"}, {"skills","talent"}};
    Solution s;
    cout << s. areSentencesSimilarTwo(words1, words2, rule) << endl;
    return 0;
}

