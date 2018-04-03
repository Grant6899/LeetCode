/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  2 22:43:02 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;

        for(string& cp : cpdomains)
            countDomain(cp, count);

        vector<string> res;

        for(auto& x : count)
            res.push_back(to_string(x.second) + " " + x.first);

        return res;
    }

    void countDomain(string& cpdomain, unordered_map<string, int>& count){
        vector<string> pair = split(cpdomain, ' ');

        int cnt = stoi(pair[0]);

        vector<string> domains = split(pair[1], '.');

        for(int i = 0; i < domains.size(); ++i){
            string cur = "";
            for(int j = i; j < domains.size(); ++j)
                cur += "." + domains[j];
            cur.erase(cur.begin());

            count[cur]+= cnt;
        }
    }

    vector<string> split(string IP, char delimiter){
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
    vector<string> domains{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    for(auto& str : domains)
        cout << str << endl;
    return 0;
}
