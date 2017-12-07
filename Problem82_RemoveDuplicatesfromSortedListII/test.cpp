/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 23:25:18 2017
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = new ListNode(0);
        pre->next = head;

        ListNode* prev

    }
};

int main(){

    Solution s;
    vector<int> tmp { 1, 2, 2, 3, 3, 5, 6, 6 };

    ListNode* h = createLinkedList(tmp);

    printLinkedList(h);
    ListNode* h_after = s.deleteDuplicates(h);
    printLinkedList(h_after);

    return 0;
}
