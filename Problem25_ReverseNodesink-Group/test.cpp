/*************************************************************************
> File Name: test.cpp
> Author: Grant Liu
> Mail: ymliu6899@gmail.com
> Created Time: Wed Dec  6 22:07:27 2017
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int> vec) {
	ListNode* head = NULL, *prev = new ListNode(0);
	for (auto it = vec.begin(); it < vec.end(); ++it) {
		ListNode* newhead = new ListNode(*it);
		prev->next = newhead;
		prev = prev->next;
		if (it == vec.begin())
			head = prev;
	}
	return head;
}

void printLinkedList(ListNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
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

	bool check(ListNode* head, int k, ListNode*& tail) {
		ListNode* prev = head;

		while (head != NULL && k >0) {
			prev = head;
			head = head->next;
			--k;
		}
		if (k > 0)
			return false;
		else {
			tail = prev;
			return true;
		}
	}

	ListNode* reverseKGroup(ListNode* head, int k) {

		ListNode* ptr = head, *pre = new ListNode(0), *tail = NULL;
		pre->next = head;
		ListNode* pre_cp = pre;

		while (ptr != NULL && check(ptr, k, tail)) {
			ListNode* temp = tail->next;
			tail->next = NULL;
			ListNode* reversed = reverseList(ptr);
			pre->next = reversed;
			ptr->next = temp;
			pre = ptr;
			ptr = temp;
		}

		return pre_cp->next;
	}

};

int main() {

	Solution s;
	vector<int> t1{ 1,2,3,4,5};

	ListNode* h1 = createLinkedList(t1);
	printLinkedList(s.reverseKGroup(h1, 1));

	return 0;
}
