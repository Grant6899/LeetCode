/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sat Dec 16 14:47:26 2017
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E), right = max(min(C, G), left);
        int down = max(B, F), up = max(min(D, H), down);

        return (D-B) * (C-A) + (H-F) * (G-E) - (up - down) * (right - left);
    }
};

int main(){
    Solution s;
    cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
