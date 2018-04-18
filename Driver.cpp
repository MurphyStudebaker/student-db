#include "BST.h"
#include <string>
using namespace std;

int main ( )
{
  BST<int> tree;
  tree.insert(30, 88);
  tree.insert(45, 77);
  tree.insert(15, 108);
  tree.printTree();
}
