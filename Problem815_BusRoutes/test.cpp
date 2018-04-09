/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  9 19:17:45 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(T == S)
            return 0;

        unordered_map<int, unordered_set<int>> to_routes; // to_routes[i]: indexes of buses that can pass stop i
        for (int i = 0; i < routes.size(); ++i)
			for (auto& j : routes[i])
				to_routes[j].insert(i);


		unordered_set<int> visited;
		int cur_transfer = 0;

        queue<pair<int, int>> q;
        q.push({S, 0});
		while(!q.empty()){

			while(!q.empty() && q.front().second == cur_transfer){
				auto cur = q.front();
				q.pop();

				for (auto& route_i : to_routes[cur.first])
					for (int next : routes[route_i])
						if (visited.find(next) == visited.end()) {
							if(next == T) return cur.second + 1;
							visited.insert(next);
							q.push({next, cur.second + 1});
						}

			}
			cur_transfer++;
		}
		return -1;
    }
};


int main(){
    Solution s;
    vector<vector<int>> routes{{1,2,7},{3,6,7}};
    cout << s.numBusesToDestination(routes, 1, 6) << endl;
    return 0;
}
