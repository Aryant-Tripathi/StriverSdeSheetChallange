/*****************************************************

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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool solve(BinaryTreeNode<int>* one, BinaryTreeNode<int>* two)
{
    if(one == NULL && two == NULL) return true;
    
    if(one == NULL || two == NULL) return false;
    
    if(one -> data != two -> data) return false;
    
    bool ans1 = solve(one -> left, two -> right);
    bool ans2 = solve(one -> right, two -> left);
    
    return ans1 && ans2;
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(root == NULL) return true;
    
    return solve(root -> left, root -> right);
}