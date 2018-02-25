/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Feb 25 08:36:50 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        map<char, int> dic;

        for(char ch : T)
            dic[ch]++;

        string first_half = "";
        for(int i = 0; i < S.size(); ++i){
            string str = string(dic[S[i]], S[i]);
            first_half += str;
            dic[S[i]] = 0;
        }



        string second_half = "";

        for(auto it = dic.begin(); it != dic.end(); ++it){
            if(it->second > 0){
                string str = string(it->second, it->first);
                second_half += str;
            }
        }

      /*  cout << second_half << endl;

        vector<string> res, second_halfs;

        while(res.empty() || second_half != second_halfs.front()){
            second_halfs.push_back(second_half);
            res.push_back(first_half + second_half);
            next_permutation(second_half.begin(), second_half.end());
        }*/

        return first_half + second_half;
    }


};

int main(){
    Solution s;
    cout << s.customSortString("bca", "acbd") << endl;
    return 0;
}
