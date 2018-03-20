/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Mar 17 20:38:40 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
		vector<int> count(nums.size() + 1, 0);
		vector<int> res{0 , 0};
		for(int i = 0; i < nums.size(); ++i){
            count[nums[i]]++;
		}

        for(int i = 1; i <= nums.size(); ++i){
            if(count[i] == 0) res[1] = i;
            if(count[i] == 2) res[0] = i;
        }


		return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,2,2,4};
    auto ans = s. findErrorNums(nums);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
