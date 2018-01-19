/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 18 21:12:45 2018
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dic;
        for(auto ele : nums)
            dic[ele]++;

        vector<pair<int,int>> seq;
        for(auto ele : dic)
            seq.push_back(make_pair(ele.first, ele.second));

        nth_element(seq.begin(), seq.begin() + k, seq.end(), [](pair<int,int>& a, pair<int, int>& b){return a.second > b.second;});

        partial_sort(seq.begin(), seq.begin() + k, seq.end(), [](pair<int,int>& a, pair<int, int>& b){return a.second > b.second;});

        vector<int> res;
        for(int i = 0;i < k; i++)
            res.push_back(seq[i].first);
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums {1,1,1,2,2,3};

    auto ans = s.topKFrequent(nums, 2);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";

    return 0;
}

