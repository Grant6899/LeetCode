/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 25 20:15:53 2018
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); ++i){
            if(temp.empty() || temperatures[temp.top()] >= temperatures[i])
                temp.push(i);
            else{
                while(!temp.empty() && temperatures[temp.top()] < temperatures[i]){ 
                    res[temp.top()] = i - temp.top();
                    temp.pop();
                }
                temp.push(i);
            }
        }
        return res;
    }
};

int main(){

    vector<int> temp {73, 74, 75, 71, 69, 72, 76, 73};

    Solution s;

    auto ans = s.dailyTemperatures(temp);

    for(int ele : ans)
        cout << ele << " ";
    cout << endl;
    return 0;
}
