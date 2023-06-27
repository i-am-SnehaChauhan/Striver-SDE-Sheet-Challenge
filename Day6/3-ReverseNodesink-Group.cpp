/*Approach 1: Iterative
    1. Reverse the first sub-list of size k. While reversing keep track of the next node and previous node.
    2. Let the pointer to the next node be next and pointer to the previous node be prev. head is the current 
       node being reversed and curr is the next node to be reversed.
    3. head->next = reverse(curr, k) ( Recursively call for rest of the list and link the two sub-lists )
    4. Return prev ( prev becomes the new head of the list (see the diagrams of iterative method of this post) )
    
    Time Complexity  : O(n)
    Space Complexity : O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    ListNode* reverse(ListNode* head, ListNode* temp){
        ListNode* prev = temp;
        ListNode* curr = head;
        ListNode* nxt = NULL;

        while(curr!=temp){
           nxt = curr->next;
           curr->next = prev;

           prev = curr;
           curr = nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        ListNode *temp = head;
        for(int i=0; i<k; i++) {
            if(!temp){
                return head;
            }
            temp = temp->next;
        } 
       auto newHead =  reverse(head, temp);
       head->next = reverseKGroup(temp,k);
       return newHead;
    }
};

/* Approach 2: Recursive
    1. Reverse the first sub-list of size k. While reversing keep track of the next node and previous node.
    2. Let the pointer to the next node be next and pointer to the previous node be prev. head is the current 
       node being reversed and curr is the next node to be reversed.
    3. head->next = reverse(curr, k) ( Recursively call for rest of the list and link the two sub-lists )
    4. Return prev ( prev becomes the new head of the list (see the diagrams of iterative method of this post) )
    
    Time Complexity  : O(n)
    Space Complexity : O(1)

*/
