/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar  8 18:43:37 2018
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

class Logger {
public:

    map<string, int> ok;
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < ok[message])
            return false;
        ok[message] = timestamp + 10;
        return true;
    }
};

int main(){
    Logger l;

    l.shouldPrintMessage(2, "2");
    return 0;
}
