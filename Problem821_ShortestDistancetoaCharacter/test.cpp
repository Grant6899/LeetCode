/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:28:43 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {

		int last_c = -10001, next_c = 0, cur = 0;

		vector<int> res(S.size(), 10001);

        while(S[next_c] != C)
				next_c++;

        while(next_c < S.size()){
			while(cur <= next_c){
				res[cur] = min(abs(cur - last_c), abs(cur - next_c));
				cur++;
			}
			last_c = next_c;
			next_c++;

            while(next_c < S.size() && S[next_c] != C)
    			next_c++;
		}


        while(cur < S.size()){
            res[cur] = abs(cur - last_c);
            cur++;
        }

		return res;
    }
};

int main(){
    Solution s;
    vector<int> ans = s.shortestToChar("loveleetcode", 'e');
    return 0;
}
