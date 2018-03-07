/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 18:46:03 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
		vector<int> idx(n, 0);

		for(int i = 0; i < n; ++i)
			idx[i] = i;

		for(auto& e : edges)
			if(e.first > e.second)
				swap(e.first, e.second);

		sort(edges.begin(), edges.end(), [](pair<int, int>& a, pair<int, int>& b){return a.first == b.first?  a.second < b.second : a.first < b.first;});


		int cnt = n;
		for(auto e : edges){
			//cout << "adding (" << e.first << ", " << e.second << ")\n";


			if(idx[e.first] == idx[e.second])
				return false;
			else{
				for(int i = 0; i < n; ++i)
					if(idx[i] == idx[e.second]) idx[i] = idx[e.first];
				cnt--;
			}
            /*for(int i = 0; i < n; ++i)
				cout << idx[i] << " ";
			cout << endl;*/
		}
		return cnt == 1? true : false;
    }

};

int main(){
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(1, 4));
    
    Solution s;

    cout << s.validTree(5, edges) << endl;
    return 0;
}
