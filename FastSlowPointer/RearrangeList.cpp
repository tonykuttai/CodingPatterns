/*
Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes 
from the second half of the LinkedList are inserted alternately to the nodes from the first half in 
reverse order. So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, 
your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.

Your algorithm should not use any extra space and the input LinkedList should be modified in-place.

Example 1:

Input: 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> null
Output: 2 -> 12 -> 4 -> 10 -> 6 -> 8 -> null 
Example 2:

Input: 2 -> 4 -> 6 -> 8 -> 10 -> null
Output: 2 -> 10 -> 4 -> 8 -> 6 -> null
*/

#include <iostream>
using namespace std;

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class RearrangeList {
 public:
  static void reorder(ListNode *head) {
    // 1. Find the middle of the List
    ListNode* middle = getMiddle(head);
    ListNode* nHead = middle->next;
    middle->next = nullptr;
    // 2. Reverse the second half from the middle node
    ListNode* rHead = reverse(nHead);
    // 3. Merge the two lists
    head = mergeLists(head,rHead);
  }
  private:
    static ListNode* mergeLists(ListNode* head1, ListNode* head2){
        ListNode* cur1{head1}, *cur2{head2}, *next1{nullptr}, *next2{nullptr};
        while(cur1){
            next1 = cur1->next;
            if(cur2){
                next2 = cur2->next;
                cur1->next = cur2;
                cur2->next = next1;
                cur1 = next1;
                cur2 = next2;
            }else{
                cur1->next = nullptr;
                cur1 = nullptr;
            }
        }
        return head1;
    }
    static ListNode* getMiddle(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode *slow{head}, *fast{head}, *pSlow{nullptr};
        while(fast && fast->next){
            pSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
            if(!fast){
                return pSlow;                
            }else if(!fast->next){
                return slow;
            }        
        }
        return nullptr; //This condition will not occur
    }
    static ListNode* reverse(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* cur{head}, *next{nullptr}, *prev{nullptr};
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;            
        }
        return prev; // the new head
    }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  RearrangeList::reorder(head);
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
}
