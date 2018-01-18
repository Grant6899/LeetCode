/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 17 19:15:28 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        
        unordered_map<int, int> dic;

        for(int i = 0; i < B.size(); ++i)
            dic[B[i]] = i;

        vector<int> res;
        for(int i = 0; i < A.size(); ++i)
            res.push_back(dic[A[i]]);

        return res;
    }
};

int main(){
    Solution s;
    vector<int> n1 {12, 28, 46, 32, 50}, n2 {50, 12, 32, 46, 28};
    auto ans = s.anagramMappings(n1, n2);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl;

    return 0;
}
