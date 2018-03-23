/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 22 19:33:15 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);

		for(int i = 1; i < flowerbed.size()-1; ++i){
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0){
                --n;
                ++i;
            }
            if(n <= 0) return true;
        }

        return false;
    }
};

int main(){
    Solution s;
    vector<int> f{1,0,0,0,1};
    cout << s. canPlaceFlowers(f, 2) << endl;
    return 0;
}
