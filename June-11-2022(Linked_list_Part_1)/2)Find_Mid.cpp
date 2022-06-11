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

int GetLength(Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head -> next;
    }
    
    return count;
}
Node *findMiddle(Node *head) {
    // Write your code here
    int len = GetLength(head);
    
    Node* ans = head;
    if(!(len & 1))
    {
        int mid = (len / 2) + 1;
        int count = 0;
        while(count < mid - 1)
        {
            count++;
            ans = ans -> next;
        }
    }
    else
    {
        int mid = (len / 2);
        int count = 0;
        while(count < mid)
        {
            count++;
            ans = ans -> next;
        }
        
            
    }
    
    return ans;
}