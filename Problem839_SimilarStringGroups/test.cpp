/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun May 27 18:14:29 2018
 ************************************************************************/

#include<iostream>
#include<vector>
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

        if(i != j)
            cnt--;

		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j]+=sz[i];
		}
		else {
			id[j] = i;
			sz[i]+=sz[j];
		}
	}

	int getCount() {
		return cnt;
	}

	~QuickUnion() {

	}

};

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        QuickUnion qu(A.size());

        for(int i = 0; i < A.size(); ++i)
            for(int j = i + 1; j < A.size(); ++j)
                if(isSameGroup(A[i], A[j])){
                    //cout << "connecting: (" << i << ", " << j << ")\n";
                    qu.unite(i, j);
                }

        return qu.getCount();
    }

    bool isSameGroup(string& s1, string& s2){
        vector<vector<char>> diff;
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] != s2[i])
                diff.push_back({s1[i], s2[i]});
            if(diff.size() >= 3)
                return false;
        }

        if(diff.size() == 2 && diff[0][0] == diff[1][1] && diff[0][1] == diff[1][0])
            return true;

        return false;
    }
};

int main(){
    Solution s;
    vector<string> list {"tars","rats","arts","star"};
    cout << s. numSimilarGroups(list) << endl;
    return 0;
}
