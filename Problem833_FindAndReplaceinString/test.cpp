/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 18:27:12 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {

        sortSt(indexes, sources, targets);

        string head;
		auto strs = split(S, indexes, head);

		for(int i = 0; i < strs.size(); ++i){
			string firstPart = strs[i].substr(0, sources[i].size());
			if(firstPart == sources[i]){
				strs[i] = targets[i] + strs[i].substr(sources[i].size());
			}
		}

        //cout << "head: " << head << endl;
		for(string& str : strs)
			head += str;
		return head;
    }

    void sortSt(vector<int>& indexes, vector<string>& sources, vector<string>& targets){

        vector<pair<int, pair<string, string>>> help_st;

        for(int i = 0; i < indexes.size(); ++i){
            help_st.push_back({indexes[i], {sources[i], targets[i]}});
        }

        sort(help_st.begin(), help_st.end(), [](pair<int, pair<string, string>>& a, pair<int, pair<string, string>>& b){return a.first < b.first;});

        for(int i = 0; i < indexes.size(); ++i){
            indexes[i] = help_st[i].first;
            sources[i] = help_st[i].second.first;
            targets[i] = help_st[i].second.second;
        }
    }

	vector<string> split(string& S, vector<int>& indexes, string& head){
		vector<string> res;
		indexes.push_back(S.size());

		head = S.substr(0, indexes[0]);

		for(int i = 0; i < indexes.size() - 1; ++i){
			string tmp = S.substr(indexes[i], indexes[i+1] - indexes[i]);
            cout << tmp << " ";
			res.push_back(tmp);
		}
        cout << head << endl;
		return res;
	}
};

int main(){
    Solution s;
    vector<int> indexes{0, 2};
    vector<string> sources{"a", "cd"}, targets{"eee", "ffff"};
    cout << s. findReplaceString("abcd", indexes, sources, targets) << endl;
    return 0;
}
