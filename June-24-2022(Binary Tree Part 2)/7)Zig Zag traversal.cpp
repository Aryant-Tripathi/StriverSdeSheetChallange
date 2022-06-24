/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/
#include<bits/stdc++.h>

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    if(root == NULL) return {};
    
    vector<int> ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    bool check = true;
    
    while(!q.empty())
    {
        int n = q.size();
        vector<int> temp;
        for(int i = 0; i < n; i++)
        {
            BinaryTreeNode<int>* curr = q.front();
            q.pop();
            
            temp.push_back(curr -> data);
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
        }
        
        if(check == false)
        {
            reverse(temp.begin(), temp.end());
        }
        
        for(int i = 0; i < temp.size(); i++)
            ans.push_back(temp[i]);
        
        check = !check;
    }
    
    return ans;
}

