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
		std::cout<<head->val<<" ";
		head = head->next;
	}

}



class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		if (!head->next)
			return NULL;

		int count = 0;
		auto t_head = new ListNode(0);
		t_head->next = head;
		auto current = t_head, remove_mark = t_head, remove_last = t_head;
		while (current) {
			current = current->next;
			count++;
			if (count > n + 1) 
				remove_last = remove_last->next;
		}

		remove_mark = remove_last->next;
		remove_last->next = remove_mark->next;

		return t_head->next;
	}
};




int main() {
	Solution s;


	vector<int> src{1, 2};

	ListNode* head = createList(src);
	

	auto ans = s.removeNthFromEnd(head, 2);
	PrintLinkedList(ans);


	return 0;
}