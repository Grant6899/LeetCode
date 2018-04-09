/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  9 19:13:49 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> l1, l2;

		for(int i = 0; i < list2.size(); ++i)
			l2[list2[i]] = i;


		vector<string> res;

		int idx_sum = INT_MAX;

		for(int i = 0; i < list1.size(); ++i){
			if(l2.find(list1[i]) != l2.end() && i + l2[list1[i]] < idx_sum){
				res = {list1[i]};
				idx_sum = i + l2[list1[i]];
			}
			else if(l2.find(list1[i]) != l2.end() && i + l2[list1[i]] == idx_sum)
				res.push_back(list1[i]);
		}
		return res;
    }
};

int main(){
    Solution s;
    vector<string> list1{"Shogun", "Tapioca Express", "Burger King", "KFC"}, list2{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    auto ans = s. findRestaurant(list1, list2);
    for(auto a : ans)
        cout << a << endl;
    return 0;
}
