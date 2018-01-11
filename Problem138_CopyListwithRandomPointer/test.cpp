/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Jan 10 20:29:15 2018
 ************************************************************************/

#include<iostream>
#include<unordered_map>
using namespace std;


//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> map;
        
        RandomListNode* new_head = new RandomListNode(0), *cur = head, *prev = new_head, *new_cur;

        while(cur!=NULL){
            new_cur = new RandomListNode(cur->label);
            map[cur] = new_cur;
            prev->next = new_cur;
            prev = new_cur;
            cur = cur->next;
        }

        new_cur = new_head->next;
        cur = head;
        while(new_cur!=NULL){
            new_cur->random = map[cur->random];
            cur = cur->next;
            new_cur = new_cur->next;
        }

        return new_head->next;
    }
};

int main(){
    
    RandomListNode *head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    head->next->next->next = new RandomListNode(4);
    head->next->next->next->next = new RandomListNode(5);
    head->next->next->next->next->next = nullptr;

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head->next->next->next;
    
    Solution s;

    RandomListNode* new_head = s.copyRandomList(head);
    
    return 0;
}
