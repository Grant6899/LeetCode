/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:18:48 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;

        for(int i = 0; i < input.size(); ++i)
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){

                //cout << input.substr(0, i) << endl;
                //cout << input.substr(i + 1) << endl;
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));

                for(int a : left)
                    for(int b : right){
                        if(input[i] == '+')
                            res.push_back(a + b);
                        else if(input[i] == '-')
                            res.push_back(a - b);
                        else
                            res.push_back(a * b);
                    }
            }

        if(res.empty())
            res.push_back(stoi(input));

        return res;
    }


};

int main(){
    Solution s;
    vector<int> ans = s. diffWaysToCompute("2-1-1");
    for(int i : ans)
        cout << i << ' ';
    cout << endl;
    return 0;
}
