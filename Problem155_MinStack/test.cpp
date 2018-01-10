/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan  9 20:49:03 2018
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        _mins.push(INT_MAX);
    }

    void push(int x) {
        _data.push(x);
        
        if(x < _mins.top())
            _mins.push(x);
        else
            _mins.push(_mins.top());
    }

    void pop() {
        _data.pop();
        _mins.pop();
    }

    int top() {
        return _data.top();
    }

    int getMin() {
        return _mins.top();
    }

private:
    stack<int> _data;
    stack<int> _mins;

};

int main(){
    
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl; 
    cout << minStack.getMin() << endl;
    return 0;
}
