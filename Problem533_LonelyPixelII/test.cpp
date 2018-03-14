/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 13 20:52:22 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        vector<int> row(picture.size(), 0), col(picture[0].size(), 0);
		
		for(int i = 0; i < picture.size(); ++i)
			for(int j = 0; j < picture[0].size(); ++j){
				if(picture[i][j] == 'B'){
					row[i]++; col[j]++;
				}
			}
			
		vector<string> row_str;
		for(int i = 0; i < picture.size(); ++i){
			string str = "";
			for(int j = 0; j < picture[0].size(); ++j)
				str += picture[i][j];
			row_str.push_back(str);
		}
		
		int res = 0;
		
		for(int i = 0; i < picture.size(); ++i)
			for(int j = 0; j < picture[0].size(); ++j){
				
				if(picture[i][j] == 'B' && row[i] == N && col[j] == N){
					unordered_set<string> pool;
					bool unique = true;
					for(int k = 0; k < picture.size(); ++k){
						if(picture[k][j] == 'B')
							pool.insert(row_str[k]);
						if(pool.size() > 1){
							unique = false;
							break;
						}

					}
					if(unique) res++;
				}
			}
		return res;
    }
};

int main(){
    vector<vector<char>> grid{{'W','B','W','B','B','W'},{'W','B','W','B','B','W'},{'W','B','W','B','B','W'},{'W','W','B','W','B','W'}};
    Solution s;
    cout << s.findBlackPixel(grid, 3) << endl;
    return 0;
}
