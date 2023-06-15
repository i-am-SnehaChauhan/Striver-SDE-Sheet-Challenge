/* Approach 1: Two pointer Approach
Time Complexity: O(N)
Space Complexity: O(1) 

*/

Node *removeKthNode(Node *head, int n) {
  Node *start = new Node();
  start->next = head;
  Node *fast = start;
  Node *slow = start;

  for (int i = 1; i <= n; ++i)
    fast = fast->next;

  while (fast->next != NULL) {
    fast = fast->next;
    slow = slow->next;
  }

  slow->next = slow->next->next;

  return start->next;
}
