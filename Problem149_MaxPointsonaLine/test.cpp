/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Dec 15 18:49:32 2017
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        
        if (points.size() <= 2)
            return points.size();

        int result = 0;
        for (int i = 0; i < points.size() - 1; ++i){
            
            unordered_map<pair<int, int>, int> book;
            int vertical = 0, dup = 0, current_max = 0;
            for (int j = i + 1; j < points.size(); ++ j){
                if (points[i].x == points[j].x){
                    if(points[i].y == points[j].y){
                        ++dup;
                        continue;
                    }
                    else
                        ++vertical;
                }
                else{
                    int a = points[i].x - points[j].x, b = points[i].y - points[j].y;
                    int gc = gcd(a,b);
                    a/=gc;
                    b/=gc;
                    ++book[make_pair(a, b)];
                    current_max = max(current_max, book[make_pair(a, b)]);                    
                }
                current_max = max(vertical, current_max);
            } 
            result = max(result, current_max + dup + 1);
        }
    return result;
    }

private:
    int gcd(int a, int b) {        
        if(b==0) return a;
        else return gcd(b, a%b);
    }
};

int main(){

    vector<Point> set { Point(0, 0), Point(1, 1), Point(1, 2), Point(2, 1), Point(2, 2) };
    Solution s;
    cout << s.maxPoints(set) << endl;
    return 0;
}
