/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 13 20:48:48 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
		int st = findN(target);

		//cout << "st: " << st << endl;
		int sum = (1 + st) * st / 2;
		while(true){
            //cout << sum << endl;
			if((sum - target) % 2 == 0)
				return st;
			st++;
            sum += st;
		}
    }

	int findN(long target){
		long left = 0, right = 50000;

		while(left <= right){
			long mid = left + (right - left) / 2;
			if((1 + mid) * mid / 2  < target && (mid + 2) * (mid + 1)/2 >= target)
				return mid + 1;
			else if((mid + 2) * (mid + 1)/2 < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
        return -1;
	}

};

int main(){
    Solution s;
    cout << s.reachNumber(100) << endl;
    return 0;
}
