/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar 14 19:01:42 2018
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        map<char, int> cnt;
		vector<string> res;

		for(char ch : s)
			cnt[ch]++;

		int excpt = 0;
		char single;
		vector<char> pool;
		for(auto c : cnt){
			if(c.second % 2 != 0){
				excpt++;
				single = c.first;
			}
			for(int i = 0; i < c.second / 2; i++)
				pool.push_back(c.first);
		}

		if(excpt > 1)
			return res;

		vector<string> halfs = permuteUnique(pool);

		for(int i = 0; i < halfs.size(); ++i){
			string a = halfs[i];
			reverse(a.begin(), a.end());
			if(excpt == 1)
				res.push_back(halfs[i] + single + a);
			else
				res.push_back(halfs[i] + a);
		}
		return res;
    }

	vector<string> permuteUnique(vector<char>& pool) {
		vector<bool> used(pool.size(), false);
		string current = "";
		vector<string> result;
		find(current, pool, used, result);
		return result;
	}

	void find(string& current, vector<char>& pool, vector<bool>& used, vector<string>& result) {
		if (current.size() == pool.size()) {
			result.push_back(current);
			return;
		}

		for (int i = 0; i< pool.size(); i++)
			if (used[i] == false) {
				if (i > 0 && pool[i] == pool[i - 1] && used[i - 1])
					return;
				current.push_back(pool[i]);
				used[i] = true;
				find(current, pool, used, result);
				used[i] = false;
				current.pop_back();
			}
	}

};
int main(){
    Solution s;
    auto ans = s. generatePalindromes("aabbbbc");
    return 0;
}
