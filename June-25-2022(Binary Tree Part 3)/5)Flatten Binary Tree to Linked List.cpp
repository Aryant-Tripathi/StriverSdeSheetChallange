/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root == NULL)
        return root;
    TreeNode<int>* L = flattenBinaryTree(root->left);
    TreeNode<int>* R = flattenBinaryTree(root->right);
    root->left = NULL;
    if(L == NULL)
    {
        root->right = R;
        return root;
    }
    else if(R == NULL)
    {
        root->right = L;
        return root;
    }
    else
    {
      root->right = L;
      while(L->right)
      {
        L = L->right;
      }
      L->right = R;
      return root;
    }
}