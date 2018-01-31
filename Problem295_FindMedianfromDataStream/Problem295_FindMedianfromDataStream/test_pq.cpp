/*************************************************************************
	> File Name: test_pq.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Jan 30 20:31:16 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }

    void addNum(int num) {
        if(small.empty() && large.empty())
            small.push(num);
        else{
            if(small.top() >= num)
                small.push(num);
            else
                large.push(num);
        }

        if(small.size() > large.size() + 1){
            int temp = small.top();
            small.pop();
            large.push(temp);
        }
        else if(small.size() < large.size()){
            int temp = large.top();
            large.pop();
            small.push(temp);
        }

    }

    double findMedian() {
        if(small.size() == large.size())
            return (small.top() + large.top()) / 2.0;
        else
            return small.top();
    }

private:
    priority_queue<int, vector<int>, less<int>> small;
    priority_queue<int, vector<int>, greater<int>> large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main(){
    MedianFinder obj;

    obj.addNum(5);
    obj.addNum(1);
    obj.addNum(10);
    cout << obj.findMedian() << endl;
    return 0;
}
