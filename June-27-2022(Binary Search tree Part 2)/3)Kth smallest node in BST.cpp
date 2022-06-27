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

void solve(TreeNode<int>* root, int& count, int& ans, int& k)
{
    if(root == NULL) return;
    solve(root -> left, count, ans, k);
    
    count++;
    if(k == count)
    {
        ans = root -> data;
        return;
    }
    
    solve(root -> right, count, ans, k);
}
int kthSmallest(TreeNode<int>* root, int k)
{
    //  Write the code here.
    int ans = 0, count = 0;
    solve(root, count, ans, k);
    return ans;
}