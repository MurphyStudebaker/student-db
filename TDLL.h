#include "TNode.h"
using namespace std;
/** A template class of a Doubly Linked List */
template <class T> class TDLL {
private:
TNode<T>* head;
TNode<T>* tail;
public:
  TDLL(); // constructor
  ~TDLL(); // destructor
  bool isEmpty() const;
  T& front();
  T& back();
  void addFront(const T& e);
  void addBack(const T& e);
  void removeFront();
  void removeBack();
  void add(TNode<T>* v, const T& e);
  void remove(TNode<T>* v);
};
template <class T>
TDLL<T>::TDLL() {
  head = new TNode<T>;
  tail = new TNode<T>;
  head->next = tail;
  tail->prev = head;
}
template <class T>
TDLL<T>::~TDLL() {
  while (!isEmpty())
    removeFront();
  delete head;
  delete tail;
}
template <class T>
bool TDLL<T>::isEmpty() const
{ return (head->next == tail); }
template <class T>
T& TDLL<T>::front()
{ return head->next->data; }
template <class T>
T& TDLL<T>::back()
{ return tail->prev->data; }
template <class T>
void TDLL<T>::add(TNode<T>* v, const T& e) {
  TNode<T>* u = new TNode<T>;
  u->data = e;
  u->next = v;
  u->prev = v->prev;
  v->prev->next = v->prev = u;
}
template <class T>
void TDLL<T>::addFront(const T& e)
{ add(head->next, e); }
template <class T>
void TDLL<T>::addBack(const T& e)
{ add(tail, e); }
template <class T>
void TDLL<T>::remove(TNode<T>* v) {
  TNode<T>* u = v->prev;
  TNode<T>* w = v->next;
  u->next = w;
  w->prev = u;
  delete v;
}
template <class T>
void TDLL<T>::removeFront()
{ remove(head->next); }
template <class T>
void TDLL<T>::removeBack()
{ remove(tail->prev); }
