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
void solve(TreeNode<int>* root, int& count, int& ans, int& k)
{
    if(root == NULL) return;
    solve(root -> right, count, ans, k);
    
    count++;
    if(k == count)
    {
        ans = root -> data;
        return;
    }
    
    solve(root -> left, count, ans, k);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int ans = -1, count = 0;
    solve(root, count, ans, k);
    return ans;
}

