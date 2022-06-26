/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

void succecsor(BinaryTreeNode<int>* root, int key, int& succ)
{
    if(root == NULL) return;
    
    while(root != NULL)
    {
        if(key >= root -> data)
        {
            root = root -> right;
        }
        else
        {
            succ = root -> data;
            root = root -> left;
        }
    }
}

void predecessor(BinaryTreeNode<int>* root, int key, int& pred)
{
    if(root == NULL) return;
    
    while(root != NULL)
    {
        if(key > root -> data)
        {
            pred = root -> data;
            root = root -> right;
        }
        else
        {
            root = root -> left;
        }
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int succ = -1;
    succecsor(root, key, succ);
    int pred = -1;
    predecessor(root, key, pred);
    
    
    return {pred, succ};
}

