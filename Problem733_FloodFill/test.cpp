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
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || image[0].empty())
            return image;
        
        fill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

private:
    void fill(vector<vector<int>>& map, int i, int j, int newColor, int oldColor){
        if(oldColor != newColor && i >=0 && i < map.size() && j >= 0 && j < map[0].size() && map[i][j] == oldColor){
            map[i][j] = newColor;
            fill(map, i-1, j, newColor, oldColor);
            fill(map, i+1, j, newColor, oldColor); 
            fill(map, i, j-1, newColor, oldColor); 
            fill(map, i, j+1, newColor, oldColor);
        }
        return;
    }
};

int main(){
    vector<vector<int>> map { {0, 0, 0},
                              {0, 1, 1}};
    
    Solution s;

    s.floodFill(map, 1, 1, 1);

    for(int i = 0;i < map.size();++i){
        for(int j = 0; j < map[0].size(); ++j)
            cout << map[i][j] << " ";
        cout << endl;
    }

    return 0;

}





