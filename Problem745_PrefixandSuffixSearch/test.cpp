/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Apr 14 17:44:51 2018
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

class WordFilter {
public:
    WordFilter(vector<string> words) {
        for(int i = 0; i < words.size(); ++i){
            string temp = words[i];
            prefixTree.insert(temp, i);
            reverse(temp.begin(), temp.end());
            suffixTree.insert(temp, i);
        }
    }
    
    int f(string prefix, string suffix) {
        string reversed_suffix = suffix;
        reverse(suffix.begin(), suffix.end());
        
        unordered_set<int> prefix_set = prefixTree.startsWith(prefix), suffix_set = suffixTree.startsWith(suffix);
        
        unordered_set<int>& min_set = (prefix_set.size() < suffix_set.size()? prefix_set : suffix_set);
        unordered_set<int>& max_set = (prefix_set.size() < suffix_set.size()? suffix_set : prefix_set);    
        
        int res = -1;
        
        for(int i : min_set)
            if(i > res && max_set.count(i))
                res = i;
        
        return res;
    }
    
private:
    IdxTrie prefixTree, suffixTree;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */


int main(){
	vector<string> words{"cabaabaaaa","ccbcababac","bacaabccba","bcbbcbacaa","abcaccbcaa","accabaccaa","cabcbbbcca","ababccabcb","caccbbcbab","bccbacbcba"};
	
	WordFilter wf(words);

	cout << wf.f("bccbacbcba","a") << endl;

	return 0;
}