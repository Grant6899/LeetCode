/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Fri Jan 19 22:47:20 2018
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* right = reverseLinkedList(slow);
        
        while(head != nullptr && right != nullptr){
            if(head->val != right->val)
                return false;
            head = head->next;
            right = right->next;
        }
        
        return true;
    }
    
private:
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = nullptr;
        while(head != nullptr){
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};

int main(){

    Solution s;
    vector<int> tmp { 1,5,3,6,2,4,7 };

    ListNode* h = createLinkedList(tmp);
    cout << s.isPalindrome(h) << endl;

    return 0;
}
