/*************************************************************************
	> File Name: t.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 11:00:46 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> cur;
        dfs(0, cur, S);
        return cur;
    }
    
    bool numstrCom(string s1, string s2){
        if(s1.size() == s2.size()) return s1 < s2;
        else
            return s1.size() < s2.size();
    }

    bool dfs(int idx, vector<int>& cur, string& S){
        if(idx == S.size() && cur.size() >= 3)
            return true;

        /*for(int a : cur)
            cout << a << ' ';
        cout << endl;
*/
        if(S[idx] == '0' && cur.empty()){
            cur.push_back(0);
            if(dfs(idx+1, cur, S))
                return true;
            cur.pop_back();
        }
        else{
            if(cur.size() < 2){
                for(int i = idx + 1; i < S.size() && i - idx < 10; ++i){
                    string next_str = S.substr(idx, i - idx);
                    if(numstrCom(next_str, "2147483647")){
                        cur.push_back(stoi(next_str));
                        if(dfs(i, cur, S))
                           return true;
                        cur.pop_back();
                    }
                }

            }
            else{
                int a = cur[cur.size() - 2];
                int b = cur[cur.size() - 1];
                long long next = a + b;
                string next_str = to_string(next);
                string next_str_in_S = S.substr(idx, to_string(next).size());
                if(numstrCom(next_str_in_S, "2147483647") && stoi(S.substr(idx, next_str_in_S.size())) == next){
                    cur.push_back(next);
                    if(dfs(idx + to_string(next).size(), cur, S))
                        return true;
                    cur.pop_back();
                }
            }
        }

        return false;
    }
};

int main(){
    Solution s;
    cout << s.numstrCom("6106617222", "2147483647") << endl;
  //  auto ans = s. splitIntoFibonacci("8208282164246410656106617222788451072981180819106");
    auto ans = s. splitIntoFibonacci("0000");
    
    return 0;
}
