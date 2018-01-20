/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 21:08:53 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2, sum;
        
        while(l1 != NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int rem = 0, digit = 1;
        while(!(s1.empty() && s2.empty() && rem == 0)){
            
            if(!s1.empty() && s2.empty()){
                rem += s1.top();
                s1.pop();
            }
            else if(!s2.empty() && s1.empty()){
                rem += s2.top();
                s2.pop();
            }
            else if(!s1.empty() && !s2.empty()){
                rem += s1.top() + s2.top();
                s1.pop();
                s2.pop();
            }
            
            sum.push(rem % 10);
            rem /= 10;           
        }
        
        ListNode* res = new ListNode(0);
        
        ListNode* head = res;
        
        while(!sum.empty()){
            head->next = new ListNode(sum.top());
            head = head->next;
            sum.pop();
        }
        return res->next;    
    }
};

int main(){

    Solution s;
    vector<int> t1 {5}, t2{5};

    ListNode* h1 = createLinkedList(t1), *h2 = createLinkedList(t2);
    printLinkedList(s.addTwoNumbers(h1, h2));

    return 0;
}

