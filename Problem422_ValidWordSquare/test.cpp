/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  8 18:31:56 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i)
			for(int j = 0; j < words[i].size(); ++j){
				if(j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i]){
                    //cout << i << " " << j << endl;
					return false;
                }
			}
		return true;
    }
};

int main(){
    Solution s;
    
    vector<string> words{  "ball","area","read","lady"};

    cout << s.validWordSquare(words) << endl;
    return 0;
}

