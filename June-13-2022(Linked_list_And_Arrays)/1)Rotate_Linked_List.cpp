#include <bits/stdc++.h> 
/********************************

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

********************************/

int LengthOfLinkedList(Node* head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head -> next;
    }
    
    return len;
}

Node *rotate(Node *head, int k) {
     // Write your code here.
    int length = LengthOfLinkedList(head);
    
    k = k % length;
    Node* ForLast = head;
    while(ForLast -> next != NULL)
    {
        ForLast = ForLast -> next;
    }
    
    int count = 0;
    Node* ToPutNuLL = head;
    
    while(count < (length - k - 1))
    {
        ToPutNuLL = ToPutNuLL -> next;
        count++;
    }
    
    ForLast -> next = head;
    Node* ToReturnAnswer = ToPutNuLL -> next;
    ToPutNuLL -> next = NULL;
    
    return ToReturnAnswer;
}