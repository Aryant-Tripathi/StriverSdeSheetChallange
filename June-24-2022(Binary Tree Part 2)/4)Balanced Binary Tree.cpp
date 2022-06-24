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

bool check;
int solve(BinaryTreeNode<int>* root)
{
    if(root == NULL) return 0;
    
    int lh = solve(root -> left);
    int rh = solve(root -> right);
    
    if(abs(lh - rh) > 1)
    {
        check = false;
    }
    
    return max(lh, rh) + 1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    check = true;
    solve(root);
    return check;
}