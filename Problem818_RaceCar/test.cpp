/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Apr 15 14:19:50 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        unordered_set<string> visited;
        
        q.push({0, 0, 1, 0});
        visited.insert("0~0~1");
        
        int step = 0;
        while(!q.empty()){
            //cout << endl;
            //cout << q.size() << endl;
            while(!q.empty() && q.front()[3] == step){
                for(int i = 0; i <= 1; ++i){
                    auto temp = q.front();
                    if(i == 0){
                        temp[0] += temp[2] * pow(2, temp[1]);
                        temp[1] ++;
                        temp[3] ++;
                    }
                    else{
                        temp[1] = 0;
                        temp[2] *= -1;
                        temp[3] ++;       
                    }
                    
                    if(temp[0] == target)
                        return temp[3];
                    //cout << "pushing: (" << temp[0] << " " << temp[1] << " " << temp[2] << " " << temp[3] << ")\n";
                    
                    if(!visited.count(to_string(temp[0]) + "~" + to_string(temp[1]) + "~" + to_string(temp[2])))
                        q.push(temp);
                }
                q.pop();
            }
            step++;
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s. racecar(5) << endl;
    return 0;
}
