/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 18:00:41 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Codec {
public:
    string encode(vector<string>& strs) {
        string res;
        for (auto& s: strs) res+= to_string(s.size()) + "~" + s;
        return res;
    }
    vector<string> decode(string str) {
        vector<string> res;
        int last = 0;

        while( str.find('~', last) != std::string::npos){
            int idx = str.find('~', last);
            string len_str = str.substr(last, idx - last);
            //cout << "len_str: " << len_str << endl;
            //cout << "idx: " << idx << endl;
            int len = stoi(len_str);
            string cur = str.substr(idx + 1, len);
            last = idx + 1 + len;
            res.push_back(cur);
        }

        return res;
    }
};

int main(){
    Codec c;
    vector<string> str_vec{"1saf", "", "\0"};
    string str = c.encode(str_vec);
    cout << str << endl;
    auto ans = c.decode(str);
    return 0;
}
