/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar  6 18:39:58 2018
 ************************************************************************/

#include<iostream>

using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
	
		long left = 0, right = 92681;
		
		while(left <= right){
			long mid = left + (right - left) / 2;
			
		if((1 + mid) * mid / 2 <= n && (2 + mid) * (mid + 1) / 2 > n)
			return mid;
		else if((1 + mid) * mid / 2 > n)
			right = mid - 1;
		else
			left = mid + 1;
		}
	}

};

int main(){
    Solution s;
    cout << s.arrangeCoins(2222) << endl;
    return 0;
}
