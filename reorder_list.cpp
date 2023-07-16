#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 
ListNode* find_last(ListNode* begin) //returns prev to last
{
    ListNode* x = begin;
    ListNode* prev;
    while( x->next != NULL )
    {
        prev=x;
        x = x->next;
    }
    return prev;
}
 
ListNode* reorderList(ListNode* A) {
    if(A==NULL) {return A;}
    if(A->next==NULL) {return A;}
    
    ListNode* start = A;
    int n=-1; // 0,1,2...n nodes
    while(A!=NULL)
    {
        n++;
        A = A->next;
    }
    if( n==1 ) {return start;}
    
    ListNode* B = start;
    int lim;
    if(n%2==0) 
    { 
        lim = (n/2)-1; 
        for(int i=0;i<=lim;i++)
        {
            ListNode* prev = find_last(B);
            ListNode* last = prev->next;
            last->next = B->next;
            B->next = last;
            prev->next = NULL;
            
            B = last->next;
        }
    }
    else
    {
        lim = (n-1)/2;
        for(int i=0;i<lim;i++) //reduce 1 iteration here
        {
            
            ListNode* prev = find_last(B);
            ListNode* last = prev->next;
            last->next = B->next;
            B->next = last;
            prev->next = NULL;
            
            B = last->next;
        }
    }
    
    return start;
}

int main()
{
    
}