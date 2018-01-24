/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan 23 20:47:02 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<time.h>
#include<stdlib.h>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) == map.end()){
            map[val] = _data.size();
            _data.push_back(val);
            return true;
        }
        else
            return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) != map.end()){
            int x = map[val];
            swap(map[val], map[_data.back()]);
            swap(_data[x], _data[_data.size()-1]);
            map.erase(val);
            _data.pop_back();
            return true;
        }
        else
            return false;
    }


    /** Get a random element from the set. */
    int getRandom() {
        //srand (time(0));
        int rand_idx = rand() % _data.size();
        return _data[rand_idx];
    }

private:
    unordered_map<int, int> map;
    vector<int> _data;
    
};


int main(){
    RandomizedSet rs;

    rs.insert(1);
    rs.insert(10);
    rs.insert(20);
    rs.insert(30);
    for(int i = 0; i < 100; i++)
        cout << rs.getRandom() << " ";

    return 0;
}
