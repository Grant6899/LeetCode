#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<unordered_map>

using namespace std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



ListNode * createList(vector<int> src)
{
	ListNode * nodePtr = NULL;
	ListNode * rootNodePtr = NULL;
	ListNode * lastNodePtr = NULL;
	for (auto it = src.begin(); it < src.end(); it++) {
		if (!nodePtr)
		{
			nodePtr = new ListNode(*it);
			if (!rootNodePtr)
				rootNodePtr = nodePtr;
			if (lastNodePtr)
				lastNodePtr->next = nodePtr;
		}
		lastNodePtr = nodePtr;
		nodePtr = nodePtr->next;
	}
	return rootNodePtr;
}

void PrintLinkedList(ListNode* head) {

	while (head) {
		std::cout << head->val << " ";
		head = head->next;
	}

}



class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == nullptr) {
			return l2;
		}
		if (l2 == nullptr) {
			return l1;
		}
		if (l1->val <= l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {

		if (lists.size() == 0)
			return NULL;

		ListNode* result = lists[0];

		for (int i = 1; i < lists.size(); i++) {
			result = mergeTwoLists(result, lists[i]);
		}

		return result;
	}
};



int main() {
	Solution s;


	vector<int> src1{1,3,4}, src2{ 0 };

	ListNode* head1 = createList(src1);
	ListNode* head2 = createList(src2);

	vector<ListNode*> vec{ };

	auto ans = s.mergeKLists(vec);

	PrintLinkedList(ans);

	return 0;
}