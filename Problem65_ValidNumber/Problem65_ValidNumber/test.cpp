#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

class Solution {
public:
	bool isNumber(string s) {

		while (s.size() > 0 && s.front() == ' ')
			s.erase(s.begin());

		while (s.size() > 0 && s.back() == ' ')
			s.pop_back();

		string sleft = s.substr(0, s.find_first_of('e'));

		if (sleft != s) {
			string sright = s.substr(s.find_first_of('e') + 1, s.size() - 1);
			if (sleft == "" && sright == "")
				return false;
			return isPureNumber(sleft) && isInteger(sright, false, true);
		}
			
		return isPureNumber(sleft);
	}


	bool isPureNumber(string s) {

		string s1 = s.substr(0, s.find_first_of('.'));
		
		if (s1 != s) {
			string s2 = s.substr(s.find_first_of('.') + 1, s.size() - 1);
			if (s1 == "" && s2 == "")
				return false;

			return (isInteger(s1, true, true) && isInteger(s2, false, false))
				  || (isInteger(s1, false, true) && isInteger(s2, true, false));
		}
		return isInteger(s1, false, true);
	}


	bool isInteger(string s, bool emptyvalid, bool signvalid) {
		if (signvalid && s.size() > 0 && (s.front() == '-' || s.front() == '+') )
			s.erase(s.begin());

		if (!emptyvalid && s == "")
			return false;
		

		for (int i = 0; i < s.size(); i++)
			if (s[i] < '0' || s[i] > '9')
				return false;

		return true;
	}
};


int main() {
	Solution s;

	vector<string> vecstr{ " ", "e", ".", ".1", "e1", "1e", "1.", "01", "-1.0", "-3e-3", "+.8", "+.", ".0" };

	
	for (int i=0;i<vecstr.size();i++)
		std::cout << std::boolalpha<< vecstr[i] << ": "<<s.isNumber(vecstr[i]) << std::endl;

	return 0;
}