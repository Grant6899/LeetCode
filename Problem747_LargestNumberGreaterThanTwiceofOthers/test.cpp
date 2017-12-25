/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 24 16:44:27 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = INT_MIN, max_2 = INT_MIN;
        int max_index = -1;

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > max){
                max_2 = max;
                max = nums[i];
                max_index = i;
            }
            else if(nums[i] > max_2)
                max_2 = nums[i];
        }
        
        if (max_2 * 2 <= max)
            return max_index;
        else
            return -1;
    }
};

int main(){
    vector<int> vec {3, 6, 1, 0};
    Solution s;
    cout << s.dominantIndex(vec) << endl;
    return 0;
}
