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

bool IsPresent(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
        
        if(slow == fast)
            return true;
    }
    
    return false;
}

Node *firstNode(Node *head)
{
    //    Write your code here.
    bool checkCycle = IsPresent(head);
    if(checkCycle == false)
        return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    do
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }while(slow != fast);
    
    fast = head;
    while(slow != fast)
    {
        slow = slow -> next;
        fast = fast -> next;
    }
    
    return slow;
}