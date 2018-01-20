/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 19 23:33:58 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic;
        for(auto ele : wordDict)
            dic.insert(ele);
        unordered_map<string, vector<string>> map;
        vector<string> res = find(s, dic, map);
        
        return res;
    }

    vector<string> find(string s, const unordered_set<string>& dic, unordered_map<string, vector<string>>& map){
        if(map.find(s) != map.end()){
            return map[s];
        }

        vector<string> res;
        if(s.size() == 0){
            res.push_back("");
            return res;
        }

        for(string word : dic){
            if(s.substr(0, word.size()) == word){
               vector<string> subvec = find(s.substr(word.size()), dic, map);
                for(string sub : subvec) 
                    res.push_back(word + (sub.empty() ? "" : " ") + sub);
            }
        }

        map[s] = res;
        return res;
    }
};

int main(){
    vector<string> list {"cat", "cats", "and", "sand", "dog"};
    string str = "catsanddog";

    Solution s;

    auto ans = s.wordBreak(str, list);

    for(int i = 0; i < ans.size();++i)
            cout << ans[i] << endl;
    
    return 0;
}
