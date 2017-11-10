#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int minDistance(string word1, string word2) {

		vector<vector<int>> minDis(word1.size()+1, vector<int>(word2.size()+1, INT_MAX));

		for (int i = 0; i <= word1.size(); i++)
			minDis[i][0] = i;
		
		for (int j = 0; j <= word2.size(); j++)
			minDis[0][j] = j;

		for (int i = 1; i <= word1.size();i++)
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i-1] == word2[j-1])
					minDis[i][j] = minDis[i - 1][j - 1];
				else
					minDis[i][j] = 1 + min(minDis[i - 1][j], min(minDis[i][j - 1], minDis[i - 1][j - 1]));
			}


		return minDis[word1.size()][word2.size()];
		
	}
};

int main() {

	Solution s;

	string s1 = "a", s2 = "d";

	std::cout << s.minDistance(s1, s2)<<std::endl;

	return 0;

}