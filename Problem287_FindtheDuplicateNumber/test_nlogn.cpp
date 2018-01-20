/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 10 21:06:22 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int low = 1, high = nums.size() - 1, mid = 0, count = 0;
        
        while(low < high){
            mid = low + (high - low) / 2;
            count = 0;
            for(int ele : nums)
                if(ele <= mid)
                    count++;
            //If the there are more than "mid" numbers that are less than "mid", 
            //then by Pigeonhole Principle, one of them has occurred more than once        
            if(count <= mid)
                low = mid + 1;
            else
                high = mid;
            
        }
    
        return low;
    }
};

int main(){
    vector<int> nums {1,2,3,4,2};

    Solution s;
    cout << s.findDuplicate(nums) << endl;
    return 0;
}
