/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int target)
{
    // Write your code here.
    int ans = 0;
    while(root)
    {
        if(root -> val == target)
        {
            ans = root -> val;
            return ans;
        }
        else if(root -> val > target)
        {
            root = root -> left;
        }
        else 
        {
            ans = root -> val;
            root = root -> right;
        }
    }
    
    return ans;
}