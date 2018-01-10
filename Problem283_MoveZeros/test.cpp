/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan  9 20:32:05 2018
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto endpoint = remove(nums.begin(), nums.end(), 0);
        for_each(endpoint, nums.end(), [](int& ele){ele = 0;});
    }
};

int main(){
    vector<int> v {0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(v);

    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    return 0;
}
