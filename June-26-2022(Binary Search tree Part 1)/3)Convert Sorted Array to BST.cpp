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

TreeNode<int>* solve(int low, int high, vector<int> &arr)
{
    if(low > high) return NULL;
    
    int mid = low + (high - low) / 2;
    TreeNode<int>* node = new TreeNode<int>(arr[mid]);
    
    node -> left = solve(low, mid - 1, arr);
    node -> right = solve(mid + 1, high, arr);
    
    return node;
    
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return solve(0, n - 1, arr);
}