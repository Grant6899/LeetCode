/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:56:28 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
		
		
		vector<int> sums(machines.size() + 1, 0);
		
		for(int i = 1; i < machines.size() + 1; ++i)
			sums[i] += sums[i-1] + machines[i - 1];
				
		if(sums.back() % machines.size() != 0)
			return -1;
		
		int avg = sums.back() / machines.size();
		
		int res = -1;
		for(int i = 0; i < machines.size(); ++i){
			int left = i * avg - sums[i];
			int right = (machines.size() - 1 - i) * avg - (sums.back() - sums[i + 1]);
			
			int temp = 0;
			if(left >= 0 && right >= 0)
				temp = abs(left) + abs(right);
			else
				temp = max(abs(left), abs(right));
			
			res = max(res, temp);
		}
		return res;
    }
};


int main(){
    Solution s;
    vector<int> m{1, 0, 5};
    cout << s.findMinMoves(m) << endl;
    return 0;
}
