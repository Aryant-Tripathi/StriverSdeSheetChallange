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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    // Write your code here.
    if(head == NULL || k == 0)
        return head;
    
    LinkedListNode<int> *prehead = new LinkedListNode<int>(-1);
    prehead -> next = head;
    LinkedListNode<int>* fast = prehead, *slow = prehead;
    
    while(k--)
        fast = fast -> next;
    
    while(fast -> next != NULL)
    {
        fast = fast -> next;
        slow = slow -> next;
    }
    
    LinkedListNode<int>* toDelete = slow -> next;
    slow -> next = slow -> next -> next;
    delete toDelete;
    
    return prehead -> next;
}