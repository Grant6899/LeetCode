/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Apr 11 21:29:14 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

struct IdxTrieNode{
    char content;
    vector<IdxTrieNode*> children;
	unordered_set<int> idx_set;
    IdxTrieNode(char ch) : content(ch){ children = vector<IdxTrieNode*>(26, NULL); }
};


class IdxTrie {
public:
    /** Initialize your data structure here. */
    IdxTrie() {
        _root = new IdxTrieNode('*');
    }

    /** Inserts a word into the trie. */
    void insert(string word, int idx) {
        insert_helper(word, idx, _root);
    }

    void insert_helper(string word, int idx, IdxTrieNode* root){
		root->idx_set.insert(idx);
        if(word.empty()){
            return;
        }

        if(!root->children[word[0] - 'a']){
            root->children[word[0] - 'a'] = new IdxTrieNode(word[0]);
        }

        insert_helper(word.substr(1), idx, root->children[word[0] - 'a']);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    unordered_set<int> startsWith(string prefix) {
        return startsWith_helper(prefix, _root);
    }

    unordered_set<int> startsWith_helper(string prefix, IdxTrieNode* root){
        if(prefix.empty()){
            if(root)
                return root->idx_set;
            else
                return unordered_set<int>();
        }

        if(!root)
            return unordered_set<int>();

        return startsWith_helper(prefix.substr(1), root->children[prefix[0]-'a']);
    }

private:
    IdxTrieNode* _root;
};


class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        IdxTrie dic;

        for(int i = 0; i < words.size(); ++i)
            dic.insert(words[i], i);

        vector<vector<string>> res;
        vector<string> cur;
        dfs(cur, dic, res, words);
        return res;
    }

    void dfs(vector<string>& cur, IdxTrie& dic, vector<vector<string>>& res, vector<string>& words){
        /*
        for(string s : cur)
            cout << s << " ";
        cout << endl;
        */
        if(!cur.empty() && cur.size() == cur.back().size()){
            res.push_back(cur);
            return;
        }

        /*cout << "prefix:" << prefix(cur) << endl;
        for(int idx : dic.startsWith( prefix(cur)))
            cout << idx << " ";

        cout << endl << endl;*/
        for(int idx : dic.startsWith( prefix(cur))){
            cur.push_back(words[idx]);
            dfs(cur, dic, res, words);
            cur.pop_back();
        }
    }

    string prefix(vector<string>& cur){
        string res = "";
        for(int i = 0 ; i < cur.size(); ++i)
            res += cur[i][cur.size()];
        return res;
    }
};

int main(){
    Solution s;
    vector<string> words{"ball","area","lead","lady"};
    
    auto ans = s. wordSquares(words);

    for(auto a : ans){
        for(string s : a)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}
