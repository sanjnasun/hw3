#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

// void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
// {
//   Node* temp = head->next;
//   if(head == NULL)
//   {
//     smaller = nullptr;
//     larger = nullptr;
//     //head = nullptr;
//     return;
//   }

//   //temp = head;
//   llpivot(head->next, smaller, larger, pivot);
//   if (head->val <= pivot)
//   {
//     head->next = smaller;
//     smaller = head;
//     //head = head->next;
//     head = nullptr;
//   }
//   else
//   {
//     head->next = larger;
//     larger = head;
//     //head = head->next;
//     head = nullptr;
//   }

//   //head = temp;
//   //llpivot(head->next, smaller, larger, pivot);
//   //head = NULL;

// }


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    llpivot(head->next, smaller, larger, pivot);

    if (head->val <= pivot) {
        head->next = smaller;
        smaller = head;
    } else {
        head->next = larger;
        larger = head;
    }

    
    head = nullptr;
}
