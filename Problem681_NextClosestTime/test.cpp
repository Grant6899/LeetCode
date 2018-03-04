/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Mar  2 21:50:10 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {

        string st = time.substr(0, 2) + time.substr(3, 2);
        vector<string> times;

        for(int i1 = 0; i1 <= 3; ++i1)
            for(int i2 = 0; i2 <= 3; ++i2)
                for(int i3 = 0; i3 <= 3; ++i3)
                    for(int i4 = 0; i4 <= 3; ++i4){
                        string HH {st[i1], st[i2]}, MM {st[i3], st[i4]};
                        if(stoi(HH) < 24 && stoi(MM) < 60){
                            times.push_back(HH + MM);
                        }
                    }

        sort(times.begin(), times.end());

        //for(string str : times)
          //  cout << str << " ";
        int it = 0;
        for(int i = 0; i < times.size(); ++i)
            if(times[i] == st)
                it = i == times.size() - 1? 0 : i + 1;
        return times[it].substr(0, 2) + ":" + times[it].substr(2, 2);
    }
};

int main(){
    Solution s;
    cout << s.nextClosestTime("11:39") << endl;
    return 0;
}
