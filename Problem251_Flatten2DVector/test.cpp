/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Mar 22 19:34:26 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Vector2D {
    vector<vector<int>>::iterator i, iEnd;
    int j = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iEnd = vec2d.end();
    }

    int next() {
        hasNext();
        return (*i)[j++];
    }

    bool hasNext() {
        while (i != iEnd && j == (*i).size())
            i++, j = 0;
        return i != iEnd;
    }
};

int main(){
    vector<vector<int>> v{{1, 2}, {3},{4,5,6}};
    Vector2D a(v);
    while(a.hasNext())
        cout << a.next() << endl;
    return 0;
}
