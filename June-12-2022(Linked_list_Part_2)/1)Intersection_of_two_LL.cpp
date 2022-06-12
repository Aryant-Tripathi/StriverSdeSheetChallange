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

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int ans = -1;
    
    Node* first = firstHead, *second = secondHead;
    
    while(first != second)
    {
        if(first == NULL)
        {
            first = secondHead;
        }
        else
        {
            first = first -> next;
        }
        
        if(second == NULL)
        {
            second = firstHead;
        }
        else
        {
            second = second -> next;
        }
    }
    
    if(first == NULL && second == NULL) return -1;
    
    return first -> data;
}