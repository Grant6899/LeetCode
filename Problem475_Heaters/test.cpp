/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Mar  2 19:22:31 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:

    int findRadius(vector<int>& A, vector<int>& H) {
        sort(A.begin(), A.end());
        sort(H.begin(), H.end());
        vector<int> res(A.size(), INT_MAX);

        // For each house, calculate distance to nearest RHS heater
        for (int i = 0, h = 0; i < A.size() && h < H.size(); ) {
            if (A[i] <= H[h]) { res[i] = H[h] - A[i]; i++; }
            else { h++; }
        }

        // For each house, calculate distance to nearest LHS heater
        for (int i = A.size()-1, h = H.size()-1; i >= 0 && h >= 0; ) {
            if (A[i] >= H[h]) { res[i] = min(res[i], A[i] - H[h]); i--; }
            else { h--; }
        }

        return *max_element(res.begin(), res.end());
    }
};



int main(){
    vector<int> houses{1,2,3,4}, heaters{1,4};

    Solution s;
    cout << s.findRadius(houses, heaters) << endl;

    return 0;
}
