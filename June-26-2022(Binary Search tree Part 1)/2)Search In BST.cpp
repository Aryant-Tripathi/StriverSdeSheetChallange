/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root == NULL) return false;
    
    if(root -> data == x) return true;
    
    bool ans;
    if(x > root -> data)
        ans = searchInBST(root -> right, x);
    else 
        ans = searchInBST(root -> left, x);
    
    return ans;
    
}