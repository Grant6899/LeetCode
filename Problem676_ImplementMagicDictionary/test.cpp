/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar 12 23:56:55 2018
 ************************************************************************/

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string &s:dict) words.insert(s);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
          for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            for (int j = 0; j < 26; j++) {
                if (c == j+'a') continue;
                word[i] = j+'a';
                if (words.count(word)) return true;
            }
            word[i] = c;
        }
        return false;
    }
private:
    unordered_set<string> words;
};

int main(){
    MagicDictionary md;
    vector<string> dict{"hello", "leetcode"};
    md.buildDict(dict);
    cout << md.search("hllo") << endl;
    return 0;
}
