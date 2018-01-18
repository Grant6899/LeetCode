/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 17:04:21 2017
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

    ListNode* insertionSortList(ListNode* head) {
        ListNode* result = NULL;
        
        while(head != NULL){
            result = insert(result, head->val);
            head = head-> next;
        }

        return result;
    }

    ListNode* insert(ListNode* head, int newval){
        ListNode *tmp = new ListNode(newval);

        if (head == NULL)
            return tmp;
        else if (newval <= head->val){
            tmp->next = head;
            return tmp;
        }
        else{
            ListNode* ptr = head, *prev = new ListNode(0);
            prev->next = head;

            while(ptr != NULL && newval > ptr->val){
                ptr = ptr->next;
                prev = prev->next;
            }
            prev->next = tmp;
            tmp->next = ptr;
            return head;
        }
    }
};

int main(){

    Solution s;
    vector<int> tmp { 1,5,3,6,2,4,7 };

    ListNode* h = createLinkedList(tmp);
    printLinkedList(s.insertionSortList(h));

    return 0;
}
