/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 27 21:42:39 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int local = 0, global = 0;

        for(int i = 0; i < A.size() - 1; ++i){

            if(A[i] > A[i+1]){
                local++;
                cout << "local : " << i << endl;
            }

            for(int j = i + 2; j < A.size(); ++j){
                if(A[i] > A[j]){
                    global++;
                    cout << "global : " << i << " " << j << endl;
                }
            }
        }

        return local == global;
    }
};

int main(){
    
    vector<int> nums {1, 0, 2};
    Solution s;
    cout << s.isIdealPermutation(nums) << endl;
    return 0;
}
