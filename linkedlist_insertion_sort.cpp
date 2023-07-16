// C++ program to sort link list
// using insertion sort
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedlistIS {

public:
	ListNode* head;
	ListNode* sorted;

	void push(int val)
	{
		/* allocate ListNode */
		ListNode* newListNode = new ListNode(val);
		/* link the old list of the new ListNode */
		newListNode->next = head;
		/* move the head to point to the new ListNode */
		head = newListNode;
	}

	// function to sort a singly linked list using insertion
	// sort
	void insertionSort(ListNode* headref)
	{
		// Initialize sorted linked list
		sorted = NULL;
		ListNode* current = headref;
		// Traverse the given linked list and insert every
		// ListNode to sorted
		while (current != NULL) {
			// Store next for next iteration
			ListNode* next = current->next;
			// insert current in sorted linked list
			sortedInsert(current);
			// Update current
			current = next;
		}
		// Update head_ref to point to sorted linked list
		head = sorted;
	}

	/*
	* function to insert a new_node in a list. Note that
	* this function expects a pointer to head_ref as this
	* can modify the head of the input linked list
	* (similar to push())
	*/
	void sortedInsert(ListNode* newListNode)
	{
		/* Special case for the head end */
		if (sorted == NULL || sorted->val >= newListNode->val) {
			newListNode->next = sorted;
			sorted = newListNode;
		}
		else {
			ListNode* current = sorted;
			/* Locate the ListNode before the point of insertion
			*/
			while (current->next != NULL
				&& current->next->val < newListNode->val) {
				current = current->next;
			}
			newListNode->next = current->next;
			current->next = newListNode;
		}
	}
	/* Function to print linked list */
	void printlist(ListNode* head)
	{
		while (head != NULL) {
			cout << head->val << " ";
			head = head->next;
		}
	}
};
// Driver program to test above functions
int main()
{
	LinkedlistIS list;
	list.head = NULL;
	list.push(5);
	list.push(20);
	list.push(4);
	list.push(3);
	list.push(30);
	cout << "Linked List before sorting" << endl;
	list.printlist(list.head);
	cout << endl;
	list.insertionSort(list.head);
	cout << "Linked List After sorting" << endl;
	list.printlist(list.head);
}

// This code is contributed by nirajgusain5
