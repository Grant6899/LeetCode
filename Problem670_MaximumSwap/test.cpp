/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Mar  5 20:45:36 2018
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {

        string str = to_string(num);

        for(int i = 0; i < str.size(); ++i){
            //cout << "i: " << i << endl;
            int index = i;
            for(int j = i + 1; j < str.size(); ++j)
                if(str[j] >= str[index])
                    index = j;
            //cout << "index: " << index << endl;
            if(index != i && str[index] != str[i]){
                swap(str[i], str[index]);
                break;
            }
        }

        return stoi(str);
    }
};

int main(){
    Solution s;
    cout << s.maximumSwap(98368) << endl;
    return 0;
}
