/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 26 22:38:17 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        vector<vector<int>> left(matrix.size(), vector<int>(matrix[0].size(), 0)), right(matrix.size(), vector<int>(matrix[0].size(), matrix[0].size())), height(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i){
            
            int cur_left = 0, cur_right = matrix[0].size();
            
            for(int j = 0; j < matrix[0].size();++j)
                if(matrix[i][j] == '1'){
                    left[i][j] = max((int)(i - 1 >= 0 ?left[i-1][j] : 0), cur_left);
                }
                else{
                    left[i][j] = 0;
                    cur_left = j + 1;
                }
                
            for(int j = matrix[0].size() - 1; j >= 0;--j)               
                if(matrix[i][j] == '1'){
                    right[i][j] = min((int)(i - 1 >= 0? right[i-1][j] : matrix[0].size()), cur_right);
                }
                else{
                    right[i][j] = matrix[0].size();
                    cur_right = j;
                }
            

            for(int j = 0; j < matrix[0].size();++j)
                if(matrix[i][j] == '1'){
                    height[i][j] = (i - 1 >= 0? height[i-1][j] : 0) + 1;            
                    res = max(res, (right[i][j] - left[i][j]) * height[i][j]);
                }
        }
     /*   
        
        for(auto l : left){
            for(int x : l)
                cout << x << ' ';
            cout << endl;
        }
        cout << endl;
        for(auto r : right){
            for(int x : r)
                cout << x << ' ';
            cout << endl;
        }
        cout << endl;
        for(auto h : height){
            for(int x : h)
                cout << x << ' ';
            cout << endl;
        }*/
        
        return res;
    }
};

int main(){

    Solution s;

    vector<vector<char>> mat{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    
    cout << s.maximalRectangle(mat) << endl;

    return 0;
}
