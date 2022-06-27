/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
class BSTiterator
{
    public:
    stack<TreeNode<int>*> s;
    void push_left(TreeNode<int> *root)
    {
        while(root != NULL)
        {
            s.push(root);
            root = root -> left;
        }
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        push_left(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int>* top = s.top();
        s.pop();
        
        int ans = top -> data;
        if(top -> right != NULL)
        {
            push_left(top -> right);
        }
        
        return ans;
    }

    bool hasNext()
    {
        // write your code here
        return !s.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/