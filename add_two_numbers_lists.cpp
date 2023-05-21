/**
 * @file add_two_numbers_lists.cpp
 * @author your name (you@domain.com)
 * @brief We've to add 2 numbers given as linked lists. The nos are given in reverse. 
 * Going into infinite while loop - cannot find issue.
 * @version 0.1
 * @date 2023-05-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* A1= A;
    int n=0;
    while(A1 != NULL)
    {
        n++;
    }
    
    ListNode* B1= B;
    int m=0;
    while(B1 != NULL)
    {
        m++;
    }
    
    if(n>m)
    {
        return addTwoNumbers(B, A);
    }
    
    ListNode* start_A = A;
    ListNode* start_B = B; //will be output in reverse
    int x,carry=0;
    
    while(A!=NULL)
    {
        x = A->val + B->val + carry;
        B->val = x%10;
        carry = x/10;
        A = A->next; B= B->next;
    }
    
    ListNode* B_end;
    while(B!=NULL)
    {
        x = B->val+carry;
        B->val = x%10;
        carry = x/10;
        B= B->next;
    } //carry might still have some value
    
    vector<int> res;
    ListNode* B2= start_B;
    while(B2 !=NULL)
    {
        res.push_back(B2->val);
        B2 = B2->next;
    }
    res.push_back(carry);
    
    reverse(res.begin(),res.end());
    
    if(res.size()>m)
    {
        struct ListNode* start_B_new;
        start_B_new->val = carry;
        start_B_new->next = start_B;
        
        ListNode* B3 = start_B_new;
        for(int i=0;i<res.size();i++)
        {
            B3->val = res[i];
            B3 = B3->next;
        }
        
        return start_B_new;
    }
    else
    {
        ListNode* B3 = start_B;
        for(int i=0;i<res.size();i++)
        {
            B3->val = res[i];
            B3 = B3->next;
        }
    }
    
    return start_B;
}

int main()
{
    int s1,s2;
    int a[s1],b[s2];
    cin>>s1;
    for(int i=0;i<s1;i++)
    {
        cin>>a[i];
        struct ListNode* A;
        A->val = a[i];
        A->next = start_B;
    }

    cin>>s2;
    for(int i=0;i<s2;i++)
    {
        cin>>b[i];
    }

}
