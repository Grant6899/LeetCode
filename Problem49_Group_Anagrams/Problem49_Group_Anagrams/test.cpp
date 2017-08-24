#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, int> count_map;

		for (int i = 0; i < strs.size(); ++i) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			if (count_map.find(temp) == count_map.end()) {
				count_map[temp] = count_map.size();
				result.push_back({ strs[i] });
			}
			else {
				result[count_map[temp]].push_back(strs[i]);
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<string> vec = { "eat", "tea", "tan", "ate", "nat", "bat" };

	auto ans = s.groupAnagrams(vec);

	/*string a = "314";
	std::sort(a.begin(), a.end());
	std::cout << a << endl;*/
	return 0;
}