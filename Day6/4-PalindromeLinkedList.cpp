/* Approach 1: Using Vector
    1. Traverse the linked list and store the values in a vector.
    2. Traverse the vector from both ends and check if the values are equal.
    3. If not equal, return false.

    Time Complexity  : O(n)
    Space Complexity : O(n)      
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->val);
            head = head->next;
        }
        for(int i=0;i<v.size()/2;i++) {
            if(v[i] != v[v.size()-i-1]){
               return false;
            } 
        }
        return true;
        
    }
};

/* Approach 2: Optimal Approach
    1. Find the middle of the linked list.
    2. Reverse the second half of the linked list.
    3. Traverse the first half and second half of the linked list and check if the values are equal.
    4. If not equal, return false.

    Time Complexity  : O(n)
    Space Complexity : O(1)      
*/  

class Solution {
  public:  
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        slow = slow->next;
        
        while(slow!=NULL){
            if(head->val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
}