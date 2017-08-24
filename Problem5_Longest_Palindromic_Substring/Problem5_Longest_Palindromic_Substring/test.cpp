#include<iostream>
#include<string>
#include<vector>


using namespace std;


class Solution {
public:

	int find_radius(string str, int current_index, int& pos, int& maxright, int st) {
		int radius = st;
		while (current_index + radius + 1 <= str.size()-1 && current_index - radius - 1 >= 0 && str[current_index + radius + 1] == str[current_index - radius - 1]) {
			radius++;
		}
		if (current_index + radius > maxright) {
			pos = current_index;
			maxright = current_index + radius;
		}
		return radius;
	}

	string longestPalindrome(string s) {

		// Create a new string with "#"
		std::string new_str(2 * s.size() + 1, '#');
		
		for (int i = 0; i < s.size();++i) {
			new_str[2 * i + 1] = s[i];
		}

		int max_index = -1, max_len = 0;

		int maxright = -1, pos = -1;

		vector<int> r(new_str.size(), 0);
		// generate largest radius array r[i]
		for (int i = 0; i < new_str.size(); ++i) {

			if (i > maxright) r[i] = find_radius(new_str, i, pos, maxright, 0);

			else if (i <= maxright) {
					int image_i = pos * 2 - i;
					if (image_i + r[image_i] <= pos) {
						r[i] = find_radius(new_str, i, pos, maxright, r[image_i]);
					}
					else {
						r[i] = find_radius(new_str, i, pos, maxright, i - (image_i + r[image_i]));
					}
				}

			if (r[i] > max_len) {
				max_index = i;
				max_len = r[i];
			}

	    }

		string result = s.substr((max_index - max_len) / 2, max_len);

		return result;

		}
};

int main() {
	Solution s;

	cout << s.longestPalindrome("bababsfdad") << endl;

	return 0;
}