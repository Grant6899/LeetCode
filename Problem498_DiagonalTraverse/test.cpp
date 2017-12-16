/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 16 14:58:00 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty())
            return result;

        bool direction = 1;

        for (int sum = 0; sum < matrix.size() + matrix[0].size() - 1; ++sum ){
            if(direction){
                for (int i = min(sum, (int)matrix.size()-1); i >= max(sum - (int)matrix[0].size() + 1, 0); --i)
                        result.push_back(matrix[i][sum-i]);
                direction = false;
            }
            else{
                for (int i = max(sum - (int)matrix[0].size() + 1, 0); i <= min(sum, (int)matrix.size()-1); ++i)
                    if(i < matrix.size() && sum - i < matrix[0].size())
                        result.push_back(matrix[i][sum-i]);
                direction = true;
            }
        }

        return result;
    }
};

int main(){
    
    vector<vector<int>> mat {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution s;
    auto temp = s.findDiagonalOrder(mat);

    for(auto it = temp.begin(); it < temp.end(); ++it)
        cout << *it << " ";

    cout << endl;
    return 0;
}
