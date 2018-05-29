/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu May  3 18:58:16 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct TrieNode{
	char val;
	vector<TrieNode*> next;
    bool isend;
	TrieNode(char ch) : val(ch), isend(true){next = vector<TrieNode*>(26, nullptr);}
};

class Solution {
public:

    int minimumLengthEncoding(vector<string>& words) {
					
		TrieNode* root = new TrieNode('*');
		
		//for(string word : words)
		//	addWord(word, root);
        addWord("time",  root);
        addWord("me", root);
        int res = 0;
		getWordLength(root, 0, res);
		return res;
    }
	
	void getWordLength(TrieNode* root, int level, int& count){
        cout << level << ":" << root->val << endl;
        if(root->isend){
            count += level + 1;
            return;
        }
        
		for(int i = 0; i < 26; i++){
			if(root->next[i])
				getWordLength(root->next[i], level + 1, count);
		}
	}

	void addWord(string word, TrieNode* root){
		
		TrieNode* cur = root;
		
		for(int i = word.size() - 1; i >= 0; i--){
            cout << word[i] << endl;
			if(cur->next[word[i] - 'a']){
				cur = cur->next[word[i] - 'a'];
			}
			else{
                cout << "new node\n";
                cur->isend = false;
				cur->next[word[i] - 'a'] = new TrieNode(word[i]);
				cur = cur->next[word[i] - 'a'];
			}
		}	
	}
};

int main(){
    vector<string> words{"time", "me"};
    Solution s;
    cout << s. minimumLengthEncoding(words) << endl;
    return 0;
}
