/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:53:45 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
		return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while(begins.size()){
			if(begins.top() == ends.top()){
				begins.pop();
				ends.pop();
			}
			else{
				auto x = begins.top();
				if(x->isInteger())
					return true;
				begins.top()++;
				begins.push(x->getList().begin());
				ends.push(x->getList().end());
			}
		}
		return false;
    }
private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};

int main(){
    
}
