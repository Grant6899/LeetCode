/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Jan 20 22:06:05 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        multiset<int> current, expected;

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        int chunks = 0;
        for(int i = 0; i < arr.size();++i){
            current.insert(arr[i]);
            expected.insert(sorted[i]);
            if(current == expected)
                chunks++;
        }
        return chunks;
    }
};

int main(){
    Solution s;
    vector<int> nums {4, 1, 0, 2, 3, 4};
    cout << s.maxChunksToSorted(nums) << endl;
    return 0;
}
