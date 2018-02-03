/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Feb  3 13:42:07 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> map;

        for(int candy : candies)
            map[candy]++;
        
        int res = 0;

        for(auto ele : map){
            res++;
            if(res == candies.size() / 2)
                return res;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> c {1,1,2,2,3,3};
    cout << s.distributeCandies(c) << endl;
    return 0 ;
}
