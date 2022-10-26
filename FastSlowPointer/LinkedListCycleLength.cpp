//  Given the head of a LinkedList with a cycle, find the length of the cycle.

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

class LinkedListCycleLength {
 public:
  static int findCycleLength(ListNode *head) {
    ListNode *slow{head},*fast{head};
    int length{0};
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            // cycle found. Now set the slow pointer as a reference, do not move it. move fast pointer by one wntil
            // it meets the slow pointer again.            
            do{
                fast = fast->next;
                length++;
            }while(slow != fast);
            break;
        }
    }

    return length;    
  } 
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle length: " << LinkedListCycleLength::findCycleLength(head) << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle length: " << LinkedListCycleLength::findCycleLength(head) << endl;
}
