/*
Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square of all of its digits, leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck in a cycle of numbers which does not include ‘1’.

Example 1:

Input: 23   
Output: true (23 is a happy number)  
Explanations: Here are the steps to find out that 23 is a happy number:
23(4+9) --->13(1+9)-->10(1+0)--->1

Example 2:

Input: 12   
Output: false (12 is not a happy number)  
Explanations: Here are the steps to find out that 12 is not a happy number:
12(1+4)-->5(25)-->25(4+25)-->29(4+81)-->85(64+25)-->89(64+81)-->145(1+16+25)-->42(16+4)-->20(4+0)-->4(16)-->16(1+36)-->37(9+49)-->58(25+64)-->89
Step ‘13’ leads us back to step ‘5’ as the number becomes equal to ‘89’, this means that we can never reach ‘1’, therefore, ‘12’ is not a happy number.

Solution#
The process, defined above, to find out if a number is a happy number or not, always ends in a cycle.
If the number is a happy number, the process will be stuck in a cycle on number ‘1,’ and if the number is not a happy number 
then the process will be stuck in a cycle with a set of numbers. As we saw in Example-2 while determining if ‘12’ is a happy 
number or not, our process will get stuck in a cycle with the following numbers: 89 -> 145 -> 42 -> 20 -> 4 -> 16 -> 37 -> 58 -> 89

We saw in the LinkedList Cycle problem that we can use the Fast & Slow pointers method to find a cycle among a set of elements. 
As we have described above, each number will definitely have a cycle. Therefore, we will use the same fast & slow pointer strategy 
to find the cycle and once the cycle is found, we will see if the cycle is stuck on number ‘1’ to find out if the number is happy or not.
*/
#include <iostream>
using namespace std;
class HappyNumber {
    public:
        static bool find(int num) {
            int slow{num},fast{num};
            do{
                slow = findSumSquareDigits(slow);
                fast = findSumSquareDigits(findSumSquareDigits(fast));
            }while(slow != fast);
            return slow == 1;
        }
    private:
        static int findSumSquareDigits(int number){
            int sumOfSquares = 0;
            int digit{0};
            while(number > 0){
                digit = number % 10;
                number /= 10;
                sumOfSquares += digit*digit;
            }
            return sumOfSquares;
        }

};

int main(int argc, char* argv[]) {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
}