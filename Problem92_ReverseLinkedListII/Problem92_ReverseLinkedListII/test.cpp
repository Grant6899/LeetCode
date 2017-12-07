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
    
    
    ListNode* reverseList(ListNode* head){
        ListNode* pre = NULL;
		while (head != NULL) {
			ListNode* temp = head->next;
			head->next = pre;
			pre = head;
			head = temp;
		}

		return pre;
    }
    
    
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n)
			return head;

		if (m > n)
			swap(m, n);
		
        
        ListNode *pre = new ListNode(0);
        pre->next = head;
		ListNode *p_m = head, *p_n = head, *pre_m = pre, *pre_n = pre;

		int iteration = 1;
		while (iteration <= n) {
			if (iteration > n - m + 1) {
				pre_m = p_m;
				p_m = p_m->next;
			}
			pre_n = p_n;
			p_n = p_n->next;
			iteration++;
		}
       
        pre_n->next = NULL; 
        ListNode* reversed = reverseList(p_m);
        pre_m->next = reversed;
        while(reversed->next != NULL)    
            reversed = reversed->next;
        reversed->next = p_n;

		return pre->next;
	}
};

int main() {
	Solution s;


	vector<int> src1{ 1,2,3,4,5 }, src2{ 0 };

	ListNode* head1 = createList(src1);
	ListNode* head2 = createList(src2);

	auto ans = s.reverseBetween(head1, 1, 5);

	PrintLinkedList(ans);

	return 0;
}
