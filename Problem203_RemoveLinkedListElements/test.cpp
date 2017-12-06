/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 12:02:52 2017
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
    ListNode *removeElements(ListNode* head, int val) {
        ListNode **hptr = &head;

        while(*hptr != NULL){
            if ((*hptr)->val == val){
                    // change the pointer itself saved in ListNode, make the pointer pointed by hptr point to next Node's next Node
                    *hptr = (*hptr)->next;
            }
            else{
                // make hptr point to next pointer saved in ListNode
                hptr = &(*hptr)->next;
            }
           
        }
        return head;
    }
};


int main(){

    Solution s;
    vector<int> tmp { 1, 2, 6, 3, 4, 5, 6 };

    ListNode* h = createLinkedList(tmp);

    printLinkedList(h);
    ListNode* h_after = s.removeElements(h, 6);
    printLinkedList(h_after);

    return 0;
}


