/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 18:24:50 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (isOverlap({rec1[0], rec1[2]}, {rec2[0], rec2[2]}) && isOverlap({rec1[1], rec1[3]}, {rec2[1], rec2[3]}))
            return true;

        return false;
    }

    bool isOverlap(pair<int, int> r1, pair<int, int> r2){
        if(r1.first > r2.first)
            swap(r1, r2);

        return (r2.first < r1.second);
    }
};

int main(){
    Solution s;
    vector<int> r1{0,0,2,2}, r2{1,1,3,3};
    cout << s. isRectangleOverlap(r1, r2) << endl;
    return 0;
}
