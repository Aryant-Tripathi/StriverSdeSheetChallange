/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

void inorder(BinaryTreeNode<int>* root, vector<int>& arr)
{
    if(root == NULL) return;
    
    inorder(root -> left, arr);
    arr.push_back(root -> data);
    inorder(root -> right, arr);
}

bool solve(vector<int>& arr, int target)
{
    int i = 0;
    int j = arr.size() - 1;
    
    while(i <= j)
    {
        int sum = arr[i] + arr[j];
        if(sum == target)
        {
            return true;
        }
        else if(sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    
    return false;
}

bool pairSumBst(BinaryTreeNode<int>* root, int target)
{
    // Write your code here
    // bst ka inorder sorted hota hai
    vector<int> arr; 
    inorder(root, arr);
    // now apply simply two sum two pointer
    
    return solve(arr, target);
}