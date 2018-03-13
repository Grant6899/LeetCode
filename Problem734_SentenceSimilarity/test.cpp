/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar 12 23:51:36 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
		if(words1.size() != words2.size())
			return false;

		map<string, unordered_set<string>> graph;

		for(auto p : pairs){
			graph[p.first].insert(p.second);
			graph[p.second].insert(p.first);
		}

		for(int i = 0; i < words1.size(); ++i){
			if(words1[i] != words2[i] && !graph[words1[i]].count(words2[i]))
				return false;
		}
		return true;
    }

};

int main(){
    Solution s;
    vector<string> words1{"great","acting","skills"}, words2{"fine","drama","talent"};
    vector<pair<string, string>> pairs{{"great","fine"},{"drama","acting"},{"skills","talent"}};

    cout << s.areSentencesSimilar(words1, words2, pairs) << endl;
    return 0;
}
