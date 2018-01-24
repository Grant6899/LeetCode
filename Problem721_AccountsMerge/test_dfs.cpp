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

class Solution{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> result;
        unordered_map<string,vector<int>> accountInfo;
        
        
        for(int i = 0 ; i < accounts.size(); i++){
            for(int j = 1 ; j < accounts[i].size(); j++)
                accountInfo[accounts[i][j]].push_back(i);
        }

        vector<bool> visited(accounts.size(), false);

        for(int i = 0 ; i < accounts.size() ; i++){
            set<string> current;
            if(visited[i]) continue;

            helper(i, current, visited, accounts, accountInfo);
            vector<string> curr(current.begin(), current.end());
            curr.insert(curr.begin(), accounts[accountInfo[curr[0]][0]][0]);
            result.push_back(curr);
        }
        return result;
    }

    void helper(int idx, set<string>& current, vector<bool>& visited, vector<vector<string>>& accounts, unordered_map<string,vector<int>> & accountInfo){
        visited[idx] = true;
        vector<string> curAccount = accounts[idx];
        int cSize = curAccount.size();

        for(int i = 1 ; i < cSize ; i++){
            current.insert(curAccount[i]);
            vector<int> idxList = accountInfo[curAccount[i]];
            int idxSize = idxList.size();
            
            for(int j = 0 ; j < idxSize ; j++){
                if(visited[idxList[j]]) continue;
                helper(idxList[j], current, visited, accounts, accountInfo);
            }
        }
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
