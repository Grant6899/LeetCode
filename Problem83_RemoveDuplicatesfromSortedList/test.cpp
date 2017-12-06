/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 11:46:04 2017
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
        ListNode *st = head;
        while(st!=NULL && st->next !=NULL){
            if (st->val == st->next->val){
                ListNode *ed = st->next;
                while(ed != NULL && ed->val == st->val)
                    ed = ed->next;
                st->next = ed;
                st = ed;
            }
            else
                st = st->next;
        }
    return head;        
    }
};

int main(){

    Solution s;
    vector<int> tmp { 1, 2, 2, 3, 4,4,4,4 };


    ListNode* h = createLinkedList(tmp);
    printLinkedList(h);
    s.deleteDuplicates(h);
    printLinkedList(h);

    return 0;

}
