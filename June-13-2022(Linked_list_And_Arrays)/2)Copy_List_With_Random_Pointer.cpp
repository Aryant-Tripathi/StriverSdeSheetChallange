#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

// https://www.youtube.com/watch?v=VNf6VynfpdM
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    
    // 1) Making a copy node
    LinkedListNode<int>* move = head;
    LinkedListNode<int>* nextptr = head;
    
    while(move != NULL)
    {
        nextptr = move -> next;
        
        LinkedListNode<int>* CopyNode = 
            new LinkedListNode<int>(move -> data);
        
        move -> next = CopyNode;
        CopyNode -> next = nextptr;
        
        move = nextptr;
    }
    
    // 2) Assigning Copy nodes to their Random Pointer
    move = head;
    while(move != NULL)
    {
        if(move -> random != NULL)
        move -> next -> random = move -> random -> next;
        else
            move -> next -> random = NULL;
        
        move = move -> next -> next;
    }
    
    // 3) Seperating copy nodes from original nodes
    move = head;
    nextptr = head;
    
    LinkedListNode<int>* prehead = new LinkedListNode<int>(-1);
    LinkedListNode<int>* ToMoveInCopy = prehead;
    
    while(move != NULL)
    {
        nextptr = move -> next -> next;
        
        ToMoveInCopy -> next = move -> next;
        move -> next = nextptr;
        
        ToMoveInCopy = ToMoveInCopy -> next;
        move = nextptr;
    }
    
    return prehead -> next;
}

