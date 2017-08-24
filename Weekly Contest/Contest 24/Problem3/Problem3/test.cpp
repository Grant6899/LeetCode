#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct point {
	int x, y, dis;
	point(int _x, int _y, int _dis) : x(_x), y(_y), dis(_dis) {
	}
};

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

		auto result = matrix;

		queue<point> point_que;
		

		int row = matrix.size();
		int col = matrix[0].size();

		vector<vector<bool>> pushed(row,vector<bool>(col,false));

		int count = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == 0) {
					point_que.push(point(i, j, 0));
					pushed[i][j] = true;
					result[i][j] = 0;
					count++;
				}
			}
		}

		int dis = 0;
		while (count < row*col) {
			dis++;
			while (point_que.front().dis < dis) {
				auto current = point_que.front();
				point_que.pop();

				if (1 + current.x >= 0 && 1 + current.x < row && pushed[1 + current.x][current.y] == false) {
					point_que.push(point(1 + current.x, current.y, dis));
					pushed[1 + current.x][current.y] = true;
					result[1 + current.x][current.y] = dis;
					count++;
				}

				if (-1 + current.x >= 0 && -1 + current.x < row && pushed[-1 + current.x][current.y] == false) {
					point_que.push(point(-1 + current.x, current.y, dis));
					pushed[-1 + current.x][current.y] = true;
					result[-1 + current.x][current.y] = dis;
					count++;
				}

				if (1 + current.y >= 0 && 1 + current.y < col && pushed[current.x][1 + current.y] == false) {
					point_que.push(point(current.x, 1 + current.y, dis));
					pushed[current.x][1 + current.y] = true;
					result[current.x][1 + current.y] = dis;
					count++;
				}

				if (-1 + current.y >= 0 && -1 + current.y < col && pushed[current.x][-1 + current.y] == false) {
					point_que.push(point(current.x, -1 + current.y, dis));
					pushed[current.x][-1 + current.y] = true;
					result[current.x][-1 + current.y] = dis;
					count++;
				}
			}
		}

		return result;
	}
	
	
};

int main() {
	vector<vector<int>> mat {{0,0,0},
							 {0,1,0},
							 {1,1,1}
							};
	Solution s;

	auto ans = s.updateMatrix(mat);

	return 0;
}