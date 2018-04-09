/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  9 19:20:30 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for(int i = 0; i < points.size(); ++i)
            for(int j = i + 1; j < points.size(); ++j)
                for(int k = j + 1; k < points.size(); ++k){
                    double s1 = distance(points[i], points[j]), s2 = distance(points[i], points[k]), s3 = distance(points[j], points[k]);
					res = max(res, area(s1, s2, s3));
                }
        return res;
    }
    
	double distance(vector<int>& p1, vector<int>& p2){
		return sqrt( pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2) );
	}
	
	double area(double s1, double s2, double s3){
		double p = (s1 + s2 + s3) / 2.0;
		return sqrt(p * (p - s1) * (p - s2) * (p - s3));
	}
  
};

int main(){
    Solution s;
    vector<vector<int>> points{{0,0},{0,1},{1,0},{0,2},{2,0}};
    cout << s. largestTriangleArea(points) << endl;
    return 0;
}
