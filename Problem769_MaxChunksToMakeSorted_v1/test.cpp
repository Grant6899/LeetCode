/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 20 22:06:05 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        vector<vector<bool>> isValid(arr.size(), vector<bool>(arr.size(), true));

        for(int i = 0; i < arr.size(); i++)
            for(int j = i; j < arr.size(); j++){
                for(int k = i; k <= j; k++)
                    if(arr[k] < i || arr[k] > j)
                        isValid[i][j] = false;
            }

        vector<int> dp(arr.size(), 0);


        for(int i = 0; i < arr.size(); ++i)
            for(int j = 0; j <= i; ++j){
                if(j - 1 >= 0 && isValid[j][i])
                    dp[i] = max(dp[i], dp[j-1] + 1);
                else if(j == 0 && isValid[j][i])
                    dp[i] = max(dp[i], 1);
        }

        return dp.back();
    }
};

int main(){
    Solution s;
    vector<int> nums {1, 0, 2, 3, 4};
    cout << s.maxChunksToSorted(nums) << endl;
    return 0;
}
