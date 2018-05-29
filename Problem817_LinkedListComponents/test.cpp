/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Mon May 28 20:21:14 2018
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



ListNode * createList(vector<int> src)
{
	ListNode * nodePtr = NULL;
	ListNode * rootNodePtr = NULL;
	ListNode * lastNodePtr = NULL;
	for (auto it = src.begin(); it < src.end(); it++) {
		if (!nodePtr)
		{
			nodePtr = new ListNode(*it);
			if (!rootNodePtr)
				rootNodePtr = nodePtr;
			if (lastNodePtr)
				lastNodePtr->next = nodePtr;
		}
		lastNodePtr = nodePtr;
		nodePtr = nodePtr->next;
	}
	return rootNodePtr;
}

void PrintLinkedList(ListNode* head) {

	while (head) {
		std::cout << head->val << " ";
		head = head->next;
	}

}

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        vector<unordered_set<int>> neibor(10001);
        
        
        
        while(head->next){
            neibor[head->val].insert(head->next->val);
            neibor[head->next->val].insert(head->val);
            head = head->next;
        }
        
        vector<bool> visited(10001, 0);
        unordered_set<int> unvisited;
        
        for(int i : G)
            unvisited.insert(i);
        
        int res = G.size();
        
        for(int i : G)
            if(!visited[i])
                dfs(i, unvisited, neibor, res, visited);
        
        return res;
    }
    
    void dfs(int i, unordered_set<int>& unvisited, vector<unordered_set<int>>& neibor, int& res, vector<bool>& visited){
        visited[i] = true;
        
        for(int next : neibor[i])
            if(!visited[next] && unvisited.count(next)){
                res--;
                dfs(next, unvisited, neibor, res, visited);
            }
    }
};

int main() {
	Solution s;


	vector<int> head{ 0,1,2,3,4}, G{ 0, 3, 1, 4 };

	ListNode* head1 = createList(head);

	auto ans = s.numComponents(head1, G);

	cout << ans << endl;

	return 0;
}
