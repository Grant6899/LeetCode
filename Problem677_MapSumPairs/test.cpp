/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 20 22:21:52 2018
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
			data[key] = val;
    }

    int sum(string prefix) {
        auto st = data.lower_bound(prefix);
		if(st == data.end())
			return 0;

		int res = 0;

		for(auto it = st; it != data.end() && startwith(prefix, it->first) ; it++)
			res += it->second;
		return res;
    }

private:
	map<string, int> data;

	bool startwith(string prefix, string str){
		if(prefix.size() > str.size())
			return false;

		for(int i = 0; i < prefix.size(); ++i)
			if(prefix[i] != str[i])
				return false;
		return true;
	}
};

int main(){
    MapSum obj = MapSum();
    obj.insert("apple",3);
    cout << obj.sum("app");
    return 0;
}
