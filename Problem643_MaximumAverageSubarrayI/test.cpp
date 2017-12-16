/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Dec 15 21:03:15 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long sum = 0; 
        int len = nums.size();

        for (int i = 0; i < k; i++)
            sum+=nums[i];

        long max = sum;
        int p1 = 0, p2 = k;
        while(p2 < len){
            sum = sum - nums[p1] + nums[p2];
            if (max < sum)
                max = sum;
            ++p1;
            ++p2;
        }
        
        return max / ((double) k);
    }
};

int main(){
    Solution s;
    vector<int> nums {1,12,-5,-6,50,3};

    cout << s.findMaxAverage(nums, 4) << endl;

    return 0;
}
