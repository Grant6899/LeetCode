/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 13 21:04:30 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
		if(n == 1)
            return 0;
		vector<int> prev{n};

		vector<bool> visited(n, false);

		int step = 0;
		while(!prev.empty()){
			step++;
			vector<int> cur;
			for(int p : prev){
				cout << p << " ";
				if((p % 2 == 1)){
					if(p + 1 == 1 || p - 1 == 1)
						return step;

					if(!visited[p+1]){
						cur.push_back(p+1);
						visited[p+1]=true;
					}

					if(!visited[p-1]){
						cur.push_back(p-1);
						visited[p-1]=true;
					}
				}
				else{
					if(p/2 == 1)
						return step;
					if(!visited[p/2]){
						cur.push_back(p/2);
						visited[p/2] = true;
					}
				}
			}
            cout << endl;
			prev = cur;
		}
		return -1;
    }


};

int main(){
    Solution s;
    cout << s.integerReplacement(127) << endl;
    return 0;
}
