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

int RemainingNodes(Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head -> next;
    }
    
    return count;
}
Node* solve(int i, Node* head, int arr[], int& n)
{
    if(head == NULL) return head;
    if(i >= n) return head;
    
//     if(RemainingNodes(head) < arr[i])
//     {
//         return reverseAllFromHere(head);
//     }
    if(arr[i] == 0) return solve(i + 1, head, arr, n);
    int group = arr[i];
    int count = 0;
    Node* nextptr;
    Node* curr = head;
    Node* prev = NULL;
    
    while(curr != NULL && count < group)
    {
        nextptr = curr -> next;
        curr -> next = prev;
        
        prev = curr;
        curr = nextptr;
        count++;
    }
    
    if(nextptr != NULL)
    {
        head -> next = solve(i + 1, nextptr,  arr, n);
    }
    
    return prev;
}
Node *getListAfterReverseOperation(Node *head, int n, int arr[]){
    // Write your code here.
    if(head == NULL )
        return head;
    
    return solve(0, head, arr, n);
}