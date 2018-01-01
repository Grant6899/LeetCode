/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 31 15:19:44 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seq{n};

        while(seq.find(1) == seq.end()){
            n = getDSum(n);
            if(n != 1 && seq.find(n) != seq.end())
                return false;
            seq.insert(n);
        }
        return true;
    }

private:
    int getDSum(int n) {
        int result = 0;
        while(n != 0){
            result += (n % 10) * (n % 10);
            n /= 10;
        }
        return result;
    }
};

int main(){
    Solution s;
    cout << s.isHappy(36) << endl;
    return 0;
}
