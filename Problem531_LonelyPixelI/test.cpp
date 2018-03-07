/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar  7 16:21:36 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<int> row(picture.size(), 0), col(picture[0].size(), 0);

        for(int i = 0; i < picture.size(); ++i)
            for(int j = 0; j < picture[0].size(); ++j){
                if(picture[i][j] == 'B'){
                    row[i]++; col[j]++;
                }
            }

        int res = 0;
        for(int i = 0; i < picture.size(); ++i)
        for(int j = 0; j < picture[0].size(); ++j)
            if(picture[i][j] == 'B' && row[i] == 1 && col[j] == 1)
                res++;

        return res;
    }
};

int main(){
    vector<vector<char>> pic{{'B','W','W'}, {'W','B','B'}};
    Solution s;
    cout << s.findLonelyPixel(pic) << endl;
    return 0;
}
