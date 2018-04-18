using namespace std;
template <class T>
class TNode {
public:
  T data;
  TNode* next;
  TNode* prev;
  TNode(T val)
  {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
  TNode()
  {
    next = nullptr;
    prev = nullptr;
  }
  ~TNode()
  {
    next = nullptr;
    prev = nullptr;
  }
};
