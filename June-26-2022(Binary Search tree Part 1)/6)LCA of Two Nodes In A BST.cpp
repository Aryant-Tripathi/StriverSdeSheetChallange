/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* solve(TreeNode<int>* root, 
                     TreeNode<int>* one, TreeNode<int>* two)
{
    if(root == NULL)
        return root;
    
    int currData = root -> data;
    
    if(currData < one -> data && currData < two -> data)
    {
        return solve(root -> right, one, two);
    }
    
    if(currData > one -> data && currData > two -> data)
    {
        return solve(root -> left, one, two);
    }
    
    return root;
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    // Write your code here
    return solve(root, P, Q);
}




// SIMPLE LCA (TLE)
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

//************************************************************

TreeNode<int>* solve(TreeNode<int>* root, 
                     TreeNode<int>* one, TreeNode<int>* two)
{
    if(root == NULL || root == one || root == two)
        return root;
    
    TreeNode<int>* left = solve(root -> left, one, two);
    TreeNode<int>* right = solve(root -> right, one, two);
    
    if(left == NULL && right == NULL)
        return NULL;
    
    if(left != NULL && right == NULL)
        return left;
    
    if(left == NULL && right != NULL)
        return right;
    
    if(left != NULL && right != NULL)
        return root;
    
    return root;
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    // Write your code here
    return solve(root, P, Q);
}
 */
