/*************************************************************************
	> File Name: test.cpp
	> Author: Grant Liu
	> Mail: ymliu6899@gmail.com
	> Created Time: Thu Feb 15 08:04:05 2018
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _val) : val(_val), next(nullptr){}
};

void simulateProcess(int n, int k){
    int i = 0;
    k--;
    int kk = k % n;

    ListNode* head = new ListNode(i);

    ListNode* prev = head;

    for(int i = 1; i < n; ++i){
        prev -> next = new ListNode(i);
        prev = prev -> next;
    }
    prev -> next = head;
    
    while(prev->next != prev){
        
        for(int i = 0; i < kk; ++i)
            prev = prev->next;
        
        ListNode* todel = prev->next;
        cout << "Node " << todel->val << " deleted.\n";
        prev->next = prev->next->next;
        delete todel;
        
        n--;
        kk = k % n;
    }
    
    cout << "Node " << prev->val << " left.\n";
}


/*
以n=5, m=3为例，一开始有这么5个人：
0 1 2 3 4

第一轮报数后2号死亡，圈子里剩下来的人的编号是这些：
3 4 0 1

这里把3号写在最前面了，因为轮到3开始报数。如果我们有办法知道n=4时的答案，即初始圈子为：
0 1 2 3

时的答案，那么可以把n=4的初始圈子的所有数x变换成(x+3) mod 5，得到：
3 4 0 1
这个恰好就是n=5时第一轮结束后的圈子状态，也就是说我们可以根据n=4的答案推出n=5时的答案。
*/


int f(int n, int k){
    if(n == 1)
        return 0;

    return (f(n-1, k) + k) % n;
}


int main(){

    int n, k;
    printf("Please enter the total number n:\n");
    scanf("%d", &n);
    printf("Please enter the key value:\n");
    scanf("%d", &k);
    
    simulateProcess(n, k);
    
    cout << "\nRecursive result:\n" << f(n, k) << endl;
    return 0;
}
