/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 11 21:52:03 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class StockDashboard{

private:
    unordered_map<string, pair<double, double>> _data;

public:
    
    // insert latest price
    void insertData(string name, double price){
        if(_data.find(name) != _data.end()){
            if(price > _data[name].second)
                _data[name] = make_pair(price, price);
            else
                _data[name] = make_pair(price, _data[name].second);
        }
        else{
            _data[name] = make_pair(price, price);
        }
    }

    // get highest history price
    double getHigh(string name){
        return _data[name].second;
    }

    // get current price
    double getPrice(string name){
        return _data[name].first;
    }

    void printHighK(int k){
        vector<pair<string, double>> temp;
        for(auto ele : _data){
            temp.push_back(make_pair(ele.first, ele.second.first));
        }

        nth_element(temp.begin(), 
                    temp.begin() + k - 1, 
                    temp.end(), 
                    [](pair<string, double> x, pair<string, double> y){ return x.second > y.second; });

        for (auto it = temp.begin(); it < temp.begin() + k; ++it)
            cout << it->first << ":" << it -> second << endl;
    }

};

int main(){
    StockDashboard s;

    s.insertData("AAA", 10);
    s.insertData("BBB", 12);
    s.insertData("CCC", 5);
    s.insertData("DDD", 1);
    s.printHighK(2);

    return 0;
}
