#include <ostream>
#include "IntList.h"

using namespace std;

// struct IntNode {
//     int data;
//     IntNode *next;
//     IntNode(int data) : data(data), next(0) {}
// };


// class IntList {

//  private:
//   IntNode *head;

//  public:
//   IntList();
//   void push_front(int);
//   friend ostream & operator<<(ostream &, const IntList &);
//   bool exists(int) const;

//  private:
//   bool exists(IntNode *, int) const;
// };

// ostream & operator<<(ostream &, IntNode *);

ostream & operator<<(ostream &out, const IntList &list) {
    /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
    */
   if (list.head != 0) {
       out << list.head->data;
       return (out << list.head->next);
   }
   else {
       return out;
   }
}

ostream & operator<<(ostream &out, IntNode *curr) {
    /* Helper function that passes in the address of a IntNode within an IntList and outputs
       all of integers within the IntList starting from this IntNode.
    */
    
    if (curr == 0) {
        return out;
    }
    else {
        out << " " << curr->data;
        return (out << curr->next);
    }
}

IntList::IntList() {
    head = 0;
}

void IntList::push_front(int value) {
    IntNode *temp = new IntNode(value);
    temp->next = this->head;
    this->head = temp;
}

bool IntList::exists(int value) const {
    /* Returns true if the integer passed in is contained within the IntList, 
      otherwise returns false.
    */
    
    return exists(head, value);
}

bool IntList::exists(IntNode *curr, int value) const {
   /* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in,
      otherwise returns false.
   */
   if (curr == 0) {
       return false;
   }
   if (curr->data == value) {
       return true;
   }
   else {
       return exists(curr->next, value);
   }
   
}
