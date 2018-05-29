/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 17:42:52 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {

	struct Tree{
		int height;
		vector<int> cordinate;
		Tree(int h_, int x_, int y_) : height(h_){ cordinate = {x_, y_}; }
	};


public:
    int cutOffTree(vector<vector<int>>& forest) {
        begin_time = clock();
		auto com = [](Tree& t1, Tree& t2){ return t1.height > t2.height; };
		priority_queue<Tree, vector<Tree>, decltype(com)> pq(com);
		for(int i = 0; i < forest.size(); ++i)
			for(int j = 0; j < forest[0].size(); ++j){
				if(forest[i][j] > 1)
					pq.push(Tree(forest[i][j], i, j));
			}

		int res = 0;
		vector<int> cur {0, 0};


		while(!pq.empty()){

			vector<int> next = pq.top().cordinate;
			pq.pop();

			int distance = BFS(cur, next, forest);
			if(distance != -1)
				res += distance;
			else
				return -1;

			cur = next;
		}

		return res;
    }

	int BFS(vector<int>& st, vector<int>& ed, vector<vector<int>>& forest){

        if(st == ed)
			return 0;

		vector<vector<bool>> visited(forest.size(), vector<bool>(forest[0].size(), false));
		visited[st[0]][st[1]] = true;
		queue<pair<vector<int>, int>> q;

		q.push(make_pair(st, 0));

		while(!q.empty()){

			auto cur = q.front();
			q.pop();
			vector<int> cur_cor = cur.first;

			for(int i = 0; i < 4; ++i){
				int next_x = cur_cor[0] + delta[i][0];
				int next_y = cur_cor[1] + delta[i][1];
				vector<int> next_cor {next_x, next_y};

				if(inRange(next_cor, forest.size(), forest[0].size()) && !visited[next_x][next_y] && forest[next_x][next_y] != 0){
					visited[next_x][next_y] = true;
                    if(next_x == ed[0] && next_y == ed[1]) return cur.second + 1;

					q.push(make_pair(next_cor, cur.second + 1));
				}
			}


		}
        std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
		return -1;
	}


private:
	vector<vector<int>> delta{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	bool inRange(vector<int>& cur, int length, int width){
		return ( 0 <= cur[0] && cur[0] < length && 0 <= cur[1] && cur[1] < width );
	}

    clock_t begin_time;
};

int main(){
    vector<vector<int>> forest {{1,2,3}, {0,0,4}, {7,6,5}};
    Solution s;
    cout << s. cutOffTree(forest) << endl;
    return 0;
}
