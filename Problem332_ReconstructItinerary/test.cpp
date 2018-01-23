/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 21 21:43:13 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> current{"JFK"};
        unordered_map<string, multiset<string>> ticket_set;

        for(auto ticket : tickets)
            ticket_set[ticket.first].insert(ticket.second);
        
        find(current, ticket_set, tickets.size() + 1);
        return current;
    }
    
    void find(vector<string>& current, unordered_map<string, multiset<string>>& ticket_set, int len){

        if(current.size()  == len){
                return;
        }

        string tmp = *ticket_set[current.back()].begin();  
        ticket_set[current.back()].erase(ticket_set[current.back()].begin());
        current.push_back(tmp);
        find(current, ticket_set, len);
    }
};

int main(){
    Solution s;
    vector<pair<string, string>> tickets {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};

    auto ans = s.findItinerary(tickets);

    for(auto ele : ans)
        cout << ele << ' ';

    cout << endl;
    return 0;
}
