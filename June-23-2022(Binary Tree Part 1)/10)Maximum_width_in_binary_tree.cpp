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

//Test cases passed only by getting maximum no of node at the level.
//while it should have been the maximum distance between two nodes at any level

// kch bhi question hai, pucho kch, nikalwao kch

int mx;
void solve(TreeNode<int>* root, int left, int right)
{
    if(root == NULL)
        return;
    
    solve(root -> left, left - 1, right);
    solve(root -> right, left, right + 1);
    
    mx = max(mx, right - left);
    //cout << left << " " << right << endl;
}
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root == NULL)
        return 0;
    
    int count = 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int n = q.size();
        count = max(count, n);
        
        while(n--)
        {
            TreeNode<int>* node = q.front();
            q.pop();
            
            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
    }
    
    return count;
   /*  (If right question asked then)
    mx = 0;
    int left = 0, right = 0;
    solve(root, left, right);
    
    //cout << (right - left) << endl;
    return (mx); */
}