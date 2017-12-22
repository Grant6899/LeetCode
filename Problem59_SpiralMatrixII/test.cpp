/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Dec 21 19:59:14 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int current = n * n; 
        vector<vector<int>> result{ {current} };
        --current;

        while(current > 0){
            rotate(result);

            vector<int> add(result[0].size(), 0);
            for(int i = add.size() - 1; i >= 0; --i)
                add[i] = current - i;

            result.insert(result.begin(), add);
            current-=add.size();
        }
        return result;
    }

    vector<vector<int>> rotate(vector<vector<int>> mat){
        vector<vector<int>> result;

        for(int i = 0; i < mat[0].size(); ++i)
        for(int j = mat.size() - 1; j == 0; --j)
            result[i].push_back(mat[i][j]);
        
        return result;
    }

};

int main(){    
    Solution s;
    auto ans = s.generateMatrix(3);
    for(auto it = ans.begin(); it < ans.end(); ++it){
        for(auto jt = (*it).begin(); jt < (*it).end(); ++jt)
            cout << *jt << "|";
        cout << endl;
    }
    return 0;
}
