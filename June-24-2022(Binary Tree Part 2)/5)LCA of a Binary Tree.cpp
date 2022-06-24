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

TreeNode<int>* solve(TreeNode<int> *root, int x, int y)
{
    if(root == NULL || root -> data == x || root -> data == y)
    {
        return root;
    }
    
    TreeNode<int>* left = solve(root -> left, x, y);
    TreeNode<int>* right = solve(root -> right, x, y);
    
    if(left == NULL && right == NULL)
    {
        return NULL;
    }
    
    if(left != NULL && right == NULL)
    {
        return left;
    }
    
    if(left == NULL && right != NULL)
    {
        return right;
    }
    
    if(left != NULL && right != NULL)
    {
        return root;
    }
    
    return root;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    TreeNode<int>* ans = solve(root, x, y);
    
    return ans -> data;
}