/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 21 18:52:44 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        vector<bool> used(nums.size(), 0);
        vector<vector<int>> current;
        
        int sum = totalLen(nums);

        if(sum == 0 || sum % 4 != 0)
            return false;

        int maxx = 0, max_index = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > maxx){
                maxx = nums[i];
                max_index = i;
            }
        }

        int target_len = sum / 4;

        bool res = find(0, current, nums, used, target_len, max_index);
        return res;
    }

    bool find(int index, vector<vector<int>>& current, const vector<int>& nums, vector<bool>& used, int target_len, int max_index){
        if(index == nums.size())
            return true;

        // optimization: if longest match is not used, then no solution
        if(index > 0 && used[max_index] == false)
            return false;
        
        if(current.empty() || totalLen(current.back()) == target_len){
            current.push_back({});
            if(find(index, current, nums, used, target_len, max_index))
               return true;
            current.pop_back();
        }
        else{
            for(int i = 0; i < nums.size(); ++i){
                if(!used[i] && ( current.back().empty() || nums[i] <= current.back().back() ) &&totalLen(current.back()) + nums[i] <= target_len){
                    current.back().push_back(nums[i]);
                    used[i] = true;
                    if(find(index+1, current, nums, used, target_len, max_index))
                        return true;
                    used[i] = false;
                    current.back().pop_back();
                }
            }
        }
        
        return false;
    }

    int totalLen(const vector<int>& vec){
        int res = 0;
        for(auto ele : vec)
            res += ele;
        return res;
    }

};

int main(){
    Solution s;
    vector<int> nums {5,5,5,5,16,4,4,4,4,4,3,3,3,3};
    cout << s.makesquare(nums) << endl;
    return 0;
}
