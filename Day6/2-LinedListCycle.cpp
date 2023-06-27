/*Intuition:
We can solve this problem using two approaches:
1. Using HashTable.
2. Slow and Fast Pointer.

Approach 1:
Using HashTable : we need to track of all nodes we have visited till now once we visit the node again return 
true else false.
1. Use a Hashtable to store all nodes.
2. start iterating the LL.
3. If current node is present return true.
4. Else insert the node in the linked List.
5. In the end of the linked list return false when we get head is equal to NULL.

Complexity:
Time complexity: O(N);
N is length of the linked list

Space complexity: O(N)
Using Hashmap to store node.
*/

// Code:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        if(temp==NULL || temp->next==NULL){
            return false;
        }
        // Using hash table to keep track of nodes
        unordered_set<ListNode*> s;

        // Iterating on the linked list
        while(temp!=NULL){
            s.insert(temp);
            temp = temp->next;
            if(s.find(temp)!=s.end()){
                return true;
            }
            
        }
    return false;
    }
}

/* Approach 2:
Using slow and fast pointer.
1. Take two pointers slow and fast.
2. Move slow pointer by one node and fast pointer by two nodes.
3. If slow and fast pointer meet at some point then there is a cycle.
4. Else if fast pointer reaches NULL then there is no cycle.

Complexity:
Time complexity: O(N);
N is length of the linked list

Space complexity: O(1)
No extra space is used.
*/

// Code:
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
       ListNode * slow = head;
       ListNode *fast = head;
       while(fast->next != NULL && fast->next->next != NULL){
           slow = slow->next;
           fast = fast->next->next;
           if(slow==fast){
               return true;
           }
       }
    return false;
    }
};