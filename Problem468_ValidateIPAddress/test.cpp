/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Feb  3 12:51:46 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>
using namespace std;


class Solution {
public:
    string validIPAddress(string IP) {
		vector<string> tokens1 = split(IP, '.');
		vector<string> tokens2 = split(IP, ':');

        //cout << tokens1.size() << endl;
        //cout << tokens2.size() << endl;

		if(tokens1.size() == 4 && count(IP.begin(), IP.end(), '.') == 3){
			for(string token : tokens1)
				if(!isValidIP4(token)){
					//cout << token << endl;
					return "Neither";
				}

			return "IPv4";
		}

		if(tokens2.size() == 8 && count(IP.begin(), IP.end(), ':') == 7){
			for(string token : tokens2)
				if(!isValidIP6(token)){
					cout << token << endl;
					return "Neither";
				}

			return "IPv6";
		}

		return "Neither";
    }

	vector<string> split(const string& IP, char delimiter){
		istringstream ss(IP);
		string token;
		vector<string> res;
		while(getline(ss, token, delimiter))
			res.push_back(token);
		return res;
	}

	bool isValidIP4(string str){
		if(str.size() > 1 && str[0] == '0' || str.empty() || str.size() > 3)
			return false;

		for(char ch : str)
			if(!isdigit(ch))
				return false;

		return (0 <= stoi(str) && stoi(str) <= 255);
	}

	bool isValidIP6(string str){
		if(str.size() > 4 || str.empty())
			return false;

		for(char ch : str)
			if(! ( (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F') ) )
				return false;
        return true;
	}

};

int main(){
    Solution s;
    cout << s.validIPAddress("172.16.254.1") << endl;
    return 0;
}
