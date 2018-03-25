/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar 25 17:33:20 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> neglen(nums.size(), 1), poslen(nums.size(), 1);

		neglen[0] = 1;
		poslen[0] = 1;

		for(int i = 1; i < nums.size();++i)
			for(int j = 0; j < i; ++j){
				if(nums[j] < nums[i])
					poslen[i] = max(neglen[j] + 1, poslen[i]);
				if(nums[j] > nums[i])
					neglen[i] = max(poslen[j] + 1, neglen[i]);
			}

        /*for(int p : poslen)
            cout << p << " ";
        cout << endl;

        for(int p : neglen)
            cout << p << " ";*/

		return max(poslen.back(), neglen.back());
    }
};

int main(){
    Solution s;
    vector<int>nums{1,17,5,10,13,15,10,5,16,8};
    cout << s. wiggleMaxLength(nums) << endl;
    return 0;
}
