/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 18 11:12:30 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = parseVersion(version1), v2 = parseVersion(version2);
        
        for(int i = 0; i < max(v1.size(), v2.size()); ++i){
            int c1 = i >= v1.size()? 0 : v1[i];
            int c2 = i >= v2.size()? 0 : v2[i];

            if(c1 > c2)
                return 1;
            else if(c1 < c2)
                return -1;
        }
        return 0;
    }

    vector<int> parseVersion(string s){
        vector<int> result;
        string temp = "";
        for(auto it = s.begin(); it < s.end(); ++it){
            if(*it == '.'){
                result.push_back(stoi(temp));
                temp = "";
                continue;
            }
            temp+=*it;
        }
        result.push_back(stoi(temp));
        return result;
    }
};

int main(){
    Solution s;
    cout << s.compareVersion("1", "0") << endl;
    return 0;
}
