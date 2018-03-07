/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar  7 14:03:46 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        
        for(int i = 0; i < num.size(); ++i){
            string temp = num.substr(0, i + 1);
            if(!(temp[0] == '0' && i > 0)){
                long first_num = stol(temp);
                dfs(num, i + 1, target, temp, first_num, first_num, '#', res);
            }
        }
        return res;
    }
    
    
    void dfs(string num, int pos, int target, string cur_str, long cur_val, long prev_val, char prev_op, vector<string>& res){
        if(cur_val == target && pos == num.size()){
            res.push_back(cur_str);
            return;
        }
        
        for(int i = pos; i < num.size(); ++i){
            if(!(num[pos] == '0' && i > pos)){
                        string temp_str = num.substr(pos, i - pos + 1);
                        long n = stol(temp_str);
                        dfs(num, i + 1, target, cur_str + "+" + temp_str, cur_val + n, n, '+', res);
                        dfs(num, i + 1, target, cur_str + "-" + temp_str, cur_val - n, n, '-', res);
                        dfs(num, i + 1, target, cur_str + "*" + temp_str, 
                            prev_op == '+' ? cur_val - prev_val + prev_val * n  : (prev_op == '-'? cur_val + prev_val - prev_val * n : prev_val * n), prev_val * n, prev_op, res);
            }
        }
    }
};

int main(){
    Solution s;
    auto ans = s.addOperators("1234", 25);
    for(auto a : ans)
        cout << a << endl;
    return 0;
}
