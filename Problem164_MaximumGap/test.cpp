/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Mar  2 19:39:22 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {

		int n = nums.size();
		if(n < 2)
			return 0;

		auto minmax = minmax_element(nums.begin(), nums.end());
		int low = *minmax.first, high = *minmax.second;
		int leap = max((high - low) / (n - 1), 1);

        if(leap == 0)
			return 0;

		int m = (high - low) / leap + 1;
		vector<int> maxs(m, INT_MIN), mins(m, INT_MAX);

		for(int n : nums){
			int index = (n - low) / leap;
			maxs[index] = max(maxs[index], n);
			mins[index] = min(mins[index], n);
		}

		int res = 0;

		int last = 0;
		for(int i = 1; i < m; ++i){
            if(maxs[i] == INT_MIN) continue;
			res = max(res, mins[i] - maxs[last]);
			last = i;
        }
        return res;
    }
};

int main(){
    vector<int> nums{7,4,2,1,5};
    Solution s;
    cout << s.maximumGap(nums) << endl;
    return 0;
}
