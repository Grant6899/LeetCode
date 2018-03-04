/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar  4 01:31:36 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> counts;
        vector<string> res;
        string str = "";
        for(int i = 0; i < s.size(); ++i){
            str = str + s[i];

            if(i >= 9){
                //cout << str <<endl;
                if(counts.find(str) != counts.end() && counts[str] == 1)
                    res.push_back(str);
                counts[str]++;
                str = str.erase(0, 1);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    auto ans = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(string str : ans)
        cout << str << endl;
    return 0;
}
