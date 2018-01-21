/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 21 16:47:33 2018
 ************************************************************************/

#include<iostream>
#include<deque>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> buffer;
        vector<int> res;

        for(auto i=0; i<nums.size();++i)
        {
            while(!buffer.empty() && nums[i]>=nums[buffer.back()]) buffer.pop_back();



            buffer.push_back(i);

            if(i>=k-1) res.push_back(nums[buffer.front()]);
            
            cout << "i == " << i << ": ";
            for(auto ele : buffer)
                cout << ele << " ";
            cout << endl;


            if(buffer.front()<= i-k + 1) buffer.pop_front();


        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums {1,3,-1,-3, 5,3,6,7};
    auto ans = s.maxSlidingWindow(nums, 3);

    for(int i =0; i < ans.size(); ++i)
        cout << ans[i] << " ";

    return 0;
}
