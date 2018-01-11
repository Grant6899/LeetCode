#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
        if(len < 3)
            return 0;

        vector<int> heightLeft(len, 0), heightRight(len, 0);


        for(int i = 1; i < len; ++i)
            heightLeft[i] = max(height[i-1], heightLeft[i-1]);

        int sum = 0;
        for(int i = len - 2; i >= 1; --i){
            heightRight[i] = max(height[i+1], heightRight[i+1]);
            sum += max( min(heightLeft[i], heightRight[i]) - height[i], 0); 
        }
    return sum;
    }
};

int main() {
	Solution s;
	
	vector<int> h{ 1, 2, 1 };

	std::cout << s.trap(h) << std::endl;

	return 0;
}
