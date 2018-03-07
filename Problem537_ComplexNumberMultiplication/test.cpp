/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar  7 15:00:22 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        auto c1 = strtocom(a), c2 = strtocom(b);

        return to_string(c1.first * c2.first - c1.second * c2.second) + "+" + to_string(c1.first * c2.second + c2.first * c1.second) + "i";

    }

    pair<int, int> strtocom(string str){
        auto x = split(str, '+');
        pair<int, int> res;
        res.first = stoi(x[0]);
        res.second = stoi(x[1].substr(0, x[1].size() - 1));
        return res;
    }

    vector<string> split(const string& IP, char delimiter){
		istringstream ss(IP);
		string token;
		vector<string> res;
		while(getline(ss, token, delimiter))
			res.push_back(token);
		return res;
	}
};

int main(){
    Solution s;
    cout << s.complexNumberMultiply("1+2i", "-1+3i") << endl;
    return 0;
}
