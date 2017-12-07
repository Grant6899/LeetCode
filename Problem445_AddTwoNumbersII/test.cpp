/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 21:08:53 2017
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = reverseList(l1);
        ListNode* n2 = reverseList(l2);
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;
        int d_sum = 0, res = 0;

        while(n1 != NULL || n2 != NULL || res > 0){
            int i1 = 0, i2 = 0;
            
            if(n1 != NULL)
                i1 = n1->val;
            if(n2 != NULL)
                i2 = n2->val;
    
            d_sum = i1 + i2 + res;
            res = d_sum / 10;
            d_sum = d_sum % 10;
            ptr->next = new ListNode(d_sum);
            ptr = ptr->next;
            
            if(n1 != NULL)
                n1 = n1->next;
            if(n2 != NULL)
                n2 = n2->next;


        }
        return reverseList(result->next);
    }
};

int main(){

    Solution s;
    vector<int> t1 { 7,2,4,3}, t2{5,6,4};

    ListNode* h1 = createLinkedList(t1), *h2 = createLinkedList(t2);
    printLinkedList(s.addTwoNumbers(h1, h2));

    return 0;
}

