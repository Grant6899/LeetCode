/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 16 13:41:59 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
	string target = "";
	vector<vector<char>> map;
	vector<vector<bool>> visited;
	unordered_map<char, vector<pair<int, int>>> st_location;
	vector<pair<int, int>> path;

	bool result = false;

public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> reval;
        map = board;
        for (int i = 0; i < map.size(); ++i)
			for (int j = 0; j < map[0].size(); ++j) {
				if (st_location.find(map[i][j]) == st_location.end()) {
					vector<pair<int, int>> vec_temp{ make_pair(i, j) };
					st_location.insert({ map[i][j], vec_temp });
				}
				else
					st_location[map[i][j]].push_back(make_pair(i, j));
			}

        for (auto it = words.begin(); it < words.end(); ++it){
            result = false;
            if (exist(board, *it)){
                reval.push_back(*it);        
            }
        }        

        sort( reval.begin(), reval.end() );
        reval.erase( unique( reval.begin(), reval.end() ), reval.end() );

        return reval;
    }

	bool exist(vector<vector<char>>& board, string word) {
        map = board;
		target = word;

		if (map.empty() || target.empty())
			return false;

		visited = vector<vector<bool>>(map.size(), vector<bool>(map[0].size(), false));
		next(0);

		return result;
	}

	bool checkRange(int r, int c) {
		return (r >= 0 && r < map.size() && c >= 0 && c < map[0].size());
	}

	void next(int i) {
		if (result == true)
			return;

		if (i == target.size()) {
			result = true;
			return;
		}

		if (i == 0) {
			if (st_location.find(target[0]) == st_location.end()) {
				result = false;
				return;
			}

			for (auto it = st_location[target[0]].begin(); it < st_location[target[0]].end(); ++it) {
				path.push_back(*it);
				visited[it->first][it->second] = true;
				next(i + 1);
				visited[it->first][it->second] = false;
				path.pop_back();
			}
		}
		else {
			for (int j = 0; j < 4; ++j) {

				if (j == 0) {
					int temp_r = path.back().first - 1, temp_c = path.back().second;

					if (checkRange(temp_r, temp_c) && map[temp_r][temp_c] == target[i] && !visited[temp_r][temp_c] ) {
						path.push_back(make_pair(temp_r, temp_c));
						visited[temp_r][temp_c] = true;
						next(i + 1);
						visited[temp_r][temp_c] = false;
						path.pop_back();
					}
				}
				if (j == 1) {
					int temp_r = path.back().first, temp_c = path.back().second - 1;

					if (checkRange(temp_r, temp_c) && map[temp_r][temp_c] == target[i] && !visited[temp_r][temp_c] ) {
						path.push_back(make_pair(temp_r, temp_c));
						visited[temp_r][temp_c] = true;
						next(i + 1);
						visited[temp_r][temp_c] = false;
						path.pop_back();
					}
				}
				if (j == 2) {
					int temp_r = path.back().first + 1, temp_c = path.back().second;

					if (checkRange(temp_r, temp_c) && map[temp_r][temp_c] == target[i] && !visited[temp_r][temp_c] ) {
						path.push_back(make_pair(temp_r, temp_c));
						visited[temp_r][temp_c] = true;
						next(i + 1);
						visited[temp_r][temp_c] = false;
						path.pop_back();
					}
				}
				if (j == 3) {
					int temp_r = path.back().first, temp_c = path.back().second + 1;

					if (checkRange(temp_r, temp_c) && map[temp_r][temp_c] == target[i] && !visited[temp_r][temp_c] ) {
						path.push_back(make_pair(temp_r, temp_c));
						visited[temp_r][temp_c] = true;
						next(i + 1);
						visited[temp_r][temp_c] = false;
						path.pop_back();
					}
				}


			}
		}
	}

};

int main(){
    vector<vector<char> > board { {'o','a','a','n'},
                                 {'e','t','a','e'},
                                 {'i','h','k','r'},
                                 {'i','f','l','v'}};

    vector<string> words {"oath","pea","eat","rain"};
    
    Solution s;

    auto temp = s.findWords(board, words);

    for (auto it = temp.begin(); it < temp.end(); ++it)
        cout << *it << endl;

    return 0;
}
