/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:28:02 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
	    int m = matrix.size();
	    if(m == 0) return false;
	    int n = matrix[0].size();
	    if(n == 0) return false;

	    int i = m - 1, j = 0;

	    while(i >= 0 && j < n){
		    if(matrix[i][j] == target)
			    return true;

		    if(matrix[i][j] > target)
			    i--;
		    else
			    j++;
	    }
	    return false;
    }

};

int main(){
    Solution s;
    vector<vector<int>> nums{
  {1,   4,  7, 11, 15},
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}
};
	cout << s.searchMatrix(nums, 5) << endl;
    return 0;
}
