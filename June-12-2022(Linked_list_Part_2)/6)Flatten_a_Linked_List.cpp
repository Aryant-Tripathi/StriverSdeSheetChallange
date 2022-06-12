#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

*****************************************************************/

Node* merge(Node* first, Node* second)
{
    if(first == NULL)
    {
        return second; 
    }
    
    if(second == NULL)
    {
        return first;
    }
    
    Node* answer = NULL;
    if(first -> data <= second -> data)
    {
        answer = first;
        answer -> child = merge(first -> child, second);
    }
    else
    {
        answer = second;
        answer -> child = merge(first, second -> child);
    }
    
    answer -> next = NULL;
    
    return answer;
}
Node* flattenLinkedList(Node* head) 
{
    // Write your code here
    if(head == NULL || head -> next == NULL)
        return head;
    
    return merge(head, flattenLinkedList(head -> next));
}

