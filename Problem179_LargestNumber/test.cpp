/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 25 19:33:16 2017
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(auto it = nums.begin(); it < nums.end(); ++it)
            temp.push_back(to_string(*it));

        sort(temp.begin(), 
             temp.end(), 
             [](const string& s1, const string& s2){return s1 + s2 > s2 + s1;}
            );

        string result = "";
        auto it = temp.begin();
        while(*it == "0" && it < temp.end() - 1)
            ++it;
        for(; it < temp.end(); ++it){
            result += (*it);
        }
        return result;
    }
};

int main(){
    vector<int> vec{3, 30, 34, 5, 9};
    Solution s;
    cout << s.largestNumber(vec) << endl;
    return 0;
}
