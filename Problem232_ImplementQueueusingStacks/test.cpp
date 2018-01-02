/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Jan  1 18:51:13 2018
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        _data = stack<int>();
    }

    // Push element x to the back of queue.
    void push(int x) {
        pushHelper(x);
    }
    void pushHelper(int x){
        if(_data.size()==0){
            _data.push(x);
            return;
        }
        int data;
        data = _data.top();
        _data.pop();
        pushHelper(x);
        _data.push(data);
        return;
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = _data.top();
        _data.pop();
        return temp;
    }

    /** Get the front element. */
    int peek() {
        return _data.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _data.empty();
    }

private:
    stack<int> _data;
};

int main(){
    MyQueue obj = MyQueue();
    obj.push(1);
    obj.push(2);
    int param_3 = obj.pop();
    int param_4 = obj.peek();
    return 0;
}
