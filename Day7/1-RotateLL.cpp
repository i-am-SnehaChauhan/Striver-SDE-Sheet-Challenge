/* Approach 1: Brute Force.
We have to roatate the list k times. So, we can simply rotate the list one by one k times.
1. Create a function rotate() that takes head pointer and k as arguments.
2. If k is 0, then return.
3. Else, traverse the list till the end and change the next of last node to head.
4. Decrement k by 1.
5. Repeat the step until k is greater than 0.


Time Complexity: O(n*k)
Space Complexity: O(1)
*/

/*Approach 2: Efficient Approach.
We can make the list circular and then move k-1 steps forward from head node and make the next node as
head and break the link from the kth node.
1. Find the length of the list.
2. Make the list circular.
3. Break the link from the length-kth node.
4. if k is greater than length, then k = k%length.
5. Return the new head.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0){
            return head;
        }

        ListNode* temp = head;
        int length = 1;
        while(temp->next!=NULL){
            length++;
            temp = temp->next;
        }
        temp->next = head;
        k = k%length;
        int end = length-k;
        while(end--){
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
