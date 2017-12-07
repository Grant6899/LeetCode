/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 19:58:52 2017
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;

        ListNode *p1 = head, *p2 = head, *meet = NULL;
        while(p1 != NULL && p1->next != NULL && p1->next->next != NULL){
            p1 = p1->next->next;
            p2 = p2->next;
            if (p1 == p2){
                meet = p1;
                break;
            }
        }
        
        if(meet != NULL){
            ListNode* entry = head;
            while(entry != meet){
                entry = entry->next;
                meet = meet->next;
            }
            return entry;
        }

        return NULL;     
    }
};



int main(){
    
    Solution s;
    vector<int> tmp { 1, 2, 3, 4, 5, 6 };

    ListNode* h = createLinkedList(tmp);
    printLinkedList(h);

    h->next->next->next->next->next = h->next->next;
    std::cout << s.detectCycle(h)->val << std::endl;

}
