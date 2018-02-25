/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Feb 25 09:08:49 2018
 ************************************************************************/

#include<iostream>
#include<map>
#include<list>
#include<vector>

using namespace std;

class Dashboard{
    public:
    // n runners and m sensors
    Dashboard(int n, int m){
        sensors = vector<list<int>>(m);
    }

    // Runner i passes Sensor j
    void update(int i, int j){
        if(j > 0){
            sensors[j].push_back(i);
            sensors[j-1].erase(location[i]);
            location[i] = sensors[j].end();
        }
        else{
            sensors[j].push_back(i);
            location[i] = sensors[j].end();
        }
    }   

    // Print first K players ranking
    void getRank(int k){
        for(int i = sensors.size() - 1; i >= 0 && k > 0; i--)
        for(auto j = sensors[i].begin(); j != sensors[i].end() && k > 0; ++j){
            cout << *j << ' ';
            k--;
        }
    }

    private:
    map<int, list<int>::iterator> location;
    vector<list<int>> sensors;
};


int main(){
    
    Dashboard d(7, 5);

    d.update(2, 0);
    d.update(2, 1);
    d.update(4, 0);
    d.update(1, 0);
    d.update(3, 0);
    d.update(3, 1);
    
    d.getRank(4);
    
    return 0;
}
