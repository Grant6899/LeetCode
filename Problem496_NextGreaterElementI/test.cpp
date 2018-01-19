/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 18 22:28:20 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> index;
        for(int i = 0; i < nums.size(); ++i){
            index[nums[i]] = i;
        }

        vector<int> res;

        for(int i = 0; i < findNums.size(); ++i){
            
            bool find = false;
            for(int j = index[findNums[i]] + 1; j < nums.size(); ++j){
                if(nums[j] > findNums[i]){
                    res.push_back(nums[j]);
                    find = true;
                    break;
                }
            }
            if(!find)
                res.push_back(-1);
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> set1 { 2,4}, set2 { 1,2,3,4 };
    auto ans = s.nextGreaterElement(set1, set2);

    for(int i = 0; i < set1.size();++i)
        cout << ans[i] << " ";

    return 0;
}
