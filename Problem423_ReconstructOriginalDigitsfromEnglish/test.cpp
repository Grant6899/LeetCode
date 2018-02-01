/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 31 19:32:49 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> map(26, 0);
        //s = "zeroonetwothreefourfivesixseveneightnine";

        for(char ch : s)
            map[ch-'a']++;
        
        vector<int> count(10, 0);

        count[0] = map['z'-'a'];
        erase(map, "zero", count[0]);
        count[2] = map['w'-'a'];
        erase(map, "two", count[2]);
        count[4] = map['u'-'a'];
        erase(map, "four", count[4]);
        count[6] = map['x'-'a'];
        erase(map, "six", count[6]);
        count[8] = map['g'-'a'];
        erase(map, "eight", count[8]);

        count[3] = map['h'-'a'];
        erase(map, "three", count[3]);
        count[5] = map['f'-'a'];
        erase(map, "five", count[5]);
        count[7] = map['s'-'a'];
        erase(map, "seven", count[7]);

        count[9] = map['i'-'a'];
        erase(map, "nine", count[9]);

        count[1] = map['o'-'a'];
        erase(map, "one", count[1]);

        string res = "";


        for(int i = 0; i < count.size(); ++i){
            string temp(count[i], char('0' + i));
            res += temp;
        }

        return res;
    }


    void erase(vector<int>& map, string num, int n){
        for(char ch : num)
            map[ch-'a'] -= n;
    }
};

int main(){
    Solution s;
    cout << s.originalDigits("onetwothree") << endl;
    return 0;
}
