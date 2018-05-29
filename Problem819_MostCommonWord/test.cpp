/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:30:48 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<char> punctuation{',','.', '?', '!', '\'', '"', ':', ';'};

        int i = 0;
        while(i < paragraph.size()){
            if(punctuation.count(paragraph[i]))
                paragraph.erase(i, 1);
            else
                ++i;

            if(isalpha(paragraph[i]))
                paragraph[i] = tolower(paragraph[i]);
        }

        vector<string> words = split(paragraph, ' ');

        unordered_map<string, int> cnt;

        for(string& s : words)
            cnt[s]++;

        auto com = [](pair<string, int>& p1, pair<string, int>& p2){return p1.second < p2.second;};
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(com)> pq(com);

        for(auto& it : cnt)
            pq.push(make_pair(it.first, it.second));

        unordered_set<string> ban;

        for(string s : banned)
            ban.insert(s);

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            if(ban.count(temp.first) == 0)
                return temp.first;
        }
        return "";
    }

    vector<string> split(string p, char delimiter){
		istringstream ss(p);
		string token;
		vector<string> res;
		while(getline(ss, token, delimiter))
			res.push_back(token);
		return res;
	}
};

int main(){
    Solution s;
    vector<string> banned{"hit"};
    cout << s.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", banned) << endl;
    return 0;
}
