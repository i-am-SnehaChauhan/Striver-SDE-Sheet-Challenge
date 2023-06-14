/*Approach 1: Naive Approach
i. First find out toal no. of nodes.
ii. Finally, we traverse through the first n/2 elements of the list and 
    return the pointer of the middle element of the linked list.

    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the number of elements in the linked list
*/

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    if(head==NULL || head->next==NULL){
        return head;
    }

    // first check No. of Nodes 
    Node *temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }

    // Move at Middle Node and make it head 
    temp = head;
    int n = count/2;

    for(int i = 1; i <= n; i++) {
        temp = temp->next;
    }
    head = temp;
    return head;

}

/*Approach 2: Tortoise-Hare-Approach
i. We will 


*/