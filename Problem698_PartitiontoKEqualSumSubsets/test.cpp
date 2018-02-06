/**************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Feb  6 18:28:57 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
		for(int num : nums)
			sum += num;
		
		if(sum % k)
			return false;
		
		vector<vector<int>> current;
		int target = sum / k;
		
		sort(nums.begin(), nums.end(), greater<int>());
        
        for(int num : nums)
            if(num > target)
                return false;
        
		vector<bool> used(nums.size(), false);
		
		int backsum = 0;
		return dfs(current, used, target, k, nums, backsum, true);
				
    }
	
	bool dfs(vector<vector<int>>& current, vector<bool>& used, int target, int k, vector<int>& nums, int& backsum, bool nextSet){
		
        /*cout << "current size: " << current.size() << endl;
        for(auto x : current){
            for(auto y : x)
                cout << y << " ";
            cout << endl;
        }
        cout << "backsum: " << backsum << endl << endl;*/
        
        if(current.size() == k && backsum == target){
		    //cout << "inside true" << endl;
            return true;
        }
		
		if(nextSet){
			current.push_back({});
            backsum = 0;
			if(dfs(current, used, target, k, nums, backsum, false))
                return true;
            backsum = target;
			current.pop_back();
		}
		else{
			for(int i = 0; i < nums.size(); ++i){
				if(!used[i] && backsum + nums[i] <= target){
					
					current.back().push_back(nums[i]);
					backsum += nums[i];
					used[i] = true;
					if(backsum == target && dfs(current, used, target, k, nums, backsum, true)){
                        //cout << "true 1" << endl;
						return true;
                    }
					else if(backsum < target && dfs(current, used, target, k, nums, backsum, false)){
                        //cout << "true 2" << endl;;
						return true;
                    }
					used[i] = false;
					backsum -= nums[i];
					current.back().pop_back();
				}
			}			
		}
		return false;
	}
};

int main(){
    Solution s;
    vector<int> nums {85,35,40,64,86,45,63,16,5364,110,5653,97,95};
    cout << s.canPartitionKSubsets(nums, 7) << endl;
    return 0;
}
