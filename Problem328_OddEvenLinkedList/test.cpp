/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 23:40:59 2017
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0), *even = new ListNode(0);
        ListNode* odd_it = odd, *even_it = even;
        bool odd_bool = true;
        while(head!=NULL){
            if (odd_bool){
                odd_it->next = new ListNode(head->val);
                odd_it = odd_it->next;
                odd_bool = false;
            }
            else{
                even_it->next = new ListNode(head->val);
                even_it = even_it->next;
                odd_bool = true;
            }
            head = head->next;
        }
        odd_it->next = even->next;
        return odd->next;
    }
};

int main(){

    Solution s;
    vector<int> tmp { 2,1,4,3,6,5,7,8 };

    ListNode* h = createLinkedList(tmp);

    printLinkedList(h);
    ListNode* h_after = s.oddEvenList(h);
    printLinkedList(h_after);

    return 0;
}
