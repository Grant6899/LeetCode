/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Dec 28 19:04:14 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_set<int> current;
        for(int i = 0; i < numCourses; ++i)
            current.insert(i);

        for(auto i : prerequisites){
            if(current.find(i.first)
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<pair<int, int>> pre { {0, 1}, {0, 2}, {0, 3}, {4, 0}, {5, 4} };
    cout << s.canFinish(8, pre) << endl;
    return 0;
}

