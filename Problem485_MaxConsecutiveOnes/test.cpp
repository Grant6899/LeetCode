/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 18 13:11:01 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp = 0, p = 0, result = 0;
        while(p < nums.size()){
            if(nums[p] != 1){
                temp = 0;
                ++p;
            }
            else{
                while(nums[p] == 1){
                    ++p;
                    ++temp;
                }
                if(temp > result)
                    result = temp;
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
