/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 26 18:46:21 2018
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> peak;
        int right_candidate = INT_MIN;

        for(int i = nums.size() - 1; i >= 0; --i){
            
            while( !peak.empty() && nums[i] > peak.top() ){
                if(peak.top() > right_candidate)
                    right_candidate = peak.top();
                peak.pop();
            }
            peak.push(nums[i]);

            if(!peak.empty() && right_candidate > nums[i])
                return true;
            
                
        }
        return false;
    }
};


int main(){
    Solution s;
    vector<int> nums {3,6,8,5,3,1,0,-2,4};
    cout << s.find132pattern(nums) << endl;

    return 0;
}
