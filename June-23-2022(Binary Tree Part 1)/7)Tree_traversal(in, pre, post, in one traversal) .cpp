/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

/*IDEA: 
1) we will use stack pair. // {node, number}

    if(number == 1) 
    {
        preorder;
        ++;
        left;
    }
    else if(number == 2)
    {
        inorder;
        ++;
        right;
    }
    else if(number == 3)
    {
        postorder
    }
    
    T.C --> O(3 * n)
    S.c --> O(4 * n) use stack
   */

#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    if(root == NULL) return {};
    vector<int> in, pre, post;
    stack<pair<BinaryTreeNode<int>*, int>> s;
    
    s.push({root, 1});
    
    while(!s.empty())
    {
        pair<BinaryTreeNode<int>*, int> curr = s.top();
        s.pop();
        
        BinaryTreeNode<int>* node = curr.first;
        int number = curr.second;
        
        if(number == 1)
        {
            pre.push_back(node -> data);
            number++;
            
            s.push({node, number});
            
            if(node -> left)
            {
                s.push({node -> left, 1});
            }
        }
        else if(number == 2)
        {
            in.push_back(node -> data);
            number++;
            
            s.push({node, number});
            
            if(node -> right)
            {
                s.push({node -> right, 1});
            }
        }
        else if(number == 3)
        {
            post.push_back(node -> data);
        }
    }
    
    vector<vector<int>> ans;
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    
    return ans;
}