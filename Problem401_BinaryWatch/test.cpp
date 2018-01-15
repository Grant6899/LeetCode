/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 15 16:06:58 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        dic = vector<vector<int>>(11, vector<int>());
        prepare();
        for(int i = 0; i <= num; ++i){
            int j = num - i;
            
            for(int ihr = 0; ihr < dic[i].size(); ++ihr)
            for(int imin = 0; imin < dic[j].size(); ++imin){
                if(dic[i][ihr] < 12){
                    string str = to_display(dic[i][ihr], dic[j][imin]);
                    res.push_back(str);
                }
            }
        }
        return res;
    }

    string to_display(int hour, int minute){
        string res;
        res = to_string(hour) + ":";
        
        if(minute < 10)
            res += "0" + to_string(minute);
        else
            res += to_string(minute);
        return res;
    }

    void prepare(){
        for(int i = 0; i <= 59; i++){
            dic[countBits(i)].push_back(i);
        }
    }

    int countBits(int n){
        n = ((n & 0xAAAAAAAA) >> 1) + (n & 0x55555555);  
        n = ((n & 0xCCCCCCCC) >> 2) + (n & 0x33333333);  
        n = ((n & 0xF0F0F0F0) >> 4) + (n & 0x0F0F0F0F);  
        n = ((n & 0xFF00FF00) >> 8) + (n & 0x00FF00FF);
        n = ((n & 0xFFFF0000) >> 16) + (n & 0x0000FFFF);
        return n;
    }

private:
    vector<vector<int>> dic;

};

int main(){
    Solution s;
    auto ans = s.readBinaryWatch(11);

    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";

    cout << endl;
    return 0;
}
