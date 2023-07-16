// C++ code for linked list merged sort
#include <bits/stdc++.h>
using namespace std;

// Link list Node
// class Node {
// public:
//    int data;
//    Node *next;
// };

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Merging the sorted linked list.
ListNode* mergeSortedList(ListNode* list1, ListNode* list2) {
   // a result pointer that will point the merged list.
   ListNode* result = NULL;

   // handling the base cases
   if (list1 == NULL)
      return (list2);
   else if (list2 == NULL)
      return (list1);

   // recursively merging two sorted lists
   if (list1->val <= list2->val) {
      result = list1;
      result->next = mergeSortedList(list1->next, list2);
   }
   else {
      result = list2;
      result->next = mergeSortedList(list1, list2->next);
   }

   // returning the merged sorted list.
   return result;
}

// Splitting the linked list into halves.
void splitListIntoHalves(ListNode* source, ListNode** front, ListNode** back) {
   ListNode *pointer1;
   ListNode *pointer2;
   pointer2 = source;
   pointer1 = source->next;

   // we will use the two pointer technique to get the halves of the original linked list.
   while (pointer1 != NULL) {
      pointer1 = pointer1->next;
      if (pointer1 != NULL) {
         pointer2 = pointer2->next;
         pointer1 = pointer1->next;
      }
   }

   // pointer2 will point at the mid point.
   *front = source;
   *back = pointer2->next;
   pointer2->next = NULL;
}

// a function that will sort the linked list.
void mergeSort(ListNode **node) {
   ListNode *head = *node;
   ListNode *pointer1;
   ListNode *pointer2;

   // handling the base cases.
   if ((head == NULL) || (head->next == NULL))
      return;

   // Splitting linked list into smaller halves.
   splitListIntoHalves(head, &pointer1, &pointer2);

   // Recursively sorting the divided linked list.
   mergeSort(&pointer1);
   mergeSort(&pointer2);

   // let the head pointer now point to the sorted linked list.
   *node = mergeSortedList(pointer1, pointer2);
}

// a function to traverse and print the linked list.
void printList(ListNode *head) {
   while (head != NULL) {
      cout << head->val << " ";
      head = head->next;
   }
}

// insertNode function will create a new node and insert the newly created node at the last.
void insertNode(ListNode **head, int newData) {
   ListNode *newNode = new ListNode(newData);
   newNode->next = (*head);
   (*head) = newNode;
}

int main() {
   // an empty linked list.
   ListNode *l = NULL;

   insertNode(&l, 12);
   insertNode(&l, 2);
   insertNode(&l, 1);
   insertNode(&l, 15);

   // printing the linked list before sorting.
   cout << "Original Linked list: " << endl;
   printList(l);

   // sorting the linked list.
   mergeSort(&l);

   // printing the linked list after sorting.
   cout << "\nSorted Linked list: " << endl;
   printList(l);

   return 0;
}