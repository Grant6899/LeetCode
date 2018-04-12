/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Apr 11 21:02:04 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool splitArray(vector<int>& nums) {
		vector<int> sums(nums.size() + 1, 0);

        for(int i = 1; i < sums.size(); ++i)
			sums[i] += sums[i-1] + nums[i-1];
		bool res = dfs(nums, sums, -1, 3, 0);

        return res;
    }

	bool dfs(vector<int>& nums, vector<int>& sums, int last, int split_needed, int share){
        //cout << "last: " << last << " split_needed: " << split_needed << endl;
		if(last != -1 && split_needed == 0)
            if(sum(last + 1, nums.size() - 1, sums) == share)
			    return true;
            else
                return false;

		if(last == -1){
			for(int i = last + 1; i < (int)sums.size() - split_needed * 2; ++i)
				if(dfs(nums, sums, i + 1, split_needed-1, sum(last + 1, i, sums)))
					return true;
		}
		else{
			for(int i = last + 1; i < (int)sums.size() - split_needed * 2; ++i)
				if(sum(last + 1, i, sums) == share && dfs(nums, sums, i + 1, split_needed-1, share))
					return true;
		}

		return false;
	}

	int sum(int left, int right, vector<int>& sums){
		return sums[right + 1] - sums[left];
	}
};

int main(){
    vector<int> nums{1,2,1,2,1,2,1};
    Solution s;
    cout << s. splitArray(nums) << endl;
    return 0;
}
