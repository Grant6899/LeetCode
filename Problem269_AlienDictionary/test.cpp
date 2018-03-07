/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 18:35:26 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, set<char>> graph;

        if(words.size() == 1)
            return words[0];

        for(string word : words){
            for(char ch : word)
			    if(graph.find(ch) == graph.end())
				    graph[ch] = set<char>();
        }


		for(int i = 0; i < words.size() - 1; ++i)
			make_graph(words[i], words[i+1], graph);

		string sorted = "";
		vector<int> onpath(26, false), visited(26, false);

       /* for(auto node : graph){
			cout << node.first << ":\n";
			for(char ch : node.second)
				cout << ch << " ";
			cout << endl;
		}*/


		for(auto node : graph){
			if(!visited[node.first - 'a'] && dfs(node.first, graph, visited, onpath, sorted)){
				return "";
			}
		}
		reverse(sorted.begin(), sorted.end());
		return sorted;
    }

	bool dfs(char ch, map<char, set<char>>& graph, vector<int>& visited, vector<int>& onpath, string& sorted){
        //cout << ch << endl;
		if(visited[ch - 'a']) return false;
		onpath[ch - 'a'] = true;
		visited[ch - 'a'] = true;

		for(char ch1 : graph[ch])
			if(onpath[ch1 - 'a'] || dfs(ch1, graph, visited, onpath, sorted))
				return true;
		sorted += ch;
		return onpath[ch-'a'] = false;
	}


	void make_graph(string& prev, string& next, map<char, set<char>>& graph){
		for(int i = 0; i < min(prev.size(), next.size()); ++i){
			if(prev[i] != next[i]){
				graph[prev[i]].insert(next[i]);
				return;
			}
		}
	}

};

int main(){
    vector<string> words{
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
    };
    Solution s;
    cout << s.alienOrder(words) << endl;
    return 0;
}
