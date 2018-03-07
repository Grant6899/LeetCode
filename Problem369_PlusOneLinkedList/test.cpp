/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Mar  7 17:28:19 2018
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
    ListNode* plusOne(ListNode* head) {
        ListNode* rev = reverseLinkedList(head);
        
        ListNode* cur = rev;
        cur->val += 1;
        
        //cout << cur->val << " " << cur->next->val << " " << cur->next->next->val << endl;
        
        int remain = cur->val / 10;
        while(remain){
            cur->val = cur->val % 10;
            //cout << cur->val << endl;
            if(!cur->next)
                cur->next = new ListNode(remain);
            else
                cur->next->val += remain;
            cur = cur->next;
            remain = cur->val / 10;
        }
        
        return reverseLinkedList(rev);
    }
    
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = nullptr;
        
        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head =temp;
        }
        return prev;
    }
    
};



int main(){
    
    Solution s;
    vector<int> tmp { 1, 2, 3, 4 };

    ListNode* h = createLinkedList(tmp);
    
    auto ans = s.plusOne(h);
    printLinkedList(ans);
    return 0;
}