/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 17 20:26:26 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> index(n);
        for (int i = 0; i < n; ++i)
            index[row[i]] = i;
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            // tar is the person should sit at row[i+1]
            int tar = row[i] + (row[i]%2? -1:1);
            if (row[i+1] != tar) {
                for(int j = 0; j < row.size(); ++j)
                    cout << row[j] << " ";
                cout << endl;
                swap(row[i+1], row[index[tar]]);
                // remember update index
                index[row[index[tar]]] = index[tar]; 
                ans++;
            }
        }
         for(int j = 0; j < row.size(); ++j)
                    cout << row[j] << " ";
                cout << endl;
       
        return ans;
    }
};

int main(){
    vector<int> nums {7, 1, 9, 5, 4, 3, 0, 2, 8, 6};
    Solution s;
    cout << s.minSwapsCouples(nums) << endl;
    return 0;
}
