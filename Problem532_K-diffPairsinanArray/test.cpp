/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Dec 14 19:46:09 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;
    unordered_map<int, int> m;
    for (int n : nums) m[n]++;
    int cnt = 0;
    for (auto p : m) {
      if ((!k && p.second > 1) || (k && m.count(p.first + k))) 
        ++cnt;
    }
    return cnt;
  }
};

int main(){
    vector<int> nums {1, 3, 1, 5, 4, 3};
    Solution s;
    cout << s.findPairs(nums, 2) << endl;
    
    return 0;
}

