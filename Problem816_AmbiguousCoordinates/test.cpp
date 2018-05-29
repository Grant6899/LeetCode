/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:27:51 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;

        string str = S.substr(1, S.size() - 2);

        for(int zero_pos = 0; zero_pos < str.size() - 1; ++zero_pos){
            string s1 = str.substr(0, zero_pos + 1), s2 = str.substr(zero_pos + 1);
            /*cout << s1 << endl;
            cout << s2 << endl;
            cout << endl;*/
            for(string left : ValidNums(s1))
                for(string right : ValidNums(s2))
                    res.push_back("(" + left + ", " + right + ")");
        }
        return res;
    }


    vector<string> ValidNums(string& str){
        vector<string> res;
        for(int c_pos = 0; c_pos < str.size() - 1; ++c_pos){
            string s1 = str.substr(0, c_pos + 1), s2 = str.substr(c_pos + 1);
            if(s1[0] == '0' && s1.size() > 1)
                continue;
            if(s2.back() == '0' && s2.size() > 1 || s2 == "0")
                continue;

            if(s1 == "0" && s2 == "0")
                continue;

            res.push_back(s1 + "." + s2);
        }

        if(!(str[0] == '0' && str.size() > 1))
            res.push_back(str);

        return res;
    }


};

int main(){
    Solution s;
    auto ans = s.ambiguousCoordinates("(123)");
    for(auto a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}
