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
	ListNode* reverseList(ListNode* head) {

		ListNode* pre = NULL;
		while (head != NULL) {
			ListNode* temp = head->next;
			head->next = pre;
			pre = head;
			head = temp;
		}

		return pre;

	}
};


int main() {
	Solution s;


	vector<int> src1{ 1,3,4 }, src2{ 0 };

	ListNode* head1 = createList(src1);
	ListNode* head2 = createList(src2);

	auto ans = s.reverseList(head1);

	PrintLinkedList(ans);

	return 0;
}