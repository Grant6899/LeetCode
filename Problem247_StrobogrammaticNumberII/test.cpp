/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:36:04 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {

        int half = n / 2;

        vector<char> pool{'0', '1', '6', '8', '9'};

        map<char, char> mapping;
        mapping['0'] = '0';
		mapping['1'] = '1';
		mapping['8'] = '8';
		mapping['6'] = '9';
		mapping['9'] = '6';

        vector<vector<char>> sets;
        vector<string> res;

        for(int i = 0; i < half; ++i)
            sets.push_back(pool);

        for(string left : decare(sets)){
            string right = left;
            reverse(right.begin(), right.end());

            if(left[0] == '0')
                continue;

            if(n % 2 == 0)
                res.push_back(left + generateRight(left, mapping));
            else{

                res.push_back(left + '0' + generateRight(left, mapping));
                res.push_back(left + '1' + generateRight(left, mapping));
                res.push_back(left + '8' + generateRight(left, mapping));
            }
        }
        return res;
    }

    string generateRight(string& left, map<char, char>& mapping){
        string res = "";

        for(char ch : left)
            res += mapping[ch];
        reverse(res.begin(), res.end());
        return res;
    }

    vector<string> decare(const vector<vector<char>> & sets){
        vector<string> rs;
        int n = sets.size();
        string tmp;

        for (int i = 0; i < n; ++i)
            tmp.push_back(sets[i][0]);

        rs.push_back(tmp);
        for (int i = n - 1; i >= 0; --i){
            int nRsSize = rs.size();
            for (int k = 1; k < sets[i].size(); ++k){
                for (int j = 0; j < nRsSize; ++j){
                    tmp = rs[j];
                    tmp[i] = sets[i][k];
                    rs.push_back(tmp);
                }
            }
        }
        return rs;
    }
};

int main(){
    Solution s;
    auto ans = s.findStrobogrammatic(2);
    for(string str : ans)
        cout << str << " ";
    cout << endl;
    return 0;
}
