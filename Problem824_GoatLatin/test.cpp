/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:26:11 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>
#include<set>
using namespace std;


class Solution {
public:
    string toGoatLatin(string S) {
		auto words = split(S, ' ');

		for(int i = 0; i < words.size(); ++i)
			convert(words[i], i + 1);

		string res = words[0];

		for(int i = 1; i < words.size(); ++i)
			res += " " + words[i];
		return res;
    }

	void convert(string& word, int index){
        cout << word << "       ";
		if(vowels.count(word[0])){
			word += "ma";
		}
		else{
			char ch = word[0];
			word.erase(0, 1);
			word += ch;
            word += "ma";
		}

		word += string(index, 'a');
        cout << word << endl;
	}

	const set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

	vector<string> split(string S, char delimiter){
		istringstream ss(S);
		string token;
		vector<string> res;
		while(getline(ss, token, delimiter))
			res.push_back(token);
		return res;
	}

};

int main(){
    Solution s;
    cout << s.toGoatLatin("I speak Goat Latin") << endl;
    return 0;
}
