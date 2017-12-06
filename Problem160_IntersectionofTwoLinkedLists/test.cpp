/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 11:49:10 2017
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB ==NULL)
            return NULL;

        ListNode* p1 = headA, *p2 = headB;
        while(p1 != NULL && p2 != NULL && p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
            
            if (p1 == p2)
                return p1;
            
            if (p1 == NULL)
                p1 = headB;
            if (p2 == NULL)
                p2 = headA;
        }
        return p1;
    }
};

int main(){
    
    Solution s;
    vector<int> tmp1 { 1, 2, 3, 4 }, tmp2 {5, 6};

    ListNode* h1 = createLinkedList(tmp1), *h2 = createLinkedList(tmp2);
    ListNode* p =  new ListNode(7);
    h1->next->next->next->next = p;
    h2->next->next = p;
    p->next = new ListNode(8);
    p->next->next = new ListNode(9);
    

    printLinkedList(h1);
    printLinkedList(h2);   
    std::cout << s.getIntersectionNode(h1, h2)->val << std::endl;
    
    return 0;
}

