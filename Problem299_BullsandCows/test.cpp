/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar 25 17:41:27 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> scnt(256, 0), gcnt(256, 0);

		int A = 0, B = 0;
		for(int i = 0; i < secret.size(); ++i){
			if(secret[i] == guess[i])
				A++;
			else{
				scnt[secret[i]]++;
				gcnt[guess[i]]++;
			}
		}

		for(int i = 0; i < 256; ++i)
			B += min(scnt[i], gcnt[i]);

		return to_string(A) + "A" + to_string(B) + "B";
    }
};

int main(){
    Solution s;
    cout << s.getHint("1123", "0111") << endl;
    return 0;
}
