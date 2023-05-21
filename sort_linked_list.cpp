#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int main()
{
    ListNode* A;

    ListNode* A1 = A;
    ListNode* A2= A;
    int zero_count=0,one_count=0;
    
    while(A1->next!=NULL)
    {
        if(A1->val==0) {zero_count++;}
        if(A1->val==1) {one_count++;}
        A1 = A1->next;
    }
    for(int i=1;i<=zero_count;i++)
    {
        A2->val = 0;
        A2 = A2->next;
    }
    for(int i=1;i<one_count;i++)
    {
        A2->val=1;
        A2 = A2->next;
    }
    
    return A;

}