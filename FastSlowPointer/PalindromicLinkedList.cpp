/*
Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.

Your algorithm should use constant space and the input LinkedList should be in the original form once the algorithm is finished. The algorithm should have 
O(N)time complexity where ‘N’ is the number of nodes in the LinkedList.

Example 1:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
Output: true
Example 2:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
Output: false
Solution#
As we know, a palindrome LinkedList will have nodes values that read the same backward or forward. 
This means that if we divide the LinkedList into two halves, the node values of the first half in the 
forward direction should be similar to the node values of the second half in the backward direction. 
As we have been given a Singly LinkedList, we can’t move in the backward direction. To handle this, we will perform the following steps:

We can use the Fast & Slow pointers method similar to Middle of the LinkedList to find the middle node of the LinkedList.
Once we have the middle of the LinkedList, we will reverse the second half.
Then, we will compare the first half with the reversed second half to see if the LinkedList represents a palindrome.
Finally, we will reverse the second half of the LinkedList again to revert and bring the LinkedList back to its original form.
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

class PalindromicLinkedList {
 public:
  static bool isPalindrome(ListNode *head) {
    if(!head || !head->next){
        return true;
    }
    ListNode* slow{head},*prevSlow{head},*fast{head};
    bool result{false};
    while(fast && fast->next){
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
        if(!fast){
            // slow will point to the second middle element of the list.
            // reverse the second half of the list
            ListNode* rHead = reverseList(slow->next);
            slow->next = nullptr;
            ListNode* tHead{head};
            result = compareLists(tHead,rHead);
            slow->next = reverseList(rHead);
            break;
        }else if(!fast->next){
            // slow will be at the middle of the list.
            // reverse the second half of the list
            ListNode* rHead = reverseList(slow->next);
            prevSlow->next = nullptr;
            ListNode* tHead{head};
            result = compareLists(tHead,rHead);
            slow->next = reverseList(rHead);
            prevSlow->next = slow;
            break;            
        }
    }
    return result;
  }
  private:
  static bool compareLists(ListNode* head1,ListNode* head2){
    ListNode* cur1{head1}, *cur2{head2};
        while(cur1 && cur2){
            if(cur1->value == cur2->value){
                cur1 = cur1->next;
                cur2 = cur2->next;
            }else{
                return false;
            }
        }
        if(!cur1 && !cur2){
            return true;
        }
        return false;
              
  }
  static ListNode* reverseList(ListNode* head){
    ListNode* cur{head},*next{nullptr},*prev{nullptr};
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}
