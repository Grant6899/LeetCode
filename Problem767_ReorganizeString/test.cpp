/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 20 22:32:14 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> mp(26);
        int n = S.size();
        for (char c: S) ++mp[c-'a'];
        vector<pair<int, char>> charCounts;
        for (int i = 0; i < 26; ++i) {
            if (mp[i] > (n+1)/2) return "";
            if (mp[i]) charCounts.push_back({mp[i], i+'a'});
        }
        sort(charCounts.rbegin(), charCounts.rend());
        string strSorted;
        for (auto& p: charCounts)
            strSorted += string(p.first, p.second);
        string ans;
        for (int i = 0, j = (n-1)/2+1; i <= (n-1)/2; ++i, ++j) {
            ans += strSorted[i];
            if (j < n) ans += strSorted[j];
        }
        return ans;
    }
};

int main(){
    Solution s;

    cout << s.reorganizeString("kkkkzrkatkwpkkkktrq") << endl;

    return 0;
}
