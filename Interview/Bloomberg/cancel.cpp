/*************************************************************************
	> File Name: cancel.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Aug 12 15:59:22 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

string cancel_stack(string& str){
    stack<int> cnt;
    stack<char> data;
    
    int i = 0;

    while(i < str.size()){
        if(!data.empty() && str[i] == data.top())
            cnt.top()++;
        else{
            data.push(str[i]);
            cnt.push(1);
        }

        if(!data.empty() && (i+1 < str.size() && str[i+1] != data.top() || i+1 ==str.size()) && cnt.top() >= 3){
            data.pop();
            cnt.pop();
        }

        i++;
    }
 
    string res = "";
    
    while(!data.empty()){
        res += string(cnt.top(), data.top());
        cnt.pop();
        data.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string data = "aabbbaac";
    cout << cancel_stack(data) << endl;
    return 0;
}
