/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode<int> *root) {
    // Write your code here.
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            BinaryTreeNode<int>* curr = q.front();
            q.pop();
            
            if(i == n - 1)
            {
                curr -> next = NULL;
            }
            else
            {
                curr -> next = q.front();
            }
            
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
        }
    }
}