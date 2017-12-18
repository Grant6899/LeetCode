/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 17 19:07:48 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            if (numbers[left] + numbers[right] == target){
                vector<int> res{ left + 1, right + 1 };
                return res;
            }
            else if (numbers[left] + numbers[right] < target)
                left++;
            else
                right--;
        }
    }
};

int main(){
    Solution s;
    vector<int> nums {2, 7, 11, 15};
    auto temp = s.twoSum(nums, 9);
    for (auto it = temp.begin(); it < temp.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
