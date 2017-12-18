/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 17 19:59:37 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        for(auto it = nums.begin(); it < nums.end(); ++it){
            if(*it == 0)
                ++num0;
            else if(*it == 1)
                ++num1;
            else
                ++num2;
        }
        vector<int> temp(num0, 0);
        for(int i = 0; i < num1; ++i)
            temp.push_back(1);
        for(int i = 0; i < num2; ++i)
            temp.push_back(2);
        nums = temp;
    }
};

int main(){
    vector<int> nums {0, 0, 1, 2, 2, 0 , 2, 1, 2,1};
    Solution s;
    s.sortColors(nums);
    for(auto it = nums.begin(); it < nums.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
