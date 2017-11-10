#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {

		vector<string> result{};

		for (int i = 0; i < words.size(); i++)
			if (maxWidth < words[i].size())
				return{};

		int nexttoadd = 0;

		while (nexttoadd < words.size()) {

			int currentLength = 0, currentcount = 0, currentWordLength;

			vector<string> currentLine = { words[nexttoadd] };
			currentcount++;
			currentLength = words[nexttoadd].size();
			currentWordLength = currentLine[0].size();
			nexttoadd++;
			while (nexttoadd < words.size() && currentLength + 1 + words[nexttoadd].size() <= maxWidth) {
				currentLength = currentLength + 1 + words[nexttoadd].size();
				currentcount++;
				currentLine.push_back(words[nexttoadd]);
				currentWordLength += words[nexttoadd].size();
				nexttoadd++;
			}

			if (nexttoadd < words.size())
				result.push_back(adjustLine(currentLine, maxWidth, currentWordLength));
			else
				result.push_back(adjustLastLine(currentLine, maxWidth, currentWordLength));

		}
		return result;
	}

	string adjustLine(vector<string> vec, int maxWidth, int wordlength) {

		int numInterval = vec.size() - 1;

		if (numInterval == 0) {
			return(vec[0] + string(maxWidth - vec[0].size(), ' '));
		}
		else {
			int additionalInterval = (maxWidth - wordlength) % numInterval;

			int minInterval = (maxWidth - wordlength - additionalInterval) / numInterval;

			string line = "";

			for (int i = 0; i < vec.size() - 1; i++) {
				line.append(vec[i]);
				line.append(string(minInterval, ' '));
				if (additionalInterval > 0) {
					line.append(" ");
					additionalInterval--;
				}
			}
			line.append(vec.back());

			return line;
		}
		return "";
	}

	string adjustLastLine(vector<string> vec, int maxWidth, int wordlength) {

		string line = "";
		for (int i = 0; i < vec.size() - 1; i++) {
			line.append(vec[i]);
			line.append(" ");
		}
		line.append(vec.back());
		line.append(string(maxWidth - line.size(), ' '));
		return line;
	}

		
};

int main() {
	Solution s;

	vector<string> vecstr{ "Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first." };
	
	auto ans = s.fullJustify(vecstr, 30);

	
	for (int i = 0; i < ans.size(); i++)
		std::cout << ans[i] << std::endl;

	return 0;
}