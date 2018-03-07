/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar  7 15:01:44 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // brute force
    /*vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length);
        for(auto u : updates){
            for(int i = u[0]; i <= u[1]; ++i)
                res[i] += u[2];
        }
        return res;
    }*/

    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> nums(length + 1, 0);

        for(auto u : updates){
            nums[u[0]] += u[2];
            nums[u[1]+1] -= u[2];
        }

        /*for(int i : nums)
            cout << i << ' ';
        cout << endl;*/

        vector<int> res;
        int sum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            res.push_back(sum);
            sum += nums[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> updates{{1,3,2},{2,4,3}, {0,2,-2}};
    vector<int> ans = s.getModifiedArray(5, updates);
    for(int a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}
