/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 18 22:48:31 2018
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    //We use a stack to keep a decreasing sub-sequence, whenever we see a number x greater than 
    // stack.top() we pop all elements less than x and for all the popped ones, their next greater element is x
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n, -1);
        stack<int> stack;
        for(int i=0, j=0; i<2*n-1; i++){
            j = (i<n)?i:i-n;
            while(!stack.empty() && nums[stack.top()]<nums[j]){
                vec[stack.top()] = nums[j];
                stack.pop();
            }
            if(i<n) stack.push(i);
        }
        return vec;
    }
};

int main(){
    vector<int> nums {3,2,8,4,9,1};
    Solution s;
    auto ans = s.nextGreaterElements(nums);

    for(int ele : ans)
        cout << ele << " ";

    cout << endl;
    return 0;
}
