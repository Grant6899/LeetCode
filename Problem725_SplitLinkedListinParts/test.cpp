/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Dec  7 09:06:46 2017
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
    int size(ListNode* head){
        int result = 0;
        while(head!=NULL){
            ++result;
            head = head->next;
        }
        return result;
    }

    vector<int> group(ListNode* root, int k){
        int len = size(root);
        vector<int> result(k, len / k);
        int res = len % k;

        auto it = result.begin();
        while(res > 0 && it < result.end()){
            ++*it;
            --res;
            it++;
        }
        return result;
    }

    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> result;
        vector<int> parts = group(root, k);
        
        for (auto it_len = parts.begin(); it_len < parts.end();++it_len){
            ListNode* pre = new ListNode(0);
            pre->next = root;
            int kk = *it_len;
            
            if (kk == 0){
                result.push_back(NULL);
                continue;
            }

            result.push_back(root);
            while(kk > 0){
                pre = root;
                root = root->next;
                --kk;
            }
            pre->next = NULL;
        }
    
        return result;
    }
};

int main(){

    Solution s;
    vector<int> tmp {};

    ListNode* h = createLinkedList(tmp);

    printLinkedList(h);
    vector<ListNode*> r = s.splitListToParts(h, 3);

 //   printLinkedList(r[0]);
 //   printLinkedList(r[1]);
 //   printLinkedList(r[2]);
    return 0;
}
