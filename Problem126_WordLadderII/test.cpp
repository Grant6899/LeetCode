/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 25 12:31:21 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> wordDic;
        for (auto it = wordList.begin(); it < wordList.end(); ++it)
            wordDic.insert(*it);

        if (wordDic.find(endWord) == wordDic.end())
            return result;

        vector<string> current = { beginWord };

        return 0;
    }

    void findNext(const string& target, vector<string>& current, set<string>& wordDic){
        if(current.back() == target){
            
        }

        for(auto it = wordDic.begin(); it != wordDic.end();){
            if(isNeighbor(current.back(), *it)){
                auto temp = *it;
                current.push_back(*it);
                it = wordDic.erase(it);
                findNext(current, wordDic);
                wordDic.insert(temp);
                current.pop_back();
            }
        }
    }



    bool isNeighbor(string s1, string s2) {
        int count = 0;

        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i])
                count++;
            if (count > 1)
                return false;
        }

        if (count == 1)
            return true;
        else return false;
    }

};

int main(){
    vector<string> strList{ "hot","dot","dog","lot","log","cog" };
    Solution s;
    cout << s.findLadders("hit", "cog", strList) << endl;
    return 0;
}

