#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

class Solution {
public:
	string simplifyPath(string path) {

		vector<string> dir{""};

		while (path[0] == '/') {
			
			while (path[0] == '/')
				path.erase(0, 1);

			if (path.size() > 0) {
				string current_dir = path.substr(0, path.find_first_of('/'));
				if ((current_dir == ".." && dir.back() == "") || current_dir == ".") {
					while (path[0] != '/' && path != "")
						path.erase(0, 1);
					continue;
				}
				else if (current_dir == "..")
					dir.pop_back();
				else
					dir.push_back(current_dir);
			
				while (path[0] != '/' && path != "")
					path.erase(0, 1);
			}
		}

		string result = "";

		if (dir.size() > 1) {
			for (int i = 1; i < dir.size(); i++) {
				result.append("/");
				result.append(dir[i]);
			}
			return result;
		}
		else
			return "/";
	}
};

int main() {
	Solution s;

	string x = "/a/./b/../../c/";

	auto ans = s.simplifyPath(x);

	std::cout << ans << std::endl;
	return 0;
}