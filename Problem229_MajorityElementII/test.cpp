/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 16 16:57:26 2017
 ************************************************************************/

#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for (i)
    }
};

int main(){
    Solution s;
    vector<int> nums {1, 2, 3, 3, 3, 3};
    auto temp = s.majorityElement(nums);

    for(auto it = temp.begin();it<temp.end();++it)
        cout<<*it << " ";

    return 0;
}
