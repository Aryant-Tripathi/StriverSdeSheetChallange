/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
        { 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
unordered_map<int,int> mp;
    
TreeNode<int>* make_tree(int start, int end, int& make_root, vector<int>& postorder, vector<int>& inorder)
    {
        // If range for inorder is NOT valid then return NULL
        if(start > end)
            return NULL;
        
        // Create a node for our root node of current subtree
        TreeNode<int>* root = new TreeNode<int>
            (postorder[make_root]);
        
        // Find position of current root in inorder array
        int i = mp[root -> data];
        
        // Decrement our pointer to postorder array for our next upcoming root if any
        make_root--;
        
        // Make a call to create right subtree, inorder range [i+1, end]
        root -> right = make_tree(i + 1, end, make_root, postorder, inorder);
        
        // Make a call to create left subtree, inorder range [start, i-1]
        root -> left = make_tree(start, i - 1, make_root, postorder, inorder);
        
        return root;
    }

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
    // Write your code here.
    int make_root = postorder.size() - 1;
        
        // Create (nodes -> index of inorder array) mapping
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        
        return make_tree(0, inorder.size() - 1, make_root, postorder, inorder);
}

