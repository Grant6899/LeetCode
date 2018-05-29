/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:09:02 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
		vector<int> maxes(3, INT_MIN), mins(2, INT_MAX);
		
		
		for(int n : nums){
			if(n >  maxes[0]){
				maxes[2] = maxes[1];
				maxes[1] = maxes[0];
				maxes[0] = n;
			}
			else if(n > maxes[1]){
				maxes[2] = maxes[1];
				maxes[1] = n;
			}
			else if(n > maxes[2]){
				maxes[2] = n;
			}
			
			if(n < mins[0]){
				mins[1] = mins[0];
				mins[0] = n;
			}
			else if(n < mins[1]){
				mins[1] = n;
			}

		}        
		return max(maxes[0] * maxes[1] * maxes[2], maxes[0] * mins[0] * mins[1]);
    }
};

int main(){
    Solution s;
    vector<int> nums{1,2,3,4};
    cout << s.maximumProduct(nums) << endl;
    return 0;
}

