/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Jan 21 21:43:13 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res, current{"JFK"};
        vector<bool> used(tickets.size(), false);
        unordered_map<string, vector<pair<string, int>>> ticket_map;

        for(int i= 0;i < tickets.size(); ++i){
            if(ticket_map.find(tickets[i].first) == ticket_map.end()){
                ticket_map[tickets[i].first] = {make_pair(tickets[i].second, i)};
            }
            else{
                ticket_map[tickets[i].first].push_back(make_pair(tickets[i].second, i));
            }
        }

        find(current, res, used, ticket_map, tickets.size() + 1);
        return res;
    }
    
    void find(vector<string>& current, vector<string>& res, vector<bool>& used, unordered_map<string, vector<pair<string, int>>>& ticket_map, int len){
        if(!res.empty() && isFront(res, current))
            return;

        if(current.size()  == len){
                res = current;
        }

        for(auto ticket : ticket_map[current.back()]){
            if( !used[ticket.second] ){
                current.push_back(ticket.first);
                used[ticket.second] = true;
                find(current, res, used, ticket_map, len);
                used[ticket.second] = false;
                current.pop_back();
            }
        }
    }

    bool isFront(vector<string>& a, vector<string>& b){
        for(int i = 0; i < b.size();++i){
            if(a[i] < b[i])
                return true;
            else if(a[i] > b[i])
                return false;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<pair<string, string>> tickets {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};

    auto ans = s.findItinerary(tickets);

    for(auto ele : ans)
        cout << ele << ' ';

    cout << endl;
    return 0;
}
