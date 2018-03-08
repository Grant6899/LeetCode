/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  8 18:33:50 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
		vector<int> counter(26, 0);

		for(char ch : licensePlate){
			if(ch >= 'a' && ch <= 'z')
				counter[ch - 'a']++;
			else if(tolower(ch) >= 'a' && tolower(ch) <= 'z')
				counter[tolower(ch) - 'a']++;
		}

        string res = string(1001, 'a');
		for(string word : words){
			vector<int> wordcounter(26, 0);
			bool find = true;
			for(char ch : word){
				if(ch >= 'a' && ch <= 'z')
					wordcounter[ch - 'a']++;
				else if(tolower(ch) >= 'a' && tolower(ch) <= 'z')
					wordcounter[tolower(ch) - 'a']++;
			}

			//cout << counter['s' - 'a'] << " " << wordcounter['s' - 'a'] << endl;
			for(int i = 0; i < 26; ++i)
				if(counter[i] > wordcounter[i]){
					find = false;
					break;
				}

			if(find && word.size() < res.size()) res = word;
		}
		return res;
    }
};

int main(){
    Solution s;
    vector<string> words{"step","steps","stripe","stepple"};
    
    cout << s.shortestCompletingWord("1s3 spt", words) << endl;
    return 0;
}
