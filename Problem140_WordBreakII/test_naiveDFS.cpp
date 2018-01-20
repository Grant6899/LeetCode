/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 19 23:33:58 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic;
        for(auto ele : wordDict)
            dic.insert(ele);
        
        vector<string> cur, res;
        
        find(s, dic, 0, cur, res);

        return res;
    }

    void find(string s, const unordered_set<string>& dic, int index, vector<string>& cur, vector<string>& res){
        if(index >= s.size()){
            string tmp = "";
            for(auto ele : cur)
                tmp += ele + " ";
            tmp.pop_back();
            res.push_back(tmp);
        }
        
        for(int i = index; i < s.size(); ++i){
            if(dic.find(s.substr(index, i - index + 1)) != dic.end()){
                cur.push_back(s.substr(index, i - index + 1));
                find(s, dic, i+1, cur, res);
                cur.pop_back();
            }
        }
    }
};

int main(){
    vector<string> list {"a"}; //{"cat", "cats", "and", "sand", "dog"};
    string str = "a"; //"catsanddog";

    Solution s;

    auto ans = s.wordBreak(str, list);

    for(int i = 0; i < ans.size();++i)
            cout << ans[i] << endl;
    
    return 0;
}
