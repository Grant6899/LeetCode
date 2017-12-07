/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 16:29:58 2017
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

    ListNode* merge(ListNode* h1, ListNode* h2){
        if (h1 == NULL)
            return h2;
        if (h2 == NULL)
            return h1;
        
        if (h1->val < h2->val){
            h1->next = merge(h1->next, h2);
            return h1;
        }
        else{
            h2->next = merge(h1, h2->next);
            return h2;
        }
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* prev = head, *p1 = head, *p2 = head;

        while(p2 != NULL && p2->next != NULL){
            prev = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        prev->next = NULL;

        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(p1);

        return merge(h1, h2);
    }
};

int main(){

    Solution s;
    vector<int> tmp { 1,5,3,6,2,4,7 };

    ListNode* h = createLinkedList(tmp);
    printLinkedList(s.sortList(h));

    return 0;
}
