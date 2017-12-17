/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 16 17:13:05 2017
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int len = nums.size();
        for(auto it = nums.begin(); it < nums.end(); ++it)
             if (++map[*it] > len / 2)
                return *it;
        return 0;
    }
};

int main(){
    vector<int> nums {1, 2, 3, 4, 4, 4, 4};
    Solution s;
    cout << s.majorityElement(nums) << endl;
    return 0;
}
