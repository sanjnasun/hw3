#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  Node* temp = head->next;
  if(head == NULL)
  {
    smaller = nullptr;
    larger = nullptr;
    head = nullptr;
  }

  //temp = head;
  if (head->next->val <= pivot)
  {
    head->next = smaller;
    
    smaller = head;
  
  }
  else
  {
    head->next = larger;
    larger = head;
    //temp = temp->next;
  }

  head = temp;
  llpivot(head->next, smaller, larger, pivot);
  //head = NULL;

}