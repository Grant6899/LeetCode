/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan  9 20:32:05 2018
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int slow = 0, fast = 0;
        
        while(fast < nums.size()){
            
            while(nums[slow] != 0)
                slow++;
            
            while(nums[fast] == 0 || fast < slow)
                fast++;
            
            if(slow < nums.size() && fast < nums.size() && nums[slow] == 0 && nums[fast] != 0)
                swap(nums[slow], nums[fast]);
            
            slow++;
            fast++;
        }
    }
};

int main(){
    vector<int> v {2, 1};
    Solution s;
    s.moveZeroes(v);

    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    return 0;
}
