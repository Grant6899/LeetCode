/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan  1 18:20:39 2018
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        _data = queue<int>();
    }

    /** Push element x onto stack. */
    void push(int x) {
        _data.push(x);
        for(int i = 0; i < _data.size()-1; ++i){
            _data.push(_data.front());
            _data.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = _data.front();
        _data.pop();
        return temp;
    }

    /** Get the top element. */
    int top() {
        return _data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _data.empty();
    }

private:
    queue<int> _data;
};

int main(){
    MyStack obj = MyStack();
    int x = 1;
    obj.push(x);
    int param_2 = obj.pop();
    int param_3 = obj.top();
    bool param_4 = obj.empty();
    return 0;
}

