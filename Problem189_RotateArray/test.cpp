/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 19 23:07:01 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main(){
    vector<int> nums { 1,2,3,4,5,6,7 };

    Solution s;

    s.rotate(nums, 2);

    for(int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ' ';
    cout << endl;

    return 0;
}
