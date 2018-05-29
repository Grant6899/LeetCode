/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:22:50 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        unordered_map<int, int64_t> combos;
		
		int res = 0;
		
		sort(A.begin(), A.end());
		
		for(int n : A){
			
			combos[n] = 1;
			
			for(int i = 2; i <= sqrt(n); ++i)
				if(n % i == 0 && combos.find(i) != combos.end()){
					combos[n] += (i == sqrt(n) ? combos[i] * combos[n / i] : 2 * combos[i] * combos[n / i]);
					combos[n] %= 1000000007;
                }
			
			res = (res + combos[n]) % 1000000007;
		}
        
		return res ;
    }
};


int main(){
    Solution s;
    vector<int> A{2,4,5,10};

    cout << s. numFactoredBinaryTrees(A) << endl;
    return 0;
}
