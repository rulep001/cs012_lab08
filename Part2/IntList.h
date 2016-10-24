#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <ostream>

using namespace std;

struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};

class IntList {

 private:
   IntNode *head;

 public:
   IntList();
   void push_front(int value);
   friend ostream & operator<<(ostream & out, const IntList &list);
   bool exists(int value) const;

 private:
   bool exists(IntNode *curr, int value) const;
};

ostream & operator<<(ostream & out, IntNode *curr);


#endif