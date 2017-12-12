/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Dec  7 14:42:46 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<bool>> visited;

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || image[0].empty())
            return image;

        visited = vector<vector<bool>>(image.size(), vector<bool>(image[0].size(), false));


    }

    void ()
};

int main{
    vector<vector<int>> map { {1, 1, 1},
                              {1, 1, 0},
                              {1, 0, 1}};
    


}
