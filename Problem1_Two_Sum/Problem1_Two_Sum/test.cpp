

#include <vector>
#include <unordered_map>
#include <iostream>
//
//class Solution {
//public:
//	std::vector<int> twoSum(std::vector<int> &numbers, int target) {
//		
//		std::vector<int> result;
//		std::unordered_map<int, int> hash;
//
//		for (int i = 0; i < numbers.size(); ++i) {
//			int tofind = target - numbers[i];
//
//			if (hash.find(tofind) != hash.end()) {
//				result.push_back(hash[tofind]);
//				result.push_back(i);
//				return result;
//			}
//			else hash[numbers[i]] = i;
//		}
//		return result;
//	}
//	
//
//};
//
//template<typename T>
//void print(std::vector<T> v) {
//	for (auto it = v.begin(); it < v.end(); ++it)
//		std::cout << *it << ' ';
//}

/*std::vector<int> vec{ 4, 3, 10, 15 };

Solution s;
print(s.twoSum(vec, 14));
*/


int main() {


	int n = 0;
	while (n < 10) {
		n = n++;
	}

	std::cout << n << std::endl;
	return 0;

}