/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Dec  7 00:45:22 2017
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0), *more = new ListNode(0);
        ListNode* less_it = less, *more_it = more;
        while(head!=NULL){
            if (head->val < x){
                less_it->next = new ListNode(head->val);
                less_it = less_it->next;
            }
            else{
                more_it->next = new ListNode(head->val);
                more_it = more_it->next;
            }
            head = head->next;
        }
        less_it->next = more->next;
        return less->next;
    }
};

int main(){

    Solution s;
    vector<int> tmp { 1,4,3,2,5,2 };

    ListNode* h = createLinkedList(tmp);

    printLinkedList(h);
    ListNode* h_after = s.partition(h, 3);
    printLinkedList(h_after);

    return 0;
}
