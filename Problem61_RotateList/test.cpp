/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 14:28:53 2017
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
    int size(ListNode* head){
        int len = 0;
        while(head != NULL){
            head = head->next;
            ++len;
        }
        return len;    
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        int len = size(head);
        k = k % len;

        // connect tail and head of the List
        ListNode** endptr = &head;
        while((*endptr)->next != NULL)
            endptr = &(*endptr)->next;
        ListNode* end = *endptr;
        (*endptr)->next = head;
        
        // find new end and start nodes
        int move = len - k;
       
        for(;move>0;--move){
            end = end->next;
            head = head->next;
        }
        
        end->next = NULL;

        return head;
    }
};

int main(){

    Solution s;
    vector<int> tmp { 1 };

    ListNode* h = createLinkedList(tmp);

    printLinkedList(h);
    ListNode* h_after = s.rotateRight(h, 1);
    printLinkedList(h_after);

    return 0;
}
