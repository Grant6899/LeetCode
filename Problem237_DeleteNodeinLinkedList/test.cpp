/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Tue Dec  5 20:43:50 2017
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
    void deleteNode(ListNode* node) {
        // note that it's based on the assumption that we are not deleting the tail node.
        *node = *(node->next);
    }
};


int main(){

    Solution s;
    vector<int> tmp { 1, 2, 3, 4 };

    ListNode* h = createLinkedList(tmp);

    printLinkedList(h);
    s.deleteNode(h->next->next);
    printLinkedList(h);
}

