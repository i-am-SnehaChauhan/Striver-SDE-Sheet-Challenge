/*Approach:: Using HashTable
    1. Traverse the list one by one and keep putting the node address in a Hash Table. 
    2. At any point, if NULL is reached then return false and if next of current node points to any of the previously stored nodes in Hash then return true.
    
    Time Complexity  : O(n) 
    Space Complexity : O(n)

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        unordered_set<ListNode *> s;
        while(head!=NULL){
            if(s.find(head)!=s.end()){
                return head;
            }
            s.insert(head);
            head = head->next;
        }
    return NULL;
    }
};