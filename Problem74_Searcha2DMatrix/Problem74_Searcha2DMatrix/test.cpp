#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m*n - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int e = matrix[mid/n][mid%n];
            if(target < e){
                end = mid - 1;
            }
            else if(target > e){
                start = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main() {

	Solution s;

	vector<vector<int>> mat{
			{1, 3, 5, 7},
			{10, 11, 16, 20},
			{23, 30, 34, 50}
	};

	std::cout << std::boolalpha<< s.searchMatrix(mat, 20) << std::endl;

	return 0;

}
