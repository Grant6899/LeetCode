/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 27 23:36:33 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<functional>
using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        auto cmp = [](pair<int, int>& a, pair<int, int>& b){return a.first * b.second < a.second * b.first;};
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> distances(cmp);

        for(int i = 1; i < stations.size(); ++i)
            distances.push(make_pair(stations[i] - stations[i-1], 1));
        
        queue<pair<int, int>> q1, q2;

        while(!distances.empty()){
            q1.push(distances.top());
            distances.pop();    
        }

        while(K > 0){
            if(q2.empty()){
                auto x = q1.front();
                q1.pop();
                q2.push(make_pair(x.first, x.second + 1));
            }
            else if(q1.empty()){
                auto x = q2.front();
                q2.pop();
                q2.push(make_pair(x.first, x.second + 1));
            }
            else{
                if(cmp(q1.front(), q2.front())){
                    auto x = q2.front();
                    q2.pop();
                    q2.push(make_pair(x.first, x.second+1));
                }
                else{
                    auto x= q1.front();
                    q1.pop();
                    q2.push(make_pair(x.first, x.second + 1));
                }
            }
            K--;
        }
 
        if(q2.empty()){
            return q1.front().first / (double) q1.front().second;
        }
        else if(q1.empty()){
            return q2.front().first / (double) q2.front().second;
        }
        else{
            if(cmp(q1.front(), q2.front())){
                return q2.front().first / (double) q2.front().second;
            }
            else{
                return q1.front().first / (double) q1.front().second;
            }
        }
           
    }
};

int main(){
    Solution s;
    vector<int> sta{10,19,25,27,56,63,70,87,96,97};

    cout << s.minmaxGasDist(sta, 3) << endl;
    return 0;
}

