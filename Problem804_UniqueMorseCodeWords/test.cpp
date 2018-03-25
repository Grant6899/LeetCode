/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar 25 17:50:25 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mos{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> pool;
        
        for(auto word : words){
            string code = "";
            for(char ch : word){
                code += mos[ch-'a'];
            }
            pool.insert(code);
        }
        
        return pool.size();
    }
};

int main(){
    Solution s;
    vector<string> words{"gin", "zen", "gig", "msg"};
    cout << s. uniqueMorseRepresentations(words) << endl;
    return 0;
}
