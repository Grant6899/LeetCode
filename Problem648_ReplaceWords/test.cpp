/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Dec 21 19:34:50 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<sstream>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> dic;
        for(auto it = dict.begin(); it < dict.end(); ++it)
            dic.insert(*it);
        
        auto words = split(sentence, ' ');
        string result = "";
        for(auto it = words.begin(); it < words.end(); ++it){
            for(int len = 1; len <= (*it).size(); ++len){
                if(dic.find(it->substr(0, len)) != dic.end()){
                    *it = *dic.find(it->substr(0, len));
                    break;
                }
            }
            result += *it + " ";
        }
        result.pop_back();
        return result;
    }

    std::vector<std::string> split(const std::string& s, char delimiter){
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter)){
            tokens.push_back(token);
        }
        return tokens;
    }
};

int main(){
    Solution s;
    string sentence = "the cattle was rattled by the battery";
    vector<string> dic {"cat", "bat", "rat"};
    cout << s.replaceWords(dic, sentence) << endl;
    return 0;
}

