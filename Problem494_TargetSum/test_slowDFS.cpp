/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 14 15:22:24 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        int cur = 0;
        find(nums, 0, cur, S, res);
        return res;
    }
    
    void find(vector<int>& nums, int idx, int& cur, int S, int& res){
        if(idx == nums.size()-1 && abs(cur - S) == nums.back()){
            res++;
            return;
        }

        for(int i = 0; i <=1; i++){
            if(idx < nums.size() - 1){ 
               if(i == 0){
                    cur += nums[idx]; 
                    find(nums, idx+1, cur, S, res);
                    cur -= nums[idx];
                }
                else{
                    cur -= nums[idx]; 
                    find(nums, idx+1, cur, S, res);
                    cur += nums[idx];
                }
            }
        }
    }
};

int main(){
    vector<int> nums {1, 1, 1, 1, 1};

    Solution s;

    cout << s.findTargetSumWays(nums, 3) << endl;

    return 0;
}
