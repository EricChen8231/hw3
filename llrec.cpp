#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    if (head == nullptr){
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    llpivot(head->next, smaller, larger, pivot);
    if (head->val <= pivot){
        if (smaller == nullptr){
            smaller = head;
            smaller->next = nullptr;
            head = nullptr;
        }
        else{
            head->next = smaller;
            smaller = head;
            head = nullptr;
        }
    }
    else {
        if (larger == nullptr)
        {
            larger = head;
            head->next = nullptr;
            head = nullptr;
        }
        else
        {
            head->next = larger;
            larger = head;
            head = nullptr;
        }
    }
}
