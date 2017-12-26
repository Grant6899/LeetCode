/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Dec 25 19:11:27 2017
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result = "";

        while(n > 0){
            char ch = static_cast<char>((n-1) % 26 + 'A');
            result += ch;
            n = (n-1) / 26 ;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution s;
    cout << s.convertToTitle(27) << endl;
    return 0;
}
