/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Sun Mar 25 17:36:50 2018
 ************************************************************************/

#include<iostream>
#include<unordered_set>
using namespace std;

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone pd. */
    PhoneDirectory(int maxNumbers) {
		for(int i = 0; i < maxNumbers; ++i)
			notused.insert(i);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(notused.empty())
			return -1;

        int temp = *notused.begin();
		notused.erase(temp);
		return temp;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return notused.count(number);
    }

    /** Recycle or release a number. */
    void release(int number) {
        notused.insert(number);
    }

private:
	unordered_set<int> notused;

};


int main(){
    PhoneDirectory pd(3);
    // It can return any available phone number. Here we assume it returns 0.
    pd.get();

     // Assume it returns 1.
    pd.get();

    // The number 2 is available, so return true.
    pd.check(2);

    // It returns 2, the only number that is left.
    pd.get();

    // The number 2 is no longer available, so return false.
    pd.check(2);

    // Release number 2 back to the pool.
    pd.release(2);

    // Number 2 is available again, return true.
    pd.check(2);
    return 0;
}
