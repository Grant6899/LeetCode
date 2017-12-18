/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 18 00:20:42 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1] == nums2[p2]){
                result.push_back(nums1[p1]);
                while(nums1[p1] == result.back())
                    ++p1;
                while(nums2[p2] == result.back())
                    ++p2;
            }
            else if (nums1[p1] > nums2[p2])
                ++p2;
            else
                ++p1;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> n1{1,2,3,2,1}, n2{1,5,2,1,2,4};
    auto temp = s.intersection(n1, n2);
    for(auto it = temp.begin();it < temp.end();++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}
