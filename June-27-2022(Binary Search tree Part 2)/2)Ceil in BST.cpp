/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int target){
    // Write your code here.
    
    int ans = -1;
    while(root)
    {
        if(root -> data == target)
        {
            ans = root -> data;
            return ans;
        }
        else if(root -> data > target)
        {
            ans = root -> data;
            root = root -> left;
        }
        else
        {
            root = root -> right;
        }
    }
    
    return ans;
}