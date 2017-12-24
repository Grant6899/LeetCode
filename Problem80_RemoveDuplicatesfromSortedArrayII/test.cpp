/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 23 15:30:05 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i){
            if(i + 2 < nums.size() && nums[i] == nums[i+1] && nums[i] == nums[i+2])
                continue;
            result.push_back(nums[i]);
            count++;
        }
        nums = result;
        return count;
    }
};

int main(){
    Solution s;
    vector<int> vec {1, 1, 1, 2, 2, 3};
    cout << s.removeDuplicates(vec) << endl;
    return 0;
}
