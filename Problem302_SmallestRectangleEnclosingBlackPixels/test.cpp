/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 15 21:39:43 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        int left = INT_MAX, up = INT_MAX, right = -1, down = -1;

        dfs(x, y, image, visited, left, right, up, down);
        //cout << left << " " << right << " " << up << " " << down << endl;
        return ((right - left + 1) * (down - up + 1));
    }

    void dfs(int i, int j, vector<vector<char>>& image, vector<vector<bool>>& visited, int& left, int& right, int& up, int& down){
        if(i >= 0 && i < image.size() && j >= 0 && j < image[0].size() && !visited[i][j] && image[i][j] == '1'){
            left = min(left, j);
            right = max(right, j);
            up = min(up, i);
            down = max(down, i);
            visited[i][j] = true;

            for(int k = 0; k < 4; ++k)
                dfs(i + delta[k][0], j + delta[k][1], image, visited, left, right, up, down);
        }
    }

private:
    vector<vector<int>> delta{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};

int main(){
    Solution s;
    vector<vector<char>> image{{'0', '1'}, {'1', '0'}};
    cout << s.minArea(image, 0, 1) << endl;
    return 0;
}
