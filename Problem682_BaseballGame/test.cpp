/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 25 18:47:49 2018
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
       vector<int> last;

        if(ops.empty())
            return 0;

        for(int i = 0; i < ops.size(); ++i){
            
            if(ops[i] == "C"){
                last.pop_back();
            }
            else if(ops[i] == "D"){
                last.push_back(last.back()*2);
            }
            else if(ops[i] == "+"){
                last.push_back(last.back() + last[last.size()-2]);
            }
            else{
                last.push_back(stoi(ops[i]));
            }
        }

        int res = 0;
        
        for(int ele : last)
            res += ele;
        return res;
    }
};

int main(){
    Solution s;

    vector<string> ops {"5","-2","4","C","D","9","+","+"};

    cout << s.calPoints(ops) << endl;

    return 0;
}
