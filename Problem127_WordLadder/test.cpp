/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 25 11:47:38 2017
 ************************************************************************/

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDic;
        for(auto it = wordList.begin(); it < wordList.end(); ++it)
            wordDic.insert(*it);
        
        if(wordDic.find(endWord) == wordDic.end())
            return -1;
        
        int step = 1;
        vector<string> current = {beginWord};
        
        while(!current.empty()){
            for(auto it = current.begin(); it < current.end(); ++it){
                vector<string> temp;
                step++;
                for(auto jt = wordDic.begin(); jt != wordDic.end();){
                    if(isNeighbor(*it, *jt)){
                        if(*jt == endWord)
                            return step;
                        temp.push_back(*jt);
                        jt = wordDic.erase(jt);
                    }
                    else
                        ++jt;
                }
                current = temp;
            }
        }
        return -1;
    }

    bool isNeighbor(string s1, string s2){
        int count = 0;
        
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] != s2[i])
                count++;
            if(count > 1)
                return false;
        }

        if(count == 1)
            return true;
        else return false;
    }

};

int main(){
    vector<string> strList{ "hot","dot","dog","lot","log","cog" };
    Solution s;
    cout << s.ladderLength("hit", "cog", strList) << endl;
    return 0;
}
