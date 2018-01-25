/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan 23 23:17:54 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct DicNode{
    char content;
    int isend;
    vector<DicNode*> children;
    DicNode(char ch) : content(ch), isend(0){ children = vector<DicNode*>(26, NULL); }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        _root = new DicNode('*');
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWord_helper(word, _root);
    }

    void addWord_helper(string word, DicNode* root){
        if(word.empty()){
            root->isend = 1;
            return;
        }
    
        if(!root->children[word[0] - 'a'])
            root->children[word[0]- 'a'] = new DicNode(word[0]);

        addWord_helper(word.substr(1), root->children[word[0]-'a']);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_helper(word, _root);
    }

    bool search_helper(string word, DicNode* root){
        if(word.empty())
            return root->isend;

        if(word[0] != '.'){
            if(root->children[word[0] - 'a'] && search_helper(word.substr(1), root->children[word[0] - 'a']))
                return true;
        }
        else{
            for(int i = 0; i < root->children.size(); ++i){
                if(root->children[i] && search_helper(word.substr(1), root->children[i]))
                    return true;
            }
        }

        return false;
    }

private:
    DicNode* _root;
};

int main(){
    WordDictionary dic;

    dic.addWord("bad");
    dic.addWord("dad");
    dic.addWord("mad");
    cout << dic.search("pad") << endl;
    cout << dic.search("bad") << endl;
    cout << dic.search(".ad") << endl;
    cout << dic.search("b..") << endl;
    return 0;
}

