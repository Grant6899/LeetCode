/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Wed Dec  6 22:07:27 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = NULL;
        
        while(head != NULL){
            insertBST(root, head->val);
            head = head->next;
        }

        return root;
    }

    void insertBST(TreeNode* root, int val){
        if (root == NULL){
            root = new TreeNode(val);
            return;
        }
        else if(val < root->val)
            insertBST(root->left, val);
        else
            insertBST(root->right, val);
    }

};

int main(){

    Solution s;
    vector<int> t1 {-10,-3,0,5,9};

    ListNode* h1 = createLinkedList(t1);
    auto result = s.sortedListToBST(h1);
    
    return 0;
}


