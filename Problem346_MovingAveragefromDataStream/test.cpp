/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Mar  2 19:20:24 2018
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }

    double next(int val) {
        if(q.size() == size){
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return sum / (double)q.size();
    }
private:
    int size, sum = 0;
    queue<int> q;
};


int main(){
    MovingAverage m(2);
    
    cout << m.next(1) << endl;
    cout << m.next(2) << endl;
    cout << m.next(3) << endl;

    return 0;
}
