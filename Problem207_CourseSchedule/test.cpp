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
        vector<unordered_set<int>> require(numCourses, unordered_set<int>());
        vector<bool> taken(numCourses, false);
        vector<unordered_set<int>> haveClass(numCourses, unordered_set<int>());


        for(auto rule : prerequisites){
            require[rule.first].insert(rule.second);
            haveClass[rule.second].insert(rule.first);
        }

        bool res = learnNext(0, taken, require, haveClass, numCourses);

        return res;
    }
    
    bool learnNext(int index, vector<bool>& taken, vector<unordered_set<int>>& require, vector<unordered_set<int>>& haveClass, int target){
        if(index == target)
            return true;

        for(int i = 0; i < target; i++){
            if(!taken[i] && require[i].empty()){
                auto snapshot = require;
                
                for(int course : haveClass[i])
                        require[course].erase(i);

                taken[i] = true;
                if(learnNext(index+1, taken, require, haveClass, target))
                    return true;
                taken[i] = false;
                
                for(int course : haveClass[i])
                    require[course].insert(i);
            }
        }

        return false;
    }

};


int main(){
    Solution s;
    vector<pair<int, int>> pre { {0, 1}, {0, 2}, {0, 3}, {4, 0}, {5, 4} };
    cout << s.canFinish(8, pre) << endl;
    return 0;
}

