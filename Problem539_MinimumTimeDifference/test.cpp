/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  9 19:09:26 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());

		int res = INT_MAX;
		for(int i = 0; i < timePoints.size() - 1; ++i)
			res = min(timediff(timePoints[i], timePoints[i + 1]), res);

        res = min(timediff(timePoints.back(), timePoints[0]), res);
		return res;
    }

	int timediff(string& s1, string& s2){
		auto v1 = split(s1, ':');
		auto v2 = split(s2, ':');

		int h1 = stoi(v1[0]), h2 = stoi(v2[0]), m1 = stoi(v1[1]), m2 = stoi(v2[1]);

		if(h1 > h2 || h1 == h2 && m1 > m2){
			swap(h1, h2);
			swap(m1, m2);
		}

		int h3 = h1 + 24;
		int m3 = m1;

		return min((h2 - h1) * 60 + (m2 - m1), (h3 - h2) * 60 + (m3 - m2));
	}

	vector<string> split(string time, char delimiter){
		istringstream ss(time);
		string token;
		vector<string> res;
		while(getline(ss, token, delimiter))
			res.push_back(token);
		return res;
	}
};

int main(){
    Solution s;
    vector<string> times{"23:59","00:00"};

    cout << s. findMinDifference(times) << endl;
    return 0;
}
