/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  8 18:27:35 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty())
            return 0;
        int res = 0;
        for(int i = 0; i < timeSeries.size() - 1; ++i){
            res += min(timeSeries[i+1] - timeSeries[i], duration);
        }
        res += duration;
        return res;
    }
};

int main(){
    vector<int> ts{1,2};
    Solution s;
    cout << s.findPoisonedDuration(ts, 2) << endl;
    return 0;
}
