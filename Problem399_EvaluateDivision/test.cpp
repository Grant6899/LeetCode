/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:57:10 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> node;
		int node_count = 0;

		for(int i = 0; i < equations.size(); ++i){
			if(node.find(equations[i].first) == node.end()){
				node[equations[i].first] = node_count;
				node_count++;
			}
			if(node.find(equations[i].second) == node.end()){
				node[equations[i].second] = node_count;
				node_count++;
			}
		}

		vector<vector<double>> graph(node_count, vector<double>(node_count, -1.0));

		for(int i = 0; i < node_count; ++i)
			graph[i][i] = 1.0;

		for(int i = 0; i < equations.size(); ++i){
			graph[node[equations[i].first]][node[equations[i].second]] = values[i];
			graph[node[equations[i].first]][node[equations[i].second]] = values[i];
		}

        //cout << "node_count: " << node_count << endl;
		for(int i = 0; i < node_count; ++i)
		for(int j = 0; j < node_count; ++j){
			for(int k = 0; k < node_count; ++k){
				if(graph[i][k] != -1 && graph[k][j] != -1){
					graph[i][j] = graph[i][k] * graph[k][j];
                    graph[j][i] = 1.0 /graph[i][j];
                }
			}
		}

		vector<double> res;

		for(auto q : queries){
			if(node.find(q.first) != node.end() && node.find(q.second) != node.end())
				res.push_back(graph[node[q.first]][node[q.second]]);
			else
				res.push_back(-1.0);
		}

		return res;
    }
};

int main(){
    Solution s;
    vector<pair<string, string>> eq;
    eq.push_back(make_pair("a", "b"));
    eq.push_back(make_pair("b", "c"));

    vector<double> values{2.0, 3.0};

    vector<pair<string, string>> qu;
    qu.push_back(make_pair("a", "c"));

    auto ans = s.calcEquation(eq, values, qu);
    return 0;
}
