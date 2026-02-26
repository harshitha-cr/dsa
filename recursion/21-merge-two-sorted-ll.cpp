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

// Too complicated to keep track of pointers
/*

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
  ListNode *curr1 = list1;
  ListNode *curr2 = list2;

  // merging list2 to list1 and if either one gets exhausted, attach remaining to other.
  while (curr1 && curr2)
  {
    // assuming curr2 is smaller than curr1, then swaps are req, too complicated
    if (curr2->val >= curr1->val)
    {

      // adjust pointers of curr2 to point to curr1->next & curr1 to point to curr2
      curr2->next = curr1->next;
      curr1->next = curr2;

      curr1 = curr1->next;
    }
  }
}
*/
