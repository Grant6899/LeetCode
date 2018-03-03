/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Mar  2 19:37:29 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0)
            return vector<int>(1, 0);
		vector<string> prev {"0", "1"};

		for(int i = 2; i <= n; ++i){
			vector<string> cur, temp = prev;
			reverse(temp.begin(), temp.end());
			for(string str : prev)
				cur.push_back("0"+str);
			for(string str : temp)
				cur.push_back("1"+str);
			prev = cur;
		}

		vector<int> res;

		for(string str : prev)
			res.push_back(std::bitset<64>(str).to_ullong());

		return res;
    }
};

int main(){
    Solution s;

    auto ans = s.grayCode(5);

    for(int a : ans)
         cout << a << ' ';
    cout << endl;
    return 0;
}
