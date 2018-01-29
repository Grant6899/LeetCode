/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 28 15:16:10 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000")
            return 0;

        unordered_set<string> visited;

        vector<string> prev{"0000"};

        for(string str : deadends)
            visited.insert(str);
        visited.insert("0000");

        bool find = false;
        int step = 0;
        while(!prev.empty() && !find){
            vector<string> current;
            step++;
            for(string code : prev){
                
                for(int i = 0; i < 4; ++i)
                for(int j = -1; j <= 1; j+=2){
                    string new_code = switchLock(code, i , j);
                      
                    if(new_code == target)
                        return step;
        
                    if(!visited.count(new_code)){
                        current.push_back(new_code);
                        visited.insert(new_code);
                    }
                }
            }
            prev = current;
        }
        return -1;
    }

    string switchLock(string code, int i , int j){
        string res = code;
        
        if(res[i] == '0' && j == -1)
            res[i] = '9';
        else if(res[i] == '9' && j == 1)
            res[i] = '0';
        else
            res[i] += j;
        return res;
    }

};

int main(){
    vector<string> deadends {"0201","0101","0102","1212","2002"};
    string target = "0202";

    Solution s;

    cout << s.openLock(deadends, target) << endl;
    
    return 0;
}
