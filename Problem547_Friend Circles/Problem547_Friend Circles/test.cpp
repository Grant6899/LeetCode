#include <vector>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class QuickUnion {
private:
	vector<int> id, sz; // id indicates the set to which the element belongs, sz indicates the height of the tree.
	int cnt;

	int root(int i) {
		while (i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}

public:
	QuickUnion(int N) {
		id = vector<int>(N);
		sz = vector<int>(N, 1);
		cnt = N;
		for (auto it = id.begin(); it < id.end(); it++)
			*it = it - id.begin();
	}

	bool find(int p, int q) {
		return root(p) == root(q);
	}

	void unite(int p, int q) {
		int i = root(p);
		int j = root(q);
		
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j]+=sz[i];
		}
		else {
			id[j] = i;
			sz[i]+=sz[j];
		}
		cnt--;
	}

	int getCount() {
		return cnt;
	}

	~QuickUnion() {

	}

};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {

		QuickUnion qu(M.size());

		for (int i = 0; i<M.size(); i++)
			for (int j = i + 1; j < M.size(); j++) {
				if (M[i][j] == 1 && !qu.find(i, j))
					qu.unite(i, j);
			}

		return qu.getCount();
	}
};

int main() {

	Solution s;

	vector<vector<int>> mat = { {1, 1, 0},
								{1, 1, 0},
								{0, 0, 1} };

	auto tmp = s.findCircleNum(mat);
	std::cout << tmp << std::endl;
	
	return 0;

}
