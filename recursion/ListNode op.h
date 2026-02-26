#include <iostream>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  ListNode()
  {
    this->val = 0;
    this->next = nullptr;
  }

  ListNode(int n)
  {
    this->val = n;
    this->next = nullptr;
  }

  ListNode(int n, ListNode *next)
  {
    this->val = n;
    this->next = next;
  }
};