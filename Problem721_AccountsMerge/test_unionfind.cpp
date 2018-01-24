/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan 23 19:51:01 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];
            }
        }
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p;
        }
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);

        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
private:
    string find(string s, map<string, string>& p) {
        return p[s] == s ? s : find(p[s], p);
    }
};

int main(){
    Solution s;

    vector<vector<string>> data {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};

    auto ans = s.accountsMerge(data);

    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i][0] <<" : ";
        for(int j = 1; j < ans[i].size(); ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
