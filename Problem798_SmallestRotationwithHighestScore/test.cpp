/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar 11 19:04:20 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int bestRotation(vector<int>& A) {
        int N = A.size();
        vector<int> change(A.size());
        int res = 0, maxx = 0;
        for (int i = 0; i < N; ++i) 
            change[(i - A[i] + 1 + N) % N] -= 1;
    
        for (int i = 1; i < N; ++i){ 
            change[i] += change[i - 1] + 1;
            if(change[i] > maxx){
                maxx = change[i];
                res = i;
            }
        }

        return res;
    }
};


int main(){
    Solution s;

    vector<int> A{2,3,1,4,0};

    cout << s.bestRotation(A) << endl;
    return 0;
}
