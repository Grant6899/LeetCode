/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 25 21:04:03 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for(int a : asteroids){
            
            if(res.empty() || res.back() * a > 0 || (res.back() < 0 && a > 0)){
                res.push_back(a);
            }
            else{

                do{
                    if(res.back() < abs(a)){
                        res.pop_back();
                    }
                    else if(res.back() == abs(a)){
                        res.pop_back();
                        a = 0;
                    }
                    else{
                        a = 0;
                    }
                }while( !( res.empty() || res.back() * a > 0 || a == 0) );

                if(a != 0)
                    res.push_back(a);
            }

        }
        return res;
    }

};

int main(){
    
    vector<int> a {5, 10, -15, 20, 1};
    Solution s;
    auto ans = s.asteroidCollision(a);

    for(int i : ans)
        cout << i << ' ';
    cout << endl;

    return 0;
}
