/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  1 20:38:59 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> names = split(input, '\n');
		
		vector<string> path;
		
		int res = 0;
		string cur_path = "";
		
		for(string name : names){
                
			int cur = trimName(name);
			
			while(path.size() != cur){
					if(path.size() == 1) cur_path = "";
					else cur_path.erase(cur_path.size() - path.back().size() - 1, path.back().size() + 1);
					path.pop_back();
			}
			
			path.push_back(name);
			if(cur == 0) cur_path += name;
			else cur_path += "/" + name;
						
			if(name.find('.') != std::string::npos)
				res = max(res, (int)cur_path.size());

		}
		return res;
    }
	
	int trimName(string& name){
		int res = 0;
		while(name.front() == '\t'){
			res++;
			name = name.substr(1);
		}
		return res;
	}
	
	vector<string> split(string input, char delimiter){
		istringstream ss(input);
		string token;
		vector<string> res;
		while(getline(ss, token, delimiter))
			res.push_back(token);
		return res;
	}
	
	
};

int main(){
    string str = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    Solution s;
    cout << s.lengthLongestPath(str) << endl;
    return 0;
}
