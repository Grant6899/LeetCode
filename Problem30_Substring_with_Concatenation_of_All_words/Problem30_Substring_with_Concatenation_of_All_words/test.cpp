#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {

	}
};


int main() {
	Solution s;


	vector<int> src1{}, src2{ 0 };

	ListNode* head1 = createList(src1);
	ListNode* head2 = createList(src2);


	auto ans = s.mergeTwoLists(head1, head2);

	PrintLinkedList(ans);


	return 0;
}