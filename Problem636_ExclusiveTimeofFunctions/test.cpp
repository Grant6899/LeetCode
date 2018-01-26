/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 25 20:53:45 2018
 ************************************************************************/

#include<assert.h>
#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
using namespace std;

struct Log {
    int id;
    string status;
    int timestamp;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<Log> st;
        for(string log: logs) {
            stringstream ss(log);
            string temp, temp2, temp3;
            getline(ss, temp, ':');
            getline(ss, temp2, ':');
            getline(ss, temp3, ':');

            Log item = {stoi(temp), temp2, stoi(temp3)};
            if(item.status == "start") {
                st.push(item);
            } else {
                assert(st.top().id == item.id);

                int time_added = item.timestamp - st.top().timestamp + 1;
                times[item.id] += time_added;
                st.pop();

                if(!st.empty()) {
                    assert(st.top().status == "start");
                    times[st.top().id] -= time_added;
                }
            }
        }

        return times;
    }
};

int main(){
    vector<string> logs{"0:start:0","1:start:2","2:start:8", "2:end:10", "1:end:15","0:end:16"};

    Solution s;

    auto ans = s.exclusiveTime(3, logs);

    for (int x : ans)
        cout << x << " ";

    cout << endl;
    return 0;
}
