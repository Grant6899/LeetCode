/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Dec 31 10:22:29 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        bool modified = false;
        for (int i = 1, prev = a[0]; i < a.size(); i++) {
            if (a[i] < prev && modified++) return false;
            if (a[i] < prev && i - 2 >= 0 && a[i - 2] > a[i]) continue;
            prev = a[i];
        }
        return true;
    }
};
int main(){
    vector<int> num {4,2,3,6};
    Solution s;
    cout << s.checkPossibility(num) << endl;
    return 0;
}
