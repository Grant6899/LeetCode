#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<numeric>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode **pp = &head, *a, *b; //pp points to the head pointer to the pair
		while ((a = *pp) && (b = a->next)) {
			a->next = b->next;
			b->next = a;
			*pp = b;     
			pp = &(a->next);
		}
		return head;
	}
};

void print(ListNode* head) {
	ListNode* ptr = head;
	while (ptr) {
		std::cout << ptr -> val << "->";
		ptr = ptr->next;
	}
}

ListNode* readFromVec(std::vector<int> src) {
	ListNode* result = new ListNode(0);
	ListNode* ptr = result;
	
	for (int i = 0; i < src.size(); i++) {
		ptr->next = new ListNode(src[i]);
		ptr = ptr->next;
	}

	return result;
}

int main() {
	Solution s;
	std::vector<int> vec{ 1,2,3,4 };
	auto head = readFromVec(vec);
	auto ans = s.swapPairs(head->next);
	print(ans);
	return 0;
}