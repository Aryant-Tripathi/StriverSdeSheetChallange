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

int ans;
int solve(TreeNode<int>* root)
{
    if(root == NULL)
        return 0;
    
    int lh = solve(root -> left);
    int rh = solve(root -> right);
    
    ans = max(ans, lh + rh);
    
    return max(lh, rh) + 1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    ans = 0;
    solve(root);
    return ans;
}

