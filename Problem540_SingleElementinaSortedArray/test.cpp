/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 17 20:12:02 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x = 0;
        for(auto ele : nums)
            x ^= ele;
        return x;
    }
};

int main(){
    vector<int> nums {1,1,2,3,3,4,4,8,8};
    Solution s;
    cout << s.singleNonDuplicate(nums) << endl;
    return 0;
}
