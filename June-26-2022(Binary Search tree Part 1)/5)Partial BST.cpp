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

bool solve(BinaryTreeNode<int> *root)
{
    if(root == NULL) return true;
    
    bool ans;
    if(root -> left)
    {
        if(root -> data < root -> left -> data)
            return false;
        else 
        {
            ans = solve(root -> left);
        }
    }
    else 
        ans = solve(root -> left);
    
    if(root -> right)
    {
        if(root -> data > root -> right -> data)
            return false;
        else
        {
            ans = ans && solve(root -> right);
        }
    }
    else ans = ans && solve(root -> right);
    
    return ans;
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    
    return solve(root);
}