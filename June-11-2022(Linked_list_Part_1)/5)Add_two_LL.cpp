#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    int carry = 0;
    Node* prehead = new Node(-1);
    Node* head = prehead;
    
    while(head1 != NULL && head2 != NULL)
    {
        int sum = head1 -> data + head2 -> data + carry;
        
        if(sum >= 10) carry = 1;
        else carry = 0;
        
        sum = sum % 10;
        
        Node* newNode = new Node(sum);
        head -> next = newNode;
        head = head -> next;
        
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    
    while(head1 != NULL)
    {
        int sum = head1 -> data + carry;
        
        if(sum >= 10) carry = 1;
        else carry = 0;
        
        sum = sum % 10;
        Node* newNode = new Node(sum);
        head -> next = newNode;
        head = head -> next;
        head1 = head1 -> next;
    }
    
    while(head2 != NULL)
    {
        int sum = head2 -> data + carry;
        
        if(sum >= 10) carry = 1;
        else carry = 0;
        
        sum = sum % 10;
        Node* newNode = new Node(sum);
        head -> next = newNode;
        head = head -> next;
        head2 = head2 -> next;
    }
    
    if(carry)
    {
        Node* newNode = new Node(1);
        head -> next = newNode;
        head = head -> next;
    }
    
    return prehead -> next;
}