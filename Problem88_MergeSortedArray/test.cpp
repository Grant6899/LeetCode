/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 17 21:07:32 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i1 = 0, i2 = 0;
        while(i1 < m || i2 < n){
            if(i1 == m){
                while(i2 < n){
                    result.push_back(nums2[i2]);
                    ++i2;
                }
                nums1 = result;
                return;
            }

            if(i2 == n){
                while(i1 < m){
                    result.push_back(nums1[i1]);
                    ++i1;
                }
                nums1 = result;
                return;
            }

            if(nums1[i1] < nums2[i2]){
                result.push_back(nums1[i1]);
                ++i1;
            }
            else{
                result.push_back(nums2[i2]);
                ++i2;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> v1{3,6,7,9}, v2{4,5,8};
    s.merge(v1, 4, v2, 3);
    for(auto it = v1.begin(); it < v1.end(); ++it)
        cout<<*it<<" ";
    cout << endl << v1.size() << endl;
    return 0;
}
