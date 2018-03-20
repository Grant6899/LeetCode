/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar 19 22:27:13 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> len(nums.size(), 0);
		vector<bool> visited(nums.size(), false);
		int res = 0;
		for(int i = 0; i < nums.size(); ++i){
            unordered_set<int> cur;
			findCycle(nums[i], cur, nums, res, visited);
        }
		
		return res;
    }
	
	void findCycle(int idx, unordered_set<int>& cur, vector<int>& nums, int& max_len, vector<bool>& visited){
		if(cur.count(idx)){
			max_len = max(max_len, (int)cur.size());
			return;
		}
        
        if(visited[idx])
			return;
        visited[idx] = true;		
		cur.insert(idx);
		findCycle(nums[idx], cur, nums, max_len, visited);
		
	}
	
};

int main(){
    Solution s;
    vector<int> nums{5,4,0,3,1,6,2};
    cout << s. arrayNesting(nums) << endl;
    return 0;
}
