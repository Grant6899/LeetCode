

#include <cstddef>
#include <vector>
#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* result = new ListNode(0);
		ListNode* p = result;
		int flag = 0;

		while (l1 != NULL || l2 != NULL || flag > 0) {

			int t1, t2;
			
			if (l1 == NULL) t1 = 0;
			else t1 = l1->val;
			
			if (l2 == NULL) t2 = 0;
			else t2 = l2->val;
			
			int temp = t1 + t2 + flag;
			
			flag = temp / 10;
			p->next = new ListNode(temp % 10);
			p = p->next;

			if (l1 != NULL) l1 = l1->next;
			if (l2 != NULL) l2 = l2->next;
		}
		return result->next;
	}
};

ListNode* generate(std::vector<int> src) {
	ListNode* result = new ListNode(0);

	ListNode* p = result;

	for (int i = 0; i < src.size(); ++i) {
		p->next = new ListNode(src[i]);
		p = p->next;
	}
	return result->next;
}

int main() {
	std::vector<int> v1{ 1, 8 }, v2{ 0 };

	ListNode* l1 = generate(v1);
	ListNode* l2 = generate(v2);
	
	Solution s;
	ListNode* x = s.addTwoNumbers(l1, l2);

	return 0;
}