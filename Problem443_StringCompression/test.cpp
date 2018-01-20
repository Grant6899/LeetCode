/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Jan 18 23:41:52 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {

        int fast = 0, slow = 0, counter = 1;

        while(fast < chars.size()){
            
            while(fast + 1 < chars.size() && chars[fast] == chars[fast+1]){
                counter++;
                fast++;
            }

            chars[slow] = chars[fast];
            if(counter > 1){
                string tmp = to_string(counter);
                for(int i = 0; i < tmp.size(); ++i)
                    chars[++slow] = tmp[i];
            }
            
            counter = 1;
            fast++;
            slow++;
        }
        return slow;
    }
};

int main(){
    
    vector<char> chars {'a','b','c'};
    //{'a', 'a', 'b','c','c','c', 'a','b','b','b','b','b','b','b','b','b','b','b','b'};

    Solution s;

    auto ans = s.compress(chars);

    for(int i = 0; i < ans; ++i)
        cout << chars[i] << ' ';

    cout << endl;
    return 0;
}
