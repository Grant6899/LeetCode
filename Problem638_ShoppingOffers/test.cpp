/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan 23 19:32:11 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // memorize intermediate results
        unordered_map<int, int> mp;
        return helper(price, special, mp, get_key(needs));
    }
private:
    int helper(vector<int>& price, vector<vector<int>>& special, unordered_map<int, int>& mp, int k) {
        if (mp.count(k)) return mp[k];
        int n = price.size(), ans = 0;
        // pows is to help get each digit of key
        vector<int> pows(n, 1);
        for (int i = n-2; i >= 0; i--) pows[i] = pows[i+1]*10;
        for (int i = 0; i < n; i++) ans += ((k/pows[i])%10)*price[i];
        for (auto spe:special) {
            int key = 0, i = 0;
            // check whether this offer is valid
            while (i < n) {
                int t = (k/pows[i])%10;
                if (t >= spe[i])
                    key = key*10+(t-spe[i++]);
                else
                    break;
            }
            if (i == n) ans = min(ans, spe[n]+helper(price, special, mp, key));
        }
        mp[k] = ans;
        return ans;
    }
    int get_key(vector<int>& needs) {
        int n = needs.size(), key = 0;
        for (int i = n-1, p = 1; i >= 0; i--, p *= 10)
            key += needs[i]*p;
        return key;
    }
};

int main(){
    Solution s;

    vector<int> price {2,3,4};

    vector<vector<int>> specials {{1,1,0,4}, {2,2,1,9}};

    vector<int> needs {1,2,1};

    cout << s.shoppingOffers(price, specials, needs) << endl;

    return 0;
}

