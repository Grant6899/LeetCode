/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Mar 17 20:34:47 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<bool> visited(10, false);
		int total = 0;
		vector<int> cur;


		dfs(m, n, cur, visited, total);
		return total;
    }

	void dfs(int m, int n, vector<int>& cur, vector<bool>& visited, int& total){
		if(cur.size() >=m && cur.size() <=n){
			total++;
           /* for(int a : cur)
                cout << a << " ";
            cout << endl;*/
			if(cur.size() == n)
				return;
		}


		for(int i = 1; i <= 9; ++i){
			if(!visited[i] && (cur.empty() || isValid(cur.back(), i, visited))){
				cur.push_back(i);
				visited[i] = true;
				dfs(m, n, cur, visited, total);
				visited[i] = false;
				cur.pop_back();
			}
		}

	}

	bool isValid(int a, int b, vector<bool>& visited){

		if(a > b) swap(a, b);

		int row_a = (a-1) / 3, col_a = (a-1) % 3, row_b = (b-1) / 3, col_b = (b-1) % 3;
		int row_diff = abs(row_a - row_b), col_diff = abs(col_a - col_b);
        //cout << "diff\n";
        //cout << row_diff << "  " << col_diff << endl;
		if(row_diff == 0 && col_diff == 2 || row_diff == 2 && col_diff == 0 || row_diff == 2 && col_diff == 2){
            //cout << "checking if " << (row_a + row_b) / 2 * 3 + (col_a + col_b) / 2 << " visited\n";
			return visited[(row_a + row_b) / 2 * 3 + (col_a + col_b) / 2 + 1];
		}
		return true;
	}
};

int main(){
    Solution s;
    cout << s. numberOfPatterns(3, 5) << endl;
    return 0;
}
