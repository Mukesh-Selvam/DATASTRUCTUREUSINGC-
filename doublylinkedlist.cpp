#include<bits/stdc++.h>
using namespace std;
typedef struct _dnode
{
	int data;
	struct _dnode* next;
	struct _dnode* prev;
} DNode;
DNode* createNode(int data)
{
	DNode* nd = new DNode;
	nd->data = data;
	nd->next=NULL;
	nd->prev = NULL;
	return nd;
}
void insertAtEnd(DNode** first, int data)
{
	DNode* nd =createNode(data);
	if(*first==NULL)
	{
		*first = nd;
		return;
	}
	DNode* curr =*first;
	while(curr->next)
		curr = curr->next;
	curr->next= nd;
	nd->prev = curr;
}
void insertAtBeginning(DNode** first, int data)
{
	DNode* nd = createNode(data);
	nd->next = *first;
	if(*first != NULL)
		(*first)->prev = nd;
	*first = nd;
}
void insertAtPos(DNode** first, int data, int pos)
{
	DNode* nd =createNode(data);
	DNode* curr = *first;
	for(int i=1; i<=pos-1; i++) 
	     curr = curr->next;
	nd->next = curr->next;
	nd->prev =curr;
	if(curr->next)
		curr->next->prev =nd;
	curr->next = nd;
}
void deleteFromBeginning(DNode** first)
{
	if(*first == NULL)
		return;
	*first = (*first)->next;
	if(*first)
		(*first)->prev = NULL;
}
void deleteFromEnd(DNode** first)
{
	if(*first == NULL)
		return;
	DNode* curr =*first;
	if(curr->next== NULL)
	{
		*first = NULL;
		return;
	}
	while(curr->next->next !=NULL) curr = curr->next;
	curr->next = NULL;
}
void deleteFromPos(DNode** first, int pos)
{
	if(*first == NULL)
		return;
	DNode* curr = *first;
	for(int i=1; i<=pos-1; i++)
		curr = curr->next;
	DNode* toDelete = curr->next;
	if(toDelete ==NULL)
		return;
	curr->next = toDelete->next;
	if(toDelete->next)
		toDelete->next->prev = curr;
} 
void displayLL(DNode** first)
{
	DNode* curr = *first;
	while(curr)
	{
		cout << curr->data << " ";
		     curr = curr->next;
	}
	cout << endl;
}
int main()
{
	DNode* head = NULL;
	insertAtEnd(&head,100);
	insertAtEnd(&head,56);
	insertAtEnd(&head,45);
	insertAtEnd(&head,66);
	insertAtEnd(&head,44);
	displayLL(&head);
	insertAtBeginning(&head,77);
	displayLL(&head);
	insertAtPos(&head, 123,3);
	displayLL(&head);
	deleteFromBeginning(&head);
	displayLL(&head);
	deleteFromEnd(&head);
	displayLL(&head);
	deleteFromPos(&head,3);
	displayLL(&head);
}