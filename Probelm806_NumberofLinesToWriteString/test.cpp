/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar 25 17:47:00 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int cur_width = 0, lines = 1;
        if(S.empty())
            return {0, 0};
        for(int i = 0; i < S.size(); ++i){
            if(cur_width + widths[S[i] - 'a'] <= 100){
                cur_width += widths[S[i] - 'a'];
                continue;
            }
            else{
                lines++;
                cur_width = widths[S[i] - 'a'];
            }
        }

        return {lines, cur_width};
    }
};

int main(){
    Solution s;
    vector<int> widths{4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};

    auto ans = s. numberOfLines(widths, "bbbcccdddaaa");

    for(auto a : ans)
        cout << a << endl;
    return 0;
}
