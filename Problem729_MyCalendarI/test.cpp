/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 19:49:27 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class MyCalendar {
    map<int, int> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound(s); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
        if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
        books[s] = e;
        return true;
    }
};

int main(){
    MyCalendar c;
    cout << c.book(10, 20) << endl;
    cout << c.book(15, 20) << endl;
    cout << c.book(20, 30) << endl;
    return 0;
}
