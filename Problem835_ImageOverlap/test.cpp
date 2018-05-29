/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 18:59:12 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {

		int length = A.size();

		int upmove = length - 1, leftmove = length - 1;

		int res = 0;
		for(int upmove = length - 1; upmove > - length; --upmove)
			for(int leftmove = length - 1; leftmove > - length; --leftmove){
                //cout << upmove << " " << leftmove << endl;
				res = max(res, countOverlap(upmove, leftmove, A, B));
			}
		return res;
    }

	int countOverlap(int upmove, int leftmove, vector<vector<int>>& A, vector<vector<int>>& B){
		int count = 0;
		int inMap = 0;
		for(int i = 0; i < A.size(); ++i)
			for(int j = 0; j < A.size(); ++j){
				if(0 <= i + upmove && i + upmove < A.size() && 0 <= j + leftmove && j + leftmove < A.size()){
					inMap++;
					if(A[i + upmove][j + leftmove] == B[i][j] && B[i][j] == 1)
						count++;
                }
			}
		//cout << "upmove: " << upmove << " leftmove: " << leftmove  << " inMap: " << inMap << endl;
		return count;
	}

};

int main(){
    Solution s;
    vector<vector<int>> A{{1,1,0},{0,1,0},{0,1,0}}, B{{0,0,0},{0,1,1},{0,0,1}};
    cout << s.largestOverlap(A, B) << endl;
    return 0;
}
