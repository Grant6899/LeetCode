/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Dec 26 19:55:07 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        int left = 1, right = 1, len = nums.size();
        int result = 0;
        for(int i = 0; i < len; ++i){
            left *= nums[i];
            right *= nums[len - i - 1];
            result = max(result, max(left, right));
            
            left = left == 0 ? 1 : left;
            right = right == 0 ? 1 : right;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> vec {2, 3, -2, 4};
    cout << s.maxProduct(vec) << endl;
    return 0;
}
