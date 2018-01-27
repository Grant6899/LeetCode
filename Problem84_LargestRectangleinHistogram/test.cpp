/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 26 23:15:09 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
            return 0;
        
        vector<int> left(heights.size(), 0), right(heights.size(), 0);

        left[0] = 0;
        for(int i = 1; i < heights.size(); ++i){
            int temp_left = i - 1;

            while(temp_left >= 0 && heights[temp_left] >= heights[i])
                temp_left = left[temp_left] - 1;
    
            left[i] = ++temp_left;
        }

        right[heights.size()-1] = heights.size() - 1;
        for(int i = heights.size()-2; i >= 0; --i){
            int temp_right = i + 1;

            while(temp_right <= heights.size() - 1 && heights[temp_right] >= heights[i])
                temp_right = right[temp_right] + 1;
    
            right[i] = --temp_right;
        }

        int res = 0;
        for(int i = 0; i < heights.size(); ++i){
            res = max(res, (right[i] - left[i] + 1)*heights[i]);
        }
        return res;

    }
};

int main(){
    Solution s;
    vector<int> h {2,1,5,6,2,3};
    cout << s.largestRectangleArea(h) << endl;
    return 0;
}
