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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode *c1 = l1, *c2 = l2;

		ListNode *result = NULL, *last = NULL, *temp = NULL;

		while (c1 || c2) {
			
			if (!c1) {
				if (!result)
					return c2;
				last->next = c2;
				return result;
			}

			if (!c2) {
				if (!result)
					return c1;
				last->next = c1;
				return result;
			}
				
			if (c1->val < c2->val) {
				temp = new ListNode(c1->val);
				c1 = c1->next;
			}
			else {
				temp = new ListNode(c2->val);
				c2 = c2->next;
			}
			
			if (!result)
				result = temp;

			if (last)
				last->next = temp;
			last = temp;
		}

		return result;
	}
};



int main() {
	Solution s;


	vector<int> src1{}, src2{0};

	ListNode* head1 = createList(src1);
	ListNode* head2 = createList(src2);


	auto ans = s.mergeTwoLists(head1, head2);

	PrintLinkedList(ans);


	return 0;
}