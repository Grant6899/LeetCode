/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan 29 19:54:53 2018
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct pointer{
    int value, row, col;
    pointer(int _value, int _row, int _col) : value(_value), row(_row), col(_col){}
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        auto cmp = [](pointer& a, pointer& b){ return a.value > b.value;};

        priority_queue<pointer, vector<pointer>, decltype(cmp)> pointers(cmp);

        for(int i = 0; i < matrix.size(); ++i)
            pointers.push(pointer(matrix[i][0], i, 0));

        int res = 0;
        while(k > 0){
            auto temp = pointers.top();
            res = temp.value;
            pointers.pop();

            if(temp.col < matrix[0].size()-1)
                pointers.push(pointer(matrix[temp.row][temp.col+1], temp.row, temp.col+1));

            k--;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> mat {{1,2},{1,3}};

    Solution s;

    cout << s.kthSmallest(mat, 4) << endl;

    return 0;
}
