/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan 23 22:04:00 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct TrieNode{
    char content;
    int isend;
    vector<TrieNode*> children;
    TrieNode(char ch) : content(ch), isend(0){ children = vector<TrieNode*>(26, NULL); }
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {          
        _root = new TrieNode('*');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insert_helper(word, _root);
    }

    void insert_helper(string word, TrieNode* root){
        if(word.empty()){
            root->isend = 1;
            return;
        }

        if(!root->children[word[0] - 'a']){
            root->children[word[0] - 'a'] = new TrieNode(word[0]); 
        }
        insert_helper(word.substr(1), root->children[word[0] - 'a']);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search_helper(word, _root);
    }

    bool search_helper(string word, TrieNode* root){
        if(word.empty()) 
            return root->isend;
        
        if(root->children[word[0]-'a']){
            if(search_helper(word.substr(1), root->children[word[0]-'a']))
                return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWith_helper(prefix, _root);
    }

    bool startsWith_helper(string prefix, TrieNode* root){
        if(prefix.empty()){
            if(root)
                return true;
            else
                return false;
        } 

        if(!root)
            return false;

        if(startsWith_helper(prefix.substr(1), root->children[prefix[0]-'a']))
            return true;

        return false;
    }

private:
    TrieNode* _root;
};

int main(){
    
    Trie dic;

    dic.insert("abc");
    dic.insert("xyz");
    dic.insert("xy");

    return 0;
}
