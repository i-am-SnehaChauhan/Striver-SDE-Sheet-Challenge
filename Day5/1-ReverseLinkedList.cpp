/*Approach 1: Iterative
  i. We will use three-pointers to traverse through the entire list and 
  interchange links between nodes. 
  ii. One pointer to keep track of the current node in the list. 
  The second one is to keep track of the previous node to the current node 
  and change links. Lastly, a pointer to keep track of nodes in front of 
  current nodes.

  Time Complexity: O(N)
  Space Complexity: O(1)
*/


#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    LinkedListNode<int> *cur = head;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *temp;

    while(!cur==NULL){
      temp = cur->next;
      cur->next = prev;

      prev = cur;
      cur = temp;
    }
    head = prev;
    return head;
}

/*Approach 2: Using Recursion
 i. Once we call a function to reach the end of the list, we get a reversed
    list except for the first node and second node.
 ii. Then we link node B to node A and node A to NULL.

 Time Complexity: O(N)
  Space Complexity: O(N)

*/
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
     if (head == NULL || head->next == NULL) {
        return head;
    }

    LinkedListNode<int> *nNode = reverseLinkedList(head->next);

    head->next->next = head;
    head->next = NULL;
    return nNode;
}