/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Mar 20 22:18:12 2018
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        _head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* sample = _head, *cur = _head;
		int idx = 0;
		while(cur->next){
			cur = cur->next;
			idx++;
			int r = rand() % (idx + 1);
			if(r < 1)
				sample = cur;
		}
		return sample->val;
    }
private:
	ListNode* _head;
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution solution = Solution(head);
    cout << solution.getRandom() << endl;
    return 0;
}
