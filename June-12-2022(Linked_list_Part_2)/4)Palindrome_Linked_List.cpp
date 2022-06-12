#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

// T.C --> O(n) && S.C --> O(1)
LinkedListNode<int>* reverse(LinkedListNode<int>* slow)
{
    LinkedListNode<int>* nextptr;
    LinkedListNode<int>* curr = slow;
    LinkedListNode<int>* prev = NULL;
    
    while(curr != NULL)
    {
        nextptr = curr -> next;
        curr -> next = prev;
        
        prev = curr;
        curr = nextptr;
    }
    
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int>* fast = head;
    LinkedListNode<int>* slow = head;
    
    // fast reached on last and slow reached on half
    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    slow = reverse(slow); // reverse right half 
    
    LinkedListNode<int>* temp = head;
    
    // now just check values
    while(slow != NULL)
    {
        if(head -> data != slow -> data)
            return false;
        
        head = head -> next;
        slow = slow -> next;
    }
    
    return true;
}