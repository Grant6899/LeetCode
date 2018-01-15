/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 14 21:02:13 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string digit2hex(int num){
        vector<string> dvec = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        return dvec[num % 16];
    }
    string toHex(int snum) {
        if(snum == INT_MIN) return "80000000";
        else if(snum == 0) return "0";
        string ostr = "";
        unsigned int num = (unsigned int) snum;
        //cout << std::bitset<32>(num) << endl;
        int mask = 15;
        int i = 0;
        while(i<= 7 && (((~0)<<4*i) & num)!=0 ){
            //cout << ((mask & num) >> 4*i);
            ostr = digit2hex((mask & num) >> 4*i)+ostr;
            mask = mask << 4;
            i++;
}
        return ostr;
    }
};

int main(){
    
    Solution s;
    cout << s.toHex(26) << endl;
    return 0;    
}
