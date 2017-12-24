/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 23 19:47:14 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
		std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
		std::vector<int> vec;
		subsetsWithDup(res, nums, vec, 0);
		return res;
    }
private:
	void subsetsWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) { 
				vec.push_back(nums[i]);
				subsetsWithDup(res, nums, vec, i + 1);
				vec.pop_back();
			}
	}
};

int main(){
    Solution s;
    vector<int> vec {1, 2, 2};
    auto ans = s.subsetsWithDup(vec);

    for(int i = 0; i < ans.size();++i){
        for(int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << ",";
        cout << endl;
    }

    return 0;
}
