#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* moveA = first;
    Node<int>* moveB = second;
    Node<int>* prehead = new Node<int>(-1);
    Node<int>* head;
    head = prehead;
    
    
    while(moveA != NULL && moveB != NULL)
    {
        if(moveA -> data <= moveB -> data)
        {
           // Node<int>* newNode = new Node<int>(moveA -> data);
            head -> next = moveA;
            moveA = moveA -> next;
        }
        else 
        {
           // Node<int>* newNode = new Node<int>(moveB -> data);
            head -> next = moveB;
            moveB = moveB -> next;
        }
        head = head -> next;
    }
    
    if(moveA != NULL)
    {
        head -> next = moveA;
    }
    
    if(moveB != NULL)
    {
        head -> next = moveB;
    }
    
    return prehead -> next;
}

