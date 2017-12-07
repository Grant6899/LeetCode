/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 17:53:10 2017
 ************************************************************************/


#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int> vec){
    ListNode* head = NULL, *prev = new ListNode(0);

    for (auto it = vec.begin(); it < vec.end(); ++it){
        ListNode* newhead = new ListNode(*it);
        prev->next = newhead;
        prev = prev->next;
        if (it == vec.begin())
            head = prev;
    }
    return head;
}

void printLinkedList(ListNode* head){
    while(head != NULL){
        cout<< head->val <<" ";
        head = head->next;
    }
    std::cout << std::endl;
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
    
    ListNode* merge(ListNode* h1, ListNode*h2){
        if (h1 == NULL)
            return h2;
        if (h2 == NULL)
            return h1;
        
        ListNode* t1 = h1->next, *t2 = h2->next;        
        h1->next = h2;
        h2->next = merge(t1, t2);
        return h1;
    }

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next ==NULL)
            return;

        ListNode* p1 = head, *p2 = head, *prev = NULL;

        while(p2 != NULL && p2->next != NULL){
            prev = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        prev->next = NULL;
        
        ListNode* r_h2 = reverseList(p1);
        
        ListNode* temp = merge(head, r_h2);
        ListNode** pp = &head;
        *pp = temp;
    }

};

int main(){

    Solution s;
    vector<int> tmp { 1,2, 3, 4, 5};

    ListNode* h = createLinkedList(tmp);
    s.reorderList(h);
    printLinkedList(h);

    return 0;
}

