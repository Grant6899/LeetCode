/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 13 21:04:30 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
		queue<pair<int, int>> q;
        vector<bool> visited(n + 2, false);
        visited[n] = true;
        q.push({n, 0});
        
		while(!q.empty()){
            int p = q.front().first;
		    int step = q.front().second;		
            if((p % 2 == 1)){
				if(p + 1 == 1 || p - 1 == 1)
					return step + 1;
					
				if(!visited[p+1]){
					q.push(make_pair(p+1, step + 1));
					visited[p+1]=true;
				}
					
				if(!visited[p-1]){
					q.push(make_pair(p-1, step + 1));
					visited[p-1]=true;
				}
			}
			else{
				if(p/2 == 1)
					return step + 1;
				if(!visited[p/2]){
					q.push(make_pair(p/2, step + 1));
					visited[p/2] = true;
				}
			}
            q.pop();
		}
	
		return -1;
    }
	
	
};

int main(){
    Solution s;
    cout << s.integerReplacement(127) << endl;
    return 0;
}
