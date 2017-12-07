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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next ==NULL)
            return;
        
        ListNode* second = head->next;

        ListNode** ptr = &head, *prev = NULL;
        
        while((*ptr)->next != NULL){
            prev = *ptr;
            ptr =&(*ptr)->next;
        }

        head->next = *ptr;
        (*ptr)->next = second;
        prev->next = NULL;
        reorderList(second);
    }

    


};

int main(){

    Solution s;
    vector<int> tmp { 1,2};

    ListNode* h = createLinkedList(tmp);
    s.reorderList(h);
    printLinkedList(h);

    return 0;
}

