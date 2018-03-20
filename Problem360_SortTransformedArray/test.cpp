/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Mar 17 20:36:10 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		vector<int> res;

		if(a == 0){
			for(int n : nums)
				res.push_back(n * b + c);

			if(b < 0)
				reverse(res.begin(), res.end());
			return res;
		}


		double pivot = -b  / (2.0 * a);
        //cout << "pivot: " << pivot << endl;
		int l = 0, r = nums.size() - 1;
		while(l <= r){
            //cout << nums[l] << " " << nums[r] << " " << fabs(nums[l] - pivot) << " " << fabs(nums[r] - pivot) << endl;
			if(fabs(nums[l] - pivot) > fabs(nums[r] - pivot)){
				res.push_back(func(a, b, c, nums[l]));
				//cout << "select " << nums[l] << endl;
                l++;
			}
			else{
				res.push_back(func(a, b, c, nums[r]));
                //cout << "select " << nums[r] << endl;
                r--;
			}
		}

		if(a > 0) reverse(res.begin(), res.end());
		return res;
    }

	int func(int a, int b, int c, int x){
		return a * x * x + b * x + c;
	}
};

int main(){
    vector<int> nums{-4, -2, 2, 4};
    Solution s;
    auto ans = s. sortTransformedArray(nums, 1, 3, 5);
    for(int a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}
