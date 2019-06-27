#include <cstring>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>


using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ostream& operator<<(ostream& os, ListNode* tr) {
  os << "[";
  if (tr)
    os << tr->val;
  tr = tr->next;
  while (tr) {
    os << "," << tr->val;
    tr = tr->next;
  }
  os << "]";
  return os;
}

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node || !node->next) return;
        ListNode *n2 = node->next;
        node->val = n2->val;
        node->next = n2->next;
        delete n2;
    }
};

void test1() {
  Solution S;
  ListNode *n1 = new ListNode(4);
  n1->next = new ListNode(5);
  n1->next->next = new ListNode(1);
  n1->next->next->next = new ListNode(9);

  cout << n1 << endl;
  S.deleteNode(n1->next);
  cout << "remove 5? " << n1 << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}
