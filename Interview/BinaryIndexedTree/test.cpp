/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon Apr  9 21:25:23 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class NumArray {
    private:
        vector<int> _nums;
        vector<int> bit;
        
        int lower_bit(int i){
            return i&-i;
        }
        
        int query(int i){
            i++; // important
            int sum=0;
            while(i>0){
                sum+=bit[i];
                i-=lower_bit(i);
            }
            return sum;
        }
        
        void add(int i, int val){
            i++;// important
            while(i<bit.size()){
                bit[i]+=val;
                i+=lower_bit(i);
            }
        }
        
    public:
        NumArray(vector<int> &nums) : _nums(nums) {
            bit.resize(nums.size()+1);
            for(int i=0; i<nums.size(); i++){
                add(i, nums[i]);
            }
        }
    
        void update(int i, int val) {
            if(val!=_nums[i]){
                add(i, val-_nums[i]);
                _nums[i]=val;
            }
        }
    
        int sumRange(int i, int j) {
            return query(j)-query(i-1);
        }
    };
int main(){
    vector<int> nums{0,9,5,7,3};

    NumArray bit(nums);
    cout << bit.sumRange(0, 0) << endl;
    cout << bit.sumRange(4, 4) << endl;
    cout << bit.sumRange(2, 4) << endl;
    cout << bit.sumRange(3, 3) << endl;
    bit.update(4, 5);
    bit.update(1, 7);
    bit.update(0, 8);
    cout << bit.sumRange(1, 2) << endl;
    bit.update(1, 9);
    cout << bit.sumRange(4, 4) << endl;
    bit.update(3, 4);
    return 0;
}
