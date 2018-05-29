/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:07:30 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

class Solution {
public:
    string maskPII(string S) {
        string res = maskEmailaddress(S);
        if(!res.empty())
            return res;
        return processNumber(S);
    }

    string processNumber(string& S){
        int cnt = 0;
        for(char ch : S)
            if(isdigit(ch))
                cnt++;

        string res = "";
        if(cnt == 10){
            for(char ch : S){
                if(isdigit(ch))
                    res += (res.size() <= 7 ? '*' : ch);
                if(res.size() == 3 || res.size() ==7)
                    res += '-';
            }
        }
        else{
            res += "+";
            for(char ch : S){
                if(isdigit(ch))
                    res += (res.size() <=  cnt - 1? '*' : ch);
                if(res.size() == cnt - 9 || res.size() == cnt - 5 || res.size() == cnt - 1)
                    res += '-';
            }
        }
        return res;
    }


    bool isName(string& s){
        if(s.size() < 2)
            return false;
        for(char ch : s)
            if(!('a' <= ch && ch <= 'z') && !('A' <= ch && ch <= 'Z'))
                return false;
        return true;
    }

    string maskEmailaddress(string& s){
        string res = "";

        auto temp = split(s, '@');
        if(temp.size() != 2)
            return res;

        auto temp1 = split(temp[1], '.');
        if(temp1.size() != 2)
            return res;

        if(isName(temp[0]) && isName(temp1[0]) && isName(temp1[1])){
            res = maskfirstName(temp[0]) + "@" + maskName(temp1[0]) + '.' + maskName(temp1[1]);
            return res;
        }

        return res;
    }

    string maskfirstName(string s){
        return (char)tolower(s[0]) + string(5, '*') + (char)tolower(s[s.size() - 1]);
    }

    string maskName(string s){
        string res = "";
        for(char ch : s)
            res += (char)tolower(ch);
        return res;
    }

    vector<string> split(string s, char delimiter){
		istringstream ss(s);
		string token;
		vector<string> res;
		while(getline(ss, token, delimiter))
			res.push_back(token);
		return res;
	}

};

int main(){
    Solution s;
    cout << s.maskPII("LeetCode@LeetCode.com") << endl;
    return 0;
}
