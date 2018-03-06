/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:17:43 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> rec;
        int sum = 0, res = 0;
        rec[0] = -1;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];

            if(rec.find(sum - k) != rec.end())
                res = max(res, i - rec[sum-k]);

            if(rec.find(sum) == rec.end())
                rec[sum] = i;
        }
        return res;

    }
};

int main(){
    vector<int> nums{1, -1, 5, 2, 3};
    Solution s;
    cout << s.maxSubArrayLen(nums, 7) << endl;
    return 0;
}
