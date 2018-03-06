/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 19:20:01 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<bool> visited(n, false);
		
		int candidate = 0;
		for(int i = 1; i < n;  ++i)
			if(knows(candidate, i))
				candidate = i;
		
		return check(candidate, n);		
    }
	
	int check(int c, int n){
		for(int i = 0; i < n; ++i)
			if( i != c && (knows(c, i) || !knows(i, c)))
				return -1;
		return c;
	}
};

