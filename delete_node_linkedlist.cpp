#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//insert node at beginning of LL
void push_ll(ListNode* head_ref, int new_data)
{
    // 1. allocate node, put in data
    ListNode* new_node = new ListNode(new_data);
 
    // 3. Make next of new node as head
    new_node->next = head_ref;
 
    // 4. Move the head to point to
    // the new node
    head_ref = new_node;
}

void insertAfter_ll(ListNode* prev_node, int new_data)
{
    // 1. Check if the given prev_node is NULL
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
 
    // 2. Allocate new node, Put in the data
    ListNode* new_node = new ListNode(new_data);
    
 
    // 4. Make next of new node as next of prev_node
    new_node->next = prev_node->next;
 
    // 5. move the next of prev_node as new_node
    prev_node->next = new_node;
}

ListNode* delete_node_ll(ListNode* head, int position)
{
    ListNode* temp = head;
    ListNode* prev = head;
    for(int i = 0; i < position; i++)
    {
        if(i == 0 && position == 1)
        {
            head = head->next;
            free(temp);
        }
        else
        {
            if (i == position - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;
                if(prev == NULL) // position was greater than number of nodes in the list
                { break; }
                temp = temp->next; 
            }
        }
    }
    
    return head;
}

void append_ll(ListNode* head_ref, int new_data)
{
    // 1. allocate node, put data, next=NULL by constructor defn
    ListNode* new_node = new ListNode(new_data);

    // 4. If the Linked List is empty, then make the new node as head
    if (head_ref == NULL) {
        head_ref = new_node;
        return;
    }
 
    // Used in step 5
    ListNode* last = head_ref;
    // 5. Else traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }
 
    // 6. Change the next of last node
    last->next = new_node;
    return;
}

int main()
{
    ListNode* head_ref = new ListNode(1);
   
    for(int i=2;i<=7;i++)
    {
        append_ll(head_ref,i);
    }
    ListNode* A= head_ref;
    while(A!=NULL) 
    {
        cout<<A->val<<" ";
        A=A->next;
    }
}