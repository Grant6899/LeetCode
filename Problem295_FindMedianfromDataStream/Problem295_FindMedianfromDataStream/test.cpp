#include<iostream>
#include<vector>

using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {
		heapLarge = vector<int>{};
		heapSmall = vector<int>{};
	}

	void addNum(int num) {
		double median = findMedian();

		if (num > median) {
			if (num > heapLarge.back())
				heapLarge.push_back(num);
			else
				heapLarge.insert(heapLarge.begin(), num);
		}


	}

	double findMedian() {
		if (countOdd())
			return heapSmall.back();
		else
			return (heapSmall.back() + heapLarge.back()) / 2.0;
	}

	bool countOdd() {
		return ( ( heapLarge.size() + heapSmall.size() ) % 2);
	}

private:
	vector<int> heapLarge, heapSmall;




};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/