#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        sums = vector<int>(nums.size() + 1);
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            sums[i + 1] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
    
    vector<int> sums;
};

int main() {
	
	vector<int> nums{ -2, 0, 3, -5, 2, -1 };

	NumArray obj(nums);
	int param_1 = obj.sumRange(2, 3);

	std::cout << param_1 << std::endl;

	return 0;
}
