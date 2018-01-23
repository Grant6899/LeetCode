/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 22 22:08:56 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int ii, int jj) {
        if(N <= 0)
            return 0;
        vector<vector<long int>> prev(m, vector<long int>(n, 0)), current(m, vector<long int>(n, 0));
        
        long long res = 0;

        for(int i = 0; i < m; ++i){
            prev[i][0]++;
            prev[i][n-1]++;
        }

        for(int j = 0; j < n; ++j){
            prev[0][j]++;
            prev[m-1][j]++;
        }
        
        res += prev[ii][jj];

        for(int k = 2; k <= N; k++){

           for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                current[i][j] = checkMethods(i-1, j, m, n, prev) + checkMethods(i+1, j, m, n, prev) + checkMethods(i, j-1, m, n, prev) + checkMethods(i, j+1, m, n, prev);              
                current[i][j] %= 1000000007;
                if(i == ii && j == jj){
                    res += current[i][j];
                    res %= 1000000007;
                }
            }
            prev = current;
        }
        return res;
    }
    
    long long checkMethods(int i, int j, int m, int n, vector<vector<long int>>& methods){
        if(i >= 0 && i < m && j >= 0 && j < n)
            return methods[i][j];
        else 
            return 0;
    }

};

int main(){
    Solution s;

    cout << s.findPaths(1,3,3,0,1) << endl;
    return 0;
}
