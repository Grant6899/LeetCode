/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Apr 11 21:12:03 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        // sign of the result
		if (numerator < 0 ^ denominator < 0) res += '-';

		// take abs of numerator and denominator
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;

		// take integral part of the result
        long integral = numer / denom;
        res += to_string(integral);

		// take remainder after division
        long rmd = numer % denom;
        if (!rmd) return res;
        res += '.';
        rmd *= 10;
        unordered_map<long, long> mp;
        while (rmd) {
            long quotient = rmd / denom;
            if (mp.find(rmd) != mp.end()) {
                res.insert(mp[rmd], 1, '(');
                res += ')';
                break;
            }
            mp[rmd] = res.size();
            res += to_string(quotient);
            rmd = (rmd % denom) * 10;
        }
        return res;
    }
};

int main(){
    Solution s;

    cout << s. fractionToDecimal(5, 3) << endl;
    return 0;
}
